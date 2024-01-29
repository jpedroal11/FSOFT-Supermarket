

#ifndef HEADERS_MODEL_PRODUTOCONTAINER_H
#define HEADERS_MODEL_PRODUTOCONTAINER_H

#include "Gestao.h"
#include "Utils.h"
#include <vector>

class ProdutoContainer{
private:
    vector<Produto> produtos;
    Produto produtoAtual;
    void makeNewPID(Produto &obj);
public:
    vector<Produto> &getAll();
    const Produto& get(unsigned int &id) const;
    void add(Produto& obj);
    void change(const string &nome, const string &localizacao);
    Produto &getAtual();
    void changeActive(Produto novo);
};

#endif //HEADERS_MODEL_PRODUTOCONTAINER_H
