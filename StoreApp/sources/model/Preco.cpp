#include "Preco.h"
#include "InvalidDataException.h"
#include <iostream>
#include <sstream>

using namespace std;

Preco::Preco(){

    unsigned int unidades = 727;
    unsigned int decimal = 27;
    setPrice(unidades , decimal);

}

Preco::Preco(unsigned int _unidades, unsigned int _decimal){
    setPrice(_unidades, _decimal);
}

string Preco::getPrecoString() const{
	stringstream stream; stream << getUnidades() << "," << getDecimal() << "€";
	return stream.str();
}

void Preco::normalizeDecimal(unsigned int &_unidades, unsigned int &_decimal){
    while (_decimal >= 100){
       _decimal = _decimal - 100;
       _unidades = _unidades + 1;
    }

    if(_decimal > 100) throw InvalidDataException
    		("Preco::normalizeDecimal -> decimal abaixo de zero. || se isto aconteceu... reza");
}

void Preco::setPrice(unsigned int &_unidades, unsigned int &_decimal){
	normalizeDecimal(_unidades, _decimal); // Passado e alterado por referência
    Preco::decimal = _decimal;
    Preco::unidades = _unidades;
}
const unsigned int Preco::getDecimal() const{
    return decimal;
}
const unsigned int Preco::getUnidades() const{
    return unidades;
}
Preco Preco::multiply(unsigned int quantidade){
    unsigned int unidades = getUnidades();
    unsigned int decimal = getDecimal();
    unidades = unidades * quantidade;
    decimal = decimal * quantidade;
    Preco precoF(unidades, decimal); // alterado e normalizado automaticamente;
    return precoF;
}
Preco Preco::multiply(Preco input){
    unsigned int uniOriginal = getUnidades();
    unsigned int uniAMultiplicar = input.getUnidades();
    unsigned int decOriginal = getDecimal();
    unsigned int decAMultiplciar = input.getDecimal();
    unsigned int uniFinal = uniOriginal * uniAMultiplicar;
    unsigned int decFinal = decOriginal * decAMultiplciar;
    Preco precoF = Preco(uniFinal,decFinal);
    return precoF;
}

Preco Preco::add(Preco input){
	unsigned int uniFinal = input.getUnidades() + unidades;
	unsigned int deciFinal = input.getDecimal() + decimal;
	return Preco(uniFinal, deciFinal);
}

Preco Preco::subtract(const Preco input) {
    unsigned int uniOriginal = getUnidades();
    unsigned int uniASubtrair = input.getUnidades();
    unsigned int decOriginal = getDecimal();
    unsigned int decASubtrair = input.getDecimal();

    unsigned int uniFinal;
	unsigned int decFinal;
    if(uniOriginal - uniASubtrair > uniOriginal)  // Over subtracted units
    	uniFinal = 0;
    else
    	uniFinal = uniOriginal - uniASubtrair; // Normal
    if(decOriginal - decASubtrair > decOriginal){
    	int intermedium = decOriginal - decASubtrair; // Over subtracted decimals
    	uniFinal--; decFinal = (100+intermedium);
    	if(decFinal > 100){
    		cout << "This shouldn't happen at all\n";
    		throw InvalidDataException("");
    	}
    }
    else decFinal = decOriginal - decASubtrair; // Normal decimals

    Preco precoF = Preco(uniFinal,decFinal);
    return precoF;
}

bool Preco::compare(Preco input){
	if(unidades > input.getUnidades()) return true;
	else if(unidades == input.getUnidades()){
		if(decimal >= input.getDecimal()) return true;
		else return false;
	}
	else return false;
}
