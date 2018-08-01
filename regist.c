//
// Created by nsu on 18-7-31.
//

#include "regist.h"
#include "client.h"

GtkWidget *regWindow;

void registWindow(int argc,char *argv[],GtkButton *a, gpointer date)
{

    GtkWidget *fixed_reg;
    GtkWidget *label_ID;
    GtkWidget *label_passwd;
    GtkWidget *IDEntry;
    GtkWidget *passwdEntry;
    GtkWidget *buttonSignUp;
    GtkWidget *label_warn_ID;
    GtkWidget *label_warn_passwd;
    GtkWidget *image_3;
    GtkWidget *image_4;

    struct LOGPACK1 *logpack1;
    logpack1 = (struct LOGPACK1 *)date;
    gtk_init(&argc,&argv);
//登陆window
    regWindow=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(regWindow,600,400);
    gtk_window_set_resizable(GTK_WINDOW(regWindow),FALSE);
    gtk_window_set_title(GTK_WINDOW(regWindow),"注册");
    gtk_container_set_border_width(GTK_CONTAINER(regWindow),0);

//布局
    fixed_reg = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(regWindow),fixed_reg);

//image_regi

    image_3 = gtk_image_new_from_file("../log_1.jpg");
    image_4 = gtk_image_new_from_file("../log_2.jpg");

    gtk_fixed_put(GTK_FIXED(fixed_reg),image_3,110,110);
    gtk_fixed_put(GTK_FIXED(fixed_reg),image_4,110,320);

//初始化界面组件
    label_ID = gtk_label_new("用户名");
    label_passwd = gtk_label_new("密码");
    label_warn_ID = gtk_label_new("账户字符数必须小于12个");
    label_warn_passwd = gtk_label_new("密码字符数应大于6个小于12");
    set_widget_font_size(label_warn_ID, 10, FALSE);
    set_widget_font_size(label_warn_passwd, 10, FALSE);
    IDEntry = gtk_entry_new();
    passwdEntry = gtk_entry_new();
    buttonSignUp= gtk_button_new_with_label("注册");

//place组件

    gtk_fixed_put(GTK_FIXED(fixed_reg),IDEntry,170,65);
    gtk_fixed_put(GTK_FIXED(fixed_reg),passwdEntry,170,210);
    gtk_fixed_put(GTK_FIXED(fixed_reg),label_passwd,80,220);
    gtk_fixed_put(GTK_FIXED(fixed_reg),label_ID,70,70);
    gtk_widget_set_size_request(IDEntry,325,30);
    gtk_widget_set_size_request(passwdEntry,325,30);
    gtk_fixed_put(GTK_FIXED(fixed_reg),buttonSignUp,490,280);
    gtk_widget_set_size_request(buttonSignUp,80,50);
    gtk_fixed_put(GTK_FIXED(fixed_reg),label_warn_ID,180,110);
    gtk_fixed_put(GTK_FIXED(fixed_reg),label_warn_passwd,180,255);

//获得数据
    regpack.ID = IDEntry;
    regpack.passwd = passwdEntry;
    regpack.window = logpack1->window;

    g_signal_connect(buttonSignUp, "clicked",G_CALLBACK(registCheck),&regpack);
    gtk_widget_show_all(regWindow);
}



void registCheck(int argc,char *argv[],GtkButton *a, gpointer date)
{
    extern int sockfd;
    int registCheck;//这里假装是后端注册函数的返回值
    extern *ID;
    char *passwd;

    GtkWidget *window;
    GtkWidget *dialog;
    GtkMessageType type;
    gchar* message;
    type = GTK_MESSAGE_INFO;


    //
    struct REGPACK *regpack;
    regpack = (struct LOGPACK *)date;
    ID = gtk_entry_get_text(GTK_ENTRY(regpack->ID));
    passwd = gtk_entry_get_text(GTK_ENTRY(regpack->passwd));
    window = regpack->window;
//    registCheck = clientSignUp(sockfd,ID,passwd);
    registCheck==0;

    if(registCheck==0)
    {
        message="注册成功";
        dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_window_set_destroy_with_parent(regWindow,gtk_window_get_destroy_with_parent(regWindow));
        gtk_widget_destroy(dialog);
        disPlayWindow(&argc,&argv);
        gtk_widget_destroy(regWindow);
        gtk_widget_destroy(window);
    }
    else if(registCheck==-3)
    {
        message="账户已被注册";
        dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
    else
    {
        message="注册失败";
        dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }

}