#ifndef CONFIG_MUSIC_H
#define CONFIG_MUSIC_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definições das notas musicais
#define DO4     262
#define RE4     294
#define MI4     330
#define FA4     349
#define SOL4    392
#define LA4     440
#define SI4     494
#define DO5     523
#define RE5     587
#define MI5     659
#define FA5     698
#define SOL5    784
#define LA5     880
#define SI5     988

// Pausa musical
#define PAUSA   0

// Estrutura para uma nota musical
typedef struct {
    int frequencia;
    int duracao;
} Nota;

// Música: "Parabéns pra você"
static Nota parabens[] = {
    {SOL4, 500}, {SOL4, 500}, {LA4, 1000}, {SOL4, 1000}, {DO5, 1000}, {SI4, 2000},
    {SOL4, 500}, {SOL4, 500}, {LA4, 1000}, {SOL4, 1000}, {RE5, 1000}, {DO5, 2000},
    {SOL4, 500}, {SOL4, 500}, {SOL5, 1000}, {MI5, 1000}, {DO5, 1000}, {SI4, 1000}, {LA4, 2000},
    {FA5, 500}, {FA5, 500}, {MI5, 1000}, {DO5, 1000}, {RE5, 1000}, {DO5, 2000}
};

#define NUM_NOTAS_PARABENS (sizeof(parabens) / sizeof(Nota))

// Música: Twinkle Twinkle Little Star
static Nota twinkle[] = {
    {DO5, 500}, {DO5, 500}, {SOL5, 500}, {SOL5, 500}, {LA5, 500}, {LA5, 500}, {SOL5, 1000},
    {FA5, 500}, {FA5, 500}, {MI5, 500}, {MI5, 500}, {RE5, 500}, {RE5, 500}, {DO5, 1000},
    {SOL5, 500}, {SOL5, 500}, {FA5, 500}, {FA5, 500}, {MI5, 500}, {MI5, 500}, {RE5, 1000},
    {SOL5, 500}, {SOL5, 500}, {FA5, 500}, {FA5, 500}, {MI5, 500}, {MI5, 500}, {RE5, 1000},
    {DO5, 500}, {DO5, 500}, {SOL5, 500}, {SOL5, 500}, {LA5, 500}, {LA5, 500}, {SOL5, 1000},
    {FA5, 500}, {FA5, 500}, {MI5, 500}, {MI5, 500}, {RE5, 500}, {RE5, 500}, {DO5, 1000}
};

#define NUM_NOTAS_TWINKLE (sizeof(twinkle) / sizeof(Nota))

// Array de músicas disponíveis
extern Nota* musicas[];
extern size_t num_notas_musicas[];
extern const char* nomes_musicas[];
#define NUM_MUSICAS 2

// Funções
void tocar_nota(uint frequencia, uint duracao_ms);
void tocar_musica(Nota *musica, size_t num_notas);
void silencio(uint duracao_ms);

#endif