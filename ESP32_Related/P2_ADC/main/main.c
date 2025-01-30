#include <stdio.h>

//RTOS
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// esp Dedicated libraries
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_log.h"

// Include drivers
#include "driver/gpio.h"
#include "driver/adc.h"


void app_main(void)
{
    // Using ADC1

    // Configuring 12 bits of resolution for ADC. Less bits used equal less
    // resolution, but also less processing time and a higher sample rate
    adc1_config_width(ADC_WIDTH_BIT_12) ;

    // Working with ADC CH4 , with 11db of gain
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);

    adc2 
}