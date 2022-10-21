// Biblioteca responsável pelos arquivos
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <string.h>

#include "game_files.h"
#include "formatting.h"
#include "player.h"

void continue_saved_game () {

    char game_file_name[FILE_NAME];
    int size_of_file_name;

    printf ("Digite o nome do arquivo do jogo: ");
    getchar ();
    fgets (game_file_name, FILE_NAME, stdin);
    printf ("\n");

    size_of_file_name = strlen (game_file_name);

    while (game_file_name[size_of_file_name - 3] != 't' ||
            game_file_name[size_of_file_name - 2] != 'x' ||
            game_file_name[size_of_file_name - 1] != 't') {

        printf (RED(BOLD("ERRO: O tipo do arquivo é inválido, informe um .txt")));
        printf ("\n\n");

        printf ("Digite o nome do arquivo do jogo: ");
        fgets (game_file_name, FILE_NAME, stdin);
        printf ("\n");

        size_of_file_name = strlen (game_file_name);
    }
}