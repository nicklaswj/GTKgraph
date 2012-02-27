#include "eqTreeView.h"

eqTreeView::eqTreeView(){
	this->refTreeModel = Gtk::TreeStore::create(this->Cols);
	this->set_model(this->refTreeModel);
} 
