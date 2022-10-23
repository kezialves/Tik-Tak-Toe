// Biblioteca responsável pelo pvp
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "player_vs_player.h"
#include "formatting.h"
#include "structs.h"
#include "game_essential.h"
#include "game_interface.h"
#include "game_files.h"
#include "validations.h"

int player_vs_player (char board[][3], Game game, Player *player1, Player *player2) {

    Command command;

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
                        printf ("Parabéns, %s! Você venceu ;)", player1->name);
                        printf ("\n\n");
                        break;
                    }
                }

                game.last_player = 1;
                game.marked_positions++;
            }

            else if (!strcmp(command.first_command, "salvar")) {
                save_game (command.second_command, player1->name, player2->name, board, 2);
                display_menu ();
            }

            else if (!strcmp(command.first_command, "voltar")) {
                strcpy (command.second_command, "current_game.txt");
                save_game (command.second_command, player1->name, player2->name, board, 2);
                display_menu ();
            }
        }

        else if (game.last_player == 1) {

            get_command (player2->name, &command);

            if (!strcmp(command.first_command, "marcar")) {

                int coordinates, x, y;
        
                coordinates = atoi (command.second_command);

                x = (((coordinates / 10) % 10)) - 1;
                y = (coordinates % 10) - 1;

                board[3][3] = mark_position (board, &x, &y, 2, player2->name);

                game.marked_positions++;

                display_board (board);

                if (game.marked_positions >= 5) {

                    if (verify_winner (board) == 2) {
                        printf ("Parabéns, %s! Você venceu ;)", player2->name);
                        printf ("\n\n");
                        break;
                    }
                }

                game.last_player = 2;
                game.marked_positions++;
            }

            if (game.marked_positions == 9) {
                printf ("Eta! Deu velha, ninguém venceu ;)");
                printf ("\n\n");
                break;
            }

            else if (!strcmp(command.first_command, "salvar")) {
                save_game (command.second_command, player1->name, player2->name, board, 1);
                display_menu ();
            }

            else if (!strcmp(command.first_command, "voltar")) {
                strcpy (command.second_command, "current_game.txt");
                save_game (command.second_command, player1->name, player2->name, board, 1);
                display_menu ();
            }
        }
    }

    return 0;
}