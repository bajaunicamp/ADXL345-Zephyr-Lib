#include "zephyr/device.h"
#include "zephyr/drivers/sensor.h"
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log_ctrl.h>
#include <zephyr/timing/timing.h>
#include "adxl345.h"

#define PERIODO_VELOCIDADE K_MSEC(1)
double ALPHA = 0.99686824604;
#define initial_acc_x -0.612915
#define initial_acc_y -0.612915
#define initial_acc_z -10.113107

static double last_accelerations = {initial_acc_x, initial_acc_y, initial_acc_z};
static double velocidade[3] = {0, 0, 0};
static const struct device *accel = DEVICE_DT_GET(DT_NODELABEL(adxl345));
static struct k_timer timer_accel;

double previous_filtered[3] = {0}, previous_input[3] = {0};
static inline void high_pass_filter(double current_input[3], double output[3]){
    previous_filtered[0] = ALPHA * (previous_filtered[0] + current_input[0] - previous_input[0]);
    previous_filtered[1] = ALPHA * (previous_filtered[1] + current_input[1] - previous_input[1]);
    previous_filtered[2] = ALPHA * (previous_filtered[2] + current_input[2] - previous_input[2]);

    output[0] = previous_filtered[0];
    output[1] = previous_filtered[1];
    output[2] = previous_filtered[2];

    previous_input[0] = current_input[0];
    previous_input[1] = current_input[1];
    previous_input[2] = current_input[2];
}

static void timer_callback(struct k_timer *timer){
    double readings[3];
    adxl345_read_acceleration(readings);
    high_pass_filter(readings, velocidade);
    k_timer_start(&timer_accel, PERIODO_VELOCIDADE, K_NO_WAIT);
}

void adxl345_init(){
    k_timer_init(&timer_accel, timer_callback, NULL);
    k_timer_start(&timer_accel, PERIODO_VELOCIDADE, K_NO_WAIT);
}

int adxl345_read_acceleration(double readings[3]){
    if(!device_is_ready(accel)) return -1;

    struct sensor_value val[3];
    // antes de ler os dados do sensor é preciso dar fetch
    sensor_sample_fetch(accel);
    sensor_channel_get(accel, SENSOR_CHAN_ACCEL_XYZ, val);
    
    readings[0] = val[0].val1 + ((double)val[0].val2)/1000000;
    readings[1] = val[1].val1 + ((double)val[1].val2)/1000000;
    readings[2] = val[2].val1 + ((double)val[2].val2)/1000000;

    return 0;
}

void adxl345_read_speed(double readings[3]){
    readings[0] = velocidade[0];
    readings[1] = velocidade[1];
    readings[2] = velocidade[2];
}
