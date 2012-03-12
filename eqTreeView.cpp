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
