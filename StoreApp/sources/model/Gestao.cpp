#include "Gestao.h"

Gestao::Gestao() {
    nCompras = 0;                                            // estes valores sao individuais
    nVendas = 0;
    precoC = Preco(0,0);
    precoV = Preco(0 ,0);
    gID = 727;
    pID = 272;
    quantidade = 0;
}

Gestao::Gestao(const Produto &copia)
{
    nVendas = 0;
    nCompras = 0;
    gID = 727;
    pID = copia.getId();
    quantidade = 0;

    this->nomeProduto = copia.getNome();
    this->precoC = copia.getprecoC();
    this->precoV = copia.getprecoV();
}

int Gestao::getQuantidade(){
    return quantidade;
}

const unsigned int Gestao::getNumVendas() const{
	return nVendas;
}

void Gestao::setQuantidade(int qnt){
    quantidade = qnt;
}

void Gestao::addQuantidade(int qnt) {
	quantidade += qnt;
}

void Gestao::setGID(const unsigned int &id){
    this->gID = id;
}

const unsigned int &Gestao::getId() const{
    return gID;
}
const unsigned int &Gestao::getPID() const{
	return pID;
}

const Preco Gestao::totalCompras(){                                               //total por produto
    Preco totalCompras = precoC.multiply(nCompras);         //precoC*nCompras
    return totalCompras;
}

void Gestao::addVendas(int qnt){
    nVendas += qnt;
}

const Preco Gestao::totalVendas(){                                                //total por produto
    Preco totalVendas = precoV.multiply(nVendas);       //precoV*nVendas
    return totalVendas;
}

const Preco Gestao::lucroIndividual(){
    Preco lucroIndividual = precoV.subtract(precoC);                                  //precoV-precoC
    return lucroIndividual;
}

