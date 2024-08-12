/**
 * @file traffic_signal.c
 * @brief Traffic signal control using LEDs connected to GPIO pins.
 *
 * This program simulates a traffic light system using three LEDs connected to
 * the GPIO pins of an ESP32 microcontroller. The green, yellow, and red LEDs 
 * are turned on and off with appropriate delays to mimic the behavior of a 
 * real traffic signal.
 */

#include <stdio.h>
#include <time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"

// Define GPIO pins for LEDs

 ///< GPIO pin for green LED
#define GREEN_LED_PIN   GPIO_NUM_2 
 ///< GPIO pin for yellow LED
#define YELLOW_LED_PIN  GPIO_NUM_4 
 ///< GPIO pin for red LED
#define RED_LED_PIN     GPIO_NUM_5 

// Function prototypes
/**
 * @brief Traffic signal task to control the LEDs.
 *
 * This task continuously cycles through the green, yellow, and red LEDs,
 * turning each one on for a specified duration to simulate a traffic signal.
 *
 * @param pvParameter A parameter passed to the task (not used in this example).
 */
void traffic_signal_task(void *pvParameter);

void traffic_signal_task(void *pvParameter) {
    while (1) {
        // Turn on green LED
        printf(" Green LED is ON\n");
        gpio_set_level(GREEN_LED_PIN, 1);
        gpio_set_level(YELLOW_LED_PIN, 0);
        gpio_set_level(RED_LED_PIN, 0);
        vTaskDelay(60000 / portTICK_PERIOD_MS); // Delay for 1 minute

        // Turn on yellow LED
        printf("Yellow LED is ON\n");
        gpio_set_level(GREEN_LED_PIN, 0);
        gpio_set_level(YELLOW_LED_PIN, 1);
        gpio_set_level(RED_LED_PIN, 0);
        vTaskDelay(3000 / portTICK_PERIOD_MS); // Delay for 3 seconds

        // Turn on red LED
        printf(" Red LED is ON\n");
        gpio_set_level(GREEN_LED_PIN, 0);
        gpio_set_level(YELLOW_LED_PIN, 0);
        gpio_set_level(RED_LED_PIN, 1);
        vTaskDelay(60000 / portTICK_PERIOD_MS); // Delay for 1 minute
    }
}

void app_main(void) {
    // Configure GPIOs for LEDs
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << GREEN_LED_PIN) | (1ULL << YELLOW_LED_PIN) | (1ULL << RED_LED_PIN);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);

    // Start the traffic signal task
    xTaskCreate(traffic_signal_task, "traffic_signal_task", 2048, NULL, 5, NULL);
}
