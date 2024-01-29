
#include "Estabelecimento.h"
#include "DuplicatedDataException.h"

Estabelecimento::Estabelecimento(){
    nome = "default";
    localizacao = "default";
    id = 727;
}

Estabelecimento::Estabelecimento(string _nome, string _localizacao){
    nome = _nome;
    localizacao = _localizacao;
    id = 727;
}
const unsigned int &Estabelecimento::getId() const{
	return id;
}
void Estabelecimento::setId(const unsigned int &id){
	this->id = id;
}

const string& Estabelecimento::getLocalizacao() const{
    return localizacao;
}
void Estabelecimento::setLocalizacao(const string &localizacao) {
    this->localizacao = localizacao;
}
const string& Estabelecimento::getNome() const {
    return nome;
}
void Estabelecimento::setNome(const string &nome) {
    this->nome = nome;
}

Gestao &Estabelecimento::getProdutoEmGestao(){
    return emGestao;
}
//void Estabelecimento::transferProduto(){}
