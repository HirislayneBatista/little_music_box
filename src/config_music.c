#include "config_music.h"
#include "musical_scores.h"
#include "led_button.h"
#include "buzzer.h"
#include <stdio.h>

// Array de músicas disponíveis
Nota* musicas[] = {musica1, musica2};
size_t num_notas_musicas[] = {NUM_NOTAS_MUSICA1, NUM_NOTAS_MUSICA2};
const char* nomes_musicas[] = {"Musica 1", "Musica 2"};

// Função para obter a música selecionada baseada no estado
int get_musica_selecionada(void) {
    switch(estado_atual) {
        case ESTADO_TOCANDO_MUSICA1:
            return 0;
        case ESTADO_TOCANDO_MUSICA2:
            return 1;
        default:
            return -1;
    }
}

void tocar_nota(uint frequencia, uint duracao_ms) {
    if (frequencia == PAUSA) {
        buzzer_stop(BUZZER_PIN);
        sleep_ms(duracao_ms);
        return;
    }
    
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
            estado_atual = ESTADO_PARADO;
            return;
        }
        
        if (musica[i].frequencia > PAUSA) {
            tocar_nota(musica[i].frequencia, musica[i].duracao);
        } else {
            silencio(musica[i].duracao);
        }
        
        silencio(30);  // Pequena pausa entre notas
    }
    
    silencio(300); // Silentio final para separar execuções
    printf("Reprodução concluída\n");
    estado_atual = ESTADO_PARADO;
}