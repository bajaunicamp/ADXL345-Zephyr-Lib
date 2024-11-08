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
        k_msleep(10);
        if(adxl345_read(data)){
            LOG_ERR("Não foi possível ler os dados do acelerômetro");
            continue;
        }

        LOG_INF("X: %f m/s²\nY: %f m/s²\nZ: %f m/s²\n", data[0], data[1], data[2]);
    }
}
