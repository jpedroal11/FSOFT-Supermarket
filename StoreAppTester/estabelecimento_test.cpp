#include "gtest/gtest.h"
#include "EstabelecimentoContainer.h"
#include "InvalidDataException.h"


TEST(EstabelecimentoConstructorTest, ValidName) {
    //Arrange
    EstabelecimentoContainer estabelecimentoContainer;
    bool flag = false;
    //Act
    try{
        Estabelecimento est ("Name","Localizacao");

        estabelecimentoContainer.add(est);

        vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

        const string name = vetor -> at(0).getNome();
    }catch(InvalidDataException& e){
        flag = true;
    }	//Assert
	EXPECT_FALSE(flag);
}


TEST(EstabelecimentoConstructorTest, InvalidName) {
    //Arrange
    EstabelecimentoContainer estabelecimentoContainer;
    bool flag = false;
    //Act
    try{
        Estabelecimento est (0,"Localizacao");

        estabelecimentoContainer.add(est);

        vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

        const string name = vetor -> at(0).getNome();
    }catch(InvalidDataException& e){
        flag = true;
    }	//Assert
	EXPECT_TRUE(flag);
}

TEST(EstabelecimentoConstructorTest, ValidLocalizacao) {
    //Arrange
    EstabelecimentoContainer estabelecimentoContainer;
    bool flag = false;
    //Act
    try{
        Estabelecimento est ("Name","Localizacao");

        estabelecimentoContainer.add(est);

        vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

        const string name = vetor -> at(0).getLocalizacao();
    }catch(InvalidDataException& e){
        flag = true;
    }	//Assert
    EXPECT_FALSE(flag);
}


TEST(EstabelecimentoConstructorTest, InvalidLocalizacao) {
    //Arrange
    EstabelecimentoContainer estabelecimentoContainer;
    Estabelecimento est;
    bool flag = false;
    //Act
    try{
        Estabelecimento est ("Name",0);

        estabelecimentoContainer.add(est);

        vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

        const string name = vetor -> at(0).getLocalizacao();
    }catch(InvalidDataException& e){
        flag = true;
    }	//Assert
    EXPECT_TRUE(flag);
}


TEST(EstabelecimentoSetTest, ValidSetName) {
    //Arrange
    EstabelecimentoContainer estabelecimentoContainer;
    Estabelecimento est;
    bool flag = false;
    //Act
    try{
        est.setNome("Name");
        est.setLocalizacao("Localizacao");

        estabelecimentoContainer.add(est);

        vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

        const string name = vetor -> at(0).getNome();
    }catch(InvalidDataException& e){
        flag = true;
    }	//Assert
    EXPECT_FALSE(flag);
}
TEST(EstabelecimentoSetTest, InvalidSetName) {
	//Arrange
    EstabelecimentoContainer estabelecimentoContainer;
	Estabelecimento est;
	bool flag = false;
	//Act
	try{
        est.setNome(0);
        est.setLocalizacao("Localizacao");

        estabelecimentoContainer.add(est);

        vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

        const string name = vetor -> at(0).getNome();
		}catch(InvalidDataException& e){
			flag = true;
		}	//Assert
	EXPECT_TRUE(flag);
}

TEST(EstabelecimentoSetTest, ValidSetLocalizacao) {
    //Arrange
    EstabelecimentoContainer estabelecimentoContainer;
    Estabelecimento est;
    bool flag = false;
    //Act
    try{
        est.setNome("Name");
        est.setLocalizacao("Localizacao");

        estabelecimentoContainer.add(est);

        vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

        const string name = vetor -> at(0).getLocalizacao();
    }catch(InvalidDataException& e){
        flag = true;
    }	//Assert
    EXPECT_FALSE(flag);
}
TEST(EstabelecimentoSetTest, InvalidSetLocalizacao) {
    //Arrange
    EstabelecimentoContainer estabelecimentoContainer;
    Estabelecimento est;
    bool flag = false;
    //Act
    try{
        est.setNome("Name");
        est.setLocalizacao(0);

        estabelecimentoContainer.add(est);

        vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

        const string name = vetor -> at(0).getLocalizacao();
    }catch(InvalidDataException& e){
        flag = true;
    }	//Assert
    EXPECT_TRUE(flag);
}

TEST(EstabelecimentoOperatorEqualTest, EqualNames) {
	//Arrange
    EstabelecimentoContainer estabelecimentoContainer;

    Estabelecimento est1 ("Nome","Localização");
    Estabelecimento est2 ("Nome","Localização");

    estabelecimentoContainer.add(est1);
    estabelecimentoContainer.add(est2);

    vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

    const string name1 = vetor -> at(0).getNome();
    const string name2 = vetor -> at(1).getNome();
	//Act
	bool flag = name1==name2;
	//Assert
	EXPECT_TRUE(flag);
}
TEST(EstabelecimentoOperatorEqualTest, NotEqualNames) {
	//Arrange
    EstabelecimentoContainer estabelecimentoContainer;

    Estabelecimento est1 ("Nome","Localização");
    Estabelecimento est2 ("Nome1","Localização");

    estabelecimentoContainer.add(est1);
    estabelecimentoContainer.add(est2);

    vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

    const string name1 = vetor -> at(0).getNome();
    const string name2 = vetor -> at(1).getNome();
    //Act
    bool flag = name1==name2;
	//Assert
	EXPECT_FALSE(flag);
}

TEST(EstabelecimentoOperatorEqualTest, EqualIds) {
    //Arrange
    EstabelecimentoContainer estabelecimentoContainer;

    Estabelecimento est1 ("Nome","Localização");
    Estabelecimento est2 ("Nome","Localização");

    estabelecimentoContainer.add(est1);
    estabelecimentoContainer.add(est2);

    vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

    unsigned int id1 = vetor -> at(0).getId();
    unsigned int id2 = vetor -> at(1).getId() - 1;

    //Act
    bool flag = id1==id2;
    //Assert
    EXPECT_TRUE(flag);
}
TEST(EstabelecimentoOperatorEqualTest, NotEqualIds) {
    //Arrange
    EstabelecimentoContainer estabelecimentoContainer;

    Estabelecimento est1 ("Nome","Localização");
    Estabelecimento est2 ("Nome1","Localização1");

    estabelecimentoContainer.add(est1);
    estabelecimentoContainer.add(est2);

    vector<Estabelecimento> *vetor = &estabelecimentoContainer.getAll();

    unsigned int id1 = vetor -> at(0).getId();
    unsigned int id2 = vetor -> at(1).getId();
    //Act
    bool flag = id1==id2;
    //Assert
    EXPECT_FALSE(flag);
}





