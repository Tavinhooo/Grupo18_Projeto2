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
    for (int i = 0; bilhete_ja_saidos[i] != ""; i++) {//loop sobre todos os números já saídos diferentes de ""
        if (bilhete_ja_saidos[i] == bilhete) {//verifica se o bilhete é igual a um bilhete que já saiu
            return true;
        }
    }
    return false;
}
string criar_bilhete(string *bilhete_ja_saidos, int &tamanho) {
    string bilhete = "TK";
    int numero_pos_TK = rand() % 9999999999;//gera um numero aleatorio de 0 à 9999999999
    bilhete += to_string(numero_pos_TK);//transforma o numero que obtive em string e junta com a parte "TK"
    while (bilhete_existe(bilhete_ja_saidos, bilhete)) {//loop que verifica se o bilhete já saiu
        numero_pos_TK = rand() % 9999999999;//gera um numero aleatorio de 0 à 9999999999
        bilhete = "TK" + to_string(numero_pos_TK);//transforma o numero que obtive em string e junta com a parte "TK"
    }
    tamanho++;
    bilhete_ja_saidos[tamanho - 1] = bilhete;//adiciona o novo bilhete à ultima posição do array
    return bilhete_ja_saidos[tamanho - 1];//retorna o último número de série adicionado ao array
}

aviao criar_aviao(){
    aviao novoAviao;
    novoAviao.nome_Do_Voo=escolher_aleatoria("voo.txt");//atribui um voo aleatorio do ficheiro
    novoAviao.modelo_Do_Aviao= escolher_aleatoria("modelo.txt");//atribui um modelo aleatorio do ficheiro
    novoAviao.origem= escolher_aleatoria("origem.txt");//atribui uma origem aleatorio do ficheiro
    novoAviao.destino= "aeroporto eda";//como o aviao esta a chegar ao aeroporto eda
    novoAviao.capacidade= capacidade_do_aviao();//um valor aleatorio de 5-15
    return novoAviao;
}
passageiro criar_passageiro(string bilhete_ja_saidos[], int &tamanho) {
    passageiro novoPassageiro;
    novoPassageiro.numero_bilhete = criar_bilhete(bilhete_ja_saidos, tamanho);//atribui um bilhete ao passageiro
    novoPassageiro.p_Nome = escolher_aleatoria("primeiro_nome.txt");//atribui um primeiro nome aleatorio do ficheiro
    novoPassageiro.s_Nome = escolher_aleatoria("segundo_nome.txt");//atribui um segundo nome aleatorio do ficheiro
    novoPassageiro.nacionalidade = escolher_aleatoria("nacionalidade.txt");//atribui nacionalidade aleatorio do ficheiro
    return novoPassageiro;
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
    cout << "entrou aqui2" << endl;
    if (Vazia(f))
        cout << "Fila vazia" << endl;
    else{
        Fila::Item *item = f.primeira;
        cout << "entrou aqui" << endl;
        while(item!= nullptr){
            cout <<item->aviao_data.origem << endl;
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
void troca_de_Filas(Fila& f1, Fila &f2){
    if(Vazia(f1)){
        cout << "Fila que deve ser removido um aviao está vazia" << endl;
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
                cout << "entrou neste ciclo";
                aux2=aux2->seguinte;
                cout << "hello" << endl;
            }
            aux2->seguinte = novoItem;
        }
        Sai(f1);
    }
}
