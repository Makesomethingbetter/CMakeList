//
// Created by nsu on 18-7-31.
//

#ifndef UNTITLED_REGIST_H
#define UNTITLED_REGIST_H

#include <gtk/gtk.h>
#include "set_font_size.h"
#include "disPlayWindow.h"
struct REGPACK{
    GtkWidget *ID;
    GtkWidget *passwd;
    GtkWidget *window;
}regpack;

struct LOGPACK1{
    GtkWidget *ID;
    GtkWidget *passwd;
    GtkWidget *window;
}logpack1;

void registCheck(int argc,char *argv[],GtkButton *a, gpointer date);
void registWindow(int argc,char *argv[],GtkButton *a, gpointer date);
#endif //UNTITLED_REGIST_H
