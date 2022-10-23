// Protótipos da biblioteca de inteligência
// Kézia Alves
// 22.1.4026

#ifndef GAME_INTELIGENCE_H_
#define GAME_INTELIGENCE_H_

#include "structs.h"

// função que roda o jogo contra o computador
int player_vs_computer ();

// função que calcula a melhor posição
void calculate_position (char board[][3]);

#endif