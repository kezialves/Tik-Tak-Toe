// Protótipos da biblioteca de validações
// Kézia Alves
// 22.1.4026

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

// função que verifica o nome do jogador
void verify_name (int number_of_player, char *name);

// função que verifica o nome do jogador 2
// msm coisa que a anterior + valida se o nome não é igual ao do p1
void verify_name_p2 (char *player1_name, char *player2_name);

// função que verifica se a posição já foi marcada
void verify_positions (char board[][3], int *x, int *y, char *name);

// função que verifica se alguém ganhou
int verify_winner (char board[][3]);

// função que verifica se o tipo do arquivo é válido
void verify_file_name (char * file_name);

// função que verifica se o arquivo buscado existe
int verify_file_exists (char * file_name);

#endif