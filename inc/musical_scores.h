#ifndef MUSICAL_SCORES_H
#define MUSICAL_SCORES_H

#include "musical_notes.h"
#include "config_music.h"


// Música: Harry Potter Theme - Hedwig's Theme
static Nota musica1[] = {
    // frase 1 (B E G F# E B A F# E G F# D# F B)
    // {SI3, 400}, {MI4, 800}, // B E 
    // {SOL4, 200}, {FA4s, 200}, {MI4, 800},   // G  F#  E
    // {SI5, 200},  {LA5, 800},  {FA5s, 800}, {PAUSA, 200},   // B  A   F#
    // {MI4, 800},  {SOL4, 400}, {FA5s, 400},   // E  G   F#
    // {MI5b, 800}, {FA5, 400},  {SI3, 800},    // D# F   B

    // {PAUSA, 400}, // pequena respiração

    // CERTO ATE AQUI

    {SI3, 400}, {MI4, 800},                              // B  E
    {SOL4, 200}, {FA4s, 200}, {MI4, 800},                // G  F# E
    {SI5, 200}, {RE6, 800}, {DO6, 800}, {PAUSA, 200},    // B  D  C
    {LA5, 800}, {DO6, 400}, {SI5, 400},                  // A  C  B
    {LA5, 800}, {FA5s, 400}, {SOL5, 800},                // A  F# G

    // {PAUSA, 400}, // respiração

    // {SOL5, 200}, {FA5s, 200}, {MI5, 800},                // G  F# E
    // {SI5, 200}, {LA5, 800}, {FA5s, 800}, {PAUSA, 200},   // B  A  F#
    // {MI5, 800}, {SOL5, 400}, {FA5s, 400},                // E  G  F#
    // {MI5b, 800}, {FA5, 400}, {SI3, 1000},                // D# F  B (sustain)
};

// Música: Super Mario Theme
static Nota musica2[] = {
    // Introdução
    {MI5, 150}, {MI5, 150}, {PAUSA, 150}, {MI5, 150}, {PAUSA, 150}, {DO5, 150}, {MI5, 150}, {PAUSA, 150},
    {SOL5, 300}, {PAUSA, 300},
    
    // Primeira frase
    {SOL4, 300}, {PAUSA, 300},
    {DO5, 150}, {PAUSA, 150}, {SOL4, 150}, {PAUSA, 150}, {MI4, 150}, {PAUSA, 150},
    {LA4, 150}, {PAUSA, 150}, {SI4, 150}, {PAUSA, 150}, {SIb4, 150}, {LA4, 150},
    
    // Ponte
    {SOL4, 150}, {MI5, 150}, {SOL5, 150}, {LA5, 150}, {PAUSA, 150}, {FA5, 150}, {SOL5, 150}, {PAUSA, 150},
    {MI5, 150}, {PAUSA, 150}, {DO5, 150}, {RE5, 150}, {SI4, 150}, {PAUSA, 150},
    
    // Refrão principal
    {DO5, 150}, {PAUSA, 150}, {SOL4, 150}, {PAUSA, 150}, {MI4, 150}, {PAUSA, 150},
    {LA4, 150}, {PAUSA, 150}, {SI4, 150}, {PAUSA, 150}, {SIb4, 150}, {LA4, 150},
    
    {SOL4, 150}, {MI5, 150}, {SOL5, 150}, {LA5, 150}, {PAUSA, 150}, {FA5, 150}, {SOL5, 150}, {PAUSA, 150},
    {MI5, 150}, {PAUSA, 150}, {DO5, 150}, {RE5, 150}, {SI4, 150}, {PAUSA, 150},
    
    // Final
    {MI5, 150}, {DO5, 150}, {SOL4, 150}, {PAUSA, 150}, {SOL4, 150}, {PAUSA, 150},
    {SOL4, 150}, {MI5, 150}, {DO5, 150}, {SOL4, 150}, {PAUSA, 150},
    {SOL4, 150}, {MI5, 150}, {DO5, 150}, {SOL4, 150}, {PAUSA, 150},
    
    {LA4, 150}, {SI4, 150}, {RE5, 150}, {FA5, 150}, {LA5, 150}, {PAUSA, 150},
    {SOL5, 150}, {MI5, 150}, {DO5, 150}, {SOL4, 150}, {PAUSA, 150},
    
    {DO5, 150}, {SOL4, 150}, {MI4, 150}, {PAUSA, 150}, {MI4, 150}, {PAUSA, 150},
    {MI4, 150}, {DO5, 150}, {SOL4, 150}, {MI4, 150}, {PAUSA, 150},
    {MI4, 150}, {DO5, 150}, {SOL4, 150}, {MI4, 150}, {PAUSA, 300},
    
    {MI5, 600}  // Nota final
};


#define NUM_NOTAS_MUSICA1 (sizeof(musica1) / sizeof(Nota))
#define NUM_NOTAS_MUSICA2 (sizeof(musica2) / sizeof(Nota))

#endif