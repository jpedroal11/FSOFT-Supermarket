

#include "EstabelecimentoView.h"
#include "InvalidDataException.h"
#include <iostream>
#include <sstream>

using namespace std;

void EstabelecimentoView::printEstList(const vector<Estabelecimento> *vetor)
{
	cout << "/~~~~~~~~~~~~~~~~~~~~~~~~\\" << "\n";
	for(int i = 0; i < vetor->size(); i++){
		Estabelecimento est = vetor->at(i);
		cout << "Select["<< i+1 << "] -> \"" << est.getNome() << "\" ID: (" << est.getId() << ")" <<endl;
	}
	cout << "\\~~~~~~~~~~~~~~~~~~~~~~~~/" << "\n\n";
}

Estabelecimento &EstabelecimentoView::getEstabelecimentoUser
(vector<Estabelecimento> *vetor, string label)
{
	size_t size = vetor->size(); int num = -1;
	while(true)
	{
		printEstList(vetor);
		//char str[201]; snprintf(str, 200, "Escolha o numero do estabelecimento %c", label);
		stringstream stream; stream << "Escolha o \"Select\" do estabelecimento "  << label;
		num = Utils::getNum(stream.str());
		if(num - 1 < size && num > 0) break;
	}
	return vetor->at(num-1);
}

Estabelecimento EstabelecimentoView::makeEstabelecimentoUser() {
    Estabelecimento estabelecimento;
    bool flag = false;
    do{
        try{
            flag = false;
            string nome = Utils::getString("Escreva nome que pretende");
            string localizacao = Utils::getString("E a localizacao");
            estabelecimento.setNome(nome);
            estabelecimento.setLocalizacao(localizacao);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return estabelecimento;
}
