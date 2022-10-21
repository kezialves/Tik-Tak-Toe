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

void player_vs_computer () {

    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };

    Player player;
    char command[COMMAND_NAME];
    int current_player = 0;
    int coordinates, x, y;
    int marked_positions = 0;

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

                do {
                    x = rand () % 3;
                    y = rand () % 3;
                } while (board[x][y] != ' ');

                board[x][y] = 'o';

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
                        printf ("jog1");
                    }
                }

                printf ("\nMinha vez :)\n");

                // 

                board[x][y] = 'o';

                marked_positions++;

                display_board (board);

                if (marked_positions >= 5) {

                    if (verify_winner (board) == 2) {
                        printf ("\nEu ganhei!\n");
                    }
                }
            }
        }
    }
}