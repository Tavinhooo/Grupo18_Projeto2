#include "menu.h"
#include "operacoes_de_avioes.h"
#include "gestao.h"
#include "structs.h"
#include <iostream>
#include <limits>

using namespace std;

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
                    AeroportoAbriu(chegando, pista, partida,bilhete_ja_saidos, tamanho);
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
        else if(ciclo == 'O' || cilco == 'O'){
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

/*
if (ciclo == 's' || ciclo == 'S') {
    if (Comprimento(partida) == 5) {
        Sai(partida);
        troca_de_Filas(pista, partida);
        troca_de_Filas_para_pista(chegando, pista,bilhete_ja_saidos,tamanho);
        Entra(chegando, criar_aviao(bilhete_ja_saidos,tamanho));
    } else if (Comprimento(partida) < 5 && Comprimento(pista) == 7) {
        troca_de_Filas(pista, partida);
        troca_de_Filas_para_pista(chegando, pista,bilhete_ja_saidos,tamanho);
        Entra(chegando, criar_aviao(bilhete_ja_saidos,tamanho));
    } else if (Comprimento(pista) < 7 ) {
        troca_de_Filas_para_pista(chegando, pista,bilhete_ja_saidos,tamanho);
        Entra(chegando, criar_aviao(bilhete_ja_saidos,tamanho));
    }
}*/
