#include "menu.h"
#include "operacoes_de_avioes.h"
#include "gestao.h"
#include "structs.h"
#include <iostream>
#include <limits>


using namespace std;

/*
* Função que implementa o menu de interação do usuário para controlar o aeroporto.
* Mostra os aviões em aproximação, na pista e em partida.
* Permite ao usuário realizar várias ações, como abrir e fechar o aeroporto, realizar operações de emergência, gravar e carregar dados, entre outros.
* Parâmetros:
* - chegando: Referência para a fila de aviões em aproximação.
* - pista: Referência para a fila de aviões na pista de decolagem.
* - partida: Referência para a fila de aviões em partida.
* - argc: Número de argumentos passados para o programa.
* - argv: Array de strings contendo os argumentos passados para o programa.
* - bilhete_ja_saidos: Array de strings contendo os bilhetes já utilizados.
* - tamanho: Referência para o tamanho atual da lista de bilhetes.
* Retorna 0 ao finalizar a execução do menu.
*/
int menu(Fila &chegando, Fila &pista, Fila &partida,int argc,char *argv[],string bilhete_ja_saidos[], int &tamanho) {
    int sair = 0;
    do {
        cout << "---------------\nEm aproximacao\n---------------\n";
        if (!Vazia(chegando)) {
            Escreve(chegando);
        }
        cout << "---------------\nEm pista\n---------------\n";
        if (!Vazia(pista))
            Escreve(pista);
        cout << "---------------\nEm partida\n---------------\n";
        if (!Vazia(partida))
            Escreve(partida);
        char ciclo;
        cin >> ciclo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (ciclo == 's' || ciclo == 'S') {
            if(fechado) {
                Entra(chegando, criar_aviao(bilhete_ja_saidos,tamanho));
                if (ciclos_fechado == 1){
                    abrirAeroporto();
                }
                ciclos_fechado--;
            } else {
                if(aeroporto_abriu) {
                    AeroportoAbriu(chegando, pista, partida);
                    if (Comprimento(chegando) <= 10){
                        aeroporto_abriu = false;
                    }
                }else{
                    if (Comprimento(partida) == 5) {//caso a pista e a partida estejam completas
                        Sai(partida);
                        troca_de_Filas(pista, partida);
                        troca_de_Filas_para_pista(chegando, pista,bilhete_ja_saidos,tamanho);
                        Entra(chegando, criar_aviao(bilhete_ja_saidos,tamanho));
                    }
                    else if (Comprimento(partida) < 5 && Comprimento(pista) == 7) {//caso a pista estaja completa mas a partida nao
                        troca_de_Filas(pista, partida);
                        troca_de_Filas_para_pista(chegando, pista,bilhete_ja_saidos,tamanho);
                        Entra(chegando, criar_aviao(bilhete_ja_saidos,tamanho));
                    }
                    else if (Comprimento(pista) < 7 ) {//caso a pista nao esteja completa
                        troca_de_Filas_para_pista(chegando, pista,bilhete_ja_saidos,tamanho);
                        Entra(chegando, criar_aviao(bilhete_ja_saidos,tamanho));
                    }
                }
            }
        }else if (ciclo == 'F' || ciclo == 'f')
            fecharAeroporto();
        else if(ciclo  == 'A' || ciclo == 'a'){
            abrirAeroporto();
            aeroporto_abriu = true;
        }
        else if (ciclo == 'G' || ciclo == 'g'){
            gravar_aeroporto(chegando,pista,partida);
        }
        else if(ciclo  == 'C' || ciclo == 'c'){
            carregar_aeroporto(chegando,pista,partida,argc,argv);
        }
        else if(ciclo  == 'I' || ciclo == 'i'){
            Inverte(pista);
        }
        else if(ciclo  == 'E' || ciclo == 'e'){
            Emergencia(chegando,pista,partida,bilhete_ja_saidos,tamanho);
        }
        else if(ciclo == 'O' || ciclo == 'o'){
            procurar_passageiro_na_fila(chegando);
            procurar_passageiro_na_fila(pista);
            procurar_passageiro_na_fila(partida);
        }
        else{
            cerr << "Opcao invalida" << endl;
            sair = 1;
        }
    }while(!sair);
    return 0;
}