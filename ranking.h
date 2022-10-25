// Biblioteca sumária do ranking

#ifndef RANKING_H
#define RANKING_H_

#include "structs.h"

// função que printa o ranking
void display_ranking ();

// função que aloca o espaço necessário de acordo com a quantidade de players
Player * create_players_struct (int number_of_players);

// função que atualiza o ranking
void update_ranking (Player player1, Player player2);

// função que ordena o ranking
void sort_ranking (Player * players, int number_of_players);

#endif