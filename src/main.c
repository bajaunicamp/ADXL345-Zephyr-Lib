#include "zephyr/device.h"
#include "zephyr/drivers/sensor.h"
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log_ctrl.h>
 
LOG_MODULE_REGISTER();
 
const struct device *accel = DEVICE_DT_GET(DT_NODELABEL(adxl345));
 
int main(){
  log_panic();
  LOG_INF("Inicializando");
  k_msleep(1000);

  if(!device_is_ready(accel)){
    LOG_ERR("O acelerometro não está pronto!");
    return 0;
  }
  else{
    LOG_INF("O acelerometro está pronto!");
  }
 
  struct sensor_value val;
 
 
 
  while (true) {
    // Além do LOG, temos o printk
 
    k_msleep(1000);
 
    sensor_sample_fetch(accel);
    sensor_channel_get(accel, SENSOR_CHAN_ACCEL_X, &val);
    LOG_INF("Aceleracao eixo X: Parte inteira %d | Parte fracional %d", val.val1, val.val2);
    k_msleep(1000);
  }
}
