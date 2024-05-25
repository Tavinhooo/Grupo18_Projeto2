#include "operacoes_de_avioes.h"
#include "structs.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "operacoes_de_passageiros.h"

using namespace std;

int ciclos_fechado = 0;
bool fechado = false;
bool aeroporto_abriu = false;

void gravar_aeroporto(Fila f1, Fila f2, Fila f3) {
    // fazer arrays copias para manipular memoria
    Fila::Item* copia1 = f1.primeira;
    Fila::Item* copia2 = f2.primeira;
    Fila::Item* copia3 = f3.primeira;
    string nomeFicheiro; // declaracao de um ficheiro que será o nome do ficheiro a ser guardado

    cout<< "Insira o nome do arquivo no qual quer guardar os dados do aeroporto " << endl;
    getline(cin, nomeFicheiro); // recebe input
    ofstream ficheiro(nomeFicheiro);
    ficheiro.clear(); // limpar o buffer

    /*
     * if statemente vê se abre o ficheiro com sucesso caso nao abra imprime
     * Depois pega em todas as copias das Filas e imprime elas conforme o inunciado
     */
    if (ficheiro.is_open()) {
        ficheiro << "---------------\nEm aproximação\n---------------\n";
        while(copia1 != nullptr) {
            ficheiro << "Voo: " <<  copia1->aviao_data.nome_Do_Voo << "\n";
            ficheiro << "Modelo: " <<  copia1->aviao_data.modelo_Do_Aviao << "\n";
            ficheiro << "Origem: " <<  copia1->aviao_data.origem << "\n";
            ficheiro << "Destino: " <<  copia1->aviao_data.destino << "\n";
            ficheiro << "Passageiros: ";
            Fila_Passageiros::Item *passenger = copia1->aviao_data.conjunto_de_passageiros.primeira;
            while (passenger != nullptr) {
                ficheiro << passenger->data_passageiro.p_Nome << "|" << passenger->data_passageiro.s_Nome << "|" << passenger->data_passageiro.nacionalidade << "|" << passenger->data_passageiro.numero_bilhete << ", ";
                passenger = passenger->seguinte;
                if (passenger->seguinte == nullptr){
                    ficheiro << passenger->data_passageiro.p_Nome << "|" << passenger->data_passageiro.s_Nome << "|" << passenger->data_passageiro.nacionalidade << "|" << passenger->data_passageiro.numero_bilhete;
                    passenger = passenger->seguinte;
                }
            }
            ficheiro << endl;
            copia1 = copia1->seguinte;
        }
        ficheiro << "---------------\nEm pista\n---------------\n";
        while(copia2 != nullptr) {
            ficheiro << "Voo: " <<  copia2->aviao_data.nome_Do_Voo << "\n";
            ficheiro << "Modelo: " <<  copia2->aviao_data.modelo_Do_Aviao << "\n";
            ficheiro << "Origem: " <<  copia2->aviao_data.origem << "\n";
            ficheiro << "Destino: " <<  copia2->aviao_data.destino << "\n";
            ficheiro << "Passageiros: ";
            Fila_Passageiros::Item *passenger = copia2->aviao_data.conjunto_de_passageiros.primeira;
            while (passenger != nullptr) {
                ficheiro << passenger->data_passageiro.p_Nome << "|" << passenger->data_passageiro.s_Nome << "|" << passenger->data_passageiro.nacionalidade << "|" << passenger->data_passageiro.numero_bilhete << ", ";
                passenger = passenger->seguinte;
                if (passenger->seguinte == nullptr){
                    ficheiro << passenger->data_passageiro.p_Nome << "|" << passenger->data_passageiro.s_Nome << "|" << passenger->data_passageiro.nacionalidade << "|" << passenger->data_passageiro.numero_bilhete;
                    passenger = passenger->seguinte;
                }
            }
            ficheiro << endl;
            copia2 = copia2->seguinte;
        }
        ficheiro << "---------------\nEm descolagem\n---------------\n";
        while(copia3 != nullptr) {
            ficheiro << "Voo: " <<  copia3->aviao_data.nome_Do_Voo << "\n";
            ficheiro << "Modelo: " <<  copia3->aviao_data.modelo_Do_Aviao << "\n";
            ficheiro << "Origem: " <<  copia3->aviao_data.origem << "\n";
            ficheiro << "Destino: " <<  copia3->aviao_data.destino << "\n";
            ficheiro << "Passageiros: ";
            Fila_Passageiros::Item *passenger = copia3->aviao_data.conjunto_de_passageiros.primeira;
            while (passenger != nullptr) {
                ficheiro << passenger->data_passageiro.p_Nome << "|" << passenger->data_passageiro.s_Nome << "|" << passenger->data_passageiro.nacionalidade << "|" << passenger->data_passageiro.numero_bilhete << ", ";
                passenger = passenger->seguinte;
                if (passenger->seguinte == nullptr){
                    ficheiro << passenger->data_passageiro.p_Nome << "|" << passenger->data_passageiro.s_Nome << "|" << passenger->data_passageiro.nacionalidade << "|" << passenger->data_passageiro.numero_bilhete;
                    passenger = passenger->seguinte;
                }
            }
            ficheiro << endl;
            copia3 = copia3->seguinte;
        }
        cout << "Os dados do aeroporto foram gravados com sucesso dentro do ficheiro " << nomeFicheiro << endl;
    } else {
        cout << "Ocorreu um erro ao abrir o ficheiro " << nomeFicheiro << endl;
    }
    ficheiro.close();
}
/*
aviao obtencao_dos_valores(ifstream &ficheiro, string &linha) {
    aviao aviao_auxiliar; //criação de um aviao auxiliar para facilitar a obtenção dos valores que estão dentro de um ficheiro
    getline(ficheiro, linha); // ignora esta primeira linha que é "---------------" que aparece logo após aproximação
    while (getline(ficheiro, linha) && linha != "---------------") {
        if (linha.substr(0, 5) == "Voo: ") {
            aviao_auxiliar.nome_Do_Voo = linha.substr(5);
        } else if (linha.substr(0, 8) == "Modelo: ") {
            aviao_auxiliar.modelo_Do_Aviao = linha.substr(8);
        } else if (linha.substr(0, 8) == "Origem: ") {
            aviao_auxiliar.origem = linha.substr(8);
        } else if (linha.substr(0, 9) == "Destino: ") {
            aviao_auxiliar.destino = linha.substr(9);
        }
    }
    return aviao_auxiliar;
}*/
void LimparFila(Fila &f) {
    while (!Vazia(f)) {
        Sai(f);
    }
}
void carregar_aeroporto(Fila &chegando, Fila &pista, Fila &partida, int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Numero de argumentos inválido!" << endl;
        return;
    }

    ifstream file(argv[1]);
    if (!file) {
        cerr << "Não foi possível abrir este ficheiro: " << argv[1] << endl;
        return;
    }
    LimparFila(chegando);
    LimparFila(pista);
    LimparFila(partida);
    string line;
    Fila* fila_auxiliar = nullptr;

    while (getline(file, line)) {
        if (line.find("Em aproximação") != string::npos) {
            fila_auxiliar = &chegando;
        } else if (line.find("Em pista") != string::npos) {
            fila_auxiliar = &pista;
        } else if (line.find("Em descolagem") != string::npos) {
            fila_auxiliar = &partida;
        } else if (fila_auxiliar && line.find("Voo:") != string::npos) {
            aviao aviao_auxiliar;
            aviao_auxiliar.nome_Do_Voo = line.substr(line.find(":") + 2);

            getline(file, line);
            aviao_auxiliar.modelo_Do_Aviao = line.substr(line.find(":") + 2);

            getline(file, line);
            aviao_auxiliar.origem = line.substr(line.find(":") + 2);

            getline(file, line);
            aviao_auxiliar.destino = line.substr(line.find(":") + 2);

            getline(file, line);
            string passengers_line = line.substr(line.find(":") + 2);
            istringstream aux(passengers_line);
            string auxiliar_para_guardar;

            Nova_P(aviao_auxiliar.conjunto_de_passageiros); // Initialize the passenger list

            while (getline(aux, auxiliar_para_guardar, ',')) {
                istringstream passenger_stream(auxiliar_para_guardar);
                passageiro novoPassageiro;
                getline(passenger_stream, novoPassageiro.p_Nome, '|');
                getline(passenger_stream, novoPassageiro.s_Nome, '|');
                getline(passenger_stream, novoPassageiro.nacionalidade, '|');
                getline(passenger_stream, novoPassageiro.numero_bilhete, '|');

                Entra_P(aviao_auxiliar.conjunto_de_passageiros, novoPassageiro);
            }
            aviao_auxiliar.capacidade = Comprimento_P(aviao_auxiliar.conjunto_de_passageiros);
            Entra(*fila_auxiliar, aviao_auxiliar);
        }
    }

    file.close();
}

/*else{
        cout << "Escolhe qual dos ficheiros pretende carregar:" << endl;
        int i = 1;
        while (argv[i] != nullptr){
            cout << "Ficheiro :" << argv[i];
            i++;
        }

    }*/

void fecharAeroporto() {
    int ciclos;
    do {
        cout << "Por quantos dias deseja fechar o aeroporto? ";
        cin >> ciclos;
        if (ciclos > 5) {
            cout << "O aeroporto nao pode ser fechado por mais de 5 dias. " << endl;
        }
    }while(ciclos > 5);
    fechado = true;
    ciclos_fechado = ciclos;
}

void abrirAeroporto() {
    fechado = false;
    ciclos_fechado = 0;
    aeroporto_abriu = true;
}

void AeroportoAbriu(Fila &chegando, Fila &pista, Fila &partida, string bilhete_ja_saidos[], int &tamanho) {
    int conta_chegada = 0;
    while (Comprimento(chegando) > 10 && conta_chegada < 2) {
        troca_de_Filas(chegando, pista);
        conta_chegada++;
    }
    while (!Vazia(pista) && !Vazia(partida)) {
        troca_de_Filas(pista, partida);
        Sai(partida);
    }
    if(Comprimento(chegando) < 10){
        aeroporto_abriu = false; // Reseta o estado de aeroporto recém-aberto
    }
}

void Inverte(Fila& f) {
    if (Vazia(f) || f.primeira->seguinte == nullptr) // Se a fila estiver vazia ou tiver apenas um elemento, não há necessidade de inverter
        return;

    Fila::Item *atual = f.primeira;
    Fila::Item *anterior = nullptr;
    Fila::Item *prox = nullptr;

    while (atual != nullptr) {
        prox = atual->seguinte; // Salva o próximo item
        atual->seguinte = anterior; // Inverte o ponteiro
        anterior = atual; // Atualiza o anterior
        atual = prox; // Move para o próximo item
    }

    f.primeira = anterior; // O último item agora é o primeiro
}

void Emergencia(Fila& f1, Fila& f2, Fila& f3, string bilhete_ja_saidos[], int& tamanho) {
    string voo_emergencia, voo_descolar;

    // Pedir ao utilizador para inserir os números dos voos pretendidos
    cout << "Insira o numero do voo em emergencia: ";
    cin >> voo_emergencia;

    // Encontrar o voo em emergência na fila de aproximação (f1)
    Fila::Item* atual = f1.primeira;
    while (atual != nullptr && atual->aviao_data.nome_Do_Voo != voo_emergencia) {
        atual = atual->seguinte;
    }
    if (atual == nullptr) {
        cerr << "Voo em emergencia não encontrado." << endl;
        return;
    }
    // Verifica se a pista está cheia e remove um avião dela, se necessário
    if (Comprimento(f2) >= 7) {
        cout << "Insira o numero do voo a descolar: ";
        cin >> voo_descolar;
        troca_Aviao2(f2, f3, voo_descolar, false); // troca avião da pista para descolagem (não emergência)
    }
    // Move o avião em emergência da fila de aproximação (f1) para a pista (f2)
    troca_Aviao2(f1, f2, voo_emergencia, true); // troca avião da aproximação para pista (emergência)
    // Adiciona um novo avião à fila de aproximação (f1) após remover a emergência
    Entra(f1, criar_aviao(bilhete_ja_saidos, tamanho));
}