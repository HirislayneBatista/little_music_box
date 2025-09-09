#include "led_button.h"
#include <stdio.h>

// Variáveis globais
volatile bool playing = false;
volatile bool stop_requested = false;
volatile int musica_selecionada = 0;  // 0 = Parabéns, 1 = Twinkle

// Inicializa o pino GPIO para o botão com pull-up
void button_init(uint pin, uint direcao) {
    gpio_init(pin);
    gpio_set_dir(pin, direcao);
    gpio_pull_up(pin);      // Ativa o resistor pull-up interno
}

// Inicializa o pino GPIO para o LED
void led_init(uint pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    gpio_put(pin, 0);       // Desliga o LED inicialmente
}

// Configura os LEDs e botões para a placa BitDogLab
void init_gpio(void) {
    // Inicializa botões
    button_init(BOTAO_A, GPIO_IN);
    button_init(BOTAO_B, GPIO_IN);

    // Inicializa LEDs
    led_init(LED_VERMELHO);
    led_init(LED_VERDE);
    led_init(LED_AZUL);

    // Configura interrupções para os botões
    gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
    gpio_set_irq_enabled(BOTAO_B, GPIO_IRQ_EDGE_FALL, true);

    printf("GPIOs inicializado para BitDogLab\n");
}

void gpio_callback(uint gpio, uint32_t events) {
    if (events & GPIO_IRQ_EDGE_FALL) {
        switch(gpio) {
            case BOTAO_A:  // Toca Parabéns
                playing = true;
                stop_requested = false;
                musica_selecionada = 0;
                printf("Botão A pressionado - Tocando Parabéns\n");
                break;
                
            case BOTAO_B:  // Toca Twinkle
                playing = true;
                stop_requested = false;
                musica_selecionada = 1;
                printf("Botão B pressionado - Tocando Twinkle\n");
                break;
        }
    }
}

void piscar_led(uint gpio_pin, int vezes, int intervalo_ms) {
    for(int i = 0; i < vezes; i++) {
        gpio_put(gpio_pin, 1);
        sleep_ms(intervalo_ms);
        gpio_put(gpio_pin, 0);
        sleep_ms(intervalo_ms);
    }
}

void set_led_color(uint vermelho, uint verde, uint azul) {
    gpio_put(LED_VERMELHO, vermelho);
    gpio_put(LED_VERDE, verde);
    gpio_put(LED_AZUL, azul);
}

EstadoBotao ler_botao(uint gpio_pin) {
    return (gpio_get(gpio_pin) == 0) ? BOTAO_PRESSIONADO : BOTAO_LIBERADO;
}