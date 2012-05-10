#include "graphView.h"

graphView::graphView(){
	this->tree = NULL;
}

graphView::~graphView(){
	
}

void graphView::setTree(eqTreeView *eqTree)
{
	this->tree = eqTree;
}

void graphView::redraw(){
	Glib::RefPtr<Gdk::Window> win = this->get_window();
	if(win)
	{
		Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
		win->invalidate_rect(r, false);
	}
}

bool graphView::on_draw(const Cairo::RefPtr<Cairo::Context>& cr){
	
	//Get the allocation of our widget, and get the height and width from it
	Gtk::Allocation wAllocation = this->get_allocation();
	const int wHeight = wAllocation.get_height();
	const int wWidth = wAllocation.get_width();
	
	const double lineWidth = wHeight;
	
	//scale the Cario context obj to the current wHeight and wWidth
	//cr->scale(wWidth, wHeight);
	//now change the offset point coordinates, so point (0,0) will be at (0.5,0.5)
	cr->translate(wWidth/2, wHeight/2);
	//set the line width to 2 px, this should be a settings for each graph in the futur
	cr->set_line_width(1);
	
	//paint the background white
	cr->set_source_rgb(1,1,1);
	cr->paint();
	
	//draw the coordinatesystem
	cr->set_source_rgb(0,0,0);
	cr->move_to(0,0);
	cr->line_to(wWidth,0);
	cr->move_to(0,0);
	cr->line_to(0,wHeight);
	cr->move_to(0,0);
	cr->line_to(-1*wWidth,0);
	cr->move_to(0,0);
	cr->line_to(0,-1*wHeight);
	
	//draw the axes unit, again this should't be hardcoded in the futur
	cr->move_to(0,0);
	
	for(int i = 1; i <= 25; i++)
	{
		cr->move_to((wWidth*0.5/25)*i,0);
		cr->rel_move_to(0, -8);
		cr->rel_line_to(0,16);
		cr->rel_move_to(0, -8);
		
		cr->move_to((wWidth*0.5/25)*-i,0);
		cr->rel_move_to(0, -8);
		cr->rel_line_to(0,16);
		cr->rel_move_to(0, -8);
		
	}
	
	cr->move_to(0, 0);
	
	for(int i = 1; i <= 25; i++)
	{
		cr->move_to(0,(wHeight*0.5/25)*i);
		cr->rel_move_to(-8,0);
		cr->rel_line_to(16,0);
		cr->rel_move_to(-8,0);
		
		cr->move_to(0,(wHeight*0.5/25)*-i);
		cr->rel_move_to(-8,0);
		cr->rel_line_to(16,0);
		cr->rel_move_to(-8,0);
		
	}
	
	cr->stroke();
	
	cr->set_source_rgb(0.8,0,0);
	if(this->tree)
	{
		cr->set_line_width(3);
		std::vector<equation*> eqs = this->tree->getEquations();
		
		double pxWidth = wWidth/50;
		double pxHeight = wHeight/50;
		
		for(int i = 0; i < eqs.size(); i++){
			
			equation *eq = eqs[i];
			
			for(double x = -25; x<= 25; x+= 0.01)
			{
				double y = eq->getYFromX(x);
				
				cr->move_to(x*pxWidth,-1*(y*pxHeight));
				cr->rel_line_to(1,1);
			}
			cr->stroke();
		}
	}
	
	return true;
}