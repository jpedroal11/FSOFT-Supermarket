#include "ProdutoView.h"
#include "InvalidDataException.h"
#include <iostream>
#include <sstream>

Produto *ProdutoView::userGetProduto(vector<Produto> *produtos, const string &label)
{
	cout << "/~~~~~~~~~~~~~~~~~~~~~~~~\\" << "\n";
	for(int i = 0; i < produtos ->size(); i++)
	{
		Produto *produto = &produtos->at(i);
		cout << "Select["<< i+1 << "] -> \"" << produto->getNome() << "\" ID: ("
				<< produto->getId() << ")" << "~~~ Preco de Venda--> \""
				<< produto->getprecoV().getPrecoString() << "\"" << endl;
	}
	cout << "\\~~~~~~~~~~~~~~~~~~~~~~~~/" << "\n";
	stringstream stream; stream << "Escolha o \"Select\" do produto em gestão "  << label;
	int index = Utils::getNum(stream.str())-1;
	return &produtos->at(index);
}

void ProdutoView::alterarPrecoProduto
(ProdutoContainer *container, EstabelecimentoContainer &estContainer,const string &label)
{
	vector<Produto> *produtos = &container->getAll();
	Produto *alterar = userGetProduto(produtos, label);

	Preco novo(0,0);

	int unidades = Utils::getNum("Insira os euros (unidades) do novo preco");
	int decimal = Utils::getNum("Insira os centimos (decimas) do novo preco");
	novo = Preco(unidades, decimal);
	stringstream stream; stream << "O seu novo preço será: \"" << novo.getPrecoString();

	alterar->setPrecoVenda(novo);
	// regenerar gestoes dependentes
	vector<Estabelecimento> *ests = &estContainer.getAll(); const unsigned int refID = alterar->getId();
	for(int i = 0; i < ests->size(); i++){
		Estabelecimento *est = &ests->at(i);
		vector<Gestao> *gests = &est->getAll();

		int toChangePID = Utils::searchForPID(*gests, refID);
		gests->at(toChangePID).setPrecoVenda(novo);
	}
}

    void ProdutoView::criarProduto(ProdutoContainer *container,EstabelecimentoContainer &estContainer){
	string nome = Utils::getString("Nome do produto que quer criar");
	Preco precoV(0,0); Preco precoC(0,0);

	int unidades = Utils::getNum("Insira os euros (unidades) do preco de compra");
	int decimal = Utils::getNum("Insira os centimos (decimas) do preco de compra");
	precoC = Preco(unidades, decimal);

	unidades = Utils::getNum("Insira os euros (unidades) do preco de venda");
	decimal = Utils::getNum("Insira os centimos (decimas) do preco de venda");
	precoV = Preco(unidades, decimal);

	Produto produto(nome, precoC, precoV);
	container->add(produto);
    // regenerar gestoes dependentes
    vector<Estabelecimento> *ests = &estContainer.getAll();
    const unsigned int refID = produto.getId();
    for(int i = 0; i < ests->size(); i++){
        Estabelecimento *est = &ests->at(i);
        est ->addProduto(produto, 10);
    }
    // regenerar pointer estabelecimento atual
    estContainer.changeActive(&ests->at(0));
}

void ProdutoView::printListaDeProdutos(ProdutoContainer *container){
		vector<Produto> *vetor = &container->getAll();
		cout << "/~~~~~~~~~~~~~~~~~~~~~~~~\\" << "\n";
		for(int i = 0; i < vetor->size(); i++){
			Produto *prod = &vetor->at(i);
			cout << "[Produto] \"" << prod->getNome() << "\" ~~~ [Preco Compra] --> \""
					<< prod->getprecoC().getPrecoString() << "\" ~~~ [Preco Venda] --> \""
					<< prod->getprecoV().getPrecoString() << "\"" << "\n";
		}
		cout << "\\~~~~~~~~~~~~~~~~~~~~~~~~/" << "\n";
}
