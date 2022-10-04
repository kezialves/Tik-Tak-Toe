// teste de fontes para o jogo da velha

#include <stdio.h>

// cores e formato de texto
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"

// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET

// caracteres uteis para tabelas
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

int main () {

    /*printf (BG_WHITE(RED(BOLD("(___  )                            ( )          ( ) ( )       (_ ) ( )           \n"))));
    printf (BG_WHITE(RED(BOLD("    | |   _      __     _         _| |   _ _    | | | |   __   | | | |__     _ _ \n"))));
    printf (BG_WHITE(RED(BOLD(" _  | | /'_`\  /'_ `\ /'_`\     /'_` | /'_` )   | | | | /'__`\ | | |  _ `\ /'_` )\n"))));
    printf (BG_WHITE(RED(BOLD("( )_| |( (_) )( (_) |( (_) )   ( (_| |( (_| |   | \_/ |(  ___/ | | | | | |( (_| |\n"))));
    printf (BG_WHITE(RED(BOLD("`\___/'`\___/'`\__  |`\___/'   `\__,_)`\__,_)   `\___/'`\____)(___)(_) (_)`\__,_)\n"))));
    printf (BG_WHITE(RED(BOLD("              ( )_) |                                                            \n"))));
    printf (BG_WHITE(RED(BOLD("               \___/'                                                            \n"))));
    printf ("\n\n");*/

    /*printf (BG_WHITE(RED(BOLD(" _(  ) /  \  / __) /  \       (    \ / _\       / )( \(  __)(  )  / )( \ / _\ \n"))));
    printf (BG_WHITE(RED(BOLD("/ \) \(  O )( (_ \(  O )       ) D (/    \      \ \/ / ) _) / (_/\) __ (/    \\n"))));
    printf (BG_WHITE(RED(BOLD("\____/ \__/  \___/ \__/       (____/\_/\_/       \__/ (____)\____/\_)(_/\_/\_/\n"))));
    printf ("\n\n");*/

    /*printf (BG_WHITE(RED(BOLD("                        \n"))));
    printf (BG_WHITE(RED(BOLD("♥  ღ ♥ ღ ♥ ღ ♥ ღ ♥ ღ  ♥ \n"))));
    printf (BG_WHITE(RED(BOLD("♥ ╔══╗ ╔╗╔═╦╦╦═╗ ╔╗╔╗ ♥ \n"))));
    printf (BG_WHITE(RED(BOLD("♥ ╚╗╔╝ ║╚╣║║║║╩╣ ║╚╝║ ♥ \n"))));
    printf (BG_WHITE(RED(BOLD("♥ ╔╝╚╗ ╚═╩═╩═╩═╝ ╚══╝ ♥ \n"))));
    printf (BG_WHITE(RED(BOLD("♥ ╚══╝ …… ღ ♥ kiss ღ  ♥ \n"))));
    printf (BG_WHITE(RED(BOLD("♥  ღ ♥ ღ ♥ ღ ♥ ღ ♥ ღ  ♥ \n"))));
    printf (BG_WHITE(RED(BOLD("                        \n"))));*/

    /*printf (BG_WHITE(RED(BOLD("                                                                                                                            \n"))));
    printf (BG_WHITE(RED(BOLD("  o         o                 o    o                                                                 o           o     o    \n"))));
    printf (BG_WHITE(RED(BOLD(" <|>       <|>               <|>  <|>                                                               <|>         <|>   <|>   \n"))));
    printf (BG_WHITE(RED(BOLD(" < >       < >               / \\  / \\                                                               / \\         < \\   / \\   \n"))));
    printf (BG_WHITE(RED(BOLD("  |         |     o__  __o   \\o/  \\o/    o__ __o         o              o     o__ __o    \\o__ __o   \\o/    o__ __o/   \\o/   \n"))));
    printf (BG_WHITE(RED(BOLD("  o__/_ _\\__o    /v      |>   |    |    /v     v\\       <|>            <|>   /v     v\\    |     |>   |    /v     |     |    \n"))));
    printf (BG_WHITE(RED(BOLD("  |         |   />      //   / \\  / \\  />       <\\      < >            < >  />       <\\  / \\   < >  / \\  />     / \\   < >   \n"))));
    printf (BG_WHITE(RED(BOLD(" <o>       <o>  \\o    o/     \\o/  \\o/  \\         /       \\o    o/\\o    o/   \\         /  \\o/        \\o/  \\      \\o/         \n"))));
    printf (BG_WHITE(RED(BOLD("  |         |    v\\  /v __o   |    |    o       o         v\\  /v  v\\  /v     o       o    |          |    o      |     o    \n"))));
    printf (BG_WHITE(RED(BOLD(" / \\       / \\    <\\/> __/>  / \\  / \\   <\\__ __/>          <\\/>    <\\/>      <\\__ __/>   / \\        / \\   <\\__  / \\  _<|>_  \n"))));
    printf (BG_WHITE(RED(BOLD("                                                                                                                            \n"))));*/

    /*printf ("\n");
    printf (BLUE(BOLD("                                                                                                      \n")));
    printf (BLUE(BOLD("      ██  ██████   ██████   ██████      ██████   █████      ██    ██ ███████ ██      ██   ██  █████   \n")));
    printf (BLUE(BOLD("      ██ ██    ██ ██       ██    ██     ██   ██ ██   ██     ██    ██ ██      ██      ██   ██ ██   ██  \n")));
    printf (BLUE(BOLD("      ██ ██    ██ ██   ███ ██    ██     ██   ██ ███████     ██    ██ █████   ██      ███████ ███████  \n")));
    printf (BLUE(BOLD(" ██   ██ ██    ██ ██    ██ ██    ██     ██   ██ ██   ██      ██  ██  ██      ██      ██   ██ ██   ██  \n")));
    printf (BLUE(BOLD("  █████   ██████   ██████   ██████      ██████  ██   ██       ████   ███████ ███████ ██   ██ ██   ██  \n")));
    printf (BLUE(BOLD("                                                                                                      \n")));
    printf ("\n");*/

    printf ("\n");
    printf ("\t    " TAB_TL TAB_HOR TAB_HOR TAB_HOR TAB_TJ TAB_HOR TAB_HOR TAB_HOR TAB_TJ TAB_HOR TAB_HOR TAB_HOR TAB_TR "\n");
    printf ("\t    " TAB_VER " 1 " TAB_VER " 2 " TAB_VER " 3 " TAB_VER "\n");
    printf ("\t"TAB_TL TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR "\n");
    printf ("\t"TAB_VER " 1 " TAB_VER "   " TAB_VER "   " TAB_VER "   " TAB_VER "\n");
    printf ("\t"TAB_ML TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR "\n");
    printf ("\t"TAB_VER " 2 " TAB_VER "   " TAB_VER "   " TAB_VER "   " TAB_VER "\n");
    printf ("\t"TAB_ML TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MJ TAB_HOR TAB_HOR TAB_HOR TAB_MR "\n");
    printf ("\t"TAB_VER " 3 " TAB_VER "   " TAB_VER "   " TAB_VER "   " TAB_VER "\n");
    printf ("\t"TAB_BL TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BJ TAB_HOR TAB_HOR TAB_HOR TAB_BR "\n");
    printf ("\n");

    return 0;
}