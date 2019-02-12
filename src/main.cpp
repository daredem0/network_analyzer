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
#include "../header/definitions.h"


using namespace std;
Gui *gui =  new Gui();

/*extern "C" void btn_setIP_clicked(GtkButton *button, Gui *data){
    GtkEntry *startIP;
    GtkEntry *endIP;
    startIP = (GtkEntry *)gui->gui_get_ui_element("entr_startIP");
    endIP = (GtkEntry *)gui->gui_get_ui_element("entr_endIP");
    cout << "Start IP: " << gtk_entry_get_text(startIP) << endl;
    cout << "End IP: " << gtk_entry_get_text(endIP) << endl;
}*/

int main(int argc, char *argv[]) { 
    std::cout << "test1" << endl;
    GObject *window;
    gtk_init(&argc, &argv);
    gui->gui_init();
    cout << gui << endl;
    window = (GObject *) gui->gui_get_ui_element("mywindow");
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    delete gui;
    return 0;
}
