#include "DuplicatedDataException.h"


DuplicatedDataException::DuplicatedDataException(string data){
	this->data = "Erro: ["+ data + "] duplicado";
}

const char* DuplicatedDataException::what(){
	return this->data.c_str();
}
