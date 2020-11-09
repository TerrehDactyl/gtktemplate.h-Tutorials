#include "gtktemplate.h"
//compile with gcc -Wall -g display.c -o display `pkg-config --cflags --libs gtk+-3.0`
int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv); //initializes GTK

	GtkWidget *window = createwindow("new window", GTK_WIN_POS_CENTER); //creates a window with the title new window and positions it in the center of the screen
	GtkWidget *display = create_text_display(TRUE, 150, 40); //sets the display widget as a text display 
	GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (display)); //sets thebuffer widget to the text gwidget.buffer of display
	gtk_text_buffer_set_text (buffer, "enter some text", -1); //displays input.num1 
	gtk_container_add (GTK_CONTAINER (window), display);

	show_and_destroy(window); //creates the callback to destory the window, shows the window, and runs the gtk main loop
}