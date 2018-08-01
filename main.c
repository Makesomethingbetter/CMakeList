#include <gtk/gtk.h>
#include <stdio.h>
#include "sendMail.h"
#include "displayRcMail.h"
#include "logcheck.h"
#include "regist.h"
#include "mySocket.h"

int sockfd;

int main(int argc,char *argv[])
{
//    sockfd = new_connected_sock("192.168.31.151", SERV_PORT);
    GtkWidget *logWindow;
    GtkWidget *fixed_log;
    GtkWidget *label_ID;
    GtkWidget *label_passwd;
    GtkWidget *IDEntry;
    GtkWidget *passwdEntry;
    GtkWidget *buttonSignIn;
    GtkWidget *buttonSignUp;
    GtkWidget *image_1;
    GtkWidget *image_2;
    gtk_init(&argc,&argv);
//登陆window
    logWindow=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(logWindow,600,400);
    gtk_window_set_resizable(GTK_WINDOW(logWindow),FALSE);
    gtk_window_set_title(GTK_WINDOW(logWindow),"我们的邮箱");
    gtk_container_set_border_width(GTK_CONTAINER(logWindow),0);

//布局
    fixed_log = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(logWindow),fixed_log);
//image_log
    image_1 = gtk_image_new_from_file("../log_1.jpg");
    image_2 = gtk_image_new_from_file("../log_2.jpg");

    gtk_fixed_put(GTK_FIXED(fixed_log),image_1,105,110);
    gtk_fixed_put(GTK_FIXED(fixed_log),image_2,105,250);


//初始化界面组件
    label_ID = gtk_label_new("用户名");
    label_passwd = gtk_label_new("密码");
    IDEntry = gtk_entry_new();
    passwdEntry = gtk_entry_new();
    buttonSignIn = gtk_button_new_with_label("登陆");
    buttonSignUp= gtk_button_new_with_label("注册");

//place组件

    gtk_fixed_put(GTK_FIXED(fixed_log),IDEntry,170,65);
    gtk_fixed_put(GTK_FIXED(fixed_log),passwdEntry,170,210);
    gtk_fixed_put(GTK_FIXED(fixed_log),label_passwd,80,210);
    gtk_fixed_put(GTK_FIXED(fixed_log),label_ID,70,70);
    gtk_widget_set_size_request(IDEntry,325,30);
    gtk_widget_set_size_request(passwdEntry,325,30);
    gtk_fixed_put(GTK_FIXED(fixed_log),buttonSignIn,150,300);
    gtk_fixed_put(GTK_FIXED(fixed_log),buttonSignUp,390,300);
    gtk_widget_set_size_request(buttonSignIn,80,50);
    gtk_widget_set_size_request(buttonSignUp,80,50);

//获得数据
    logpack.ID = IDEntry;
    logpack.passwd = passwdEntry;
    logpack.window = logWindow;

    g_signal_connect(buttonSignIn, "clicked",G_CALLBACK(logcheck),&logpack);
    g_signal_connect(buttonSignUp, "clicked",G_CALLBACK(registWindow),&logpack);



    gtk_widget_show_all(logWindow);

    gtk_main();
    return 0;
}




