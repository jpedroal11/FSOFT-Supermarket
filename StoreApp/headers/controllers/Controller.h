#ifndef HEADERS_CONTROLLERS_CONTROLLER_H_
#define HEADERS_CONTROLLERS_CONTROLLER_H_


#include "View.h"
#include "EstabelecimentoView.h"
#include "ProdutoView.h"
#include "GestaoView.h"
#include "Lojas.h"
#include "Gestao.h"

class Controller{
private:
	Lojas model;
    View view;
    EstabelecimentoView estabelecimentoView;
    GestaoView gestaoView;
    ProdutoView produtoView;

    void runEstabelecimentos();
    void runGestao(EstabelecimentoContainer *container);

    void runProdutos();
    void testFunction();
public:
    Controller();
    Controller(Lojas& loja);
    //void setLoja(Loja);
    void run();
};

#endif //HEADERS_CONTROLLERS_CONTROLLER_H_
