
#ifndef FSOFT2022_1A_2_MOCKDATA_H
#define FSOFT2022_1A_2_MOCKDATA_H

#include <time.h>
#include <string>
#include <vector>
#include "Utils.h"
#include "ProdutoContainer.h"
#include "GestaoContainer.h"
#include "EstabelecimentoContainer.h"
#include "Lojas.h"

using namespace std;

class MockData{
private:
    const int QUANTIDADE_PRODUTO = 10;
    const int NR_ESTABELECIMENTOS = 5;
    const vector<string> nomeProdutos = {"Sofás","Camas","Tapetes","Sofás1","Camas1","Tapetes1","Sofás2","Camas2"};
    const vector<string> nomeEstabelecimentos = {"Loja Porto", "Loja Lisboa", "Loja Braga", "Loja Aveiro", "Loja Faro", "MC Ikea"};
    const vector<string> localizacoes = {"Porto", "Lisboa", "Braga", "Aveiro", "Faro", "Olisipo"};
    const vector<Preco> precoCompra = {Preco(0,50), Preco(1,00), Preco(1,50), Preco(2,00), Preco(2,50), Preco(3,00), Preco(3,50), Preco(4,00), Preco(4,50), Preco(5,00)};
    const vector<Preco> precoVenda = {Preco(1,00), Preco(2,00), Preco(3,00), Preco(4,00),Preco(5,00), Preco(6,00), Preco(7,00), Preco(8,00), Preco(9,00), Preco(10,00)};

    void insertProduto(ProdutoContainer& container);
    void insertQuantidade(Estabelecimento *container, ProdutoContainer &produtos);
    void insertEstabelecimentos(EstabelecimentoContainer& container);

public:
    Lojas generateData(Lojas& model);

};

#endif //FSOFT2022_1A_2_MOCKDATA_H
