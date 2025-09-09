#ifndef CONFIG_MUSIC_H
#define CONFIG_MUSIC_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "led_button.h"

// Pausa musical
#define PAUSA   0

// Estrutura para uma nota musical
typedef struct {
    int frequencia;
    int duracao;
} Nota;

// Array de músicas disponíveis
extern Nota* musicas[];
extern size_t num_notas_musicas[];
extern const char* nomes_musicas[];

// Funções
void tocar_nota(uint frequencia, uint duracao_ms);
void tocar_musica(Nota *musica, size_t num_notas);
void silencio(uint duracao_ms);
int get_musica_selecionada(void);

#endif