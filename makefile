OBJ = main.o mainWindow.o eqTreeView.o equation.o muparser_v2_2_2/src/muParser.o muparser_v2_2_2/src/muParserBase.o muparser_v2_2_2/src/muParserBytecode.o muparser_v2_2_2/src/muParserCallback.o muparser_v2_2_2/src/muParserError.o muparser_v2_2_2/src/muParserTokenReader.o 
INC=-Imuparser_v2_2_2/include/
CPPFLAGS = `pkg-config gtkmm-3.0 --cflags --libs` $(INC)
CXX = g++


GTKgraph : $(OBJ)
	g++ $(OBJ) -o GTKgraph $(CPPFLAGS)

main.o : mainWindow.h

mainWindow.o : mainWindow.h