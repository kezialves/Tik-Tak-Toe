// Biblioteca responsável pelas funcionalidades gerais
// Kézia Alves
// 22.1.4026

// função que recebe a opção
void choose_menu ();
// função que encerra o jogo
void close_game ();
// função que inicia um novo jogo
void new_game ();

void choose_menu () {

    int option;

    printf ("Escolha a opção: ");
    scanf ("%d", &option);
    printf ("\n");

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

    int number_of_players;

    printf ("Digite o número de jogadores (1 ou 2): ");
    scanf ("%d", &number_of_players);
    printf ("\n");

    while (number_of_players != 1 && number_of_players != 2) {

        printf (RED(BOLD("ERRO: Número de jogadores inválido.")));
        printf ("\n\n");

        printf ("Digite o número de jogadores (1 ou 2): ");
        scanf ("%d", &number_of_players);
        printf ("\n");
    }

    if (number_of_players == 1) {
        player_vs_computer ();
    }

    else {
        player_vs_player ();
    }
}