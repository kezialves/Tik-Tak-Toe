// Biblioteca responsável pelas validações
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "validations.h"
#include "formatting.h"
#include "structs.h"
#include "game_essential.h"

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

void verify_name_p2 (char *player1_name, char *player2_name) {

    verify_name (2, player2_name);

    while (!strcmp (player2_name, player1_name)) {

        printf (RED(BOLD("ERRO: Você não pode jogar contra você mesmo.\n")));
        printf ("\nDigite o nome do jogador 2: ");
        fgets (player2_name, PLAYER_NAME, stdin);
        printf ("\n");

        verify_name (2, player2_name);
    }
}

void verify_positions (char board[][3], int *x, int *y, char *name) {

    Command command;
    int coordinates;

    while (*x < 0 || *x > 2 || *y < 0 || *y > 2) {

        printf (RED(BOLD("\nERRO: Posição inválida.")));
        printf ("\n\n");

        get_command (name, &command);

        command.second_command[strlen (command.second_command) - 1] = '\0';
        
        coordinates = atoi (command.second_command);

        *x = (((coordinates / 10) % 10)) - 1;
        *y = (coordinates % 10) - 1;
    }

    while (board[*x][*y] != ' ') {

        printf (RED(BOLD("\nERRO: Posição já preenchida.")));
        printf ("\n\n");

        get_command (name, &command);

        command.second_command[strlen (command.second_command) - 1] = '\0';
        
        coordinates = atoi (command.second_command);

        *x = (((coordinates / 10) % 10)) - 1;
        *y = (coordinates % 10) - 1;

        while (*x < 0 || *x > 2 || *y < 0 || *y > 2) {

            printf (RED(BOLD("\nERRO: Posição inválida.")));
            printf ("\n\n");

            get_command (name, &command);

            command.second_command[strlen (command.second_command) - 1] = '\0';
        
            coordinates = atoi (command.second_command);

            *x = (((coordinates / 10) % 10)) - 1;
            *y = (coordinates % 10) - 1;
        }
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
    }

    sum = 0;

    // laço que verifica a soma da diagonal secundária

    for (int i = 0; i < 3; i++) {

        sum += board[i][3 - i - 1];

        if (sum == 360) {
            return 1;
        }

        else if (sum == 333) {
            return 2;
        }
    }

    return 0;
}

void verify_file_name (char *file_name) {

    int size_of_file_name = strlen (file_name);

    file_name[size_of_file_name - 1] = '\0';

    while (file_name[size_of_file_name - 5] != '.' ||
            file_name[size_of_file_name - 4] != 't' ||
            file_name[size_of_file_name - 3] != 'x' ||
            file_name[size_of_file_name - 2] != 't') {

        printf (RED(BOLD("ERRO: O tipo do arquivo é inválido, informe um .txt\n\n")));

        printf ("Digite o nome do arquivo do jogo: ");
        fgets (file_name, FILE_NAME, stdin);
        printf ("\n");

        size_of_file_name = strlen (file_name);
    }
}

int verify_file_exists (char *file_name) {

    FILE * file;

    if ((file = fopen(file_name, "r"))){

        fclose(file);

        return 1;
    }

    return 0;
}

void verify_file (char *file_name) {

    verify_file_name (file_name);

    while (!verify_file_exists (file_name)) {

        printf (RED(BOLD("ERRO: O arquivo não existe.\n\n")));
        printf ("Digite o nome do arquivo do jogo: ");
        fgets (file_name, FILE_NAME, stdin);
        printf ("\n");

        verify_file_name (file_name);
    }
}