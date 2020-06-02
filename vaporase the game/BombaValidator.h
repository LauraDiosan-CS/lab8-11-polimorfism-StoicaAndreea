#pragma once
#include"Bomba.h"
#include <string>
#include<vector>
using namespace std;

class BombaException
{
private:
    vector<string>errors;
public:
    BombaException(vector<string> _errors);
    vector<string> getErrors() const;
};

class BombaValidator {
public:
    BombaValidator() {};
    void validate(Bomba& m);
};