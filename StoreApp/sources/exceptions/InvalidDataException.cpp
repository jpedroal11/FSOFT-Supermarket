#include "InvalidDataException.h"


InvalidDataException::InvalidDataException(string data){
	this->data = data;
}

const char* InvalidDataException::what(){
	string msg = "Erro: ["+ data + "] não é valido";
			return msg.c_str();
}

