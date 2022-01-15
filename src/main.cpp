/**
 * @file main.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 05.02.2019
 * @brief Main Function network analyzer. Mainly ochestrates the init and gui creation
 */
#include "../header/Gui.h"
#include "../header/callbacks.h"


using namespace std;

int main(int argc, char *argv[]) { 
    GObject *window;
    Gui *gui =  new Gui();
    gtk_init(&argc, &argv);
    gui->gui_init();
    window = (GObject *) gui->gui_get_ui_element("mywindow");
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    delete gui;
    return 0;
}