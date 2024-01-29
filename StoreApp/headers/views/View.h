
#ifndef HEADERS_VIEWS_VIEW_H_
#define HEADERS_VIEWS_VIEW_H_

#include <string>
#include "Estabelecimento.h"
#include "Lojas.h"
using namespace std;

class View{
private:
	void printEstabelecimentoAtual(const Estabelecimento *atual) const;
public:
    View();
    int menuLoja();
    int menuEstabelecimentos(const Estabelecimento *atual);
    int menuGestao(Estabelecimento *atual);
    int menuProduto();

    void lucroGeral(Lojas &loja);
};


#endif //HEADERS_VIEWS_VIEW_H
