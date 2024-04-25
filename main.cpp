#include <iostream>
#include "operacoes_de_avioes.h"
#include "Abertura_de_ficheiro.h"
#include "structs.h"
#include "menu.h"

int main() {
    srand(time(0));
    const int NUM_AVIOES = 10;
    aviao listaDeAvioes[NUM_AVIOES];
    Fila chegando;
    Nova(chegando);
    for (int i = 0; i < 10; ++i) {
        Entra(chegando, criar_aviao());
    }
    Escreve(chegando);
    Fila pista;
    Nova(pista);
    Fila partida;
    Nova(partida);
    while (true) {
        menu(chegando, pista, partida);
        cout<<"chegando"<<endl;
        Escreve(chegando);
        cout<<"pista"<<endl;
        Escreve(pista);
        cout<<"partida"<<endl;
        Escreve(partida);
    }
    return 0;
}
