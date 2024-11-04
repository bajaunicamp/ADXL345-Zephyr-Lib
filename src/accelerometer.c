#include "accelerometer.h"

static const struct device *adxl345 = DEVICE_DT_GET(DT_NODELABEL(i2c1));

int iniciar_accel(){
    return adxl345_init(adxl345);
}

int ler_accel(double data[3]){
    int ret;

    struct adxl345_sample *sample;
    struct sensor_value *val;

    ret = adxl345_read_sample(adxl345, sample);
    if(ret) return ret;

    adxl345_accel_convert(val, sample->x);
    data[0] = val->val1 + val->val2/1000000;

    adxl345_accel_convert(val, sample->y);
    data[1] = val->val1 + val->val2/1000000;

    adxl345_accel_convert(val, sample->z);
    data[2] = val->val1 + val->val2/1000000;

    return 0;
}