#pragma once
#include"Vapor.h"
#include <string>
#include<vector>
using namespace std;

class VaporasException
{
private:
    vector<string>errors;
public:
    VaporasException(vector<string> _errors);
    vector<string> getErrors() const;
};

class VaporasValidator {
public:
    VaporasValidator() {};
    void validate(Vaporas*& m);
};