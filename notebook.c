#include "gtktemplate.h"
//gcc -Wall -g notebook.c -o notebook `pkg-config --cflags --libs gtk+-3.0`
int main( int argc, char *argv[] )
{
    GtkWidget *window;
    GtkWidget *notebook;
    char *labels[] = {"label 1", "label 2", "label 3", "label 4", "label 5"};
    size_t label_size = arraysize(labels);

    gtk_init (&argc, &argv);
    
    window = createwindow("notebook", GTK_WIN_POS_CENTER, "test.png");
    notebook = createnotebook(window);

    for(int i = 0; i < label_size; i++)
    {
    	create_frame_with_pagehead(notebook, labels, i); //this function creates the page labels and 
    													 // can return the frame widget 
    													 //if you want to attach anything to it
    }
    show_and_destroy(window);
}

