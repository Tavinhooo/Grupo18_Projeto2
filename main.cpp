#include <iostream>
#include "operacoes_de_avioes.h"
#include "Abertura_de_ficheiro.h"
#include "structs.h"

int main() {
    const int NUM_AVIOES = 10;
    aviao listaDeAvioes[NUM_AVIOES];

    for (int i = 0; i < NUM_AVIOES; ++i) {
        listaDeAvioes[i] = criar_aviao();
    }
    for (int i = 0; i < NUM_AVIOES; ++i) {
        cout << listaDeAvioes[i].origem << endl;
    }

    // Agora você tem um array com 10 aviões prontos para serem usados.
    return 0;
}