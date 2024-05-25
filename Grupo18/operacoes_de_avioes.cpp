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
/*
* Retorna a capacidade aleatória de um avião (entre 5 e 15 passageiros).
*/
int capacidade_do_aviao(){
    return ((rand()%11) + 5); //5-15
}
/*
* Cria um novo avião com informações aleatórias e uma lista de passageiros preenchida.
* Parâmetros:
* - bilhete_ja_saidos: Array de strings contendo os bilhetes já utilizados.
* - tamanho: Referência para o tamanho atual da lista de bilhetes.
* Retorna o avião criado.
*/
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
/*
* Verifica se uma fila de aviões está vazia.
*/
bool Vazia(Fila& f){
    return f.primeira == nullptr;
}
/*
* Cria uma nova fila de aviões.
* Parâmetros:
* - f: Referência para a fila de aviões a ser criada.
*/
void Nova(Fila& f){
    f.primeira = nullptr;
}

/*
* Adiciona um avião à fila de aviões.
* Parâmetros:
* - f: Referência para a fila de aviões.
* - data_aviao: Avião a ser adicionado à fila.
*/
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
/*
* Exibe informações sobre os aviões na fila.
* Parâmetros:
* - f: Referência para a fila de aviões.
*/
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
/*
* Remove um avião da fila de aviões.
* Parâmetros:
* - f: Referência para a fila de aviões.
*/
void Sai(Fila& f){
    if (Vazia(f))
        throw ERRO_FILA_VAZIA;
    Fila::Item * itemAux = f.primeira;
    f.primeira = itemAux->seguinte;
    delete itemAux;
}
/*
* Retorna o comprimento atual da fila de aviões.
* Parâmetros:
* - f: Referência para a fila de aviões.
* Retorna o número de aviões na fila.
*/
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
/*
* Move um avião de uma fila para outra.
* Parâmetros:
* - f1: Referência para a fila de onde o avião será removido.
* - f2: Referência para a fila para onde o avião será adicionado.
*/
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
/*
* Move um avião de uma fila para a pista de decolagem, atualizando sua origem, destino e passageiros.
* Parâmetros:
* - f1: Referência para a fila de onde o avião será removido.
* - f2: Referência para a fila que representa a pista de decolagem.
* - bilhete_ja_saidos: Array de strings contendo os bilhetes já utilizados.
* - tamanho: Referência para o tamanho atual da lista de bilhetes.
*/
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
    Fila::Item* anterior = nullptr;
    Fila::Item* atual = origem.primeira;
    while (atual != nullptr && atual->aviao_data.nome_Do_Voo != nome_voo) {
        anterior = atual;
        atual = atual->seguinte;
    }

    if (atual == nullptr) {
        if (is_emergencia) {
            cout << "Aviao em emergencia nao encontrado." << endl;
        } else {
            cout << "Aviao nao encontrado na pista para descolagem." << endl;
        }
        return;
    }

    // Remover o avião da fila de origem (chegada,pista dependendo do que queremos)
    if (anterior != nullptr) {
        anterior->seguinte = atual->seguinte;
    } else {
        origem.primeira = atual->seguinte;
    }

    // Adiciona o avião à fila de destino (pista, partida dependendo do que queremos)
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

/*
aviao reseta_aviao(aviao novoAviao){
    novoAviao.nome_Do_Voo= "";
    novoAviao.modelo_Do_Aviao= "";
    novoAviao.origem= "";
    novoAviao.destino= "";
    novoAviao.capacidade= 0;
    Nova_P(novoAviao.conjunto_de_passageiros);

}*/