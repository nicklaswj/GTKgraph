#include "eqTreeView.h"
#include <iostream>


eqTreeView::eqTreeView(){
	//create treeView model
	this->refTreeModel = Gtk::TreeStore::create(this->Cols);
	this->set_model(this->refTreeModel);
	
	//appendColunms
	this->append_column_editable(" ", Cols.eqEnabled);
	this->append_column("Name", Cols.eqName);
	this-append_column("String", Cols.eqString);
	this->signal_button_press_event().connect_notify(sigc::mem_fun(*this, &eqTreeView::eqClicked));
	
	//setup for right click menu
	menuActionGroup = Gtk::ActionGroup::create();
	
	menuActionGroup->add(Gtk::Action::create("Delete", "Delete"),
			       sigc::mem_fun(*this, &eqTreeView::slotDeleteEquation));
	
	menuUIManager = Gtk::UIManager::create();
	menuUIManager->insert_action_group(menuActionGroup);

	//add_accel_group(menuUIManager->get_accel_group());
	
	Glib::ustring ui_info =
        "<ui>"
        "  <popup name='rightMenu'>"
        "    <menuitem action='Delete'/>"
        "  </popup>"
        "</ui>";
	
	try
	{
		menuUIManager->add_ui_from_string(ui_info);
	}
	catch(const Glib::Error& ex)
	{
		std::cerr << "building menus failed: " <<  ex.what();
	}

	//Get the menu:
	menuPopup = dynamic_cast<Gtk::Menu*>(
		menuUIManager->get_widget("/rightMenu")); 
	
	if(!menuPopup)
		
	g_warning("menu not found");
} 

Gtk::TreeModel::Row eqTreeView::addRow(bool Tchecked, Glib::ustring Tname, Glib::ustring Tstring)
{
	Gtk::TreeModel::Row row = *(refTreeModel->append());
	row[this->Cols.eqEnabled] = Tchecked;
	row[this->Cols.eqName] = Tname;
	row[this->Cols.eqString] = Tstring;
	
	return row;
}

Gtk::TreeModel::Row eqTreeView::addRow(Glib::ustring Tname, Glib::ustring Tstring)
{
	return this->addRow(true, Tname, Tstring);
}

void eqTreeView::addEquation(equation *eq)
{
	//check for function with samme name
	Gtk::TreeModel::Children children = this->refTreeModel->children();
	for(Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); ++iter){
		Gtk::TreeModel::Row tmpRow = *iter;
		equation *tmpEq = tmpRow[this->Cols.equationPrt];
		if(eq->getName() == tmpEq->getName())
		{
			Gtk::MessageDialog dia("Function exist");
			dia.set_secondary_text("The function name already exist, please change the name of your function");
			dia.run();
			delete eq;
			return;
		}
	}
	
	Glib::ustring name = eq->getName();
	name.append("(");
	name.append(eq->getVariable());
	name.append(")");
	
	Gtk::TreeModel::Row row = this->addRow(true, name, eq->getEquation());
	row[this->Cols.equationPrt] = eq;
	
	return;
}

void eqTreeView::eqClicked(GdkEventButton* event)
{
	std::cerr << event->button;
	if((event->type == GDK_BUTTON_PRESS) && (event->button == 3)){
		menuPopup->popup(event->button, event->time);
	}else{
		
	}
}

void eqTreeView::slotDeleteEquation()
{
	this->removeSelected();
}

void eqTreeView::removeSelected()
{
	Glib::RefPtr<Gtk::TreeView::Selection> selectionRef;
	selectionRef = this->get_selection();
	
	Gtk::TreeModel::Row tmpRow = *(selectionRef->get_selected());
	equation *tmpEq = tmpRow[this->Cols.equationPrt];
	delete(tmpEq);
	
	refTreeModel->erase(selectionRef->get_selected());
}

bool eqTreeView::removeByName(Glib::ustring name)
{
	Gtk::TreeModel::Children children = this->refTreeModel->children();
	
	for(Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); ++iter){
		Gtk::TreeModel::Row row = *iter;
		equation *tmp = row[this->Cols.equationPrt];
		
		if(tmp->getName() == name)
		{
			delete(tmp);
			
			this->refTreeModel->erase(row);
			return true;
		}
	}
	return false;
}

std::vector<equation*> eqTreeView::getEquations()
{
	Gtk::TreeModel::Children children = this->refTreeModel->children();
	std::vector<equation*> eqVector;
	
	for(Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); ++iter){
		Gtk::TreeModel::Row row = *iter;
		equation *tmp = row[this->Cols.equationPrt];
		
		if(row[this->Cols.eqEnabled] == true)
		{
			eqVector.push_back(tmp);
		}
	}
	return eqVector;
}

equation* eqTreeView::getEqByName(Glib::ustring name)
{
	Gtk::TreeModel::Children children = this->refTreeModel->children();
	
	for(Gtk::TreeModel::Children::iterator iter = children.begin(); iter != children.end(); ++iter){
		Gtk::TreeModel::Row row = *iter;
		equation *tmp = row[this->Cols.equationPrt];
		
		if(tmp->getName() == name)
		{
			
			return tmp;
		}
	}
	return false;
}
