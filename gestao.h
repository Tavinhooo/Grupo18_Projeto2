//
// Created by MSI on 25/04/2024.
//

#ifndef GRUPO18_PROJETO2_GESTAO_H
#define GRUPO18_PROJETO2_GESTAO_H

#include "structs.h"

extern int ciclos_fechado;
extern bool fechado;
extern bool aeroporto_abriu;
void gravar_aeroporto(Fila f1, Fila f2, Fila f3);
void carregar_aeroporto(Fila &chegando,Fila &pista , Fila &partida,int argc, char *argv[]);
void AeroportoAbriu(Fila &chegando, Fila &pista, Fila &partida);
void fecharAeroporto();
void abrirAeroporto();
void Inverte(Fila& f);
void Emergencia(Fila& f1, Fila& f2,Fila& f3, string bilhete_ja_saidos[], int& tamanho);
#endif //GRUPO18_PROJETO2_GESTAO_H
