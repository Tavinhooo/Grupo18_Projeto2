//
// Created by octav on 23/04/2024.
//
#include <string>
#include <cstdlib>

using namespace std;
#ifndef GRUPO18_PROJETO2_STRUCTS_H
#define GRUPO18_PROJETO2_STRUCTS_H


/*
* Struct que define um passageiro com as informações defenidas no enunciado
*/
struct passageiro {
    string p_Nome; // Primeiro nome do passageiro
    string s_Nome; // Segundo nome do passageiro
    string numero_bilhete; // Número do bilhete do passageiro
    string nacionalidade; // Nacionalidade do passageiro
};

/*
* Struct que define um nó.
*/
struct no_passageiro {
    passageiro valor_passageiros; // Informações do passageiro
    no_passageiro* esquerda; // Ponteiro para o nó à esquerda
    no_passageiro* direita; // Ponteiro para o nó à direita
};

/*
* Struct que representa uma lista da nacionalidade da pista (auxiliar para as arvores na pista)associada a uma lista de passageiros da mesma nacionalidade.
*/
struct nacionalidade_pista {
    struct Item {
        string nacionalidade; // Nacionalidade dos passageiros
        no_passageiro no_desta_nacionalidade; // Nó contendo passageiros dessa nacionalidade
        Item* seguinte; // Ponteiro para o próximo item na lista de nacionalidades
    };
    Item* primeira; // Ponteiro para o primeiro item na lista de nacionalidades
};

/*
* Struct que define um item em uma fila de passageiros.
*/
struct Fila_Passageiros {
    struct Item {
        passageiro data_passageiro; // Informações do passageiro
        Item* seguinte; // Ponteiro para o próximo passageiro na fila
    };
    Item* primeira; // Ponteiro para o primeiro passageiro na fila
};

/*
* Struct que representa um avião com suas características e uma fila de passageiros de acordo com o enunciado.
*/
struct aviao {
    string nome_Do_Voo; // Nome do voo
    string modelo_Do_Aviao; // Modelo do avião
    string origem; // Origem do voo
    string destino; // Destino do voo
    int capacidade = 0; // Capacidade máxima de passageiros
    Fila_Passageiros conjunto_de_passageiros; // Fila de passageiros a bordo do avião
};

/*
* Struct que define um item em uma fila de aviões.
*/
struct Fila {
    struct Item {
        aviao aviao_data; // Informações do avião
        Item* seguinte; // Ponteiro para o próximo avião na fila
    };
    Item* primeira; // Ponteiro para o primeiro avião na fila
};
#endif //GRUPO18_PROJETO2_STRUCTS_H
