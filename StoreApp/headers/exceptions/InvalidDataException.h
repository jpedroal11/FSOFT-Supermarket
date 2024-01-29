#ifndef HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H_
#define HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H_

#include <exception>
#include <string>
using namespace std;

class InvalidDataException :public exception{
private:
	string data;
public:
	InvalidDataException(string data);

	const char* what();
};




#endif // HEADERS_EXCEPTIONS_INVALIDDATAEXCEPTION_H_
