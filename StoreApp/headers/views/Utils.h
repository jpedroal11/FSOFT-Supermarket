

#ifndef HEADERS_VIEWS_UTILS_H
#define HEADERS_VIEWS_UTILS_H
#include <string>
#include <vector>
#include <iostream>
#include "Gestao.h"

using namespace std;

class Utils{
public:
	static int getNum(const string&  label);
	static string getString(const string&  label);

	template <class T>
	static int searchOrderedVector(const vector<T> &vetor, const unsigned int& id){
		//A classe do vetor que estamos a passar precisa de ter defenido a função getNome()
		/*Algoritmo de pesquisa binária
            (o vetor "vetor" precisa de estar ordenado em ordem numérica (id)*/
		size_t arraysize = vetor.size();
		int mid = arraysize / 2;
		while (true) {
			T este = vetor.at(mid);
            unsigned int searchId = este.getId();

			if (searchId == id) {
				return mid;
			}
			else {
				if (searchId < id){
                    if (mid == arraysize - 2) mid = arraysize - 1;
					else mid = arraysize - mid/2;
				}
				else{
					if(mid == 1) mid = 0;
					mid = mid - mid/2;
				}
			}
		}
	}

	static int searchForPID(const vector<Gestao> &vetor, const unsigned int &id);

	template<class T>
	static void addOrderedVector(vector<T> &vetor,T &obj){
		if(vetor.empty()){
			vetor.push_back(obj);
			return;
		}
		size_t mid = vetor.size() / 2 - 1, lowerBound = 0, upperBound = vetor.size() - 1;
		if(mid>vetor.size()/2){
			mid = 0; //scuffed solution
		}
        unsigned int insertTarget = obj.getId();
		while(true)
		{

			if(vetor.at(vetor.size() - 1).getId()< insertTarget) {
				vetor.insert(vetor.end(), obj);

				break;
			}

			else if(vetor.at(0).getId() > insertTarget) {
				vetor.insert(vetor.begin(), obj);

				break;
			}
			if(vetor.at(mid).getId() == insertTarget) break;
			else if(vetor.at(mid).getId() < insertTarget) {

				if(vetor.at(mid + 1).getId() > insertTarget) {
					vetor.insert(vetor.begin() + (mid + 1), obj);
					break;
				}
				else
				{
					lowerBound = mid;
				}

			}
			else
			{
				if(vetor.at(mid).getId() < insertTarget) {
					vetor.insert(vetor.begin() + (mid - 1), obj);
					break;
				}
				else
				{
					upperBound = mid;
				}

			}
			mid = (upperBound + lowerBound) / 2;
		}
	}
};

#endif //HEADERS_VIEWS_UTILS_H
// anoiniman was here |727|
