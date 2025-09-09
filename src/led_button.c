#include "led_button.h"
#include <stdio.h>

// Variáveis globais
volatile bool playing = false;
volatile bool stop_requested = false;
volatile EstadoReproducao estado_atual = ESTADO_PARADO;

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

// Callback de interrupção para os botões
void gpio_callback(uint gpio, uint32_t events) {
    if (events & GPIO_IRQ_EDGE_FALL) {
        switch(gpio) {
            case BOTAO_A:  // Play/Pause Parabéns
                if (estado_atual == ESTADO_TOCANDO_PARABENS) {
                    // Se já está tocando Parabéns, para
                    stop_requested = true;
                    estado_atual = ESTADO_PARADO;
                    printf("Parabéns pausado\n");
                } else {
                    // Se não está tocando ou está tocando outra música, inicia Parabéns
                    playing = true;
                    stop_requested = false;
                    estado_atual = ESTADO_TOCANDO_PARABENS;
                    printf("Tocando Parabéns\n");
                }
                break;
                
            case BOTAO_B:  // Play/Pause Twinkle
                if (estado_atual == ESTADO_TOCANDO_TWINKLE) {
                    // Se já está tocando Twinkle, para
                    stop_requested = true;
                    estado_atual = ESTADO_PARADO;
                    printf("Twinkle pausado\n");
                } else {
                    // Se não está tocando ou está tocando outra música, inicia Twinkle
                    playing = true;
                    stop_requested = false;
                    estado_atual = ESTADO_TOCANDO_TWINKLE;
                    printf("Tocando Twinkle\n");
                }
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

void set_led_estado(EstadoReproducao estado) {
    switch(estado) {
        case ESTADO_PARADO:
            set_led_color(0, 0, 1);  // Azul - pronto
            break;
        case ESTADO_TOCANDO_PARABENS:
            set_led_color(1, 0, 0);  // Vermelho - Parabéns
            break;
        case ESTADO_TOCANDO_TWINKLE:
            set_led_color(0, 1, 0);  // Verde - Twinkle
            break;
    }
}

EstadoBotao ler_botao(uint gpio_pin) {
    return (gpio_get(gpio_pin) == 0) ? BOTAO_PRESSIONADO : BOTAO_LIBERADO;
}