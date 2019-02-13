/* 
 * File:   main.cpp
 * Author: Florian Leuze
 * E-Mail: FlorianLeuze@aol.com
 * Universität Stuttgart
 *
 * Created on 5. Februar 2019, 10:19
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
