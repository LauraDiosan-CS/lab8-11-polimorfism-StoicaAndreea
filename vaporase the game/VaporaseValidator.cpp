#include "VaporaseValidator.h"
using namespace std;

VaporasException::VaporasException(vector<string>_errors) : errors{ _errors } {}

vector<string> VaporasException::getErrors() const {
	return this->errors;
}

void VaporasValidator::validate(Vaporas*& a) {
	vector<string> errors;
	if (a->getOrientareCoada() == "nord")
	{
		if (!((a->getX() >= 0) && (a->getY() >= 0) && (a->getY() + a->getLen() <= 10)))
		{
			errors.push_back(string("The boat is outside of the play ground \n"));
		}
	}
	else {
		if (a->getOrientareCoada() == "vest") {
			if (!((a->getX() >= 0) && (a->getX() + a->getLen() - 1 < 10) && (a->getY() >= 0))) {
				errors.push_back(string("The boat is outside of the play ground \n"));
			}
		}
		else {
			if (a->getOrientareCoada() == "est") {
				if (!((a->getX() < 10) && (a->getX() - a->getLen() + 1 >= 0) && (a->getY() < 10))) {
					errors.push_back(string("The boat is outside of the play ground \n"));
				}
			}
			else {
				if (a->getOrientareCoada() == "sud") {
					if (!((a->getX() < 10) && (a->getY() - a->getLen() + 1 >= 0) && (a->getY() <= 10))) {
						errors.push_back(string("The boat is outside of the play ground \n"));
					}
				}
				else { errors.push_back(string("the orientation is not valid \n")); }
			}
		}
	}
	if (errors.size() > 0) throw VaporasException(errors);
}