// Biblioteca responsável pelo pvp
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "player_vs_player.h"
#include "formatting.h"
#include "player.h"
#include "game_interface.h"
#include "validations.h"

int player_vs_player () {

    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };

    Player player1, player2;
    char command[COMMAND_NAME];
    int current_player = 0;
    int coordinates, x, y;
    int marked_positions = 0;

    getchar ();

    printf ("Digite o nome do jogador 1: ");
    fgets (player1.name, PLAYER_NAME, stdin);
    printf ("\n");

    verify_name (1, player1.name);

    printf ("Digite o nome do jogador 2: ");
    fgets (player2.name, PLAYER_NAME, stdin);
    printf ("\n");

    verify_name (1, player2.name);

    player1.name[strlen (player1.name) - 1] = '\0';
    player2.name[strlen (player2.name) - 1] = '\0';

    display_board (board);

    printf ("%s, digite o comando: ", player1.name);
    fgets (command, COMMAND_NAME, stdin);

    while (command[0] == 'm') { // enquanto o comando for "marcar", o jogo roda

        while (marked_positions <= 9) {
            
            if (current_player == 0) {

                while (command[7] < 49 || command[7] > 51 || command[8] < 49 || command[8] > 51) {
        
                    printf (RED(BOLD("\nERRO: Posição inválida.")));
                    printf ("\n\n");

                    printf ("%s, digite o comando: ", player1.name);
                    fgets (command, COMMAND_NAME, stdin);
                }

                command[0] = command [7];
                command[1] = command [8];
                command[2] = '\0';

                coordinates = atoi (command);
                x = (((coordinates / 10) % 10)) - 1;
                y = (coordinates % 10) - 1;

                board[x][y] = 'x';

                marked_positions++;
                current_player += 2;

                display_board (board);
            }

            if (current_player == 2) {

                printf ("%s, digite o comando: ", player2.name);
                fgets (command, COMMAND_NAME, stdin);

                while (command[7] < 49 || command[7] > 51 || command[8] < 49 || command[8] > 51) {
        
                    printf (RED(BOLD("\nERRO: Posição inválida.")));
                    printf ("\n\n");

                    printf ("%s, digite o comando: ", player2.name);
                    fgets (command, COMMAND_NAME, stdin);
                }

                command[0] = command [7];
                command[1] = command [8];
                command[2] = '\0';

                coordinates = atoi (command);
                x = (((coordinates / 10) % 10)) - 1;
                y = (coordinates % 10) - 1;

                verify_positions (board, x, y, player2.name);

                board[x][y] = 'o';

                marked_positions++;
                current_player--;

                display_board (board);

                if (marked_positions >= 5) {

                    if (verify_winner (board) == 2) {
                        return 2;
                    }
                }
            }

            if (current_player == 1) {

                printf ("%s, digite o comando: ", player1.name);
                fgets (command, COMMAND_NAME, stdin);

                while (command[7] < 49 || command[7] > 51 || command[8] < 49 || command[8] > 51) {
        
                    printf (RED(BOLD("\nERRO: Posição inválida.")));
                    printf ("\n\n");

                    printf ("%s, digite o comando: ", player1.name);
                    fgets (command, COMMAND_NAME, stdin);
                }

                command[0] = command [7];
                command[1] = command [8];
                command[2] = '\0';

                coordinates = atoi (command);
                
                x = (((coordinates / 10) % 10)) - 1;
                y = (coordinates % 10) - 1;

                verify_positions (board, x, y, player1.name);

                board[x][y] = 'x';

                marked_positions++;
                current_player++;

                display_board (board);

                if (marked_positions >= 5) {

                    if (verify_winner (board) == 1) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}