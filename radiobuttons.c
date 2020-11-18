#include "gtktemplate.h"
//compile with gcc -Wall -g radiobuttons.c -o radiobuttons `pkg-config --cflags --libs gtk+-3.0`
void cbk1(); 
void cbk2();
void cbk3();
int main(int argc, char *argv[])
{
	gchar *labels[] = {"button 1", "button 2", "Button 3"};                       // creates labels for the buttons 
	void *button_callbacks[] = {cbk1, cbk2, cbk3};                                //creates callback array
	size_t len = arraysize(labels);
	gtk_init(&argc, &argv);                                                        //initialize gtk

	GtkWidget *window = createwindow("button grid", GTK_WIN_POS_CENTER, "test.png");           //create window with title button grid
	GtkWidget *radios = createradiobuttons(labels, button_callbacks, len); //creates a grid and adds the buttons to the grid, the labels to the buttons, and the callbacks to the buttons

	gtk_container_add(GTK_CONTAINER(window), radios);                         //adds the grid to the window 
	show_and_destroy(window);                                                      //shows the window, creates the callback to destroy the window, and initializes the main loop 
}

void cbk1()
{
	g_print("this is button 1\n");
}

void cbk2()
{
	g_print("this is button 2\n");
}

void cbk3()
{
	g_print("this is button 3\n");
}

