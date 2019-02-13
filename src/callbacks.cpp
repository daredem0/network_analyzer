/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../header/callbacks.h"

using namespace std;

extern "C" void btnSetIP_clicked(GtkButton *button, Gui *gui){
    GtkEntry *startIP;
    GtkEntry *endIP;
    startIP = (GtkEntry *)gui->gui_get_ui_element("entr_startIP");
    endIP = (GtkEntry *)gui->gui_get_ui_element("entr_endIP");
    if(gtk_entry_get_text(endIP)[0] != '\0' && gtk_entry_get_text(startIP)[0] != '\0'){
        cout << "Start Information " << gtk_entry_get_text(startIP) << endl;
        cout << "End Information: " << gtk_entry_get_text(endIP) << endl;
        gui->data->setIPRange(gtk_entry_get_text(startIP), gtk_entry_get_text(endIP));
        gui->data->ip->checkIP();
    }
    else
        cout << "Please set values for both Addresses" << endl;
}

extern "C" void btnInfo_clicked(GtkButton *button, Gui *gui){
    cout << "This is information from the data object" << endl;
    cout << "Start IP: " << gui->data->ip->firstIP_toString() << endl;
    cout << "Last IP: " << gui->data->ip->lastIP_toString() << endl;
    cout << "Another test" << endl;
    
    int *ip = gui->data->ip->getIP();
    cout << "First IP should be: ";
    for(int i = 0; i < 4; ++i){
        cout << to_string(*(ip + i));
        if(i < 3)
            cout << ".";
    }
    
    cout << endl;
    cout << "done." << endl;
}

extern "C" void btnStart_clicked(GtkButton *button, Gui *gui){
    gui->data->ip->ping();
    //gui->data->printPing();
}

extern "C" void btnReset_clicked(GtkButton *button, Gui *gui){
    gui->data->ip->pingAll();
}
extern "C" void btnDraw_clicked(GtkButton *button, Gui *gui);