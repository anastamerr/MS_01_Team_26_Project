#include "led.h"
#include "pico/stdlib.h"
#include <stdio.h>

void led_init(void)
{
    // Initialize GPIO pins
    gpio_init(RED_LED_PIN);
    gpio_init(GREEN_LED_PIN);
    gpio_init(BLUE_LED_PIN);

    // Set GPIO directions
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

    // Initial state: all LEDs off
    gpio_put(RED_LED_PIN, 0);   // 0 for off (positive logic)
    gpio_put(GREEN_LED_PIN, 0); // 0 for off (positive logic)
    gpio_put(BLUE_LED_PIN, 1);  // 1 for off (negative logic)
}

void led_cycle(void)
{
    // All LEDs off for 5 seconds
    gpio_put(RED_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 0);
    gpio_put(BLUE_LED_PIN, 1);
    sleep_ms(5000);

    // Red LED on for 1 second
    gpio_put(RED_LED_PIN, 1);
    sleep_ms(1000);
    gpio_put(RED_LED_PIN, 0);

    // Green LED on for 1 second
    gpio_put(GREEN_LED_PIN, 1);
    sleep_ms(1000);
    gpio_put(GREEN_LED_PIN, 0);

    // Blue LED on for 1 second
    gpio_put(BLUE_LED_PIN, 0); // 0 for on (negative logic)
    sleep_ms(1000);
    gpio_put(BLUE_LED_PIN, 1); // 1 for off (negative logic)

    // All LEDs on for 2 seconds
    gpio_put(RED_LED_PIN, 1);
    gpio_put(GREEN_LED_PIN, 1);
    gpio_put(BLUE_LED_PIN, 0); // 0 for on (negative logic)
    sleep_ms(2000);

    // Turn off all LEDs at the end of the cycle
    gpio_put(RED_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 0);
    gpio_put(BLUE_LED_PIN, 1); // 1 for off (negative logic)
}