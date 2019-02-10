/* 
 * File:   main.cpp
 * Author: Florian Leuze
 * E-Mail: FlorianLeuze@aol.com
 * Universität Stuttgart
 *
 * Created on 5. Februar 2019, 10:19
 */

#include <cstdlib>
#include <iostream>
#include "../header/Gui.h"

Gui* gui = new Gui();

using namespace std;

extern "C" void btn_setIP_clicked(GtkButton *button, Gui *data){
    string test;
    cout << "test" << endl;
    /*string test;
    GET_UI_ELEMENT (GtkEntry, entr_startIP);*/
    cout << gtk_buildable_get_name((GtkBuildable *)button) << endl;
    //GtkEntry *startIP;
    //startIP = (GtkEntry *)gui->gui_get_ui_element("btn_setIP");
    //cout << "handler: " << gtk_entry_get_text(startIP) << endl;
    cout << "test b" << endl;
    cout << gui << endl;
    cout << data << endl;
}

int main(int argc, char *argv[]) { 
    std::cout << "test1" << endl;
    //GtkBuilder *builder;
    GObject *window;
    gtk_init(&argc, &argv);
    //builder = gtk_builder_new();
    //gtk_builder_add_from_file(builder, "./GUI/test_glade_002.glade", NULL);
    //window = gtk_builder_get_object (builder, "mywindow");
    //gtk_builder_connect_signals (builder, NULL);
    //g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //g_object_unref (G_OBJECT (builder));
    gui->gui_init();
    cout << gui << endl;
    window = (GObject *) gui->gui_get_ui_element("mywindow");
    //GtkEntry *startIP;
    //startIP = (GtkEntry *) gui->gui_get_ui_element("entr_startIP");
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    delete gui;
    return 0;
}
