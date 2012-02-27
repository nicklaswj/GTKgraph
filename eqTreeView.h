#include <gtkmm.h>

class eqTreeView : public Gtk::TreeView
{
public:
	eqTreeView(void);
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
	}
	
	eqTreeViewCol Cols;
	
	Glib::RefPtr<Gtk::TreeStore> refTreeModel
	
}

