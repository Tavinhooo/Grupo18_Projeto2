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
    const int NUM_passageiros = 10;
    string bilhetes_existentes[NUM_passageiros] = {""}; // Array para armazenar os bilhetes gerados
    int tamanho_bilhetes = 0; // Variável para acompanhar o tamanho da lista de bilhetes

    passageiro lista_de_passageiros[NUM_passageiros];

    // Define a semente para a geração de números aleatórios
    srand(time(nullptr));

    // Cria os passageiros
    for (int i = 0; i < NUM_passageiros; ++i) {
        lista_de_passageiros[i] = criar_passageiro(bilhetes_existentes, tamanho_bilhetes);
    }

    // Imprime os nomes dos passageiros
    for (int i = 0; i < NUM_passageiros; ++i) {
        cout << "Passageiro " << i + 1 << ":" << endl;
        cout << "Número do Bilhete: " << lista_de_passageiros[i].numero_bilhete << endl;
        cout << "Primeiro Nome: " << lista_de_passageiros[i].p_Nome << endl;
        cout << "Segundo Nome: " << lista_de_passageiros[i].s_Nome << endl;
        cout << "Nacionalidade: " << lista_de_passageiros[i].nacionalidade << endl;
        cout << endl;
    }

    return 0;
}