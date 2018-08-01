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

struct RIGHT {
    GtkWidget *bodyInput;
    GtkWidget *table;
    GtkWidget *lable_tip;
    GtkWidget *lable_body;
    GtkWidget *button_sendMail;
    GtkWidget *button_cancel;
}right;
int sendEmail(GtkButton *button, gpointer date);
void interface_SendMail(GtkButton *button,gpointer fixed);
void cancel(GtkButton *button, gpointer date);



#endif //UNTITLED_LOGIN_H
