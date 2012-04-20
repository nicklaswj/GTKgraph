#include "equation.h"

equation::equation()
{
	eqParser = new mu::Parser();
}

equation::~equation()
{
}

bool equation::setEquation(Glib::ustring eqString)
{
	//keep the original expression
	this->equationString = eqString;
	this->eqParser->SetExpr(eqString);
	
}
double equation::getYFromX(double x)
{
	this->variable = x;
	return this->eqParser->Eval();
}

void equation::setName(Glib::ustring name)
{
	this->funcName = name;
}

void equation::setVariable(Glib::ustring name)
{
	this->variableName = name;
	this->eqParser->DefineVar(name, &variable);
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