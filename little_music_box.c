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
    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }
    
    init_gpio();              // LEDs e botões
    buzzer_init(BUZZER_PIN);  // Buzzer com PWM

    printf("\n=== Caixinha Musical BitDogLab ===\n");
    printf("Botão A: Play/Pause Parabéns\n");
    printf("Botão B: Play/Pause Twinkle\n");

    // LED azul indicando pronto
    set_led_estado(ESTADO_PARADO);

    // Beep de inicialização
    buzzer_beep(BUZZER_PIN, 1000, 100);
    sleep_ms(100);
    buzzer_beep(BUZZER_PIN, 1200, 100);

    while (true) {
        if (playing && !stop_requested) {
            int musica_idx = get_musica_selecionada();
                if (musica_idx >= 0) {
                    printf("Tocando: %s\n", nomes_musicas[musica_idx]);
                    
                    // Atualiza LED conforme a música
                    set_led_estado(estado_atual);
                    
                    tocar_musica(musicas[musica_idx], num_notas_musicas[musica_idx]);
                    
                    playing = false;
                    
                    // Volta para estado parado
                    set_led_estado(ESTADO_PARADO);
                }
            }
        
        // Pequena pausa para não sobrecarregar a CPU
        sleep_ms(100);
    }

    return 0;
}