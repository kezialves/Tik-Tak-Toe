// Protótipos da biblioteca de arquivos
// Kézia Alves
// 22.1.4026

#ifndef GAME_FILES_H_
#define GAME_FILES_H_

#include "formatting.h"

// função que continua um jogo salvo
void continue_saved_game ();

// função que continua o jogo atual
void continue_current_game ();

// função que salva o jogo
void save_game (char file_name[FILE_NAME], char *player1_name, char *player2_name, char board[][3], int last_player);

#endif