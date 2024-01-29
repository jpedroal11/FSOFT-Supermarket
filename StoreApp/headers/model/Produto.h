
#ifndef HEADERS_MODEL_PRODUTO_H_
#define HEADERS_MODEL_PRODUTO_H_


#include <string>
#include <vector>
#include "Preco.h"


using namespace std;
class Produto{
protected:
    string nomeProduto;
    Preco precoC;
    Preco precoV;
    unsigned int pID;
public:
    Produto();
    Produto(string nome, Preco precoC, Preco precoV);
    const unsigned int &getId() const;
    void setPID(const unsigned int &id);
    string getNome() const;
    Preco getprecoC() const;
    Preco getprecoV() const;
    void setPrecoVenda(Preco novo);
};

#endif /* HEADERS_MODEL_PRODUTO_H_ */
