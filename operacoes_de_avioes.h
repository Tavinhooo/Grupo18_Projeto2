//
// Created by octav on 23/04/2024.
//

#ifndef GRUPO18_PROJETO2_OPERACOES_DE_AVIOES_H
#define GRUPO18_PROJETO2_OPERACOES_DE_AVIOES_H
#include "structs.h"
int capacidade_do_aviao();
bool bilhete_existe(string *bilhete_ja_saidos, string &bilhete);
string criar_bilhete(string *bilhete_ja_saidos, int &tamanho);
passageiro criar_passageiro(string bilhete_ja_saidos[], int &tamanho);
aviao criar_aviao();

#endif //GRUPO18_PROJETO2_OPERACOES_DE_AVIOES_H
