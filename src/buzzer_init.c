#include "buzzer.h"
#include "led_button.h"
#include <stdio.h>
#include <math.h>

// Variável global do slice PWM (definida aqui)
uint buzzer_slice;

// Configura o PWM em qualquer pino GPIO
uint config_pwm(uint pin, uint32_t frequency, uint32_t wrap, float duty_cycle) {
    if (wrap == 0) wrap = BUZZER_WRAP;                     // Evita divisão por zero
    gpio_set_function(pin, GPIO_FUNC_PWM);                 // Configura o pino como PWM
    uint slice = pwm_gpio_to_slice_num(pin);               // Obtém o slice PWM
    
    uint32_t system_clock = 125000000;                     // Clock do sistema (125 MHz)
    float div = system_clock / (frequency * (float)wrap);  // Calcula divisor para a frequência
    if (div < 1.0f) div = 1.0f;                           // Divisor mínimo
    uint32_t level = (uint32_t)(duty_cycle * (float)wrap); // Calcula nível do duty cycle

    pwm_set_clkdiv(slice, div);                            // Define divisor
    pwm_set_wrap(slice, wrap);                             // Define resolução do PWM
    pwm_set_gpio_level(pin, level);                        // Define duty cycle inicial
    pwm_set_enabled(slice, false);                         // PWM desativado inicialmente
    
    return slice;                                          // Retorna o slice para uso posterior
}

// Configura o buzzer com PWM
void buzzer_init(uint gpio_pin) { 
    // Inicializa com frequência padrão e duty cycle 0%
    buzzer_slice = config_pwm(gpio_pin, 1000, BUZZER_WRAP, BUZZER_DUTY_CYCLE_0);
    printf("Buzzer inicializado no GPIO %u, slice %u\n", gpio_pin, buzzer_slice);
}

// Emite um beep por uma duração específica
void buzzer_beep(uint gpio_pin, uint frequency, uint duration_ms) {
    // Reconfigura para a frequência desejada com 50% duty cycle
    uint32_t system_clock = 125000000;
    float div = system_clock / (frequency * (float)BUZZER_WRAP);
    if (div < 1.0f) div = 1.0f;
    uint32_t level = (uint32_t)(BUZZER_DUTY_CYCLE_50 * BUZZER_WRAP);

    pwm_set_clkdiv(buzzer_slice, div);
    pwm_set_wrap(buzzer_slice, BUZZER_WRAP);
    pwm_set_gpio_level(gpio_pin, level);
    pwm_set_enabled(buzzer_slice, true);                          // Liga o PWM
    
    sleep_ms(duration_ms);                                 // Aguarda a duração do beep
    
    pwm_set_enabled(buzzer_slice, false);                         // Desliga o PWM
}

// Para o buzzer (garante que está desligado)
void buzzer_stop(uint gpio_pin) {
    pwm_set_enabled(buzzer_slice, false);
    pwm_set_gpio_level(gpio_pin, 0);
}