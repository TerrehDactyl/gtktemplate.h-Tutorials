#include "gtktemplate.h"
// compile with gcc -Wall -g popup.c -o popup `pkg-config --cflags --libs gtk+-3.0`

int main(int argc, char *argv [])
{
gtk_init(&argc, &argv); //starting gtk 

GtkWidget *window = createwindow("main window",GTK_WIN_POS_CENTER, "test.png"); //popups can be done with createwindow as well 
GtkWidget *popup = create_custom_window("popup", GTK_WINDOW_TOPLEVEL, GTK_WIN_POS_CENTER, "test.png",480,640);
gtk_widget_show_all(popup); //you can use show and destroy for this but it will make the windows
                            //tied together so if you close one they both close 
show_and_destroy(window); //shows all widgets, connects the callback for the window and starts gtkmain
}
