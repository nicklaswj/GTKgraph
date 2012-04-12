#include <gtkmm.h>
#include <iostream>
#include <muParser.h>


class equation
{
	
private:
	Glib::ustring equationString;
	Glib::ustring funcName;
	Glib::ustring variableName;
	
	double variable;
	
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