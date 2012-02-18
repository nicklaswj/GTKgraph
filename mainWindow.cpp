#include "mainWindow.h"

mainWindow::mainWindow()
{
	//init layout boxes
	mainBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0);
	upperBox = new Gtk::Box();
	lowerBox = new Gtk::Box();
	toolbarBox = new Gtk::Box();
	eqPaned = new Gtk::HPaned();
	commandAlign = new Gtk::Alignment();
	
	test1 = new Gtk::Button();
	test2 = new Gtk::Button();
	eqPaned->add1(*test1);
	eqPaned->add2(*test2);
	
	
	//init commandline
	commandAlign->set_padding(0,0,0,15);
	commandLine = new Gtk::Entry();
	
	//initial the window
	set_border_width(0);
	resize(300,400);
	
	//Init toolbar and menu
	refActionGroup = Gtk::ActionGroup::create();
	
		//filemenu
		refActionGroup->add(Gtk::Action::create("FileMenu", "File"));
		refActionGroup->add(Gtk::Action::create("FileOpen", Gtk::Stock::OPEN),
			sigc::mem_fun(*this, &mainWindow::openSaved)
		);
		
		refActionGroup->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
				    sigc::mem_fun(*this, &mainWindow::quitWindow)
		);
		
	//Init UIManager
	refUIManager = Gtk::UIManager::create();
	refUIManager->insert_action_group(refActionGroup);
	
	Glib::ustring ui_info = 
		"<ui>"
		"	<menubar name='MenuBar'>"
		"		<menu action='FileMenu'>"
		"			<menuitem action='FileOpen'/>"
		"			<separator/>"
		"			<menuitem action='FileQuit'/>"
		"		</menu>"
		"	</menubar>"
		"</ui>";
		
	try
	  {
	    refUIManager->add_ui_from_string(ui_info);
	  }
	  catch(const Glib::Error& ex)
	  {
	    std::cerr << "building menus failed: " <<  ex.what();
	  }
	  
	
	Gtk::Widget *MenuBar = refUIManager->get_widget("/MenuBar");
	
	if(MenuBar)
		toolbarBox->pack_start(*MenuBar, Gtk::PACK_SHRINK);
	
	//Pack the upper and lower box
	mainBox->pack_start(*toolbarBox, false, false, 0);
	mainBox->pack_start(*upperBox);
	mainBox->pack_start(*lowerBox, false, false, 0);
	
	upperBox->pack_start(*eqPaned);
	lowerBox->pack_start(*commandLine, true, true, 10);
	
	
	//add and show children
	
	add(*mainBox);
	show_all_children();
}

mainWindow::~mainWindow()
{
}

void mainWindow::quitWindow()
{
	hide();
}

void mainWindow::openSaved()
{
}