
#include "MockData.h"
#include "DuplicatedDataException.h"

void MockData::insertProduto(ProdutoContainer& container){
    for (size_t i = 0; i < nomeProdutos.size();i++){
        Produto obj(nomeProdutos[i], precoCompra[i], precoVenda[i]);
        container.add(obj);
    }
}

void MockData::insertQuantidade
(Estabelecimento *estabelecimento, ProdutoContainer &produtos){
    vector<Produto> *vetor = &produtos.getAll();
   // cout << vetor->size();
	for (size_t i = 0; i < vetor->size(); i++){
        int n = 1 + rand() % QUANTIDADE_PRODUTO;
        Produto obj = vetor->at(i);
        estabelecimento->addProduto(obj, QUANTIDADE_PRODUTO);
    }
    //return estabelecimento;
}

void MockData::insertEstabelecimentos(EstabelecimentoContainer& container){

    int n = 2 + rand() % NR_ESTABELECIMENTOS;
    for (size_t i = 0; i < n;i++){
        string nome = nomeEstabelecimentos[i];
        string localizacao = localizacoes[i];
        Estabelecimento obj = Estabelecimento(nome, localizacao);
        container.add(obj);
    }
}

Lojas MockData::generateData(Lojas &model) {
    srand (time(NULL));
    insertEstabelecimentos(model.getEstabelecimentoContainer());
    insertProduto(model.getProdutoContainer());

    EstabelecimentoContainer *estContainer = &model.getEstabelecimentoContainer();
    Estabelecimento *ptr = &estContainer->getAll().at(0);
    estContainer->changeActive(ptr);

    vector<Estabelecimento> *vetor = &estContainer->getAll();
    for(int i = 0; i < vetor->size(); i++){
        Estabelecimento *est = &vetor->at(i);
        insertQuantidade(est, model.getProdutoContainer());

    }
    model.setEstabelecimentoContainer(*estContainer);

    return model;
}
