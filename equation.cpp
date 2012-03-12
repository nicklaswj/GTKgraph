#include "equation.h"

equation::equation()
{
}

equation::~equation()
{
}

void equation::setEquation(Glib::ustring eqString)
{
	this->equationString = eqString;
}
int equation::getYFromX(float x)
{
	int y;
	
	return y;
}

void equation::setName(Glib::ustring name)
{
	this->funcName = name;
}

void equation::setVariable(Glib::ustring name)
{
	this->variableName = name;
}

Glib::ustring equation::getName(){
	return funcName;
}

Glib::ustring equation::getVariable(){
	return variableName;
}

Glib::ustring equation::getEquation(){
	return equationString;
}