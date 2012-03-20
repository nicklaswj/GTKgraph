#include "equation.h"

equation::equation()
{
}

equation::~equation()
{
}

bool equation::setEquation(Glib::ustring eqString)
{
	//keep the original expression
	this->equationString = eqString;
	
	//vector<
	
	for(int i = 0; i < eqString.length(); i++)
	{
		
	}
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