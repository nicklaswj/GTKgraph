#include "equation.h"

equation::equation()
{
}

equation::~equation()
{
}

int equation::pO(Glib::ustring oper)
{
	if(oper == "*")
	{
		return 3;
	}else if(oper == "/"){
		return 3;
	}else if(oper == "^"){
		return 4;
	}else if(oper == "-"){
		return 2;
	}else if(oper == "+"){
		return 2;
	}
}

int equation::opAssoc(Glib::ustring oper)
{
	if(oper == "^")
	{
		return RIGHT;
	}else{
		return LEFT;
	}
}

bool equation::setEquation(Glib::ustring eqString)
{
	//keep the original expression
	this->equationString = eqString;
// 	
// 	std::vector<Glib::ustring> raw;
// 	
// 	std::vector<Glib::ustring> stack;
// 	std::vector<Glib::ustring> output;
// 	
// 	for(int i = 0; i < eqString.length(); i++)
// 	{
// 		Glib::ustring token = eqString.substr(i,i+1);
// 		if(raw.size() == 0)
// 		{
// 			raw.push_back(token);
// 		}else{
// 			if((isNumber(raw.back().substr(raw.back().size()-1, raw.back().size())) || 
// 				raw.back().substr(raw.back().size()-1, raw.back().size()) == ".") && isNumber(token))
// 			{
// 				raw[raw.size()-1].append(token);
// 			} else if(isNumber(token)){
// 				raw.push_back(token);
// 			} else if(isOperator(token)){
// 				Glib::ustring last = raw.back().substr(raw.back().size()-1, raw.back().size());
// 				if(isNumber(last))
// 				{
// 					raw.push_back(token);
// 				}else if(last == "."){
// 					raw.back().append("0");
// 					raw.push_back(token);
// 				}else if(isOperator(last))
// 				{
// 					return false;
// 				}
// 			} else if(token == ".")
// 			{
// 				Glib::ustring last = raw.back().substr(raw.back().size()-1, raw.back().size());
// 				if(isOperator(last))
// 				{
// 					raw.push_back("0");
// 					raw.back().append(token);
// 				}else if(isNumber(last))
// 				{
// 					raw.back().append(token);
// 				}
// 			}
// 		}
// 	}
// 	
// 	for(int i = 0; i < eqString.length(); i++)
// 	{
// 		Glib::ustring token = eqString.substr(i,i+1);
// 		
// 		if(isNumber(token))
// 		{
// 			output.push_back(token);
// 		}else if(isOperator(token)){
// 			if(stack.size() == 0)
// 			{
// 				stack.push_back(token);
// 			}else{
// 				if((opAssoc(token) == LEFT && pO(token) <= pO(stack.back())) || 
// 					(opAssoc(token) == RIGHT && pO(token) < pO(stack.back()))){
// 					
// 					output.push_back(stack.back());
// 					stack.pop_back();
// 				}
// 				stack.push_back(token);
// 			}
// 		}else if(token == "(")
// 		{
// 			stack.push_back(token);
// 		}else if(token == ")")
// 		{
// 			std::vector<Glib::ustring>::reverse_iterator iter;
// 			for(iter = stack.rbegin(); iter < stack.rend(); ++iter)
// 			{
// 				if(stack.size() != 0)
// 				{
// 					if(*iter == "("){
// 						stack.pop_back();
// 						break;
// 					}else{
// 						output.push_back(stack.back());
// 						stack.pop_back();
// 					}
// 				}else{
// 					return false;
// 				}
// 			}
// 		}
// 	}
// 	
// 	if(stack.size() > 0)
// 	{
// 		std::vector<Glib::ustring>::reverse_iterator iter;
// 		for(iter = stack.rbegin(); iter < stack.rend(); ++iter)
// 		{
// 			if(*iter == "(" || *iter == ")")
// 			{
// 				return false;
// 			}else{
// 				output.push_back(stack.back());
// 				stack.pop_back();
// 			}
// 		}
// 	}
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