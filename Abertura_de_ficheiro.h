//
// Created by franc on 23/04/2024.
//

#ifndef PROJETOEDA_ABERTURA_DE_FICHEIRO_H
#define PROJETOEDA_ABERTURA_DE_FICHEIRO_H
#include "structs.h"
#include <string>
string* ler_ficheiro(const string& nomeFicheiro, int& numero_linhas);
string chooseRandomLine(const string* lines, int& numero_linhas);
string Marca_ou_categoria_aleatoria(const string& nomeFicheiro);
#endif //PROJETOEDA_ABERTURA_DE_FICHEIRO_H
