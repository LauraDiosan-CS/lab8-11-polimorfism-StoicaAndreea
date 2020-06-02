#include "BombaValidator.h"
using namespace std;

BombaException::BombaException(vector<string>_errors) : errors{ _errors } {}

vector<string> BombaException::getErrors() const {
	return this -> errors;
}

void BombaValidator::validate(Bomba& b) {
	vector<string> errors;
	if (!((b.getX() >= 0) && (b.getX() < 10) && (b.getY() >= 0) && (b.getY() < 10))) {
		errors.push_back(string("The bomb is outside of the play ground \n"));
	}

	if (errors.size() > 0) throw BombaException(errors);
}