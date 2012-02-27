#include <gtkmm.h>
#include <iostream>
#include <eqTreeView.h>

class mainWindow : public Gtk::Window
{
public:
	mainWindow();
	virtual ~mainWindow();
protected:
	Gtk::Box *mainBox;
	Gtk::Box *upperBox;
	Gtk::Box *lowerBox;
	Gtk::VBox *toolbarBox;
	
	Gtk::Alignment *commandAlign;

	Gtk::Entry *commandLine;
	
	Gtk::HPaned *eqPaned;
	Gtk::Button *test1;
	Gtk::Button *test2;
	
	Glib::RefPtr<Gtk::UIManager> refUIManager;
	Glib::RefPtr<Gtk::ActionGroup> refActionGroup;
	Glib::RefPtr<Gtk::RadioAction> refChoiceOne, m_refChoiceTwo;

	void quitWindow();
	void openSaved();
};
