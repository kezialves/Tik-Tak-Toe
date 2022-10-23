// Biblioteca responsável pelos arquivos
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <string.h>

#include "game_files.h"
#include "validations.h"
#include "formatting.h"
#include "structs.h"

void continue_saved_game () {

    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };

    char game_file_name[FILE_NAME];
    int number_of_players;
    char c;
    int last_player;

    printf ("Digite o nome do arquivo do jogo: ");
    fgets (game_file_name, FILE_NAME, stdin);
    printf ("\n");

    verify_file_name (game_file_name);

    FILE * file = fopen (game_file_name, "r");

    fscanf (file, "%d", &number_of_players);

    char player_name[PLAYER_NAME];
    fgets (player_name, PLAYER_NAME, file);

    if (number_of_players == 2) {
        char player2_name[PLAYER_NAME];
        fgets (player2_name, PLAYER_NAME, file);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 3; i++) {

            c = fgetc (file);

            if (c == 'X') {
                board[i][j] = 'x';
            }

            else if (c == 'O') {
                board[i][j] = 'o';
            }

            else if (c == '-') {
                board[i][j] = ' ';
            }

            else {
                i--;
            }
        }
    }

    fclose (file);
}

void save_game (char file_name[FILE_NAME], char *player1_name, char *player2_name, char board[][3], int last_player) {

    verify_file_name (file_name);

    FILE * file = fopen (file_name, "w");

    if (!strcmp (player2_name, "Computador")) {
        fprintf (file, "1\n%s\n", player1_name);
    }

    else {
        fprintf (file, "2\n%s\n%s\n", player1_name, player2_name);
    }

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (board[i][j] == 'x') {
                fputc ('X', file);
            }

            else if (board[i][j] == 'o') {
                fputc ('O', file);
            }

            else {
                fputc ('-', file);
            }

            if (j != 2) {
                fputc (' ', file);
            }
        }

        fputc ('\n', file);
    }

    fprintf (file, "%d", last_player);

    fclose (file);
}