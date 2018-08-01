//
// Created by nsu on 18-7-31.
//

#ifndef UNTITLED_LOGCHECK_H
#define UNTITLED_LOGCHECK_H

#include <gtk/gtk.h>
#include "disPlayWindow.h"
#include "client.h"


struct LOGPACK{
    GtkWidget *ID;
    GtkWidget *passwd;
    GtkWidget *window;
}logpack;

void logcheck(int argc,char *argv[],GtkButton *a, gpointer date);
#endif //UNTITLED_LOGCHECK_H
