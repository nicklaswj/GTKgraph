#include <gtkmm.h>

class equation
{
private:
	Glib::ustring equationString;
	Glib::ustring funcName;
	Glib::ustring variableName;
public:
	equation();
	~equation();
	
	void setEquation(Glib::ustring eqString);
	int getYFromX(float x);
	void setName(Glib::ustring name);
	void setVariable(Glib::ustring name);
	
	Glib::ustring getName();
	Glib::ustring getVariable();
	Glib::ustring getEquation();
protected:

};