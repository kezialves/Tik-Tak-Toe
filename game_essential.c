// Biblioteca responsável pelas funcionalidades gerais
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <unistd.h>

#include "game_essential.h"
#include "formatting.h"
#include "player.h"
#include "player_vs_player.h"
#include "game_inteligence.h"
#include "game_interface.h"
#include "game_files.h"

void choose_menu (int time) {

    int option;

    printf ("Escolha a opção: ");
    scanf ("%d", &option);
    printf ("\n");

    if (time == 0) {
        while (option == 3) {
            printf (RED(BOLD("ERRO: Não há nenhum jogo em andamento.")));
            printf ("\n\n");

            printf ("Escolha a opção: ");
            scanf ("%d", &option);
            printf ("\n");
        }
    }

    while (option != 0 && option != 1 && option != 2 && option != 3 && option != 4) {

        printf (RED(BOLD("ERRO: Opção inválida.")));
        printf ("\n\n");

        printf ("Escolha a opção: ");
        scanf ("%d", &option);
        printf ("\n");
    }

    switch (option) {

        case 0:
            close_game ();
        break;

        case 1:
            new_game ();
        break;

        case 2:
            continue_saved_game ();
        break;

        /*case 3:
            continue_current_game ();
        break;

        case 4:
            display_ranking ();
        break;*/
    }
}

void close_game () {

    usleep (500000);
    printf (CYAN(BOLD("\tAté a próxima ;)\n\n")));
    usleep (500000);
}

void new_game () {

    char number_of_players;

    printf ("Digite o número de jogadores (1 ou 2): ");
    getchar ();
    scanf ("%c", &number_of_players);
    printf ("\n");

    while (number_of_players != '1' && number_of_players != '2') {

        printf (RED(BOLD("ERRO: Número de jogadores inválido.")));
        printf ("\n\n");

        printf ("Digite o número de jogadores (1 ou 2): ");
        getchar ();
        scanf ("%c", &number_of_players);
        printf ("\n");
    }

    if (number_of_players == '1') {
        player_vs_computer ();
    }

    else {

        if (player_vs_player () == 1) {
            printf ("Parabéns, jog1! Você venceu ;)");
            printf ("\n\n");
        }

        else if (player_vs_player () == 2) {
            printf ("Parabéns, jog2! Você venceu ;)");
            printf ("\n\n");
        }

        else {
            printf ("Eta! Deu velha, ninguém venceu ;)");
            printf ("\n\n");
        }
    }

    display_menu ();
    choose_menu (1);
}