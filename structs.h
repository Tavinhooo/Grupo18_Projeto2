//
// Created by octav on 23/04/2024.
//
#include <string>
#include <stdlib.h>

using namespace std;
#ifndef GRUPO18_PROJETO2_STRUCTS_H
#define GRUPO18_PROJETO2_STRUCTS_H


struct passageiro{
    string numero_bilhete; //numero do bilhete
    string p_Nome; //primeiro nome do passageiro
    string s_Nome; //segundo nome do passageiro
    string nacionalidade; //nacionaliade do individuo
};

struct aviao{
    string nome_Do_Voo;
    string modelo_Do_Aviao;
    string origem; //de onde vem o aviao
    string destino; // destino do mesmo
    int capacidade;
    passageiro *conjunto_de_passageiros; //apontador que existe para guardar os passageiros no aviao
};

struct Fila {
    struct Item {
        int     valor;
        Item* seguinte;
    };
    Item* primeira;
};
#endif //GRUPO18_PROJETO2_STRUCTS_H
