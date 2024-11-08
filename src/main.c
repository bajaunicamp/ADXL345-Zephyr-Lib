#include "zephyr/device.h"
#include "zephyr/drivers/sensor.h"
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log_ctrl.h>
#include "adxl345.h"
 
LOG_MODULE_REGISTER();
  
int main(){
    double data[3];
    while(1){
        k_msleep(100);
        if(adxl345_read_acceleration(data)){
            LOG_ERR("Não foi possível ler os dados do acelerômetro");
            continue;
        }

        LOG_INF("Xa: %f m/s²\nYa: %f m/s²\nZa: %f m/s²\n", data[0], data[1], data[2]);
    
        adxl345_read_speed(data);
        LOG_INF("Xv: %f m/s²\nYv: %f m/s²\nZv: %f m/s²\n", data[0], data[1], data[2]);

    }
}
