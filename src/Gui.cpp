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
#include <forward_list>
#include <iostream>
#include <string>

Gui::Gui() {
}

Gui::Gui(const Gui& orig) {
}

Gui::~Gui() {
}

GObject *Gui::gui_get_ui_element(const gchar * name)
{

    std::cout << "you ended up here a" << std::endl;
    const gchar *s;
    GSList *list;
    int temp = 0;

    list = this->objects;
    do{
        std::cout << "you ended up here c: " << std::to_string(temp) << std::endl;
        std::cout << gtk_buildable_get_name((GtkBuildable *)list->data) << std::endl;
        s = gtk_buildable_get_name((GtkBuildable *)list->data);
        std::cout << "you ended up here c: " << std::to_string(temp) << std::endl;
        ++temp;
        if (strcmp (s, name) == 0) {
            return (GObject *)list->data;
        }

    } while (list = g_slist_next(list));
    std::cout << "you ended up here c" << std::endl;
    return NULL;
}   
    
void Gui::gui_init()
{
    std::cout << this << std::endl;
    GError *err = NULL;
    
    this->definitions = gtk_builder_new ();
    
    gtk_builder_add_from_file (this->definitions, UI_DEFINITIONS_FILE, &err);
    
    if (err != NULL) {
        g_printerr("Error while loading app definitions file: %s\n", err->message);
        g_error_free (err);
        gtk_main_quit ();
    }
    
    gtk_builder_connect_signals (this->definitions, this);
    std::cout << this << std::endl;
    
    this->objects = gtk_builder_get_objects(this->definitions);
}