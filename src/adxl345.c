#include "zephyr/device.h"
#include "zephyr/drivers/sensor.h"
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log_ctrl.h>
#include "adxl345.h"

const struct device *accel = DEVICE_DT_GET(DT_NODELABEL(adxl345));

int adxl345_read(double readings[3]){
    if(!device_is_ready(accel)) return -1;

    struct sensor_value val[3];
    sensor_sample_fetch(accel);
    sensor_channel_get(accel, SENSOR_CHAN_ACCEL_XYZ, val);
    
    readings[0] = val[0].val1 + ((double)val[0].val2)/1000000;
    readings[1] = val[1].val1 + ((double)val[1].val2)/1000000;
    readings[2] = val[2].val1 + ((double)val[2].val2)/1000000;

    return 0;
}
