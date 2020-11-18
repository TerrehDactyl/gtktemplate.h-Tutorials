#include "gtktemplate.h"
//compile with gcc -Wall -g checkbox.c -o checkbox `pkg-config --cflags --libs gtk+-3.0`
void cbk1(); 
int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);                                                        //initialize gtk

	GtkWidget *window = createwindow("button grid", GTK_WIN_POS_CENTER, "test.png");            //create window with title button grid
	GtkWidget * checkbox = create_checkbox(window, "new checkbox", FALSE, cbk1);    //creates a checkbox that is not checked
	gtk_container_add(GTK_CONTAINER(window), checkbox);                         	//adds the checkbox to the window 
	show_and_destroy(window);                                                       //shows the window, creates the callback to destroy the window, and initializes the main loop 
}

void cbk1()
{
	g_print("this is button 1\n");
}
