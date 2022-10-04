// Biblioteca responsável pela inteligência
// Kézia Alves
// 22.1.4026

// função que roda o jogo contra o computador
void player_vs_computer ();

void player_vs_computer () {

    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };

    Player player;

    getchar ();

    printf ("Digite o nome do jogador: ");
    fgets (player.name, PLAYER_NAME, stdin);
    printf ("\n");

    display_board (board);
}