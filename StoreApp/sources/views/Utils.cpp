
#include <iostream>
#include <limits>
#include "Estabelecimento.h"
#include "InvalidDataException.h"
using namespace std;

int Utils::getNum(const string&  text){
    int num;
    while(true){
        cout<<text<<": ";

        cin >> num;
        if(cin.fail()){
            cout << "Não é um número valido, por favor insira outra vez."<< endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            if (num < 0)
                cout<<"Não é um número valido, por favor insira outra vez."<< endl;
            else
            break;
        }

    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return num;
}
string Utils::getString(const string&  text){
    string input;
    cout<<text<<": ";
    getline (cin, input);
    return input;
}

int Utils::searchForPID(const vector<Gestao> &vetor, const unsigned int &id){
	size_t arraysize = vetor.size();
	int mid = arraysize / 2;
	while (true) {
		Gestao este = vetor.at(mid);
        unsigned int searchId = este.getPID();

		if (searchId == id) {
			return mid;
		}
		else {
			if (searchId < id){
                if (mid == arraysize - 2) mid = arraysize - 1;
                else
                mid = arraysize - mid/2;
			}
			else{
				if(mid == 1) mid = 0;
				mid = mid - mid/2;
			}
		}
	}
}
