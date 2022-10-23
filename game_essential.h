// Protótipos da biblioteca de funcionalidades gerais
// Kézia Alves
// 22.1.4026

#ifndef GAME_ESSENTIAL_H_
#define GAME_ESSENTIAL_H_

#include "structs.h"

// função que recebe a opção
void choose_menu (int time);

// função que encerra o jogo
void close_game ();

// função que inicia um novo jogo
void new_game ();

// função que inicializa o tabuleiro;
char ** initializes_board ();

// função que inicializa o jogador
void initializes_player (Player *player);

// função que recebe o comando
void get_command (char *player_name, Command *command);

// função que marca no tabuleiro
char mark_position (char board[][3], int *x, int *y, int player, char *player_name);

#endif