

#ifndef HEADERS_VIEWS_PRODUTOVIEW_H
#define HEADERS_VIEWS_PRODUTOVIEW_H
#include "Produto.h"
#include "ProdutoContainer.h"
#include "GestaoContainer.h"
#include "EstabelecimentoContainer.h"

class ProdutoView{
private:
	Produto *userGetProduto(vector<Produto> *produtos, const string &label);
public:
    void alterarPrecoProduto
	(ProdutoContainer *container, EstabelecimentoContainer &estContianer,const string &label);
    void criarProduto(ProdutoContainer *container,EstabelecimentoContainer &estContainer);
    void printListaDeProdutos(ProdutoContainer *container);

};

#endif //HEADERS_VIEWS_PRODUTOVIEW_H
