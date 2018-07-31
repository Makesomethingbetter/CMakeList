//
// Created by nsu on 18-7-31.
//

#include "logcheck.h"

void logcheck(int argc,char *argv[],GtkButton *a, gpointer date)
{
    char *ID;
    char *passwd;
    struct LOGPACK *logpack;
    logpack = (struct LOGPACK *)date;
    ID = gtk_entry_get_text(GTK_ENTRY(logpack->ID));
    passwd = gtk_entry_get_text(GTK_ENTRY(logpack->passwd));

    if(!strcmp(ID,passwd))
    {
        disPlayWindow(&argc,&argv);
    }
}