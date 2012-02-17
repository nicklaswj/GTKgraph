#include <gtkmm.h>
#include "mainWindow.h"

int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  mainWindow window;

  Gtk::Main::run(window);

  return EXIT_SUCCESS;
}