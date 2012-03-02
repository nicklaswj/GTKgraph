#include "eqTreeView.h"

eqTreeView::eqTreeView(){
	//create treeView
	this->refTreeModel = Gtk::TreeStore::create(this->Cols);
	this->set_model(this->refTreeModel);
	
	//appendColunms
	this->append_column(" ", Cols.eqEnabled);
	this->append_column("Name", Cols.eqName);
	this-append_column("String", Cols.eqString);
} 
