// Biblioteca responsável pelas funcionalidades gerais
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"
#include "game_essential.h"
#include "formatting.h"
#include "player_vs_player.h"
#include "game_inteligence.h"
#include "game_interface.h"
#include "game_files.h"
#include "validations.h"

void choose_menu (int time) {

    char option[COMMAND_NAME];

    printf ("Escolha a opção: ");
    fgets (option, COMMAND_NAME, stdin);
    printf ("\n");

    // como eu usei a função fgets, que também pega o \n, ele se inclui nas comparações
    // não acho necessário remover o \n antes de comparar, pois esse número não será usado novamente

    if (time == 0) {
        while (!strcmp (option, "3\n")) {
            printf (RED(BOLD("ERRO: Não há nenhum jogo em andamento.")));
            printf ("\n\n");

            printf ("Escolha a opção: ");
            fgets (option, COMMAND_NAME, stdin);
            printf ("\n");
        }
    }

    while (!(!strcmp (option, "0\n") || !strcmp (option, "1\n")  || !strcmp (option, "2\n")  || !strcmp (option, "3\n")  || !strcmp (option, "4\n"))) {

        printf (RED(BOLD("ERRO: Opção inválida.")));
        printf ("\n\n");

        printf ("Escolha a opção: ");
        fgets (option, COMMAND_NAME, stdin);
        printf ("\n");
    }

    if (!strcmp (option, "0\n")) {
        close_game ();
    }

    else if (!strcmp (option, "1\n")) {
        new_game ();
    }

    else if (!strcmp (option, "2\n")) {
        continue_saved_game ();
    }

    // else if (!strcmp (option, "3\n")) {
    //     continue_current_game ();
    // }

    // else {
    //     display_ranking ();
    // }
}

void close_game () {

    usleep (500000);
    printf (CYAN(BOLD("\tAté a próxima ;)\n\n")));
    usleep (500000);
}

void new_game () {

    char number_of_players[COMMAND_NAME];
    Game game;
    Player player1, player2;

    // inicializa o tabuleiro do jogo
    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };

    // inicializa o jogo
    game.number_of_players = 0;
    game.last_player = 2;
    game.marked_positions = 0;

    // pega o número de jogadores (1 ou 2)
    printf ("Digite o número de jogadores (1 ou 2): ");
    fgets (number_of_players, COMMAND_NAME, stdin);
    printf ("\n");

    while (!(!strcmp (number_of_players, "1\n") || !strcmp (number_of_players, "2\n"))) {

        printf (RED(BOLD("ERRO: Número de jogadores inválido.")));
        printf ("\n\n");

        printf ("Digite o número de jogadores (1 ou 2): ");
        fgets (number_of_players, COMMAND_NAME, stdin);
        printf ("\n");
    }

    // armazena a quantidade de jogadores na struct do jogo
    game.number_of_players = atoi (number_of_players);

    // pega o nome do jogador 1 e armazena na struct
    printf ("Digite o nome do jogador 1: ");
    fgets (player1.name, PLAYER_NAME, stdin);
    printf ("\n");

    // valida o nome do bichinho e inicializa os pontos
    verify_name (1, player1.name);
    initializes_player (&player1);

    // tira o "\n" do nome pra imprimir certinho
    player1.name[strlen (player1.name) - 1] = '\0';

    // se o número de jogadores for 2, pega o nome do jogador 2 e armazena na struct
    if (game.number_of_players == 2) {

        printf ("Digite o nome do jogador 2: ");
        fgets (player2.name, PLAYER_NAME, stdin);
        printf ("\n");

        // valida o nome do bichinho e inicializa os pontos
        verify_name_p2 (player1.name, player2.name);
        initializes_player (&player2);

        // tira o "\n" do nome pra imprimir certinho
        player2.name[strlen (player2.name) - 1] = '\0';
    }

    // chama a função correspondente ao número de jogadores
    if (!strcmp (number_of_players, "1\n")) {
        player_vs_computer ();
    }

    else {
        player_vs_player (board, game, &player1, &player2);
    }

    printf ("\nDigite qualquer tecla para continuar: ");
    printf ("\n");

    display_menu ();
    choose_menu (1);
}

void initializes_player (Player *player) {

    player->victories = 0;
    player->draws = 0;
    player->defeats = 0;
}

void get_command (char *player_name, Command *command) {

    printf ("%s, digite o comando: ", player_name);
    scanf ("%s", command->first_command);
    getchar ();
    fgets (command->second_command, FILE_NAME, stdin);

    while (!(!strcmp (command->first_command, "marcar") || !strcmp (command->first_command, "salvar") || !strcmp (command->first_command, "voltar"))) {

        printf (RED(BOLD("ERRO: Comando inválido.")));
        printf ("\n");

        printf (RED(BOLD("-> Os comandos são: ""marcar"", ""salvar"" e ""voltar"" ;)")));
        printf ("\n\n");

        printf ("%s, digite o comando: ", player_name);
        scanf ("%s", command->first_command);
        getchar ();
        fgets (command->second_command, FILE_NAME, stdin);
    }
}

char mark_position (char board[][3], int *x, int *y, int player, char *player_name) {

    verify_positions (board, x, y, player_name);

    if (player == 1) {
        board[*x][*y] = 'x';
    }

    else {
        board[*x][*y] = 'o';
    }

    return board[3][3];
}