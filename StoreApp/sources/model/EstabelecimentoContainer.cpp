
#include "EstabelecimentoContainer.h"

using namespace std;

EstabelecimentoContainer::EstabelecimentoContainer(){
}
void EstabelecimentoContainer::makeNewId(Estabelecimento &obj){

	if(estabelecimentos.empty() == true)	{
		obj.setId(7216);
		return;
	}

	const unsigned int *prevId = &estabelecimentos.at(estabelecimentos.size() - 1).getId();
    unsigned int newId = *prevId + 1;
	obj.setId(newId);
}

vector<Estabelecimento> &EstabelecimentoContainer::getAll(){
    return estabelecimentos;
}
Estabelecimento &EstabelecimentoContainer::get(unsigned int& id){
    int index = Utils::searchOrderedVector(estabelecimentos,id);
    return estabelecimentos.at(index);
}

Estabelecimento *EstabelecimentoContainer::getAtual() {
	return estabelecimentoAtual;
}


void EstabelecimentoContainer::add(Estabelecimento obj) {
	makeNewId(obj); // Dá, por referência, um ID ao objeto
	Utils::addOrderedVector(estabelecimentos,obj);
}

void EstabelecimentoContainer::remove(unsigned int &id) {
    int index = Utils::searchOrderedVector(estabelecimentos , id);
    vector<Estabelecimento>::iterator p = estabelecimentos.begin() + index;

    estabelecimentos.erase(p);
}

void EstabelecimentoContainer::changeActive(Estabelecimento *novo){
	estabelecimentoAtual = novo;
}
void EstabelecimentoContainer::setGestao(GestaoContainer gestao) {
	this->gestao = gestao;
}
