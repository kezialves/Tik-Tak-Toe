// Biblioteca de structs

#ifndef PLAYER_H_
#define PLAYER_H_

#include "formatting.h"

typedef struct {
    int number_of_players;
    int last_player;
    int marked_positions;
} Game;

typedef struct {
    char name[PLAYER_NAME];
    int victories;
    int draws;
    int defeats;
} Player;

typedef struct {
    char first_command[COMMAND_NAME];
    char second_command[COMMAND_NAME];
} Command;

#endif