// Protótipos da biblioteca de interface
// Kézia Alves
// 22.1.4026

#ifndef GAME_INTERFACE_H_
#define GAME_INTERFACE_H_

// função que imprime o nome
void display_name ();

// função que imprime o ASCII da Pucca ;)
void display_ascii_txt (char file_name[]);

// função que imprime o menu
void display_menu ();

// função que exibe o ranking
void display_ranking ();

// função que imprime o tabuleiro
void display_board (char board[3][3]);

// função que llmpa a tela do terminal
void clear_screen ();

// função que printa um caractere várias vezes
void print_various_times (char *c, int times);

#endif