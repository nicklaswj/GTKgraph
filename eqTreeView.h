#include <gtkmm.h>

class eqTreeView : public Gtk::TreeView
{
public:
	eqTreeView(void);
	addRow(bool Tchecked, Glib::ustring Tname, Glib::ustring Tstring);
	addRow(Glib::ustring Tname, Glib::ustring Tstring);
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
		}
		
		Gtk::TreeModelColumn<bool> eqEnabled;
 		Gtk::TreeModelColumn<Glib::ustring> eqName;
		Gtk::TreeModelColumn<Glib::ustring> eqString;
	};
	
	eqTreeViewCol Cols;
	
	Glib::RefPtr<Gtk::TreeStore> refTreeModel;
	
};

