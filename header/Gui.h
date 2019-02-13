/**
 * @file Gui.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 09.02.2019
 * @brief Class that organises gui, workers and signal handlers
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

