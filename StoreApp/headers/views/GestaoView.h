
#ifndef HEADERS_VIEWS_GESTAOVIEW_H
#define HEADERS_VIEWS_GESTAOVIEW_H
#include "Gestao.h"
#include "Utils.h"
#include "Estabelecimento.h"
#include "EstabelecimentoView.h"
#include "EstabelecimentoContainer.h"
#include <vector>

class GestaoView{
private:
	int selectGestao(const vector<Gestao> *vetor, const string &label) const;
public:
	void transferirGestao
	(EstabelecimentoView &estView, Estabelecimento *estOrigem,
			EstabelecimentoContainer *estCont, const string &label0, const string &label1);

	void analisarQuantidade(vector<Gestao> *vetor, const string &label);

	void adicionarProdutos(vector<Gestao> *vetor, const string &label);
	void removerProdutos(vector<Gestao> *vetor, const string &label);

	void numeroVendas(vector<Gestao> *vetor, const string &label);
	void analiseLucro(vector<Gestao> *vetor, const string &label);
	//void analiseGlobal(vector<Gestao> *vetor, const string &label);
};

#endif //HEADERS_VIEWS_GESTAOVIEW_H
