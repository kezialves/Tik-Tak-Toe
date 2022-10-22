// Protótipos da biblioteca de funcionalidades gerais
// Kézia Alves
// 22.1.4026

#ifndef GAME_ESSENTIAL_H_
#define GAME_ESSENTIAL_H_

#include "player.h"

// função que recebe a opção
void choose_menu (int time);

// função que encerra o jogo
void close_game ();

// função que inicia um novo jogo
void new_game ();

// função que inicializa o jogador
void initializes_player (Player *player);

#endif