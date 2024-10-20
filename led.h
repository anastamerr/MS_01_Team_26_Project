#ifndef LED_H
#define LED_H
#include "pico/stdlib.h"

// Define LED pins
#define RED_LED_PIN 15   // Positive logic
#define GREEN_LED_PIN 14 // Positive logic
#define BLUE_LED_PIN 13  // Negative logic

// Function prototypes
void led_init(void);
void led_cycle(void);

#endif