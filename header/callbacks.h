/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   callbacks.h
 * Author: Florian Leuze
 *
 * Created on 9. Februar 2019, 16:54
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

