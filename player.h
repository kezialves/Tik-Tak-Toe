// Struct responsável pelos dados dos jogadores

#ifndef PLAYER_H_
#define PLAYER_H_

#include "formatting.h"

typedef struct {
    char name[PLAYER_NAME];
    int victories;
    int draws;
    int defeats;
} Player;

#endif