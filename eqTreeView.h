#include <gtkmm.h>
#include "equation.h"

class eqTreeView : public Gtk::TreeView
{
public:
	eqTreeView(void);
	Gtk::TreeModel::Row addRow(bool Tchecked, Glib::ustring Tname, Glib::ustring Tstring);
	Gtk::TreeModel::Row addRow(Glib::ustring Tname, Glib::ustring Tstring);
	
	void addEquation(equation *eq);
	
	void removeSelected();
	bool removeByName(Glib::ustring name);
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
	
	Glib::RefPtr<Gtk::TreeStore> refTreeModel;
	
	//pointer for the rightClick menu
	Glib::RefPtr<Gtk::UIManager> menuUIManager;
	Glib::RefPtr<Gtk::ActionGroup> menuActionGroup;
	
	Gtk::Menu* menuPopup;
	
	void eqClicked(GdkEventButton* event);
	
	void slotDeleteEquation();
	
};

