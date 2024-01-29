
#include "ProdutoContainer.h"

using namespace std;

void ProdutoContainer::makeNewPID(Produto &obj ){
    if(produtos.empty() == true)	{
        obj.setPID(7216);
        return;
    }
    const unsigned int *prevId = &produtos.at(produtos.size() - 1).getId();
    unsigned int newId = *prevId + 1;
    obj.setPID(newId);
}

vector<Produto> &ProdutoContainer::getAll(){
    return produtos;
}

const Produto &ProdutoContainer::get(unsigned int& id) const{
    int index = Utils::searchOrderedVector(produtos,id);
    return produtos.at(index);
}

Produto &ProdutoContainer::getAtual() {
    return produtoAtual;
}

void ProdutoContainer::changeActive(Produto novo){
    produtoAtual = novo;
}

void ProdutoContainer::add(Produto& obj) {
    makeNewPID(obj); // Dá, por referência, um ID ao objeto
    Utils::addOrderedVector(produtos,obj);
}




