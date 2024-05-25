#ifndef GRUPO18_PROJETO2_MENU_H
#define GRUPO18_PROJETO2_MENU_H
#include "structs.h"


extern int ciclos_fechado;
extern bool fechado;
extern bool aeroporto_abriu;
int menu(Fila &chegando, Fila &pista, Fila &partida,int argc,char *argv[],string bilhete_ja_saidos[], int &tamanho);


#endif //GRUPO18_PROJETO2_MENU_H
