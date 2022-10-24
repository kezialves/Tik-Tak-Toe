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

        printf (BLUE(BOLD("\t   " TAB_VER)));
        print_various_times (" ", times);
        printf ((BLUE(BOLD("JOGADOR"))));
        print_various_times (" ", times);

        times = (int) ceil ((15 - (double) 8) / 2);

        printf (BLUE(BOLD("\t   " TAB_VER)));
        print_various_times (" ", times);
        printf ((BLUE(BOLD("VITÓRIAS"))));
        print_various_times (" ", times);

        times = (int) ceil ((15 - (double) 7) / 2);

        printf (BLUE(BOLD("\t   " TAB_VER)));
        print_various_times (" ", times);
        printf ((BLUE(BOLD("EMPATES"))));
        print_various_times (" ", times);

        times = (int) ceil ((15 - (double) 8) / 2);

        printf (BLUE(BOLD("\t   " TAB_VER)));
        print_various_times (" ", times);
        printf ((BLUE(BOLD("DERROTAS"))));
        print_various_times (" ", times);
        printf ("\n");

        printf ("\t");
        print_various_times (TAB_HOR, 95);
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