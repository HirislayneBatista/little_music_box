#ifndef LED_BUTTON_H
#define LED_BUTTON_H

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição das pinagens - placa BitDogLab
#define BUZZER_PIN      21  // GPIO do buzzer A na BitDogLab
#define BOTAO_A         5  // Botão A na BitDogLab
#define BOTAO_B         6  // Botão B na BitDogLab
#define LED_VERMELHO    13  // LED Vermelho
#define LED_VERDE       11  // LED Verde
#define LED_AZUL        12  // LED Azul (onboard)

// Estados dos botões
typedef enum {
    BOTAO_LIBERADO,
    BOTAO_PRESSIONADO
} EstadoBotao;

// Protótipos das funções
void init_gpio(void);
void gpio_callback(uint gpio, uint32_t events);
void piscar_led(uint gpio_pin, int vezes, int intervalo_ms);
void set_led_color(uint vermelho, uint verde, uint azul);
EstadoBotao ler_botao(uint gpio_pin);

// Variáveis globais (declaradas como extern)
extern volatile bool playing;
extern volatile bool stop_requested;
extern volatile int musica_selecionada;

#endif