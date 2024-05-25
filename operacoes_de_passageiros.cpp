//
// Created by octav on 25/05/2024.
//
#include "Abertura_de_ficheiro.h"
#include <cstdlib>
#include <iostream>
#include "structs.h"
#include "operacoes_de_passageiros.h"
#include <string>
using namespace std;

/*
* Verifica se um bilhete já foi registrado.
* Parâmetros:
* - bilhete_ja_saidos: Ponteiro para um array de strings contendo os bilhetes já utilizados.
* - bilhete: Referência para o bilhete a ser verificado.
* Retorna true se o bilhete já existe na lista, false caso contrário.
*/
bool bilhete_existe(string *bilhete_ja_saidos, string &bilhete) {
    for (int i = 0; bilhete_ja_saidos[i] != ""; i++) {
        if (bilhete_ja_saidos[i] == bilhete) {
            return true;
        }
    }
    return false;
}
/*
* Cria um novo bilhete único que ainda não foi utilizado.
* Parâmetros:
* - bilhete_ja_saidos: Ponteiro para um array de strings contendo os bilhetes já utilizados.
* - tamanho: Referência para o tamanho atual da lista de bilhetes.
* Retorna o novo bilhete criado.
*/
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

// Verifica se a fila de passageiros está vazia
bool Vazia_P(Fila_Passageiros& f) {
    return f.primeira == nullptr;
}

// Inicializa uma nova fila de passageiros
void Nova_P(Fila_Passageiros& f) {
    f.primeira = nullptr;
}

// Adiciona um novo passageiro à fila de passageiros
void Entra_P(Fila_Passageiros& f, passageiro data_passageiro) {
    Fila_Passageiros::Item* novoItem = new Fila_Passageiros::Item;
    novoItem->data_passageiro = data_passageiro;
    novoItem->seguinte = nullptr;
    if (Vazia_P(f)) {
        f.primeira = novoItem;
    } else {
        Fila_Passageiros::Item* aux = f.primeira;
        while (aux->seguinte != nullptr) {
            aux = aux->seguinte;
        }
        aux->seguinte = novoItem;
    }
}

// Cria um novo passageiro com bilhete único e dados aleatórios
passageiro criar_passageiro(string bilhete_ja_saidos[], int &tamanho) {
    passageiro novoPassageiro;
    novoPassageiro.numero_bilhete = criar_bilhete(bilhete_ja_saidos, tamanho);
    novoPassageiro.p_Nome = escolher_aleatoria("primeiro_nome.txt");
    novoPassageiro.s_Nome = escolher_aleatoria("segundo_nome.txt");
    novoPassageiro.nacionalidade = escolher_aleatoria("nacionalidade.txt");
    return novoPassageiro;
}

// Calcula o comprimento da fila de passageiros
int Comprimento_P(Fila_Passageiros& f) {
    int tamanho = 0;
    if (!Vazia_P(f)) {
        Fila_Passageiros::Item* Aux = f.primeira;
        while (Aux != nullptr) {
            tamanho++;
            Aux = Aux->seguinte;
        }
    }
    return tamanho;
}
/*
 * parte do projeto nao funcional, devido a estar incompleto
 */
/*
* Função para criar um novo nó na lista de passageiros.
*/
no_passageiro* novo_Nodo(passageiro passageiro_inicial) {
    no_passageiro* novo = new no_passageiro;
    novo->valor_passageiros = passageiro_inicial;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

/*
* Função para criar uma nova nacionalidade na lista de nacionalidades da pista.
*/
void cria_nacionalidade_na_lista(nacionalidade_pista& lista_de_nacionalidades_Pista, passageiro passageiro_inicial) {
    nacionalidade_pista::Item* novo_item = new nacionalidade_pista::Item;
    novo_item->nacionalidade = passageiro_inicial.nacionalidade;
    novo_item->no_desta_nacionalidade = *novo_Nodo(passageiro_inicial);
    novo_item->seguinte = lista_de_nacionalidades_Pista.primeira;
    lista_de_nacionalidades_Pista.primeira = novo_item;
}

/*
* Função para verificar se uma nacionalidade já existe na pista.
*/
bool existe_ja_a_nacionalidade_na_pista(nacionalidade_pista lista_de_nacionalidades_Pista, string nacionalidade) {
    while (lista_de_nacionalidades_Pista.primeira != nullptr) {
        if (lista_de_nacionalidades_Pista.primeira->nacionalidade == nacionalidade) {
            return true;
        }
        lista_de_nacionalidades_Pista.primeira = lista_de_nacionalidades_Pista.primeira->seguinte;
    }
    return false;
}

/*
* Função para mover os passageiros do avião para a pista, criando novas nacionalidades se necessário.
*/
void passagem_do_aviao_para_a_pista(Fila_Passageiros passageiros_aqui, nacionalidade_pista& lista_de_nacionalidades_Pista) {
    while (passageiros_aqui.primeira != nullptr) {
        if (!(passageiros_aqui.primeira->data_passageiro.nacionalidade == "Portuguese")) {
            if (!existe_ja_a_nacionalidade_na_pista(lista_de_nacionalidades_Pista, passageiros_aqui.primeira->data_passageiro.nacionalidade)) {
                cria_nacionalidade_na_lista(lista_de_nacionalidades_Pista, passageiros_aqui.primeira->data_passageiro);
            }
            // esta parte do codigo ia ser o inserir que nao estava a dar corretamente!
        }
        passageiros_aqui.primeira = passageiros_aqui.primeira->seguinte;
    }
}
