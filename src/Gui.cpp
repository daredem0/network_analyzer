/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gui.cpp
 * Author: Florian Leuze
 * 
 * Created on 9. Februar 2019, 16:43
 */

#include "../header/Gui.h"
extern Gui* gui;

Gui::Gui() {
    data = new Data();
}

Gui::Gui(const Gui& orig) {
}

Gui::~Gui() {
    delete data;
}

GObject *Gui::gui_get_ui_element(const gchar * name)
{
    const gchar *s;
    GSList *list;
    int temp = 0;

    list = this->objects;
    do{
        s = gtk_buildable_get_name((GtkBuildable *)list->data);
        ++temp;
        if (strcmp (s, name) == 0) {
            return (GObject *)list->data;
        }

    } while (list = g_slist_next(list));
    return NULL;
}   
    
void Gui::gui_init()
{
    GObject *window;
    GError *err = NULL;
    
    this->definitions = gtk_builder_new ();
    
    gtk_builder_add_from_file(this->definitions, UI_DEFINITIONS_FILE, &err);
    
    if (err != NULL) {
        g_printerr("Error while loading app definitions file: %s\n", err->message);
        g_error_free (err);
        gtk_main_quit ();
    }
    
    gtk_builder_connect_signals(this->definitions, this);
    
    this->objects = gtk_builder_get_objects(this->definitions);
    gtk_entry_set_text((GtkEntry *)this->gui_get_ui_element("entr_startIP"), "192.168.1.1");
    gtk_entry_set_text((GtkEntry *)this->gui_get_ui_element("entr_endIP"), "192.168.1.50");
    window = (GObject *) this->gui_get_ui_element("mywindow");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}