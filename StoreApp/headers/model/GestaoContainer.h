

#ifndef HEADERS_MODEL_GESTAOCONTAINER_H
#define HEADERS_MODEL_GESTAOCONTAINER_H

#include "Gestao.h"
#include "Utils.h"
#include <vector>

class GestaoContainer{
protected:
	vector<Gestao> produtosEmGestao;
	Gestao emGestao;
public:
    GestaoContainer();
	virtual ~GestaoContainer();

	vector<Gestao> &getAll();
    void addProduto(Produto& obj, int qnt);
    virtual void transferProduto(const int &index);

    void makeNewGID(Gestao& obj);
    virtual Gestao &getProdutoEmGestao();
};

#endif //HEADERS_MODEL_GESTAOCONTAINER_H
