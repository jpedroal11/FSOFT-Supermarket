#include <iostream>
#include "Controller.h"
#include "Lojas.h"
#include "MockData.h"

int main() {

    Lojas loja = Lojas("IKEA");

    MockData mock;
    loja = mock.generateData(loja);

    Controller controller = Controller(loja);
    controller.run();

    cout << endl << "Programme exited sucessfully!" << endl;
    cout << "Thank you!";

    return 0;
}

