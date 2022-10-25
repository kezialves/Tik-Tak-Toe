// Biblioteca responsável pelo ranking
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "ranking.h"
#include "game_files.h"
#include "structs.h"
#include "formatting.h"
#include "validations.h"
#include "game_interface.h"
#include "game_essential.h"

void display_ranking () {

    int number_of_players;
    int times;

    if (!verify_file_exists ("velha.ini")) {
        printf (RED(BOLD("\nVocê precisa jogar para o ranking ser criado ;).\n")));
    }

    else {

        FILE * ranking = fopen ("velha.ini", "r");

        fscanf (ranking, "%d", &number_of_players);
        fgetc (ranking);

        Player * players = create_players_struct (number_of_players);

        for (int i = 0; i < number_of_players; i++) {

            fgets (players[i].name, PLAYER_NAME, ranking);
            players[i].name[strlen (players[i].name) - 1] = '\0';
            
            fscanf (ranking, "%d", &players[i].victories);
            fgetc (ranking);

            fscanf (ranking, "%d", &players[i].draws);
            fgetc (ranking);

            fscanf (ranking, "%d", &players[i].defeats);
            fgetc (ranking);
        }

        fclose (ranking);

        times = (int) ceil ((25 - (double) 7) / 2);

        printf ("\n");

        printf ("\t    ");
        print_various_times (" ", times);
        printf ((BLUE(BOLD("JOGADOR"))));
        print_various_times (" ", times);

        times = (int) ceil ((15 - (double) 8) / 2);

        printf ("  ");
        print_various_times (" ", times);
        printf ((BLUE(BOLD("VITÓRIAS"))));
        print_various_times (" ", times);

        times = (int) ceil ((15 - (double) 7) / 2);

        print_various_times (" ", times);
        printf ((BLUE(BOLD("EMPATES"))));
        print_various_times (" ", times);

        times = (int) ceil ((15 - (double) 8) / 2);

        printf (" ");
        print_various_times (" ", times);
        printf ((BLUE(BOLD("DERROTAS"))));
        print_various_times (" ", times);
        printf ("\n");

        printf ("\t");
        print_various_times (TAB_HOR, 82);
        printf ("\n");

        for (int i = 0; i < number_of_players; i++) {
            
            printf ((BLUE(BOLD("\t %d "))), i + 1);
            printf ((BLUE(BOLD(TAB_VER))));

            times = (int) ceil ((25 - (double) strlen (players[i].name)) / 2);

            print_various_times (" ", times);
            printf ("%s", players[i].name);
            print_various_times (" ", times);
            printf ((BLUE(BOLD(TAB_VER))));

            times = (int) ceil ((15 - (double) 1) / 2);

            print_various_times (" ", times);
            printf ("%d", players[i].victories);
            print_various_times (" ", times);
            printf ((BLUE(BOLD(TAB_VER))));

            print_various_times (" ", times);
            printf ("%d", players[i].draws);
            print_various_times (" ", times);
            printf ((BLUE(BOLD(TAB_VER))));

            print_various_times (" ", times);
            printf ("%d", players[i].defeats);
            print_various_times (" ", times);
            printf ((BLUE(BOLD(TAB_VER))));

            printf ("\n");
        }

        printf ("\n");

        free (players);
    }
}

Player * create_players_struct (int number_of_players) {

    Player * players = malloc (number_of_players * sizeof (Player));

    return players;
}

void update_ranking (Player player1, Player player2) {

    int number_of_players = 0;
    int aux_players;

    if (!verify_file_exists ("velha.ini")) {
        
        FILE * ranking = fopen ("velha.ini", "w");

        if (!strcmp (player2.name, "Computador")) {
            fprintf (ranking, "3\n");
        }

        else {
            fprintf (ranking, "2\n");
        }

        fprintf (ranking, "%s\n", player1.name);
        fprintf (ranking, "%d ", player1.victories);
        fprintf (ranking, "%d ", player1.draws);
        fprintf (ranking, "%d\n", player1.defeats);

        fprintf (ranking, "%s\n", player2.name);
        fprintf (ranking, "%d ", player2.victories);
        fprintf (ranking, "%d ", player2.draws);
        fprintf (ranking, "%d\n", player2.defeats);

        if (strcmp (player2.name, "Computador")) {

            fprintf (ranking, "Computador\n");
            fprintf (ranking, "0 0 0\n");
        }
    }

    else {

        FILE * ranking = fopen ("velha.ini", "r");

        fscanf (ranking, "%d", &number_of_players);
        fgetc (ranking);

        Player * players = create_players_struct (number_of_players + 2);

        for (int i = 0; i < number_of_players; i++) {

            fgets (players[i].name, PLAYER_NAME, ranking);
            players[i].name[strlen (players[i].name) - 1] = '\0';
            
            fscanf (ranking, "%d", &players[i].victories);
            fgetc (ranking);

            fscanf (ranking, "%d", &players[i].draws);
            fgetc (ranking);

            fscanf (ranking, "%d", &players[i].defeats);
            fgetc (ranking);
        }

        fclose (ranking);

        aux_players = number_of_players;

        for (int i = 0; i < number_of_players; i++) {
            if (strcmp (players[i].name, player1.name) || strcmp (players[i].name, player2.name)) {
                aux_players++;
            }
        }

        sort_ranking (players, number_of_players);

        FILE * new_ranking = fopen ("velha.ini", "w");

        fprintf (new_ranking, "%d\n", number_of_players);

        for (int i = 0; i < number_of_players; i++) {
        
            fprintf (new_ranking, "%s\n", players[i].name);
            fprintf (new_ranking, "%d ", players[i].victories);
            fprintf (new_ranking, "%d ", players[i].draws);
            fprintf (new_ranking, "%d\n", players[i].defeats);
        }

        fclose (new_ranking);

        free (players);

        // clear_screen ();
        // printf ("\nDigite qualquer tecla para continuar: ");
        // char key[COMMAND_NAME];
        // fgets (key, COMMAND_NAME, stdin);

        // clear_screen ();
        // display_menu ();
        // choose_menu ();
    }
}

void sort_ranking (Player * players, int number_of_players) {

    for (int i = 0; i < number_of_players; i++) {

        for (int j = 0; j < number_of_players; j++) {

            if (players[i].victories > players[j].victories) {

                Player aux = players[i];
                players[i] = players[j];
                players[j] = aux;
            }
        }
    }

    for (int i = 0; i < number_of_players; i++) {

        for (int j = 0; j < number_of_players; j++) {

            if (players[i].victories == players[j].victories) {
                
                if (players[i].draws > players[j].draws) {

                    Player aux = players[i];
                    players[i] = players[j];
                    players[j] = aux;
                }
            }
        }
    }
}