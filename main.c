// Jogo da Velha :)
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// macro que define o máximo de caracteres do nome de um jogador
#define PLAYER_NAME 256
// macro que define o máximo de caracteres de um comando
#define COMMAND_NAME 267 // 7 para o comando e, no caso do "salvar", + 256 para o nome + 4 para o ".txt"

#include "formatting.h"
#include "game_interface.h"
#include "player_vs_player.h"
#include "game_inteligence.h"
#include "game_files.h"
#include "functional.h"

int main () {

    display_name ();
    //display_ascii_txt ("pucca_ascii.txt");
    display_menu (0);
    choose_menu ();

    return 0;
}