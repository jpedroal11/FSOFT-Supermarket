

#ifndef HEADERS_VIEWS_ESTABELECIMENTOVIEW_H
#define HEADERS_VIEWS_ESTABELECIMENTOVIEW_H

#include <vector>
#include "Estabelecimento.h"

class EstabelecimentoView{
private:
	static const unsigned int pageSize = 4;
	void printEstList(const vector<Estabelecimento> *vetor); //Print vetor de estabelecimentos
public:
    //  Pedir ao user para escolher um estabelecimento e dar return à referência dele
	// (mais rápido que dar return ao valor)
	Estabelecimento &getEstabelecimentoUser
	(vector<Estabelecimento> *vetor, string label);
    Estabelecimento makeEstabelecimentoUser();

};


#endif //HEADERS_VIEWS_ESTABELECIMENTOVIEW_H
