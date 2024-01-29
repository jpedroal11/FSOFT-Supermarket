

#ifndef HEADERS_MODEL_STOCK_H
#define HEADERS_MODEL_STOCK_H

#include "Produto.h"
#include <vector>
using namespace std;

class Gestao : public Produto{
private:
    unsigned int nVendas;
    unsigned int nCompras;
    unsigned int quantidade;
    unsigned int gID;
public:
	Gestao();
    Gestao(const Produto &copia);

    const unsigned int getNumVendas() const;

    int getQuantidade();
    void setQuantidade(int qnt);
    void addQuantidade(int qnt);

    void setGID(const unsigned int &id);
    const unsigned int &getId() const;

    const unsigned int &getPID() const;

    const Preco totalCompras();
    const Preco totalVendas();
    void addVendas(int qnt);
    const Preco lucroIndividual();

};

#endif //HEADERS_MODEL_STOCK_H
