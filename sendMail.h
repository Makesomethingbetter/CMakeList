#ifndef UNTITLED_LOGIN_H
#define UNTITLED_LOGIN_H
//
// Created by nsu on 18-7-29.
//
#include <gtk/gtk.h>
 struct PACK{
    GtkWidget *ID;
    GtkWidget *theme;
    gchar *body;
}pack;
void sendEmail(GtkButton *button_sendMail, gpointer date);
void interface_SendMail(GtkButton *button,gpointer fixed);
void set_widget_font_size(GtkWidget *widget, int size, gboolean is_button);


#endif //UNTITLED_LOGIN_H
