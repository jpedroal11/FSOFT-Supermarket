#include "gtest/gtest.h"
#include "ProdutoContainer.h"
#include "InvalidDataException.h"

TEST(ProdutoConstructorTest, ValidName) {
    //Arrange
    bool flag = false;
    ProdutoContainer produtoContainer;
    //Act
    try {
        Produto product("Produto", Preco(5, 0), Preco(6, 0));


        produtoContainer.add(product);

        string nome = product.getNome();
	}catch(InvalidDataException& e){
		flag = true;
	}
	//Assert
	EXPECT_FALSE(flag);
}

TEST(ProdutoConstructorTest, InvalidName) {
    //Arrange
    bool flag = false;
    ProdutoContainer produtoContainer;
    //Act
    try {
        Produto product(0, Preco(5, 0), Preco(6, 0));


        produtoContainer.add(product);

        string nome = product.getNome();
    }catch(InvalidDataException& e){
        flag = true;
    }
    //Assert
    EXPECT_TRUE(flag);
}

TEST(ProdutoConstructorTest, ValidPrice) {
    //Arrange
    bool flag = false;
    ProdutoContainer produtoContainer;
    //Act
    try {
        Produto product("Produto", Preco(5, 0), Preco(6, 0));

        produtoContainer.add(product);

        Preco preco = product.getprecoV();
    }catch(InvalidDataException& e){
        flag = true;
    }
    //Assert
    EXPECT_FALSE(flag);
}

TEST(ProdutoConstructorTest, InvalidPrice) {
    //Arrange
    bool flag = false;
    ProdutoContainer produtoContainer;
    //Act
    try {
        Produto product("Produto", Preco(5, 0), Preco(-6, 0));


        produtoContainer.add(product);

        Preco preco = product.getprecoV();
    } catch (InvalidDataException &e) {
        flag = true;
    }
    //Assert
    EXPECT_FALSE(flag);
}

TEST(ProdutoOperatorEqualTest, EqualId) {
    //Arrange
    ProdutoContainer produtoContainer;

    Produto product1("Produto", Preco(5,0) , Preco(6,0));
    Produto product2("Produto", Preco(5,0) , Preco(6,0));

    produtoContainer.add(product1);
    produtoContainer.add(product2);

    unsigned int id1 = product1.getId();
    unsigned int id2 = product2.getId() - 1;

    //Act
    bool flag = id1==id2;
    //Assert
    EXPECT_TRUE(flag);
}
TEST(ProdutoOperatorEqualTest, NotEqualId) {
    ProdutoContainer produtoContainer;
    //Arrange
    Produto product1("Produto", Preco(5,0) , Preco(6,0));
    Produto product2("Produto", Preco(5,0) , Preco(6,0));

    produtoContainer.add(product1);
    produtoContainer.add(product2);

    unsigned int id1 = product1.getId();
    unsigned int id2 = product2.getId();
    //Act
    bool flag = id1==id2;
    //Assert
    EXPECT_FALSE(flag);
}

