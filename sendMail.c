//
// Created by nsu on 18-7-29.
//


#include "sendMail.h"



void interface_SendMail(GtkButton *button,gpointer fixed)
{
    GtkWidget *lable_targetID;
    GtkWidget *lable_theme;
    GtkWidget *lable_body;
    GtkWidget *targetIdInput;
    GtkWidget *themeInput;
    GtkWidget *bodyInput;
    GtkTextBuffer *bodybuffer;
    GtkWidget *table;
    GtkWidget *lable_tip;
    GtkWidget *button_sendMail;
    GtkWidget *button_cancel;
    char *tip="收件人可以填对方的邮箱地址(固定后缀名)也可以填备注\n主题最多输入XX字";




//创建
    lable_targetID = gtk_label_new("收件人");
    lable_theme = gtk_label_new("主题");
    lable_body = gtk_label_new("内容");
    targetIdInput = gtk_entry_new();
    themeInput = gtk_entry_new();
    lable_tip=gtk_label_new(tip);
    set_widget_font_size(lable_tip,10,FALSE);


//处理主题收件人
    table = gtk_table_new(2,10,TRUE);
    gtk_fixed_put(GTK_FIXED(fixed),table,500,100);
    gtk_widget_set_size_request(table,900,150);
    gtk_table_set_row_spacings(GTK_TABLE(table),40);
    gtk_table_attach_defaults(GTK_TABLE(table),lable_targetID,0,1,0,1);
    gtk_table_attach_defaults(GTK_TABLE(table),targetIdInput,1,10,0,1);
    gtk_table_attach_defaults(GTK_TABLE(table),lable_theme,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(table),themeInput,1,10,1,2);
    gtk_fixed_put(GTK_FIXED(fixed),lable_tip,600,260);

//处理发邮件的按钮
    button_cancel=gtk_button_new_with_label("取消");
    button_sendMail=gtk_button_new_with_label("发送");
    gtk_fixed_put(GTK_FIXED(fixed),button_sendMail,850,900);//950为中线
    gtk_fixed_put(GTK_FIXED(fixed),button_cancel,1050,900);
    gtk_widget_set_size_request(button_sendMail,100,50);
    gtk_widget_set_size_request(button_cancel,100,50);

//处理body样子
    bodyInput=gtk_text_view_new();/*创建文本框构件*/
    bodybuffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(bodyInput));/*获得文本框缓冲区*/
    gtk_fixed_put(GTK_FIXED(fixed),bodyInput,593,330);
    gtk_fixed_put(GTK_FIXED(fixed),lable_body,526,330);
    gtk_widget_set_size_request(bodyInput,805,333);
    pack.ID=targetIdInput;
    pack.theme=themeInput;
    pack.body=bodybuffer;



    g_signal_connect(button_sendMail, "clicked",G_CALLBACK(sendEmail),&pack);
    if(sendEmail==1)
    {
        GtkWidget *label_warn;
        label_warn = gtk_label_new("发送成功");
        gtk_fixed_put(GTK_FIXED(fixed),label_warn,960,900);//950为中线
    }


//显示

    gtk_widget_show_all(fixed);
}


gint sendEmail(GtkButton *button_sendMail, gpointer date)
{

    GtkTextIter start,end;
    GtkTextBuffer *buffer;
    struct PACK *pack;
    pack = (struct PACK *)date;
    buffer = pack->body;
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);
    g_print("%s",gtk_entry_get_text(GTK_ENTRY(pack->ID)));
    g_print("%s",gtk_text_buffer_get_text(buffer,&start,&end,FALSE));

    gint goodsend=1;
    if(goodsend==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}




