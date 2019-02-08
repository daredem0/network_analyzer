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

using namespace std;

static void entr_endIP_changed_cb(void);
static void entr_endIP_insert_text_cb(void);
static void entr_startIP_changed_cb(void);
static void entr_startIP_changed_cb(void);

int main(int argc, char *argv[]) { 
    GtkBuilder *builder;
    GObject *window;
    gtk_init(&argc, &argv);
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "test_glade_002.glade", NULL);
    window = gtk_builder_get_object (builder, "mywindow");
    gtk_builder_connect_signals (builder, NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_object_unref (G_OBJECT (builder));
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}

static void entr_endIP_changed_cb(void);
static void entr_endIP_insert_text_cb(void);
static void entr_startIP_changed_cb(void);
static void entr_startIP_changed_cb(void);