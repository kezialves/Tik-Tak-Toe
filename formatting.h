// Biblioteca responsável pela formatação de texto
// Kézia Alves
// 22.1.4026

#ifndef FORMATTING_H_
#define FORMATTING_H_

// cores e formatos de texto
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_RED        "\x1b[31m" // fonte vermelha
#define ANSI_COLOR_BLUE       "\x1b[34m" // fonte azul
#define ANSI_COLOR_CYAN       "\x1b[36m" // fonte ciano

// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET

// caracteres do tabuleiro
#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL  "\u250F" // ┏ (top-left)
#define TAB_ML  "\u2523" // ┣ (middle-left)
#define TAB_BL  "\u2517" // ┗ (bottom-left)
#define TAB_TJ  "\u2533" // ┳ (top-join)
#define TAB_MJ  "\u254B" // ╋ (middle-join)
#define TAB_BJ  "\u253B" // ┻ (bottom-join)
#define TAB_TR  "\u2513" // ┓ (top-right)
#define TAB_MR  "\u252B" // ┫ (middle-right)
#define TAB_BR  "\u251B" // ┛ (bottom-right)

// macro que define o máximo de caracteres do nome de um jogador
#define PLAYER_NAME 256

// macro que define o máximo de caracteres de um comando
#define COMMAND_NAME 267 // 7 para o comando e, no caso do "salvar", + 256 para o nome + 4 para o ".txt"

// macro que define o máximo de caracteres do nome de um arquivo
#define FILE_NAME 260 // 256 para o nome + 4 para o ".txt"

#endif