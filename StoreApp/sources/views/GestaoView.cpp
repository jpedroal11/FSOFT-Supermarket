#include "GestaoView.h"
#include "InvalidDataException.h"
#include <iostream>
#include <sstream>

using namespace std;

int GestaoView::selectGestao(const vector<Gestao> *vetor, const string &label) const{
	if(vetor->empty()){
		cout << "\nEstabelecimento em gestão não tem produtos em gestão!\n";
		cout << "¯\\_(ツ)_/¯ -> Adicione pelo menos um produto em gestão";
	}

	cout << "/~~~~~~~~~~~~~~~~~~~~~~~~~~~\\" << "\n";
	for(int i = 0; i < vetor->size(); i++){
		Gestao gest = vetor->at(i);
		cout << "Select["<< i+1 << "] -> \"" << gest.getNome() << "\" ID: (" << gest.getId() << ")"
				/*"Preco Venda: " << gest.getprecoV().getPrecoString()*/ <<endl;
	}
	cout << "\\~~~~~~~~~~~~~~~~~~~~~~~~~~~/" << "\n\n";
	stringstream stream; stream << "Escolha o \"Select\" do produto em gestão "  << label;
	return (Utils::getNum(stream.str())-1);
}


void GestaoView::transferirGestao
(EstabelecimentoView &estView, Estabelecimento *estOrigem, EstabelecimentoContainer *estCont,
		const string &label0, const string &label1)
{
	// Pedir ao user que escolhe produto-gestao a transferir
	vector<Gestao> *gestoes = &estOrigem->getAll();
	int index = selectGestao(gestoes, label0); Gestao *aRemover = &gestoes->at(index);
	unsigned int qnt = aRemover->getQuantidade();
	aRemover->setQuantidade(0);

	// Pedir ao user o estabelecimento destino
	vector<Estabelecimento> *ests = &estCont->getAll();
	Estabelecimento *estTrans = &estView.getEstabelecimentoUser(ests, label1);

	// Encontrar gestao destino
	const unsigned int pIDEncontrar = aRemover->getPID(); vector<Gestao> *gTrans = &estTrans->getAll();
	index = Utils::searchForPID(*gTrans, pIDEncontrar);
	Gestao *g = &gTrans->at(index); g->addQuantidade(qnt);
}

void GestaoView::analisarQuantidade(vector<Gestao> *vetor, const string &label)
{
	int index = selectGestao(vetor, label);
	cout << "Quantidade de Produto é: \"" << vetor->at(index).getQuantidade() << "\"\n";
}

void GestaoView::adicionarProdutos(vector<Gestao> *vetor, const string &label){
	int index = selectGestao(vetor, label);
	int toAdd = Utils::getNum("Quanto é que pretende adicionar");
	vetor->at(index).addQuantidade(toAdd);
}

void GestaoView::removerProdutos(vector<Gestao> *vetor, const string &label){
	int index = selectGestao(vetor, label);
	int toRemove = Utils::getNum("Quanto é que pretende remover");
	int qnt = vetor->at(index).getQuantidade();
	if(qnt-toRemove >= 0) {
        vetor->at(index).setQuantidade(qnt - toRemove);
        vetor->at(index).addVendas(toRemove);
    }
	else {
		cout << "Tentativa de remover mais produtos do que aqueles que existem, " <<
				"a colocar quantidade de produto a \"0\"";
		vetor->at(index).setQuantidade(0);
	}
}

void GestaoView::numeroVendas(vector<Gestao> *vetor, const string &label){
	int index = selectGestao(vetor, label);
	Gestao *toAnalise = &vetor->at(index);
	const unsigned int vendas = toAnalise->getNumVendas();

	cout << "Total de vendas do produto: \"" << toAnalise->getNome() << "\" é de: ["
			<< vendas << "]" << "\n\n";
}

void GestaoView::analiseLucro(vector<Gestao> *vetor, const string &label) {
	int index = selectGestao(vetor, label);
	Gestao *toAnalise = &vetor->at(index);

	const Preco venda = toAnalise->lucroIndividual();
	string stringVenda = venda.getPrecoString();

	 cout << "Lucro por produto: \"" << toAnalise->getNome() << "\" é de: ["
			 << stringVenda << "]" << "\n\n";
}

