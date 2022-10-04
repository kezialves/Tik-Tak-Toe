// Biblioteca responsável pelo pvp
// Kézia Alves
// 22.1.4026

typedef struct {
    char name[PLAYER_NAME];
    int victories;
    int draws;
    int defeats;
} Player;

// função que roda o jogo pvp
void player_vs_player ();

void player_vs_player () {

    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };

    Player player1, player2;
    char command[COMMAND_NAME];
    int current_player = 0;
    int coordinates;
    int marked_positions = 0;

    getchar ();

    printf ("Digite o nome do jogador 1: ");
    fgets (player1.name, PLAYER_NAME, stdin);
    printf ("\n");

    printf ("Digite o nome do jogador 2: ");
    fgets (player2.name, PLAYER_NAME, stdin);
    printf ("\n");

    player1.name[strlen (player1.name) - 1] = '\0';
    player2.name[strlen (player2.name) - 1] = '\0';

    display_board (board);

    printf ("%s, digite o comando: ", player1.name);
    fgets (command, COMMAND_NAME, stdin);

    while (command[0] == 'm') { // enquanto o comando for "marcar", o jogo roda

        while (marked_positions <= 9) {
            
            if (current_player == 0) {

                command[0] = command [7];
                command[1] = command [8];
                command[2] = '\0';

                coordinates = atoi (command);

                board[(((coordinates / 10) % 10)) - 1][(coordinates % 10) - 1] = 'x';

                marked_positions++;
                current_player += 2;

                display_board (board);
            }

            if (current_player == 2) {

                printf ("%s, digite o comando: ", player2.name);
                fgets (command, COMMAND_NAME, stdin);

                command[0] = command [7];
                command[1] = command [8];
                command[2] = '\0';

                coordinates = atoi (command);

                board[(((coordinates / 10) % 10)) - 1][(coordinates % 10) - 1] = 'o';

                marked_positions++;
                current_player--;

                display_board (board);
            }

            if (current_player == 1) {

                printf ("%s, digite o comando: ", player1.name);
                fgets (command, COMMAND_NAME, stdin);

                command[0] = command [7];
                command[1] = command [8];
                command[2] = '\0';

                coordinates = atoi (command);

                board[(((coordinates / 10) % 10)) - 1][(coordinates % 10) - 1] = 'x';

                marked_positions++;
                current_player++;

                display_board (board);
            }
        }
    }
}