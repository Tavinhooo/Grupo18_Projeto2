//
// Created by octav on 23/04/2024.
//

#ifndef GRUPO18_PROJETO2_OPERACOES_DE_AVIOES_H
#define GRUPO18_PROJETO2_OPERACOES_DE_AVIOES_H
#include "structs.h"
const int ERRO_FILA_VAZIA = 1;
int capacidade_do_aviao();
aviao criar_aviao(string bilhete_ja_saidos[], int &tamanho);
bool Vazia(Fila& f);
void Nova(Fila& f);
void Entra(Fila& f, aviao data_aviao);
void Escreve(Fila& f);
void troca_de_Filas(Fila& f1, Fila &f2);
void troca_de_Filas_para_pista(Fila& f1, Fila &f2,string bilhete_ja_saidos[], int &tamanho);
int Comprimento(Fila& f);
void Sai(Fila& f);
void troca_Aviao2(Fila& origem, Fila& destino, const string& nome_voo, bool is_emergencia);


#endif //GRUPO18_PROJETO2_OPERACOES_DE_AVIOES_H
