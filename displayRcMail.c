//
// Created by nsu on 18-7-29.
//

#include "displayRcMail.h"



void displayRcMail(int argc,char *argv[],GtkButton *button,gpointer fixed)
{
    GtkWidget *window_RcMail;
    static gchar *titles[4] = {" ","发件人", "主题","时间"};
    static GtkWidget *list;
    GtkWidget *fixed_RcMail;
    GtkWidget *scrolled;
    gtk_init(&argc, &argv);

    window_RcMail = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window_RcMail), 500, 320);

    fixed_RcMail= gtk_fixed_new();
//    gtk_container_add(GTK_CONTAINER(window_RcMail),fixed);

    list=gtk_list_box_new ();
    gtk_container_add(GTK_CONTAINER(window_RcMail),list);

    gtk_widget_show_all(window_RcMail);

}