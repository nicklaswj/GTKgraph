#include <gtkmm.h>

class mainWindow : public Gtk::Window
{
public:
	mainWindow();
	virtual ~mainWindow();
protected:
	Gtk::Box *mainBox;
	Gtk::Box *upperBox;
	Gtk::Box *lowerBox;

	Gtk::Entry *commandLine;
	
	Gtk::HPaned *eqPaned;
	Gtk::Button *test1;
	Gtk::Button *test2;
};
