#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define PIN_USED 25
#define PIN_DI 34

void app_main(void)
{
    gpio_pad_select_gpio(PIN_USED);
    gpio_set_direction(PIN_USED, GPIO_MODE_OUTPUT);

    gpio_pad_select_gpio(PIN_DI);
    gpio_set_direction(PIN_DI, GPIO_MODE_INPUT);

    bool status = 0;

    while(1){
        
        status = gpio_get_level(PIN_DI);
        if (status == 1) {
            ESP_LOGW("GPIO 34", "PIN STATUS CHANGED");
        }

        gpio_set_level(PIN_USED,status);
        //ESP_LOGW("GPIO 5", "PIN STATUS CHANGED");

        vTaskDelay(10 / portTICK_PERIOD_MS);     

    }
}
