//
// Created by nsu on 18-7-30.
//

#include "set_font_size.h"

void set_widget_font_size(GtkWidget *widget, int size, gboolean is_button)
{
    GtkWidget *labelChild;
    PangoFontDescription *font;
    gint fontSize = size;

    font = pango_font_description_from_string("Sans");          //"Sans"字体名
    pango_font_description_set_size(font, fontSize*PANGO_SCALE);//设置字体大小

    if(is_button){
        labelChild = gtk_bin_get_child(GTK_BIN(widget));//取出GtkButton里的label
    }else{
        labelChild = widget;
    }

    //设置label的字体，这样这个GtkButton上面显示的字体就变了
    gtk_widget_modify_font(GTK_WIDGET(labelChild), font);
    pango_font_description_free(font);
}