#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Constantes para PWM
#define BUZZER_WRAP 4096              // Resolução do PWM (4096 para 12 bits)
#define BUZZER_DUTY_CYCLE_50 0.5f     // Duty cycle de 50% para buzzer
#define BUZZER_DUTY_CYCLE_0 0.0f      // Duty cycle de 0% para buzzer (desligado)

// Variável global do slice PWM (adicionar esta linha)
extern uint buzzer_slice;

// Protótipos das funções
void buzzer_init(uint gpio_pin);
void buzzer_beep(uint gpio_pin, uint frequency, uint duration_ms);
void buzzer_stop(uint gpio_pin);
uint config_pwm(uint pin, uint32_t frequency, uint32_t wrap, float duty_cycle);

#endif