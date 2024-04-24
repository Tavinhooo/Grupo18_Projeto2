//
// Created by octav on 23/04/2024.
//
#include "Abertura_de_ficheiro.h"
#include "operacoes_de_avioes.h"
#include <cstdlib>
#include "structs.h"
#include <iostream>

using namespace std;

int capacidade_do_aviao(){
    return ((rand()%11) + 5); //5-15
}
bool bilhete_existe(string *bilhete_ja_saidos, string &bilhete) {
    for (int i = 0; bilhete_ja_saidos[i] != ""; i++) {
        if (bilhete_ja_saidos[i] == bilhete) {
            return true;
        }
    }
    return false;
}
string criar_bilhete(string *bilhete_ja_saidos, int &tamanho) {
    string bilhete = "TK";
    int numero_pos_TK = rand() % 9999999999;
    bilhete += to_string(numero_pos_TK);
    while (bilhete_existe(bilhete_ja_saidos, bilhete)) {
        numero_pos_TK = rand() % 9999999999;
        bilhete = "TK" + to_string(numero_pos_TK);
    }
    tamanho++;
    bilhete_ja_saidos[tamanho - 1] = bilhete;
    return bilhete_ja_saidos[tamanho - 1];
}

aviao criar_aviao(){
    aviao novoAviao;
    novoAviao.nome_Do_Voo=escolher_aleatoria("voo.txt");
    novoAviao.modelo_Do_Aviao= escolher_aleatoria("modelo.txt");
    novoAviao.origem= escolher_aleatoria("origem.txt");
    novoAviao.destino= "aeroporto eda";
    novoAviao.capacidade= capacidade_do_aviao();
    return novoAviao;
}
passageiro criar_passageiro(string bilhete_ja_saidos[], int &tamanho) {
    passageiro novoPassageiro;
    novoPassageiro.numero_bilhete = criar_bilhete(bilhete_ja_saidos, tamanho);
    novoPassageiro.p_Nome = escolher_aleatoria("primeiro_nome.txt");
    novoPassageiro.s_Nome = escolher_aleatoria("segundo_nome.txt");
    novoPassageiro.nacionalidade = escolher_aleatoria("nacionalidade.txt");
    return novoPassageiro;
}
