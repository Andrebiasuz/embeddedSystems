#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define PIN_USED 5


void app_main(void)
{
    gpio_pad_select_gpio(PIN_USED);
    gpio_set_direction(PIN_USED, GPIO_MODE_OUTPUT);

    bool status = 0;

    while(1){
        
        status = !status;
        gpio_set_level(PIN_USED,status);
        vTaskDelay(10 / portTICK_PERIOD_MS);     
        ESP_LOGW("GPIO 5", "PIN STATUS CHANGED");

    }
}
