//
// Created by nsu on 18-7-29.
//


#include "sendMail.h"



void interface_SendMail(GtkButton *button,gpointer fixed)
{
    GtkWidget *lable_targetID;
    GtkWidget *lable_theme;
    GtkWidget *targetIdInput;
    GtkWidget *themeInput;
    GtkTextBuffer *bodybuffer;


    char *tip="收件人可以填对方的邮箱地址(固定后缀名)也可以填备注\n主题最多输入XX字";


//创建
    lable_targetID = gtk_label_new("收件人");
    lable_theme = gtk_label_new("主题");
    right.lable_body = gtk_label_new("内容");
    targetIdInput = gtk_entry_new();
    themeInput = gtk_entry_new();
    right.lable_tip=gtk_label_new(tip);
    set_widget_font_size(right.lable_tip,10,FALSE);


//处理主题收件人
    right.table = gtk_table_new(2,10,TRUE);
    gtk_fixed_put(GTK_FIXED(fixed),right.table,500,100);
    gtk_widget_set_size_request(right.table,900,150);
    gtk_table_set_row_spacings(GTK_TABLE(right.table),40);
    gtk_table_attach_defaults(GTK_TABLE(right.table),lable_targetID,0,1,0,1);
    gtk_table_attach_defaults(GTK_TABLE(right.table),targetIdInput,1,10,0,1);
    gtk_table_attach_defaults(GTK_TABLE(right.table),lable_theme,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(right.table),themeInput,1,10,1,2);
    gtk_fixed_put(GTK_FIXED(fixed),right.lable_tip,600,260);

//处理发邮件的按钮
    right.button_cancel=gtk_button_new_with_label("取消");
    right.button_sendMail=gtk_button_new_with_label("发送");
    gtk_fixed_put(GTK_FIXED(fixed),right.button_sendMail,850,900);//950为中线
    gtk_fixed_put(GTK_FIXED(fixed),right.button_cancel,1050,900);
    gtk_widget_set_size_request(right.button_sendMail,100,50);
    gtk_widget_set_size_request(right.button_cancel,100,50);

//处理body样子
    right.bodyInput=gtk_text_view_new();/*创建文本框构件*/
    bodybuffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(right.bodyInput));/*获得文本框缓冲区*/
    gtk_fixed_put(GTK_FIXED(fixed),right.bodyInput,593,360);
    gtk_fixed_put(GTK_FIXED(fixed),right.lable_body,526,330);
    gtk_widget_set_size_request(right.bodyInput,805,333);
    pack.ID=targetIdInput;
    pack.theme=themeInput;
    pack.body=bodybuffer;



 g_signal_connect(right.button_sendMail, "clicked",G_CALLBACK(sendEmail),&pack);
    g_signal_connect(right.button_cancel, "clicked",G_CALLBACK(cancel),NULL);


//显示

    gtk_widget_show_all(fixed);
}


int sendEmail(GtkButton *button, gpointer date)
{
//传给后端4个char *，分别为
//gtk_entry_get_text(GTK_ENTRY(pack->ID))
//gtk_text_buffer_get_text(buffer,&start,&end,FALSE)
//ID (发送人的ID)
//gtk_entry_get_text(GTK_ENTRY(pack->theme))
    extern char *ID;
    GtkWidget* dialog;
    GtkMessageType type;
    gchar* message;
    GtkTextIter start,end;
    GtkTextBuffer *buffer;
    struct PACK *pack;
    pack = (struct PACK *)date;
    buffer = pack->body;
    ID=gtk_entry_get_text(GTK_ENTRY(pack->ID));
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);
    g_print("%s",gtk_entry_get_text(GTK_ENTRY(pack->theme)));
    g_print("%s",gtk_text_buffer_get_text(buffer,&start,&end,FALSE));
    g_print("ID:%s",ID);
    gint goodsend=1;
    type = GTK_MESSAGE_INFO;
    switch(goodsend)
    {
        case 0:
            message = "boy bad send";
            dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
            break;
        case 1:
            message = "发送成功 ";
            dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
            gtk_widget_destroy(right.table);
            gtk_widget_destroy(right.bodyInput);
            gtk_widget_destroy(right.lable_body);
            gtk_widget_destroy(right.lable_tip);
            gtk_widget_destroy(right.button_cancel);
            gtk_widget_destroy(right.button_sendMail);
            break;
    }





}


void cancel(GtkButton *button, gpointer date)
{
    gtk_widget_destroy(right.table);
    gtk_widget_destroy(right.bodyInput);
    gtk_widget_destroy(right.lable_body);
    gtk_widget_destroy(right.lable_tip);
    gtk_widget_destroy(right.button_cancel);
    gtk_widget_destroy(right.button_sendMail);
}








