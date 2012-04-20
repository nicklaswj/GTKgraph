#include "mainWindow.h"

mainWindow::mainWindow()
{
	//init layout boxes
	mainBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0);
	upperBox = new Gtk::Box();
	lowerBox = new Gtk::Box();
	toolbarBox = new Gtk::VBox();
	eqPaned = new Gtk::HPaned();
	commandAlign = new Gtk::Alignment();
	
	eqView = new eqTreeView();
	
	test1 = new Gtk::Button();
	test2 = new Gtk::Button();
	eqPaned->add1(*eqView);
	eqPaned->add2(*test2);
	
	
	//init commandline
	commandAlign->set_padding(0,0,0,15);
	commandLine = new Gtk::Entry();
	commandAlign->add(*commandLine);
	
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
		"	<toolbar name='ToolBar'>"
		"		<toolitem action='FileOpen'/>"
		"	</toolbar>"
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
	
	Gtk::Widget *toolBar = refUIManager->get_widget("/ToolBar");
	
	if(toolBar)
		toolbarBox->pack_start(*toolBar, Gtk::PACK_SHRINK);
	
	//Pack the upper and lower box
	mainBox->pack_start(*toolbarBox, false, false, 0);
	mainBox->pack_start(*upperBox);
	mainBox->pack_start(*lowerBox, false, false, 0);
	
	upperBox->pack_start(*eqPaned);
	
	lowerBox->pack_start(*commandAlign, true, true, 0);
	
	//Connect signals
	commandLine->signal_key_press_event().connect(sigc::mem_fun(*this, &mainWindow::commandLineKeyPress), false);
	
	
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

bool mainWindow::commandLineKeyPress(GdkEventKey* event)
{
	switch(event->keyval)
	{
		case GDK_KEY_Return:
			
			if(callFunc(commandLine->get_text()) == FUNC_NOT_FOUND)
			{
				equation *tmp = this->createEqFromStr(commandLine->get_text());
			
				if(tmp != 0)
				{
					eqView->addEquation(tmp);
				}
			}
			
			return true;
			break;
	}
	return false;
}

int mainWindow::callFunc(Glib::ustring str)
{
	Gtk::MessageDialog tempDialog(*this, "Error!");
	unsigned int leftBrace = str.find("(");
	unsigned int rightBrace = str.find(")");
	
	if(leftBrace > 2000000000)
	{
		tempDialog.set_secondary_text("Missing \"(\"");
		tempDialog.run();
		return SYNTAX_ERROR;
	}else if(rightBrace > 2000000000){
		tempDialog.set_secondary_text("Missing \")\"");
		tempDialog.run();
		return SYNTAX_ERROR;
	}else if(leftBrace > rightBrace){
		tempDialog.set_secondary_text("Syntax error near )");
		tempDialog.run();
		return SYNTAX_ERROR;
	}else if(leftBrace == 0){
		tempDialog.set_secondary_text("No function name given");
		tempDialog.run();
		return SYNTAX_ERROR;
	}else{
		Glib::ustring funcName = str.substr(0, leftBrace);
		Glib::ustring rawArg = str.substr(leftBrace+1, rightBrace);
		
		if(funcName == "del")
		{
			if(this->eqView->removeByName(rawArg) == false)
			{
				tempDialog.set_secondary_text("No funtion to delete");
				tempDialog.run();
			}
			return FUNC_HANDLED;
		}else{
			if(this->eqView->getEqByName(funcName))
			{
				equation *tmpEq = this->eqView->getEqByName(funcName);
				double number = strtod(rawArg.c_str(),NULL);
				number = tmpEq->getYFromX(number);
				printf("%f", number);
				
			}else{
				return FUNC_NOT_FOUND;
			}
		}
	}
}

equation* mainWindow::createEqFromStr(Glib::ustring str)
{
	Gtk::MessageDialog tempDialog(*this, "Error!");
	unsigned int equalPos = commandLine->get_text().find("=");
	
	//check for = sign else give a error
	if(equalPos > 2000000000)
	{
		tempDialog.set_secondary_text("No \"=\" found");
		tempDialog.run();
		return 0;
	}else{
		//Now substring the str form equalPos
		Glib::ustring leftSide = str.substr(0, equalPos);
		
		//now find the function variable
		unsigned int firstBrace = leftSide.find("(");
		//if this is zero, no function name is given.
		if(firstBrace == 0)
		{
			tempDialog.set_secondary_text("No function name is given");
			tempDialog.run();
			return 0;
		}else{
			//if ( is not found error
			if(firstBrace > 2000000000)
			{
				tempDialog.set_secondary_text("Missing \"(\" in function name");
				tempDialog.run();
				return 0;
			}
			
			
			Glib::ustring afterBrace = leftSide.substr(firstBrace);
			if(afterBrace.length() != 3)
			{
				tempDialog.set_secondary_text("Syntax error in variable name");
				tempDialog.run();
				return 0;
			}
			
			Glib::ustring variableName = afterBrace.substr(1,1);
			Glib::ustring functionName = leftSide.substr(0, firstBrace);
			
			Glib::ustring rightSide = str.substr(equalPos+1);
			
			equation *tempEq = new equation();
			tempEq->setName(functionName);
			tempEq->setEquation(rightSide);
			tempEq->setVariable(variableName);
			return tempEq;
		}
	}
}