/**
 * @file Gui.cpp.
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 09.02.2019
 * @brief Gui class cpp file
 */

#include "../header/Gui.h"

const std::string Gui::first = "192.168.1.1";
const std::string Gui::last = "192.168.1.50";

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
    mutex m;
    m.lock();
    outputStream = new OutputStream();
    m.unlock();
    if(!g_thread_supported()){
        //g_thread_init(NULL);
        //gdk_threads_init();
        cout << "g_thread supported" << endl;
    }
    else{
        cout << "g_thread unsupported" << endl;
    }
    
    this->definitions = gtk_builder_new ();
    
    gtk_builder_add_from_file(this->definitions, UI_DEFINITIONS_FILE_BACKUP, &err);
    if (err != NULL) {
        g_printerr("Error while loading app definitions file: %s\n", err->message);
        g_error_free (err);
        GError *err = NULL;
        gtk_builder_add_from_file(this->definitions, UI_DEFINITIONS_FILE, &err);
        if (err != NULL) {
            g_error_free(err);
            gtk_main_quit ();
        }
    }
    
    gtk_builder_connect_signals(this->definitions, this);
    
    this->objects = gtk_builder_get_objects(this->definitions);
    gtk_entry_set_text((GtkEntry *)this->gui_get_ui_element("entr_startIP"), Gui::first.c_str());
    gtk_entry_set_text((GtkEntry *)this->gui_get_ui_element("entr_endIP"), Gui::last.c_str());
    window = (GObject *) this->gui_get_ui_element("mywindow");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}