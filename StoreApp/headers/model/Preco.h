#ifndef HEADERS_VIEWS_PRECO_H_
#define HEADERS_VIEWS_PRECO_H_

#include <string>

using namespace std;
class Preco{
private:
    int decimal; //,xx€
    int unidades; //xx,€
    void normalizeDecimal(unsigned int &_unidades, unsigned int &_decimal);
public:
    Preco();
    Preco(unsigned int _unidades, unsigned int _decimal);

    void setPrice(unsigned int &_unidades, unsigned int &_decimal);
    const unsigned int getDecimal() const;
    const unsigned int getUnidades() const;

    string getPrecoString() const;

    Preco multiply(unsigned int quantidade);
    Preco multiply(Preco input);
    Preco add(Preco input);
    Preco subtract(Preco input);
    bool compare(Preco input); // return true se chamante for maior ou igual
};


#endif /* HEADERS_VIEWS_PRECO_H_ */
