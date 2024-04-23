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
aviao criar_aviao(){
    aviao novoAviao;
    novoAviao.nome_Do_Voo=escolher_aleatoria("voo.txt");
    novoAviao.modelo_Do_Aviao= escolher_aleatoria("modelo.txt");
    novoAviao.origem= escolher_aleatoria("origem.txt");
    novoAviao.destino= "aeroporto eda";
    novoAviao.capacidade= capacidade_do_aviao();
}

