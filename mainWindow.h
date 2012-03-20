#include <gtkmm.h>
#include <iostream>
#include "eqTreeView.h"
#include <vector>

#define FUNC_NOT_FOUND		0
#define SYNTAX_ERROR		1
#define FUNC_HANDLED		2


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
	eqTreeView *eqView;
	
	Gtk::Button *test1;
	Gtk::Button *test2;
	
	Glib::RefPtr<Gtk::UIManager> refUIManager;
	Glib::RefPtr<Gtk::ActionGroup> refActionGroup;
	Glib::RefPtr<Gtk::RadioAction> refChoiceOne, m_refChoiceTwo;

	void quitWindow();
	void openSaved();
	bool commandLineKeyPress(GdkEventKey*);
	
private:
	equation* createEqFromStr(Glib::ustring str);
	int callFunc(Glib::ustring str);
};
