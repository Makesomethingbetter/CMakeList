//
// Created by nsu on 18-7-31.
//

#include "logcheck.h"
#include "mySocket.h"

char *ID;

void logcheck(int argc,char *argv[],GtkButton *a, gpointer date)
{
    extern int sockfd;
    GtkWidget *logwindow;
    char *passwd;
    struct LOGPACK *logpack;
    GtkWidget *dialog;
    GtkMessageType type;
    gchar* message;
    type = GTK_MESSAGE_INFO;

    logpack = (struct LOGPACK *)date;
    ID = gtk_entry_get_text(GTK_ENTRY(logpack->ID));
    passwd = gtk_entry_get_text(GTK_ENTRY(logpack->passwd));
    logwindow = GTK_WINDOW(logpack->window);
    int logcheck=clientSignIn(sockfd,ID,passwd);
    logcheck = 0;
    if(logcheck==0)
    {
        disPlayWindow(&argc,&argv);
        gtk_widget_destroy(logwindow);
    }
    else if(logcheck==-3)
    {
        message="密码错误";
        dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
    else if(logcheck==-2)
    {
        message="账户不存在 您可以点击注册";
        dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
    else if(logcheck==-4)
    {
        message="用户已经在其他设备登陆";
        dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
    else
    {
        message="未知错误，请联系我们";
        dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}