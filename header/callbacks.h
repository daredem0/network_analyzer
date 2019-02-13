/**
 * @file callbacks.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 09.02.2019
 * @brief header file to store declarations of all callback functions
 */

#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "../header/Data.h"
#include "../header/Gui.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
extern "C" void btnSetIP_clicked(GtkButton *button, Gui *gui);
extern "C" void btnInfo_clicked(GtkButton *button, Gui *gui);
extern "C" void btnStart_clicked(GtkButton *button, Gui *gui);
extern "C" void btnReset_clicked(GtkButton *button, Gui *gui);
extern "C" void btnDraw_clicked(GtkButton *button, Gui *gui);
#endif /* CALLBACKS_H */

