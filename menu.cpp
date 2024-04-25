#include "menu.h"
#include "Abertura_de_ficheiro.h"
#include "operacoes_de_avioes.h"
#include <cstdlib>
#include "structs.h"
#include <iostream>

using namespace std;

int menu(Fila &chegando, Fila &pista, Fila &partida) {
    string ciclo;
    cin >> ciclo;

    if (ciclo == "s" || ciclo == "S") {
        if (Comprimento(partida) == 5) {
            Sai(partida);
            troca_de_Filas(pista, partida);
            troca_de_Filas_para_pista(chegando, pista);
            Entra(chegando, criar_aviao());
        } else if (Comprimento(partida) < 5 && Comprimento(pista) == 7) {
            troca_de_Filas(pista, partida);
            troca_de_Filas_para_pista(chegando, pista);
            Entra(chegando, criar_aviao());
        } else if (Comprimento(pista) < 7) {
            troca_de_Filas_para_pista(chegando, pista);
            Entra(chegando, criar_aviao());
        }
    }

    return 0;
}
