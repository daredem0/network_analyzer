/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../header/callbacks.h"

using namespace std;

extern "C" void btn_setIP_clicked(GtkButton *button, Gui *data){
    GtkEntry *startIP;
    GtkEntry *endIP;
    startIP = (GtkEntry *)gui->gui_get_ui_element("entr_startIP");
    endIP = (GtkEntry *)gui->gui_get_ui_element("entr_endIP");
    cout << "Start Information " << gtk_entry_get_text(startIP) << endl;
    cout << "End Information: " << gtk_entry_get_text(endIP) << endl;
    gui->data->setIP(gtk_entry_get_text(startIP), gtk_entry_get_text(endIP));
    gui->data->checkIP();
}

extern "C" void btnInfo_clicked(GtkButton *button, Gui *data){
    cout << "This is information from the data object" << endl;
    cout << "Start IP: " << gui->data->firstIP_toString() << endl;
    cout << "Last IP: " << gui->data->lastIP_toString() << endl;
}