
#include "GestaoContainer.h"

GestaoContainer::GestaoContainer(){

}
GestaoContainer::~GestaoContainer(){
}

void GestaoContainer::addProduto(Produto& obj, int qnt){
    Gestao novo = Gestao(obj);
    makeNewGID(novo);
    novo.setQuantidade(qnt);
    Utils::addOrderedVector(produtosEmGestao,novo);
}

void GestaoContainer::makeNewGID(Gestao &obj){
    if(produtosEmGestao.empty() == true)	{
        obj.setGID(7216);
        return;
    }
    const unsigned int *prevId = &produtosEmGestao.at(produtosEmGestao.size() - 1).getId();
    unsigned int newId = *prevId + 1;
    obj.setGID(newId);

}

vector<Gestao> &GestaoContainer::getAll(){
    return produtosEmGestao;
}

Gestao &GestaoContainer::getProdutoEmGestao(){
}

void GestaoContainer::transferProduto(const int &index){}

