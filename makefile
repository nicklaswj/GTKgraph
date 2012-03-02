OBJ = main.o mainWindow.o eqTreeView.o
CPPFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`
CXX = g++


GTKgraph : $(OBJ)
	g++ $(OBJ) -o GTKgraph $(CPPFLAGS)

main.o : mainWindow.h

mainWindow.o : mainWindow.h