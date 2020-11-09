#include "gtktemplate.h"
//compile with gcc -Wall -g gtkwindow.c -o gtkwindow `pkg-config --cflags --libs gtk+-3.0`
int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv); //initializes GTK
	GtkWidget *window = createwindow("new window", GTK_WIN_POS_CENTER); //creates a window with the title new window and positions it in the center of the screen
	show_and_destroy(window); //creates the callback to destory the window, shows the window, and runs the gtk main loop
}