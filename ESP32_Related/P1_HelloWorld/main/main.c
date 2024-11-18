#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define PIN_POWERON 13 // Intermitent blink, showing system is running
#define PIN_DO 25 // Led Activated with Microswitch
#define PIN_DI 34 // Microswitch connected

void app_main(void)
{

    gpio_pad_select_gpio(PIN_DI);
    gpio_set_direction(PIN_DI, GPIO_MODE_INPUT);

    gpio_pad_select_gpio(PIN_DO);
    gpio_set_direction(PIN_DO, GPIO_MODE_OUTPUT);

    gpio_pad_select_gpio(PIN_POWERON);
    gpio_set_direction(PIN_POWERON, GPIO_MODE_OUTPUT);

    bool state_DI_PIN = 0;

    while(1){

        // LED For Power ON 
        gpio_set_level(PIN_POWERON,1);
        

        // Read DI, Activate DO routine

        state_DI_PIN = gpio_get_level(PIN_DI);

        if (state_DI_PIN == 1) {
            ESP_LOGW("GPIO 34", "PIN STATUS CHANGED");
            gpio_set_level(PIN_DO,state_DI_PIN);
        }
        else {
            gpio_set_level(PIN_DO,0);
        }

        // Delay for RTOS
        vTaskDelay(10 / portTICK_PERIOD_MS);     

    }
}
