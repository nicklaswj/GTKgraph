#include "mainWindow.h"

mainWindow::mainWindow()
{
	//init layout boxes
	mainBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0);
	upperBox = new Gtk::Box();
	lowerBox = new Gtk::Box();
	eqPaned = new Gtk::HPaned();
	
	test1 = new Gtk::Button();
	test2 = new Gtk::Button();
	eqPaned->add1(*test1);
	eqPaned->add2(*test2);
	
	
	//init commandline
	commandLine = new Gtk::Entry();
	
	//initial the window
	set_border_width(10);
	resize(300,400);
	
	
	//Pack the upper and lower box
	mainBox->pack_start(*upperBox);
	mainBox->pack_start(*lowerBox, false, false, 0);
	
	upperBox->pack_start(*eqPaned);
	lowerBox->pack_start(*commandLine);
	
	
	//add and show children
	
	add(*mainBox);
	show_all_children();
}

mainWindow::~mainWindow()
{
}