//
// Created by nsu on 18-7-30.
//

#include "disPlayWindow.h"

void signOut();
void disPlayWindow(int argc,char *argv[])
{
    GtkWidget *fixed;
    GtkWidget *window;
    GtkWidget *shoujianxiang;//for fixed
    GtkWidget *xieyoujian;
    GtkWidget *fajianxiang;
    GtkWidget *lajixiang;
    GtkWidget *heimingdan;
    GtkWidget *lianxiren;//for fixed
    GtkWidget *label_title;
    GtkWidget *image;
    GtkWidget *image_pre;
    GtkWidget *button_signout;

    char *welcome="我们的邮箱\n希望你能喜欢\n";

//
    gtk_init(&argc,&argv);

//
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window),fixed);
    image = gtk_image_new_from_file("../3.jpg");
    image_pre = gtk_image_new_from_file("../pre.jpg");
    gtk_widget_set_size_request(image,10,10);
    gtk_fixed_put(GTK_FIXED(fixed),image,0,0);
    gtk_fixed_put(GTK_FIXED(fixed),image_pre,50,50);
/*chushihua to window*/
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window,1500,1000);
    gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
    gtk_window_set_title(GTK_WINDOW(window),"Email");
    gtk_container_set_border_width(GTK_CONTAINER(window),0);

/*chuli to button*/
    xieyoujian = gtk_button_new_with_label("写     邮     件");
    shoujianxiang = gtk_button_new_with_label("收     件     箱");
    lianxiren = gtk_button_new_with_label("联     系     人");
    heimingdan = gtk_button_new_with_label("黑     名     单");
    fajianxiang = gtk_button_new_with_label("发     件     箱");
    lajixiang = gtk_button_new_with_label("垃     圾     箱");
    button_signout  = gtk_button_new_with_label("注销");
    gtk_fixed_put(GTK_FIXED(fixed),button_signout,1550,30);
    gtk_fixed_put(GTK_FIXED(fixed),xieyoujian,30,300);
    gtk_widget_set_size_request(xieyoujian,375,70);
    gtk_fixed_put(GTK_FIXED(fixed),shoujianxiang,30,400);
    gtk_widget_set_size_request(shoujianxiang,375,70);
    gtk_fixed_put(GTK_FIXED(fixed),fajianxiang,30,500);
    gtk_widget_set_size_request(fajianxiang,375,70);
    gtk_fixed_put(GTK_FIXED(fixed),lajixiang,30,600);
    gtk_widget_set_size_request(lajixiang,375,70);
    gtk_fixed_put(GTK_FIXED(fixed),lianxiren,30,700);
    gtk_widget_set_size_request(lianxiren,375,70);
    gtk_fixed_put(GTK_FIXED(fixed),heimingdan,30,700);
    gtk_widget_set_size_request(heimingdan,375,70);
    set_widget_font_size(shoujianxiang,24,TRUE);
    set_widget_font_size(xieyoujian,24,TRUE);
    set_widget_font_size(fajianxiang,24,TRUE);
    set_widget_font_size(lajixiang,24,TRUE);
    set_widget_font_size(lianxiren,24,TRUE);
    set_widget_font_size(heimingdan,24,TRUE);


/*处理标签*/
    label_title= gtk_label_new(welcome);   //新建标签
    gtk_fixed_put(GTK_FIXED(fixed),label_title,280,80);
    gtk_label_set_justify(GTK_LABEL(label_title),GTK_JUSTIFY_CENTER);


//image




    g_signal_connect(xieyoujian, "clicked", G_CALLBACK(interface_SendMail), fixed);
    g_signal_connect(shoujianxiang, "clicked", G_CALLBACK(displayRcMail), fixed);
    g_signal_connect(button_signout, "clicked", G_CALLBACK(signOut), NULL);

    gtk_widget_show_all(window);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}


void signOut()
{
    extern char *ID;
    extern int *sockfd;
    clientLogOut(sockfd,ID);
    gtk_main_quit();


}