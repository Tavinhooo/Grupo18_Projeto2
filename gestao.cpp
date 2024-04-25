#include "Abertura_de_ficheiro.h"
#include "operacoes_de_avioes.h"
#include <cstdlib>
#include "structs.h"
#include <iostream>
#include <fstream>

using namespace std;

void gravar_aeroporto(Fila f1, Fila f2, Fila f3) {
    Fila::Item* copia1 = f1.primeira;
    Fila::Item* copia2 = f2.primeira;
    Fila::Item* copia3 = f3.primeira;
    string nomeFicheiro;

    cout<< "Insira o nome do arquivo no qual quer guardar os dados do aeroporto " << endl;
    getline(cin, nomeFicheiro);

    ofstream ficheiro(nomeFicheiro);
    ficheiro.clear();


    if (ficheiro.is_open()) {
        while(copia1 != nullptr) {
            ficheiro << "---------------\nEm aproximação\n---------------\n";
            ficheiro << "Voo: " <<  copia1->aviao_data.nome_Do_Voo << "\n";
            ficheiro << "Modelo: " <<  copia1->aviao_data.modelo_Do_Aviao << "\n";
            ficheiro << "Origem: " <<  copia1->aviao_data.origem << "\n";
            ficheiro << "Destino: " <<  copia1->aviao_data.destino << "\n";
            ficheiro << "Passageiros: " << "\n";

            copia1 = copia1->seguinte;
        }
        while(copia2 != nullptr) {
            ficheiro << "---------------\nEm pista\n---------------\n";
            ficheiro << "Voo: " <<  copia2->aviao_data.nome_Do_Voo << "\n";
            ficheiro << "Modelo: " <<  copia2->aviao_data.modelo_Do_Aviao << "\n";
            ficheiro << "Origem: " <<  copia2->aviao_data.origem << "\n";
            ficheiro << "Destino: " <<  copia2->aviao_data.destino << "\n";
            ficheiro << "Passageiros: " << "\n";

            copia2 = copia2->seguinte;
        }
        while(copia3 != nullptr) {
            ficheiro << "---------------\nEm descolagem\n---------------\n";
            ficheiro << "Voo: " <<  copia3->aviao_data.nome_Do_Voo << "\n";
            ficheiro << "Modelo: " <<  copia3->aviao_data.modelo_Do_Aviao << "\n";
            ficheiro << "Origem: " <<  copia3->aviao_data.origem << "\n";
            ficheiro << "Destino: " <<  copia3->aviao_data.destino << "\n";
            ficheiro << "Passageiros: " << "\n";

            copia3 = copia3->seguinte;
        }
        cout << "Os dados do aeroporto foram gravados com sucesso dentro do ficheiro " << nomeFicheiro << endl;
    } else {
        cout << "Ocorreu um erro ao abrir o ficheiro " << nomeFicheiro << endl;
    }
    ficheiro.close();
}