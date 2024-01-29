
#include "Lojas.h"

Lojas::Lojas(){
    name = "default";
}

Lojas::Lojas(const string& name){
    this->name = name;
}

const string& Lojas::getName() const {
    return name;
}

void Lojas::setName(const string &name) {
    this->name = name;
}

EstabelecimentoContainer &Lojas::getEstabelecimentoContainer(){
    return this->estabelecimentoContainer;
}
void Lojas::setEstabelecimentoContainer(EstabelecimentoContainer est){
	estabelecimentoContainer = est;
}

ProdutoContainer &Lojas::getProdutoContainer() {
    return this->produtoContainer;
}



