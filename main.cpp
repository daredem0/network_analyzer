/* 
 * File:   main.cpp
 * Author: Florian Leuze
 * E-Mail: FlorianLeuze@aol.com
 * Universität Stuttgart
 *
 * Created on 5. Februar 2019, 10:19
 */

#include <cstdlib>
#include <gtk/gtk.h>
#include <iostream>

using namespace std;


extern "C" void btn_setIP_clicked();

int main(int argc, char *argv[]) { 
    std::cout << "test1" << endl;
    GtkBuilder *builder;
    GObject *window;
    gtk_init(&argc, &argv);
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "./GUI/test_glade_002.glade", NULL);
    window = gtk_builder_get_object (builder, "mywindow");
    gtk_builder_connect_signals (builder, NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_object_unref (G_OBJECT (builder));
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}

extern "C" void btn_setIP_clicked(){
    
}