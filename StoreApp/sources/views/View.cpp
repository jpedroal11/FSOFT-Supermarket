
#include <iostream>
#include "View.h"
#include "InvalidDataException.h"

using namespace std;

View::View(){
}
void View::printEstabelecimentoAtual(const Estabelecimento *atual) const{
	cout << "\n> [Estabelecimento Atual]: (" << atual->getNome() <<
			")  || [localização]: (" << atual->getLocalizacao() << ")  || [ID]: (" << atual->getId() << ")\n";
}

int View::menuLoja() {
    int op = -1;
    do{
    	cout<<"\n\n********** Menu Loja **********\n";
        cout<<"1 - Estabelecimentos\n";
        cout<<"2 - Produtos\n";
        cout<<"3 - Receita Global\n";
        cout<<"\n0 - Exit\n";
        op = Utils::getNum("Option");
    }while(op < 0 || op > 3);
    return op;
}

int View::menuEstabelecimentos(const Estabelecimento *atual) {
    int op = -1;
    do{
    	cout<<"\n\n********** Menu Estabelecimentos **********";
    	printEstabelecimentoAtual(atual);
        cout<<"1 - Criar\n";
        cout<<"2 - Alterar Nome\n";
        cout<<"3 - Mudar de Estabelecimento\n";
        cout<<"4 - Gestão\n";
        cout<<"\n0 - Exit\n";
        op = Utils::getNum("Option");
    }while(op < 0 || op > 4);
    return op;
}

int View::menuGestao(Estabelecimento *atual) {
	int op = -1;
    do{
        cout<<"\n\n********** Menu Gestao **********\n";
        printEstabelecimentoAtual(atual);
        cout<<"1 - Analisar Quantidade\n";
        cout<<"2 - Adicionar Produtos\n";
        cout<<"3 - Remover Produtos\n";
        cout<<"4 - Transferir Produtos\n";
        cout<<"5 - Numero de vendas de um Produto\n";
        cout<<"6 - Lucro de um Produto\n";
        cout<<"\n0 - Exit\n";
        op = Utils::getNum("Option");
    }while(op < 0 || op > 6);
    return op;
}

int View::menuProduto() {
    int op = -1;
    do{
        cout<<"\n\n********** Menu Produto **********\n";
        cout<<"1 - Criar\n";
        cout<<"2 - Alterar Preco de Venda\n";
        cout<<"3 - Analisar Lista de Produtos\n";
        cout<<"\n0 - Exit\n";
        op = Utils::getNum("Option");
    }while(op < 0 || op > 3);
    return op;
}

void View::lucroGeral(Lojas &loja){
	ProdutoContainer *produtoContainer = &loja.getProdutoContainer();
	EstabelecimentoContainer *estabelecimentoContainer = &loja.getEstabelecimentoContainer();

	cout << "/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\ \n";
	Preco totalLoja(0,0);
	vector<Produto> *produtos = &produtoContainer->getAll();

	vector<Estabelecimento> *vEst = &estabelecimentoContainer->getAll();
	for(int i = 0; i < vEst->size(); i++)
	{
		Preco totalEstabelecimento(0,0);
		Estabelecimento *est = &vEst->at(i);
		vector<Gestao> *vGest = &est->getAll();

		Gestao *maisLucravel = nullptr; Preco champ(0,0);
		for(int j = 0; j < vGest->size(); j++)
		{
			// calculos de lucro
			Gestao *gest = &vGest->at(j);
			Preco lucroIndividual = gest->lucroIndividual();
			lucroIndividual = lucroIndividual.multiply(gest->getNumVendas());
			totalEstabelecimento = totalEstabelecimento.add(lucroIndividual);
			//////////////////////////////////////////
			// Encontrar o mais lucrável
			if(maisLucravel != nullptr){
				if(!champ.compare(lucroIndividual)) {
					maisLucravel = gest;
					champ = maisLucravel->lucroIndividual();
					champ = champ.multiply(maisLucravel->getNumVendas());
				}
			}
			else {
				maisLucravel = gest;
				champ = maisLucravel->lucroIndividual();
				champ = champ.multiply(maisLucravel->getNumVendas());
			}
			/////////////////////////////////////////////////////////////
		}
		cout << "[Estabelecimento] \"" << est->getNome() << "\" ~~~ [Lucro] --> \""
				<< totalEstabelecimento.getPrecoString() << "\" ~~~ [Mais Lucrável] \""
				<< maisLucravel->getNome() << "\" --> \"" << champ.getPrecoString() <<"\"\n";

		totalLoja = totalLoja.add(totalEstabelecimento);
	}
	cout << "\\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/" << "\n";
	cout << "[Lucro Total] --> \"" << totalLoja.getPrecoString() << "\"\n";
	cout << "Press enter to continue... \n";
	cin.get();
	cin.clear();
}

