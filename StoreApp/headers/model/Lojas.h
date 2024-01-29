#ifndef HEADERS_MODEL_LOJAS_H
#define HEADERS_MODEL_LOJAS_H

#include "Preco.h"
#include "EstabelecimentoContainer.h"
#include "ProdutoContainer.h"
#include <string>
using namespace std;

class Lojas {
private:
    string name;
    EstabelecimentoContainer estabelecimentoContainer;
    ProdutoContainer produtoContainer;

public:
    Lojas();
    Lojas(const string& name);


    const string& getName() const ;
    void setName(const string &name) ;

    EstabelecimentoContainer  &getEstabelecimentoContainer();
    ProdutoContainer &getProdutoContainer();
    void setEstabelecimentoContainer(EstabelecimentoContainer est);
};



#endif //HEADERS_MODEL_LOJAS_H
