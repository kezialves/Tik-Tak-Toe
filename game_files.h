// Biblioteca responsável pelos arquivos
// Kézia Alves
// 22.1.4026

// macro que define o máximo de caracteres do nome de um arquivo
#define FILE_NAME 260 // 256 para o nome + 4 para o ".txt"

// função que continua um jogo salvo
void continue_saved_game ();
// função que continua o jogo atual
void continue_current_game ();
// função que salva o jogo
void save_game (char file_name[FILE_NAME]);

void continue_saved_game () {

    char game_file_name[FILE_NAME];
    int size_of_file_name;

    printf ("Digite o nome do arquivo do jogo: ");
    getchar ();
    fgets (game_file_name, FILE_NAME, stdin);
    printf ("\n");

    size_of_file_name = strlen (game_file_name);

    while (game_file_name[size_of_file_name - 3] != 't' &&
            game_file_name[size_of_file_name - 2] != 'x' &&
            game_file_name[size_of_file_name - 1] != 't') {

        printf (RED(BOLD("ERRO: O tipo do arquivo é inválido, informe um .txt")));
        printf ("\n\n");

        printf ("Digite o nome do arquivo do jogo: ");
        fgets (game_file_name, FILE_NAME, stdin);
        printf ("\n");

        size_of_file_name = strlen (game_file_name);
    }
}