// Biblioteca responsável pela inteligência
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "game_inteligence.h"
#include "formatting.h"
#include "player.h"
#include "game_interface.h"
#include "validations.h"

int player_vs_computer () {

    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };

    Player player;
    // Player computer;
    char command[COMMAND_NAME];
    int current_player = 0;
    int coordinates, x, y;
    int marked_positions = 0;

    // initializes_player (&player);
    // initializes_player (&computer);

    srand (time(NULL));

    getchar ();

    printf ("Digite o nome do jogador 1: ");
    fgets (player.name, PLAYER_NAME, stdin);
    printf ("\n");

    verify_name (1, player.name);

    player.name[strlen (player.name) - 1] = '\0';

    display_board (board);

    printf ("%s, digite o comando: ", player.name);
    fgets (command, COMMAND_NAME, stdin);

    while (command[0] == 'm') { // enquanto o comando for "marcar", o jogo roda

        while (marked_positions <= 9) {
            
            if (current_player == 0) {

                while (command[7] < 49 || command[7] > 51 || command[8] < 49 || command[8] > 51) {
        
                    printf (RED(BOLD("\nERRO: Posição inválida.")));
                    printf ("\n\n");

                    printf ("%s, digite o comando: ", player.name);
                    fgets (command, COMMAND_NAME, stdin);
                }

                command[0] = command [7];
                command[1] = command [8];
                command[2] = '\0';

                coordinates = atoi (command);
                x = (((coordinates / 10) % 10)) - 1;
                y = (coordinates % 10) - 1;

                board[x][y] = 'x';

                display_board (board);

                printf ("\nMinha vez :)\n");

                // se o jogador 1 marcar em algum dos cantos, o bot marca no meio

                if (board[0][0] == 'x' || board [0][2] == 'x' || board[2][0] == 'x' || board[2][2] == 'x') {
                    board[1][1] = 'o';
                }

                // senão, o bot marca em alguma posição aleatória

                else {
                    do {
                        x = rand () % 3;
                        y = rand () % 3;
                    } while (board[x][y] != ' ');

                    board[x][y] = 'o';
                }

                marked_positions += 2;
                current_player ++;

                display_board (board);
            }

            if (current_player == 1) {

                printf ("%s, digite o comando: ", player.name);
                fgets (command, COMMAND_NAME, stdin);

                while (command[7] < 49 || command[7] > 51 || command[8] < 49 || command[8] > 51) {
        
                    printf (RED(BOLD("\nERRO: Posição inválida.")));
                    printf ("\n\n");

                    printf ("%s, digite o comando: ", player.name);
                    fgets (command, COMMAND_NAME, stdin);
                }

                command[0] = command [7];
                command[1] = command [8];
                command[2] = '\0';

                coordinates = atoi (command);
                
                x = (((coordinates / 10) % 10)) - 1;
                y = (coordinates % 10) - 1;

                while (board[x][y] != ' ') {

                    printf (RED(BOLD("\nERRO: Posição já preenchida.")));
                    printf ("\n\n");

                    printf ("%s, digite o comando: ", player.name);
                    fgets (command, COMMAND_NAME, stdin);
                }

                board[x][y] = 'x';

                marked_positions++;

                display_board (board);

                if (marked_positions >= 5) {

                    if (verify_winner (board) == 1) {

                        printf ("Parabéns! Você ganhou ;)\n\n");
                        // player.victories++;
                        // computer.defeats++;

                        return 0;
                    }
                }

                printf ("\nMinha vez :)\n");

                calculate_position (board);

                marked_positions++;

                display_board (board);

                if (marked_positions >= 5) {

                    if (verify_winner (board) == 2) {

                        printf ("Eu ganhei ;)\n\n");
                        // computer.victories++;
                        // player.defeats++;

                        return 0;
                    }
                }
            }
        }

        printf ("Eta! Deu velha, ninguém venceu ;)\n\n");

        // player.draws++;
        // computer.draws++;

        return 0;
    }

    return 0;
}

void calculate_position (char board[][3]) {

    int random;

    // se o jogador 1 estiver quase marcando uma linha, o bot barra
    // se o jogador 1 estiver quase marcando uma coluna, o bot barra
    // se o jogador 1 estiver quase marcando uma diagonal, o bot barra
    // se o jogador 1 estiver quase fazendo o L, o bot barra
    // casos de L: ┗ || ┓ || ┏ || ┛

    // primeira linha

    // o bot tenta marcar na melhor opção

    if (board[0][0] == 'x' && board [0][2] == 'x' && board[0][1] == ' ') {
        board[0][1] = 'o';
    }

    // se já estiver marcada, o bot tenta barrar os L's ┓ e ┏

    else if (board[0][0] == 'x' && board [0][2] == 'x' && board[2][0] == ' ' && board[2][2] == ' ') {

        random = rand () % 2;

        if (random == 1) random++;

        board[2][random] = 'o';
    }

    else if (board[0][0] == 'x' && board [0][2] == 'x' && board[2][0] == ' ') {
        board[2][0] = 'o';
    }

    else if (board[0][0] == 'x' && board [0][2] == 'x' && board[2][2] == ' ') {
        board[2][2] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[0][0] == 'x' && board [0][1] == 'x' && board[0][2] == ' ') {
        board[0][2] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[0][1] == 'x' && board [0][2] == 'x' && board[0][0] == ' ') {
        board[0][0] = 'o';
    }

    // linha do meio

    // o bot tenta marcar na melhor opção

    else if (board[1][0] == 'x' && board [1][2] == 'x' && board[1][1] == ' ') {
        board[1][1] = 'o';
    }
    
    // o bot tenta marcar na melhor opção

    else if (board[1][0] == 'x' && board [1][1] == 'x' && board[1][2] == ' ') {
        board[1][2] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[1][1] == 'x' && board [1][2] == 'x' && board[1][0] == ' ') {
        board[1][0] = 'o';
    }

    // terceira linha

    // o bot tenta marcar na melhor opção

    else if (board[2][0] == 'x' && board [2][2] == 'x' && board[2][1] == ' ') {
        board[2][1] = 'o';
    }

    // se já estiver marcada, o bot tenta barrar os L's ┗ e ┛
    
    else if (board[2][0] == 'x' && board [2][2] == 'x' && board[0][0] == ' ' && board[0][2] == ' ') {

        random = rand () % 2;

        if (random == 1) random++;

        board[0][random] = 'o';
    }

    else if (board[2][0] == 'x' && board [2][2] == 'x' && board[2][1] == ' ') {
        board[0][0] = 'o';
    }

    else if (board[2][0] == 'x' && board [2][2] == 'x' && board[2][1] == ' ') {
        board[0][2] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[2][0] == 'x' && board [2][1] == 'x' && board[2][2] == ' ') {
        board[2][2] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[2][1] == 'x' && board [2][2] == 'x' && board[2][0] == ' ') {
        board[2][0] = 'o';
    }

    // primeira coluna

    // o bot tenta marcar na melhor opção

    else if (board[0][0] == 'x' && board [2][0] == 'x' && board[1][0] == ' ') {
        board[1][0] = 'o';
    }

    // se já estiver marcada, o bot tenta barrar os L's ┗ e ┏
    
    else if (board[0][0] == 'x' && board [2][0] == 'x' && board[0][2] == ' ' && board[2][2] == ' ') {

        random = rand () % 2;

        if (random == 1) random++;

        board[random][2] = 'o';
    }

    else if (board[0][0] == 'x' && board [2][0] == 'x' && board[0][2] == ' ') {
        board[0][2] = 'o';
    }

    else if (board[0][0] == 'x' && board [2][0] == 'x' && board[2][2] == ' ') {
        board[2][2] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[0][0] == 'x' && board [1][0] == 'x' && board[2][0] == ' ') {
        board[2][0] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[1][0] == 'x' && board [2][0] == 'x' && board[0][0] == ' ') {
        board[0][0] = 'o';
    }

    // coluna do meio

    // o bot tenta marcar na melhor opção

    else if (board[0][1] == 'x' && board [2][1] == 'x' && board[1][1] == ' ') {
        board[1][1] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[0][1] == 'x' && board [1][1] == 'x' && board[2][1] == ' ') {
        board[2][1] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[1][1] == 'x' && board [2][1] == 'x' && board[0][1] == ' ') {
        board[0][1] = 'o';
    }

    // terceira coluna

    // o bot tenta marcar na melhor opção

    else if (board[0][2] == 'x' && board [2][2] == 'x' && board[1][2] == ' ') {
        board[1][2] = 'o';
    }

    // se já estiver marcada, o bot tenta barrar os L's ┓ e ┛
        
    else if (board[0][2] == 'x' && board [2][2] == 'x' && board[0][0] == ' ' && board[2][0] == ' ') {

        random = rand () % 2;

        if (random == 1) random++;

        board[random][0] = 'o';
    }

    else if (board[0][2] == 'x' && board [2][2] == 'x' && board[0][0] == ' ') {
        board[0][0] = 'o';
    }

    else if (board[0][2] == 'x' && board [2][2] == 'x' && board[2][0] == ' ') {
        board[2][0] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[0][2] == 'x' && board [1][2] == 'x' && board[2][2] == ' ') {
        board[2][2] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[1][2] == 'x' && board [2][2] == 'x' && board[0][2] == ' ') {
        board[0][2] = 'o';
    }

    // diagonal principal

    // o bot tenta marcar na melhor opção

    else if (board[0][0] == 'x' && board [2][2] == 'x' && board[1][1] == ' ') {
        board[1][1] = 'o';
    }

    // se já estiver marcada, o bot tenta barrar os L's ┗ e ┓
    
    else if (board[0][0] == 'x' && board [2][2] == 'x' && board[2][0] == ' ' && board[0][2] == ' ') {

        int random_y;

        do {
            random = rand () % 2;
            random_y = rand () % 2;

            if (random == 1) random++;
            if (random_y == 1) random_y++;
        }
        while (board[random][random_y] != ' ');

        board[random][random_y] = 'o';
    }

    else if (board[0][0] == 'x' && board [2][2] == 'x' && board[2][0] == ' ') {
        board[2][0] = 'o';
    }

    else if (board[0][0] == 'x' && board [2][2] == 'x' && board[0][2] == ' ') {
        board[0][2] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[0][0] == 'x' && board [1][1] == 'x' && board[2][2] == ' ') {
        board[2][2] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[1][1] == 'x' && board [2][2] == 'x' && board[0][0] == ' ') {
        board[0][0] = 'o';
    }

    // diagonal secundária

    // o bot tenta marcar na melhor opção

    else if (board[0][2] == 'x' && board [2][0] == 'x' && board[1][1] == ' ') {
        board[1][1] = 'o';
    }

    // se já estiver marcada, o bot tenta barrar os L's
    
    else if (board[0][2] == 'x' && board [2][0] == 'x') {

        int random_y;

        do {
            random = rand () % 2;
            random_y = rand () % 2;

            if (random == 1) random++;
            if (random_y == 1) random_y++;
        }
        while (board[random][random_y] != ' ');

        board[random][random_y] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[0][2] == 'x' && board [1][1] == 'x' && board[2][0] == ' ') {
        board[2][0] = 'o';
    }

    // o bot tenta marcar na melhor opção

    else if (board[1][1] == 'x' && board [2][0] == 'x' && board[0][2] == ' ') {
        board[0][2] = 'o';
    }
}