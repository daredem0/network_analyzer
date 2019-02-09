/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gui.h
 * Author: Florian Leuze
 *
 * Created on 9. Februar 2019, 16:43
 */

#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>

#define UI_DEFINITIONS_FILE "./GUI/test_glade_002.glade"
//#define GET_UI_ELEMENT(TYPE, ELEMENT)   TYPE *ELEMENT = (TYPE *) gui_get_ui_element(#ELEMENT);

class Gui {
public:
    GtkBuilder *definitions;
    GSList *objects;
    Gui();
    Gui(const Gui& orig);
    virtual ~Gui();
    GObject *gui_get_ui_element(const gchar *name);
private:
};
void gui_init(Gui *gui);



    
#endif /* GUI_H */

