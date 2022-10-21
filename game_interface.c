// Biblioteca responsável pela interface
// Kézia Alves
// 22.1.4026

#include <stdio.h>
#include <unistd.h>

#include "game_interface.h"
#include "formatting.h"

void display_name () {

    /*printf ("\n");
    printf (CYAN(BOLD("\tPara uma melhor exibição, deixe o terminal com no mínimo 110 de largura.\n"))); // tamanho mínimo p/ o ASCII do nome aparecer bonitinho
    sleep (5); // função que vai dar um delay entre o aviso e o nome*/

    printf ("\n\n");
    printf (BLUE(BOLD("        ██  ██████   ██████   ██████      ██████   █████      ██    ██ ███████ ██      ██   ██  █████   \n")));
    printf (BLUE(BOLD("        ██ ██    ██ ██       ██    ██     ██   ██ ██   ██     ██    ██ ██      ██      ██   ██ ██   ██  \n")));
    printf (BLUE(BOLD("        ██ ██    ██ ██   ███ ██    ██     ██   ██ ███████     ██    ██ █████   ██      ███████ ███████  \n")));
    printf (BLUE(BOLD("   ██   ██ ██    ██ ██    ██ ██    ██     ██   ██ ██   ██      ██  ██  ██      ██      ██   ██ ██   ██  \n")));
    printf (BLUE(BOLD("    █████   ██████   ██████   ██████      ██████  ██   ██       ████   ███████ ███████ ██   ██ ██   ██  \n")));
    printf ("\n\n");

    sleep (1); // função que vai dar um delay entre o nome e o menu
}

void display_ascii_txt (char file_name[]) {

    char c;

    FILE * file = fopen (file_name, "r");

    c = fgetc (file);

    while (c != EOF) {
        printf ("%c", c);
        c = fgetc (file);
    }

    fclose (file);
}

void display_menu () {

    printf (CYAN(BOLD("\t0. Sair do jogo\n")));
    usleep (500000);
    printf (CYAN(BOLD("\t1. Começar um novo jogo\n")));
    usleep (500000);
    printf (CYAN(BOLD("\t2. Continuar um jogo salvo\n")));
    usleep (500000);
    printf (CYAN(BOLD("\t3. Continuar o jogo atual\n")));
    usleep (500000);
    printf (CYAN(BOLD("\t4. Exibir o ranking\n")));
    usleep (500000);
    printf (CYAN(BOLD("\tDurante o jogo digite “voltar” para retornar ao menu.\n")));
    usleep (500000);
    printf ("\n\n");
}

void display_board (char board[3][3]) {

    printf ("\n");
    printf ("\t    " TAB_TL TAB_HOR TAB_HOR TAB_HOR TAB_TJ TAB_HOR TAB_HOR TAB_HOR TAB_TJ TAB_HOR TAB_HOR TAB_HOR TAB_TR "\n");
    printf ("\t    " TAB_VER " 1 " TAB_VER " 2 " TAB_VER " 3 " TAB_VER "\n");
    printf ("\t"TAB_TL TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR "\n");
    printf ("\t"TAB_VER " 1 " TAB_VER " %c " TAB_VER " %c " TAB_VER " %c " TAB_VER "\n", board[0][0], board[0][1], board[0][2]);
    printf ("\t"TAB_ML TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR "\n");
    printf ("\t"TAB_VER " 2 " TAB_VER " %c " TAB_VER " %c " TAB_VER " %c " TAB_VER "\n", board[1][0], board[1][1], board[1][2]);
    printf ("\t"TAB_ML TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR "\n");
    printf ("\t"TAB_VER " 3 " TAB_VER " %c " TAB_VER " %c " TAB_VER " %c " TAB_VER "\n", board[2][0], board[2][1], board[2][2]);
    printf ("\t"TAB_BL TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BR "\n");
    printf ("\n");
}