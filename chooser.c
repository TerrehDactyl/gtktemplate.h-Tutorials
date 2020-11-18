#include "gtktemplate.h"
// compile with gcc -Wall -g chooser.c -o chooser `pkg-config --cflags --libs gtk+-3.0`
void opencbk(GtkButton *button, location* data);

int main(int argc, char *argv [])
{
gchar *chooserlabels [] = {"Open", "Open", "Open", "Open"};
void *choosercallbacks[] = {createfilechoosers, createfilechoosers, createfilechoosers, createfilechoosers};
gchar *show_label[] = {"show"};
void *show_cbk[] = {opencbk};

gtk_init(&argc, &argv); //starting gtk 

location data;

data = (location){.pointer = {"test"}, .current = 0, .max = 4};

GtkWidget *window = createwindow("chooser", GTK_WIN_POS_CENTER, "test.png");
GtkWidget *chooserbox = createsinglesizegrid(chooserlabels, choosercallbacks, &data, 4,1);
GtkWidget *show_button = createsinglesizegrid(show_label, show_cbk, &data, 1,1);
GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);

gtk_container_add(GTK_CONTAINER(window), vbox); //adds the vbox to the window 
gtk_box_pack_start(GTK_BOX(vbox),  chooserbox, FALSE, FALSE, 0); //packs the display into the vbox
gtk_box_pack_start(GTK_BOX(vbox),  show_button, FALSE, FALSE, 0); //packs the display into the vbox

show_and_destroy(window); //shows all widgets, connects the callback for the window and starts gtkmain
}

void opencbk(GtkButton *button, location* data)
{
	for(int i = 0; i <data->max; i++)
	{
		g_print("%s from second callback\n", data->pointer[i]);
	}
}
