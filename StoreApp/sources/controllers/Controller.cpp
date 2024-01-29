#include <iostream>
#include <sstream>
#include <string>
#include "View.h"
#include "Controller.h"
#include "DataConsistencyException.h"


using namespace std;

Controller::Controller() {
    this -> model = Lojas("default");
    this -> estabelecimentoView = EstabelecimentoView();
}

Controller::Controller(Lojas &loja){
    this->model = loja;
    this->estabelecimentoView = EstabelecimentoView();
    this->view = View();
}

void Controller::run(){
   // testFunction();
	EstabelecimentoContainer *estContainer = &model.getEstabelecimentoContainer();
    estContainer->changeActive(&estContainer -> getAll().at(0));
    //estContainer->changeActive(estContainer->getAll().at(0));
	int op = -1;
    do{
        op=this->view.menuLoja();
        switch(op){
            case 1:
            	runEstabelecimentos();
                break;
            case 2:
            	runProdutos();
                break;
            case 3:
                    //Receita Global
            		view.lucroGeral(model);
                break;
            case 0:
            	return;
            default:
            	stringstream stream;
            	stream << "Error processing input, expected value between '1' and '3', but got: \"" << op << "\"\"";
            	throw DataConsistencyException(stream.str());
                break;
        }
    }while(op!=0);

}

void Controller::testFunction(){
    // O uso do pointer permite-nos modificar diretamente os conteudos do container
	EstabelecimentoContainer *container = &model.getEstabelecimentoContainer();
    Estabelecimento est1 = Estabelecimento("Maia","Porto");
    container->add(est1);
    Estabelecimento est2 = Estabelecimento("Porto","Braga");
    container->add(est2);
    Estabelecimento est3 = Estabelecimento("Altura","Braga");
    container->add(est3);
    Estabelecimento est4 = Estabelecimento("Aveiro","Braga");
    container->add(est4);
    Estabelecimento est5 = Estabelecimento("Tondela","Braga");
    container->add(est5);

    Produto teste("teste", Preco(0,50), Preco(35,34));
    for(int i = 0; i < container->getAll().size(); i++){
    	container->getAll().at(i).addProduto(teste, 10);
    }
}

void Controller::runEstabelecimentos() {
    // O uso do pointer permite-nos modificar diretamente os conteudos do container
	EstabelecimentoContainer *container = &model.getEstabelecimentoContainer();
	int op = -1;
    do{
        const Estabelecimento* current = container->getAtual();
    	op = this->view.menuEstabelecimentos(current);
        switch(op){
            case 1:	{
                //Criar Estabelecimento
                Estabelecimento novo = estabelecimentoView.makeEstabelecimentoUser();
                container->add(novo);
            }
                break;
            case 2:{
                //Mudar o nome do Estabelecimento Local
                vector<Estabelecimento> *vetor = &container->getAll();

                // O uso do pointer permite-nos modificar diretamente os conteudos do estabelecimento
                Estabelecimento *est =
                		&estabelecimentoView.getEstabelecimentoUser(vetor, "que pretende mudar o nome");

                string novoNome = Utils::getString("Escolha o novo nome");
                est->setNome(novoNome);
            }
                break;
            case 3: {
                //Mudar o Estabelecimento em que se está
            	vector<Estabelecimento> *vetor = &container->getAll();
            	Estabelecimento *alterar =
            			&estabelecimentoView.getEstabelecimentoUser(vetor, "que prente assumir controlo");
            	container->changeActive(alterar);
            }
                break;
            case 4:{
                //Ir para o menu Gestão
            	runGestao(container);
            }
                break;
            default:
                break;
        }
    }while(op!=0);
}

void Controller::runGestao(EstabelecimentoContainer *container){
	int op = -1;
	Estabelecimento* est = container->getAtual();
	vector<Gestao> *vetor = &est->getAll();
	do{
        op = this->view.menuGestao(est);
		switch(op){
		case 1:	{
			//Analisar a quantidade do produto selecionado nos estabelecimento local
            gestaoView.analisarQuantidade(vetor, "que pretende analisar a quantidade");
		}
			break;
		case 2:{
			//Adicionar x quantidade de um produto
            gestaoView.adicionarProdutos(vetor, "que pretende adicionar");
		}
			break;
		case 3:{
			//Remover x quantidade de um produto (foi vendido)
			gestaoView.removerProdutos(vetor, "que pretende remover");
		}
			break;
		case 4:{
			//Transferir produtos entre estabelecimentos
			gestaoView.transferirGestao
			(estabelecimentoView, est, container, "que pretende transferir",
					"para aonde pretende transferir");
		}
			break;
        case 5:
           // Num de vendas de Produto
        	gestaoView.numeroVendas(vetor, "que pretende analisar vendas");
        	break;
        case 6:
        	 //Lucro de um Produto (individual)
        	gestaoView.analiseLucro(vetor, "que pretende analisar lucro (por unidade)");
        	break;
		default:
			break;
		}
		if(op!=0){
			cout << "\nPress Enter to continue...";
			cin.get();
			cin.clear();
		}
	}while(op!=0);
}


void Controller::runProdutos(){
	ProdutoContainer *container =  &model.getProdutoContainer();

	int op = -1;
    do{
        op = this->view.menuProduto();
        switch(op){
            case 1:	{
                //Criar um novo produto
            	produtoView.criarProduto(container ,model.getEstabelecimentoContainer());
            }
                break;
            case 2:{
                //Alterar o preço de venda de um produto
            	produtoView.alterarPrecoProduto
                (container, model.getEstabelecimentoContainer(), "que pretende alterar o preço de");
            }
                break;
            case 3:{
                //Analisar quais são os produtos que existem (foram criados)
            	produtoView.printListaDeProdutos(container);
            }
                break;

            default:
                break;
        }
    }while(op!=0);
}



