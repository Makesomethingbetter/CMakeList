//
// Created by nsu on 18-7-31.
//

#include "logcheck.h"

char *ID;

void logcheck(int argc,char *argv[],GtkButton *a, gpointer date)
{

    char *passwd;
    struct LOGPACK *logpack;
    int logcheck=2;
    GtkWidget *dialog;
    GtkMessageType type;
    gchar* message;
    type = GTK_MESSAGE_INFO;

    logpack = (struct LOGPACK *)date;
    ID = gtk_entry_get_text(GTK_ENTRY(logpack->ID));
    passwd = gtk_entry_get_text(GTK_ENTRY(logpack->passwd));

    if(!strcmp(ID,passwd))
    {
        logcheck=1;
    }

    if(logcheck==1)
    {
        disPlayWindow(&argc,&argv);
    }
    else if(logcheck==2)
    {
        message="密码错误";
        dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
    else if(logcheck==3)
    {
        message="账户不存在 您可以点击注册";
        dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}