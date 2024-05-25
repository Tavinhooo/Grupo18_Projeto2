//
// Created by octav on 23/04/2024.
//
#include "Abertura_de_ficheiro.h"
#include "operacoes_de_avioes.h"
#include <cstdlib>
#include "structs.h"
#include <iostream>
#include "operacoes_de_passageiros.h"

using namespace std;

int capacidade_do_aviao(){
    return ((rand()%11) + 5); //5-15
}
/*
aviao reseta_aviao(aviao novoAviao){
    novoAviao.nome_Do_Voo= "";
    novoAviao.modelo_Do_Aviao= "";
    novoAviao.origem= "";
    novoAviao.destino= "";
    novoAviao.capacidade= 0;
    Nova_P(novoAviao.conjunto_de_passageiros);

}*/
aviao criar_aviao(string bilhete_ja_saidos[], int &tamanho){
    aviao novoAviao;
    novoAviao.nome_Do_Voo=escolher_aleatoria("voo.txt");
    novoAviao.modelo_Do_Aviao= escolher_aleatoria("modelo.txt");
    novoAviao.origem= escolher_aleatoria("origem.txt");
    novoAviao.destino= "aeroporto eda";
    novoAviao.capacidade= capacidade_do_aviao();
    Nova_P(novoAviao.conjunto_de_passageiros);
    for (int i = 0; i< novoAviao.capacidade ;i++){
        Entra_P(novoAviao.conjunto_de_passageiros,criar_passageiro(bilhete_ja_saidos,tamanho));
    }
    return novoAviao;
}

bool Vazia(Fila& f){
    return f.primeira == nullptr;
}
void Nova(Fila& f){
    f.primeira = nullptr;
}

void Entra(Fila& f, aviao data_aviao){
    Fila::Item* novoItem = new Fila::Item;
    novoItem->aviao_data = data_aviao;
    novoItem->seguinte = nullptr;
    if(Vazia(f)){
        f.primeira = novoItem;
    }
    else{
        Fila::Item* aux = f.primeira;
        while (aux->seguinte !=nullptr){
            aux=aux->seguinte;
        }
        aux->seguinte = novoItem;
    }
}
void Escreve(Fila& f){
    if (!Vazia(f)) {
        Fila::Item *item = f.primeira;
        while (item != nullptr) {
            cout << "Voo: " << item->aviao_data.nome_Do_Voo << endl;
            cout << "Modelo: " << item->aviao_data.modelo_Do_Aviao << endl;
            cout << "Origem: " << item->aviao_data.origem << endl;
            cout << "Destino: " << item->aviao_data.destino << endl;
            cout << "Passageiros: ";
            Fila_Passageiros::Item *passenger = item->aviao_data.conjunto_de_passageiros.primeira;
            while (passenger != nullptr) {
                cout << passenger->data_passageiro.p_Nome << ", ";
                passenger = passenger->seguinte;
                if (passenger->seguinte == nullptr){
                    cout << passenger->data_passageiro.p_Nome;
                    passenger = passenger->seguinte;
                }
            }
            cout << endl;
            item = item->seguinte;
        }
    }
}
void Sai(Fila& f){
    if (Vazia(f))
        throw ERRO_FILA_VAZIA;
    Fila::Item * itemAux = f.primeira;
    f.primeira = itemAux->seguinte;
    delete itemAux;
}
int Comprimento(Fila& f){
    int tamanho = 0;
    if (!Vazia(f)) {
        Fila::Item *Aux = f.primeira;
        while (Aux != nullptr){
            tamanho++;
            Aux = Aux->seguinte;
        }
    }
    return  tamanho;
}
void troca_de_Filas(Fila& f1, Fila &f2){
    if(Vazia(f1)){
        cout << "Fila que deve ser removido um aviao está vazia" << endl;
        return;
    }
    else{
        Fila::Item* novoItem = new Fila::Item;
        novoItem->aviao_data = f1.primeira->aviao_data;
        novoItem->seguinte = nullptr;
        if (Vazia(f2)) {
            f2.primeira = novoItem;
        }else{
            Fila::Item* aux2 = f2.primeira;
            while (aux2->seguinte !=nullptr){
                aux2=aux2->seguinte;
            }
            aux2->seguinte = novoItem;
        }
        Sai(f1);
    }
}
void troca_de_Filas_para_pista(Fila& f1, Fila &f2,string bilhete_ja_saidos[], int &tamanho){//(Fila& f1, Fila &f2,string bilhete_ja_saidos[], int &tamanho) -> argumentos apra quando for possivel manipular as arvores
    if(Vazia(f1)){
        cout << "Fila que deve ser removido um aviao está vazia" << endl;
        return;
    }
    else{
        Fila::Item* novoItem = new Fila::Item;
        novoItem->aviao_data = f1.primeira->aviao_data;
        novoItem->aviao_data.origem = "aeroporto eda";
        novoItem->aviao_data.destino =escolher_aleatoria("destino.txt");
        Nova_P(novoItem->aviao_data.conjunto_de_passageiros);
        for (int i = 0; i< novoItem->aviao_data.capacidade ;i++){
            Entra_P(novoItem->aviao_data.conjunto_de_passageiros,criar_passageiro(bilhete_ja_saidos,tamanho));
        }
        novoItem->seguinte = nullptr;
        if (Vazia(f2)) {
            f2.primeira = novoItem;
        }else{
            Fila::Item* aux2 = f2.primeira;
            while (aux2->seguinte !=nullptr){
                aux2=aux2->seguinte;
            }
            aux2->seguinte = novoItem;
        }
        Sai(f1);
    }
}
void troca_Aviao2(Fila& origem, Fila& destino, const string& nome_voo, bool is_emergencia) {
    // Procura o avião com o nome do voo escolhido
    Fila::Item* anterior = nullptr;// Declara um pointer 'anterior' que será usado para manter o aviao anterior ao atual na fila
    Fila::Item* atual = origem.primeira;//Declara um pointer 'atual' e inicializa-o como o primeiro aviao da fila de origem.
    while (atual != nullptr && atual->aviao_data.nome_Do_Voo != nome_voo) { //Percorre a fila até encontrar o aviao pretendido
        anterior = atual; 
        atual = atual->seguinte; 
    }
    if (atual == nullptr) { //Verifica se o aviao não foi encontrado
        if (is_emergencia) {
            cout << "Aviao em emergencia nao encontrado." << endl;
        } else {
            cout << "Aviao nao encontrado na pista para descolagem." << endl;
        }
        return;
    }
    // Remove aviao da fila de origem (chegada ou pista)
    if (anterior != nullptr) {
        anterior->seguinte = atual->seguinte;
    } else {
        origem.primeira = atual->seguinte;
    }
    // Adiciona o avião à fila de destino (pista ou descolagem)
    atual->seguinte = nullptr;
    if (Vazia(destino)) {
        destino.primeira = atual;
    } else {
        Fila::Item* aux = destino.primeira;
        while (aux->seguinte != nullptr) {
            aux = aux->seguinte;
        }
        aux->seguinte = atual;
    }
}
