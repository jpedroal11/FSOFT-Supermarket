
#include "DuplicatedDataException.h"

#include "Produto.h"

Produto::Produto(){
    nomeProduto = "default";
    this-> precoC = Preco(0,0);
    this-> precoV = Preco(0,0);
    this->pID = 727;
}

Produto::Produto(string nome, Preco precoC, Preco precoV)
{
    nomeProduto = nome;
    this-> precoC = precoC;
    this-> precoV = precoV;
    this->pID = 727;
}

void Produto::setPID(const unsigned int &id){
    this->pID = id;
}

const unsigned int &Produto::getId() const{
    return pID;
}

string Produto::getNome() const {
    return nomeProduto;
}

Preco Produto::getprecoC() const{
    return precoC;
}

Preco Produto:: getprecoV() const{
    return precoV;
}

void Produto::setPrecoVenda(Preco novo){
    precoV = novo;
}



