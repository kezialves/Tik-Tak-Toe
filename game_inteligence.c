// Biblioteca responsável pela inteligência
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "game_inteligence.h"
#include "formatting.h"
#include "structs.h"
#include "game_interface.h"
#include "game_essential.h"
#include "game_files.h"
#include "validations.h"

int player_vs_computer (char board[][3], Game game, Player *player1) {

    Command command;

    // cria e inicializa a struct do computador
    Player computer;
    strcpy (computer.name, "Computador");
    initializes_player (&computer);

    srand (time(NULL));

    display_board (board);

    while (1) {

        if (game.last_player == 2) {

            get_command (player1->name, &command);

            if (!strcmp(command.first_command, "marcar")) {

                int coordinates, x, y;
        
                coordinates = atoi (command.second_command);

                x = (((coordinates / 10) % 10)) - 1;
                y = (coordinates % 10) - 1;

                board[3][3] = mark_position (board, &x, &y, 1, player1->name);

                game.marked_positions++;

                display_board (board);

                if (game.marked_positions >= 5) {

                    if (verify_winner (board) == 1) {

                        printf ("Parabéns, %s! Você venceu ;)\n\n", player1->name);

                        player1->victories++;
                        computer.defeats++;

                        break;
                    }
                }

                game.last_player = 1;
            }

            else if (!strcmp(command.first_command, "salvar")) {
                save_game (command.second_command, player1->name, computer.name, board, 1);
                printf (CYAN(BOLD("\nO arquivo do jogo foi criado com sucesso ;)\n\n")));
            }

            else if (!strcmp(command.first_command, "voltar")) {
                strcpy (command.second_command, "current_game.txt");
                save_game (command.second_command, player1->name, computer.name, board, 1);
                display_menu ();
                choose_menu (1);
                break;
            }
        }

        else if (game.last_player == 1) {

            int x, y;

            printf ("\nMinha vez :)\n");

            // se for a primeira jogada do computador, não tem muito critério pra melhor posição
            if (game.marked_positions == 1) {
                
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
            }

            else {
                calculate_position (board);
            }

            game.marked_positions++;

            display_board (board);

            if (game.marked_positions >= 5) {

                if (verify_winner (board) == 2) {

                    printf ("Eu venci ;)\n\n");

                    computer.victories++;
                    player1->defeats++;

                    break;
                }
            }

            game.last_player = 2;
        }

        if (game.marked_positions == 9) {

            printf ("Eta! Deu velha, ninguém venceu ;)\n\n");

            player1->draws++;
            computer.draws++;

            break;
        }
    }

    if (verify_file_exists ("current_game.txt")) {
        remove ("current_game.txt");
    }

    return 0;
}

void calculate_position (char board[][3]) {

    int random, random_y;

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

    else {
        do {
            random = rand () % 2;
            random_y = rand () % 2;

            if (random == 1) random++;
            if (random_y == 1) random_y++;
        }
        while (board[random][random_y] != ' ');

        board[random][random_y] = 'o';
    }
}