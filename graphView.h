#include <gtkmm/drawingarea.h>
#include "eqTreeView.h"

class graphView : public Gtk::DrawingArea
{
public:
	graphView();
	~graphView();
	void redraw();
	void setTree(eqTreeView *eqTree);
	
private:
	eqTreeView *tree;
protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
};