#include <gtkmm.h>
#include "equation.h"
#include <vector>

class eqTreeView : public Gtk::TreeView
{
public:
	eqTreeView(void);
	Gtk::TreeModel::Row addRow(bool Tchecked, Glib::ustring Tname, Glib::ustring Tstring);
	Gtk::TreeModel::Row addRow(Glib::ustring Tname, Glib::ustring Tstring);
	
	void addEquation(equation *eq);
	
	void removeSelected();
	bool removeByName(Glib::ustring name);
	equation* getEqByName(Glib::ustring name);
	Glib::RefPtr<Gtk::TreeStore> refTreeModel;
	std::vector<equation*> getEquations();
	
private:
protected:
	class eqTreeViewCol : public Gtk::TreeModel::ColumnRecord 
	{
	public:
		eqTreeViewCol()
		{
			add(eqEnabled);
			add(eqName);
			add(eqString);
			add(equationPrt);
		}
		
		Gtk::TreeModelColumn<bool> eqEnabled;
 		Gtk::TreeModelColumn<Glib::ustring> eqName;
		Gtk::TreeModelColumn<Glib::ustring> eqString;
		Gtk::TreeModelColumn<equation*> equationPrt;
	};
	
	eqTreeViewCol Cols;
	
	//pointer for the rightClick menu
	Glib::RefPtr<Gtk::UIManager> menuUIManager;
	Glib::RefPtr<Gtk::ActionGroup> menuActionGroup;
	
	Gtk::Menu* menuPopup;
	
	void eqClicked(GdkEventButton* event);
	
	void slotDeleteEquation();
	
};

