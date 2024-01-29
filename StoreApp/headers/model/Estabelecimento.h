
#ifndef HEADERS_MODEL_ESTABELECIMENTO_H
#define HEADERS_MODEL_ESTABELECIMENTO_H

#include <string>
#include "GestaoContainer.h"

using namespace std;

class Estabelecimento : public GestaoContainer{
private:
    unsigned int id;
	string nome;
    string localizacao;

public:
    Estabelecimento();
    Estabelecimento(string _nome, string _localizacao);
    const unsigned int &getId() const;
    void setId(const unsigned int &id);

    const string &getLocalizacao() const;
    void setLocalizacao(const string &localizacao);

    const string &getNome() const;
    void setNome(const string &nome);

    Gestao &getProdutoEmGestao();

};

#endif //HEADERS_MODEL_ESTABELECIMENTO_H
