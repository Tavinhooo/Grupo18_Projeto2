/*
 * Grupo 18
 * Membro 1 - Octávio Abreu -2151223
 * Membro 2 - Francisco Fernandes 2168522
 * Membro 3 - Manuel Gama 2106723
 * Membro 4 - Leandro Rodrigues 2104123
 */

#include <iostream>
#include "operacoes_de_avioes.h"
#include "structs.h"
#include "menu.h"

/*
* Função principal do programa.
* Inicializa as filas de chegada, pista e partida.
* Gera 10 aviões aleatórios e os adiciona à fila de chegada.
* Chama a função do menu para interação com o usuário.
* Parâmetros:
* - argc: Número de argumentos passados para o programa.
* - argv: Array de strings contendo os argumentos passados para o programa.
* - bilhete_ja_saidos: Array de strings contendo os bilhetes já utilizados.
* - tamanho: Referência para o tamanho atual da lista de bilhetes.
* Retorna 0 ao finalizar o programa.
*/
int main(int argc, char *argv[]) {
    srand(time(0));
    Fila chegando;
    Fila pista;
    Fila partida;
    Nova(chegando);
    Nova(pista);
    Nova(partida);
    int tamanho = 0;
    string bilhete_ja_saidos[1000];
    for (int i = 0; i < 10; ++i) {
        Entra(chegando, criar_aviao(bilhete_ja_saidos,tamanho));
    }
    menu(chegando,pista,partida,argc,argv,bilhete_ja_saidos,tamanho);
    return 0;
}