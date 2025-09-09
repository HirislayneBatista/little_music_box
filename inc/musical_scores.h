#ifndef MUSICAL_SCORES_H
#define MUSICAL_SCORES_H

#include "musical_notes.h"
#include "config_music.h"

// Música: "Parabéns pra você"
static Nota parabens[] = {
    {SOL4, 500}, {SOL4, 500}, {LA4, 1000}, {SOL4, 1000}, {DO5, 1000}, {SI4, 2000},
    {SOL4, 500}, {SOL4, 500}, {LA4, 1000}, {SOL4, 1000}, {RE5, 1000}, {DO5, 2000},
    {SOL4, 500}, {SOL4, 500}, {SOL5, 1000}, {MI5, 1000}, {DO5, 1000}, {SI4, 1000}, {LA4, 2000},
    {FA5, 500}, {FA5, 500}, {MI5, 1000}, {DO5, 1000}, {RE5, 1000}, {DO5, 2000}
};

// Música: Twinkle Twinkle Little Star
static Nota twinkle[] = {
    {DO5, 500}, {DO5, 500}, {SOL5, 500}, {SOL5, 500}, {LA5, 500}, {LA5, 500}, {SOL5, 1000},
    {FA5, 500}, {FA5, 500}, {MI5, 500}, {MI5, 500}, {RE5, 500}, {RE5, 500}, {DO5, 1000},
    {SOL5, 500}, {SOL5, 500}, {FA5, 500}, {FA5, 500}, {MI5, 500}, {MI5, 500}, {RE5, 1000},
    {SOL5, 500}, {SOL5, 500}, {FA5, 500}, {FA5, 500}, {MI5, 500}, {MI5, 500}, {RE5, 1000},
    {DO5, 500}, {DO5, 500}, {SOL5, 500}, {SOL5, 500}, {LA5, 500}, {LA5, 500}, {SOL5, 1000},
    {FA5, 500}, {FA5, 500}, {MI5, 500}, {MI5, 500}, {RE5, 500}, {RE5, 500}, {DO5, 1000}
};

#define NUM_NOTAS_PARABENS (sizeof(parabens) / sizeof(Nota))
#define NUM_NOTAS_TWINKLE (sizeof(twinkle) / sizeof(Nota))

#endif