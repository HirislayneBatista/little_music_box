/*
Bem-vindo à Caixinha Musical BitDogLab!
Este projeto transforma um Raspberry Pi Pico em uma caixinha musical interativa com LEDs e botões.

Funcionalidades:
Botão A: Play/Pause da música Parabéns
Botão B: Play/Pause da música Twinkle
LED indicador: Mostra qual música está tocando

As músicas são tocadas através de um buzzer controlado por PWM, e os LEDs indicam o estado atual.
Divirta-se personalizando as músicas e os efeitos visuais!

Autores: Hirislayne Batista
Data: 08-09-2025

*/
#include "led_button.h"
#include "config_music.h"
#include "buzzer.h"
#include <stdio.h>

int main() {
    // Inicializações
    stdio_init_all();
    init_gpio();              // LEDs e botões
    buzzer_init(BUZZER_PIN);  // Buzzer com PWM

    printf("=== Caixinha Musical BitDogLab ===\n");
    printf("Botao A (GPIO %d): Toca Parabéns\n", BOTAO_A);
    printf("Botao B (GPIO %d): Toca Twinkle\n", BOTAO_B);
    printf("Buzzer: GPIO %d\n", BUZZER_PIN);
    printf("Musica atual: %s\n", nomes_musicas[musica_selecionada]);

    // LED azul indicando pronto
    set_led_color(0, 0, 1);

    // Beep de inicialização
    buzzer_beep(BUZZER_PIN, 1000, 100);
    sleep_ms(100);
    buzzer_beep(BUZZER_PIN, 1200, 100);

    while (true) {
        if (playing && !stop_requested) {
            printf("Tocando: %s\n", nomes_musicas[musica_selecionada]);
            
            // LED verde durante reprodução
            set_led_color(0, 1, 0);
            piscar_led(LED_VERDE, 2, 100);
            
            tocar_musica(musicas[musica_selecionada], num_notas_musicas[musica_selecionada]);
            
            playing = false;
            
            // Volta para LED azul
            set_led_color(0, 0, 1);
        }
        
        // Pequena pausa para não sobrecarregar a CPU
        sleep_ms(100);
    }

    return 0;
}