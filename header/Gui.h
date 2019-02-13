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
#include <forward_list>
#include <iostream>
#include <string>
#include "../header/Data.h"
#include "../header/OutputStream.h"

#define UI_DEFINITIONS_FILE "./GUI/test_glade_002.glade"

class Gui {
public:
    GtkBuilder *definitions;
    GSList *objects;
    Data *data;
    Gui();
    Gui(const Gui& orig);
    virtual ~Gui();
    void gui_init();
    GObject *gui_get_ui_element(const gchar *name);
    OutputStream *getOutput();
private:
    void outputWorker(void* data);
    OutputStream *outputStream;
};

#endif /* GUI_H */

