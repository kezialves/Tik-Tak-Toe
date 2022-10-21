// Protótipos da biblioteca de validações
// Kézia Alves
// 22.1.4026

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

// função que verifica o nome do jogador
void verify_name (int number_of_player, char *name);

// função que verifica se a posição já foi marcada
void verify_positions (char board[][3], int x, int y, char *name) {

// função que verifica se alguém ganhou
int verify_winner (char board[][3]);

#endif