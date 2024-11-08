#ifndef ADXL345_H
#define ADXL345_H

void adxl345_init();

int adxl345_read_acceleration(double readings[3]);

void adxl345_read_speed(double readings[3]);

#endif