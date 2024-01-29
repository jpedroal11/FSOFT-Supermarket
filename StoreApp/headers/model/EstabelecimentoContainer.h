
#ifndef HEADERS_MODEL_ESTABELECIMENTOCONTAINER_H
#define HEADERS_MODEL_ESTABELECIMENTOCONTAINER_H

#include <vector>
#include <list>
#include <string.h>
#include "Estabelecimento.h"
#include "GestaoContainer.h"

using namespace std;

class EstabelecimentoContainer{
private:
	void makeNewId(Estabelecimento &obj);

	vector<Estabelecimento> estabelecimentos;
    Estabelecimento *estabelecimentoAtual = nullptr; // ( ͡° ͜ʖ ͡°)
    GestaoContainer gestao;
public:
    EstabelecimentoContainer();

    vector<Estabelecimento> &getAll();
    Estabelecimento &get(unsigned int& id);
    Estabelecimento *getAtual();

    void add(Estabelecimento obj);
    void remove(unsigned int& id);
    void changeActive(Estabelecimento *novo);
    void setGestao(GestaoContainer gestao);
};

#endif //HEADERS_MODEL_ESTABELECIMENTOCONTAINER_H
