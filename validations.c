// Biblioteca responsável pelas validações
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <string.h>

#include "validations.h"
#include "formatting.h"
#include "player.h"

void verify_name (int number_of_player, char *name) {

    while (!strcmp (name, "\n")) {

        printf (RED(BOLD("ERRO: Nome inválido.\n")));
        printf ("\nDigite o nome do jogador %d: ", number_of_player);
        fgets (name, PLAYER_NAME, stdin);
        printf ("\n");
    }

    while (!strcmp (name, "Computador\n")) {

        printf (RED(BOLD("ERRO: Certeza que você se chama Computador?\n")));
        printf ("\nDigite o nome do jogador %d: ", number_of_player);
        fgets (name, PLAYER_NAME, stdin);
        printf ("\n");

        while (!strcmp (name, "\n")) {

            printf (RED(BOLD("ERRO: Nome inválido.\n")));
            printf ("\nDigite o nome do jogador %d: ", number_of_player);
            fgets (name, PLAYER_NAME, stdin);
            printf ("\n");
        }
    }
}

void verify_positions (char board[][3], int x, int y, char *name) {

    char command[COMMAND_NAME];

    while (board[x][y] != ' ') {

        printf (RED(BOLD("ERRO: Posição já preenchida.")));
        printf ("\n\n");

        printf ("%s, digite o comando: ", name);
        fgets (command, COMMAND_NAME, stdin);
    }
}

int verify_winner (char board[][3]) {

    int sum = 0;

    // laço que verifica a soma das linhas

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += board[i][j];
        }

        if (sum == 360) {
            return 1;
        }

        else if (sum == 333) {
            return 2;
        }

        sum = 0;
    }

    // laço que verifica a soma das colunas

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += board[j][i];
        }

        if (sum == 360) {
            return 1;
        }

        else if (sum == 333) {
            return 2;
        }

        sum = 0;
    }

    // laço que verifica a soma da diagonal principal

    for (int i = 0; i < 3; i++) {
        
        sum += board[i][i];

        if (sum == 360) {
            return 1;
        }

        else if (sum == 333) {
            return 2;
        }

        sum = 0;
    }

    // laço que verifica a soma da diagonal secundária

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
        
            sum += board[j][i];

            if (sum == 360) {
                return 1;
            }

            else if (sum == 333) {
                return 2;
            }

            sum = 0;
        }
    }

    return 0;
}