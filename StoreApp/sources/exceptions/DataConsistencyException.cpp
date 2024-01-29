#include "DataConsistencyException.h"

DataConsistencyException::DataConsistencyException(string data){
    this->data = "Erro: ["+ data + "] consistencia de dados";
}

const char* DataConsistencyException::what(){
    return this->data.c_str();
}
