/**
 * @file Gui.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 09.02.2019
 * @brief Gui class header
 */


#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>
#include <forward_list>
#include <iostream>
#include <string>
#include "../header/Data.h"
#include "../header/OutputStream.h"

#define UI_DEFINITIONS_FILE "./GUI/test_glade_002.glade" /**< Defines the path to the gui-xml file. For convenience and tidiness.*/
#define UI_DEFINITIONS_FILE_BACKUP "../../../GUI/test_glade_002.glade"
/**
 *@brief The Gui class handles most of the initialization of the program. it loads all gui objects and stores them. 
 * Furthermore it implements the methods needed to access each ui element and organises workers and handlers.
 */
class Gui {
public:
    //CONSTRUCTORS/DECONSTRUCTORS/************************************************************/
    /**
    * @brief Standard constructor. Also builds a new data object
    */
    Gui();
    /**
    * @brief Standard copy constructor. __Copy for data object still needs to be implemented__
    */
    Gui(const Gui& orig);
    /**
    * @brief Standard deconstructor. Deletes data object. 
    */
    virtual ~Gui();
    /**
    * @brief Initializes the gui. outputStream will be built, gtk_builder is called and loaded, signals are connected. Just rudimentary error handlign implemented.
    */
    void gui_init();
    /**
    * @brief method that will return the GObject corresponding to the gchar in parameter list
    * @param const gchar *name - name of the ui element that shall be returned
    */
    GObject *gui_get_ui_element(const gchar *name);
    /**
    * @brief Initializes the gui. outputStream will be built, gtk_builder is called and loaded, signals are connected. Just rudimentary error handlign implemented.
    */
    static const std::string first; /**< Constant definition for first ip address that is preset. Defined in Gui.cpp*/
    static const std::string last;/**< Constant definition for last ip addresss that is preset. Defined in Gui.cpp*/
    Data *data; /**< Data container. Outdaded and should be exchanged through a Network type object soon*/
    GtkBuilder *definitions; /**< Contains the GtkBuilder which loads the gui from the xml file*/
    GSList *objects; /**< Contains all objects that were loaded through the GtkBuilder*/
private:
    OutputStream *outputStream; /**< outputstream object to make cout thread safe __still somewhat buggy__*/
};

#endif /* GUI_H */

