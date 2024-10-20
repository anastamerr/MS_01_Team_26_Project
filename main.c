#include <stdio.h>
#include "pico/stdlib.h"
#include "led.h"

int main()
{
    // Initialize standard I/O
    stdio_init_all();

    // Initialize LEDs
    led_init();

    printf("LED Cycle Program Started\n");

    // Continuously repeat the 10-second cycle
    while (true)
    {
        led_cycle();
    }

    return 0;
}