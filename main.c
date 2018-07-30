#include <gtk/gtk.h>
#include <stdio.h>
#include "sendMail.h"
#include "displayRcMail.h"


int main(int argc,char *argv[])
{
    gtk_init(&argc,&argv);
    displayWindow();
    gtk_main();
    return 0;
}

void displayWindow(int argc,char *argv[])
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

    char *welcome="我们的邮箱\n希望你能喜欢";

//
    gtk_init(&argc,&argv);

//
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window),fixed);

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
    gtk_fixed_put(GTK_FIXED(fixed),label_title,160,58);
    gtk_label_set_justify(GTK_LABEL(label_title),GTK_JUSTIFY_CENTER);


//写邮件
    g_signal_connect(xieyoujian, "clicked", G_CALLBACK(interface_SendMail), fixed);
    g_signal_connect(shoujianxiang, "clicked", G_CALLBACK(displayRcMail), fixed);

    gtk_widget_show_all(window);
}


