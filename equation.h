#include <gtkmm.h>
#include <iostream>


#define isNumber(x)	(x >= "0" && x <= "9")
#define isOperator(x)	(x == '*' || x == '/' || x == '^' || x == '-'  || x == '+')

#define LEFT	1
#define RIGHT	2

typedef struct calcItem {
	unsigned char type;
	long double number;
	unsigned char operation;
} calcItem;

class equation
{
	
private:
	Glib::ustring equationString;
	Glib::ustring funcName;
	Glib::ustring variableName;
	Glib::ustring RPN;
	
	int pO(Glib::ustring oper);
	int opAssoc(Glib::ustring oper);
	
	//vector<calcItem> operationList;
	//vector<double long> sumList;
public:
	equation();
	~equation();
	
	bool setEquation(Glib::ustring eqString);
	int getYFromX(float x);
	void setName(Glib::ustring name);
	void setVariable(Glib::ustring name);
	
	Glib::ustring getName();
	Glib::ustring getVariable();
	Glib::ustring getEquation();
protected:

};