#include "config_music.h"
#include "led_button.h"
#include "buzzer.h"
#include <stdio.h>

// Array de músicas disponíveis
Nota* musicas[] = {parabens, twinkle};
size_t num_notas_musicas[] = {NUM_NOTAS_PARABENS, NUM_NOTAS_TWINKLE};
const char* nomes_musicas[] = {"Parabens", "Twinkle"};

void tocar_nota(uint frequencia, uint duracao_ms) {
    if (frequencia == PAUSA) {
        buzzer_stop(BUZZER_PIN);
        sleep_ms(duracao_ms);
        return;
    }
    
    // Toca a nota usando a função buzzer_beep
    buzzer_beep(BUZZER_PIN, frequencia, duracao_ms);
}

void silencio(uint duracao_ms) {
    buzzer_stop(BUZZER_PIN);
    sleep_ms(duracao_ms);
}

void tocar_musica(Nota *musica, size_t num_notas) {
    printf("Iniciando reprodução de %zu notas...\n", num_notas);
    
    for (size_t i = 0; i < num_notas; i++) {
        if (stop_requested) {
            printf("Reprodução interrompida\n");
            buzzer_stop(BUZZER_PIN);
            return;
        }
        
        if (musica[i].frequencia > PAUSA) {
            tocar_nota(musica[i].frequencia, musica[i].duracao);
        } else {
            silencio(musica[i].duracao);
        }
        
        // Pequena pausa entre notas
        silencio(30);
    }
    
    // Silêncio no final
    silencio(300);
    printf("Reprodução concluída\n");
}