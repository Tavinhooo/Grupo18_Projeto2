//
// Created by octav on 25/05/2024.
//

#ifndef GRUPO18_PROJETO2_OPERACOES_DE_PASSAGEIROS_H
#define GRUPO18_PROJETO2_OPERACOES_DE_PASSAGEIROS_H

bool bilhete_existe(string *bilhete_ja_saidos, string &bilhete);
string criar_bilhete(string *bilhete_ja_saidos, int &tamanho);
passageiro criar_passageiro(string bilhete_ja_saidos[], int &tamanho);
void Entra_P(Fila_Passageiros& f, passageiro data_passageiro);
void Nova_P(Fila_Passageiros& f);
int Comprimento_P(Fila_Passageiros& f);
void passagem_do_aviao_para_a_pista(Fila_Passageiros passageiros_aqui,nacionalidade_pista &lista_de_nacionalidades_Pista);
#endif //GRUPO18_PROJETO2_OPERACOES_DE_PASSAGEIROS_H
