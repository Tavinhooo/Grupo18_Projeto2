//
// Created by octav on 23/04/2024.
//
#include <string>
#include <cstdlib>

using namespace std;
#ifndef GRUPO18_PROJETO2_STRUCTS_H
#define GRUPO18_PROJETO2_STRUCTS_H


struct passageiro{
    string p_Nome; //primeiro nome do passageiro
    string s_Nome; //segundo nome do passageiro
    string numero_bilhete; //numero do bilhete
    string nacionalidade; //nacionaliade do individuo
};

struct Fila_Passageiros {
    struct Item {
        passageiro data_passageiro;
        Item* seguinte;
    };
    Item* primeira;
};
struct aviao{
    string nome_Do_Voo;
    string modelo_Do_Aviao;
    string origem; //de onde vem o aviao
    string destino; // destino do mesmo
    int capacidade = 0;
    Fila_Passageiros conjunto_de_passageiros; //apontador que existe para guardar os passageiros no aviao
};
struct Fila {
    struct Item {
        aviao aviao_data;
        Item* seguinte;
    };
    Item* primeira;
};
struct nacionalidades {
    string nacionalidade;
    struct passageiro_no {
        passageiro_no *esquerda;
        passageiro_no *direita;
    };
};
#endif //GRUPO18_PROJETO2_STRUCTS_H
