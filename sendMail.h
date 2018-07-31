#ifndef UNTITLED_LOGIN_H
#define UNTITLED_LOGIN_H
//
// Created by nsu on 18-7-29.
//
#include <gtk/gtk.h>
#include "set_font_size.h"
 struct PACK{
    GtkWidget *ID;
    GtkWidget *theme;
    GtkTextBuffer  *body;
}pack;
gint sendEmail(GtkButton *button_sendMail, gpointer date);
void interface_SendMail(GtkButton *button,gpointer fixed);



#endif //UNTITLED_LOGIN_H
