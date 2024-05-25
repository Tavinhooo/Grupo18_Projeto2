//
// Created by octav on 25/05/2024.
//
#include "Abertura_de_ficheiro.h"
#include <cstdlib>
#include "structs.h"
#include "operacoes_de_passageiros.h"


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

bool Vazia_P(Fila_Passageiros& f){
    return f.primeira == nullptr;
}
void Nova_P(Fila_Passageiros& f){
    f.primeira = nullptr;
}
void Entra_P(Fila_Passageiros& f, passageiro data_passageiro){
    Fila_Passageiros::Item* novoItem = new Fila_Passageiros::Item;
    novoItem->data_passageiro = data_passageiro;
    novoItem->seguinte = nullptr;
    if(Vazia_P(f)){
        f.primeira = novoItem;
    }
    else{
        Fila_Passageiros::Item* aux = f.primeira;
        while (aux->seguinte !=nullptr){
            aux=aux->seguinte;
        }
        aux->seguinte = novoItem;
    }
}

passageiro criar_passageiro(string bilhete_ja_saidos[], int &tamanho) {
    passageiro novoPassageiro;
    novoPassageiro.numero_bilhete = criar_bilhete(bilhete_ja_saidos, tamanho);
    novoPassageiro.p_Nome = escolher_aleatoria("primeiro_nome.txt");
    novoPassageiro.s_Nome = escolher_aleatoria("segundo_nome.txt");
    novoPassageiro.nacionalidade = escolher_aleatoria("nacionalidade.txt");
    return novoPassageiro;
}

int Comprimento_P(Fila_Passageiros& f){
    int tamanho = 0;
    if (!Vazia_P(f)) {
        Fila_Passageiros::Item *Aux = f.primeira;
        while (Aux != nullptr){
            tamanho++;
            Aux = Aux->seguinte;
        }
    }
    return  tamanho;
}