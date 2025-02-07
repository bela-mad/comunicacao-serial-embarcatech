#ifndef BUTTON_H
#define BUTTON_H

#include "pico/stdio.h"
#include "pico/stdlib.h"

// Defines
# define BUTTON_A_PIN 5
# define BUTTON_B_PIN 6

// Cabeçalhos das funções
void button_init(uint gpio);

#endif