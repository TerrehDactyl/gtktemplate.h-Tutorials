#include "gtktemplate.h"
// compile with gcc -Wall -g chooser.c -o chooser `pkg-config --cflags --libs gtk+-3.0`
void opencbk(gpointer data[]);

int main(int argc, char *argv [])
{
gchar *chooserlabels [] = {"Open", "Open", "Open", "Open"};
void *choosercallbacks[] = {createfilechoosers, createfilechoosers, createfilechoosers, createfilechoosers};
gchar *show_label[] = {"show"};
void *show_cbk[] = {opencbk};

gtk_init(&argc, &argv); //starting gtk 

GtkWidget *window = createwindow("tportman", GTK_WIN_POS_CENTER);
GtkWidget *chooserbox = createsinglesizegrid(chooserlabels, choosercallbacks, (gpointer) &location.pointer, 4,1);
GtkWidget *show_button = createsinglesizegrid(show_label, show_cbk, (gpointer) &location.pointer, 1,1);
GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);
gtk_container_add(GTK_CONTAINER(window), vbox); //adds the vbox to the window 
gtk_box_pack_start(GTK_BOX(vbox),  chooserbox, FALSE, FALSE, 0); //packs the display into the vbox
gtk_box_pack_start(GTK_BOX(vbox),  show_button, FALSE, FALSE, 0); //packs the display into the vbox

show_and_destroy(window); //shows all widgets, connects the callback for the window and starts gtkmain
}

void opencbk(gpointer data[])
{
	for (int i = 0; i < 4; i++)
	{
		g_print("%s\n", location.pointer[i]);
	}
}


