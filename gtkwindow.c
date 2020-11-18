#include "gtktemplate.h"
// compile with gcc -Wall -g icon.c -o icon `pkg-config --cflags --libs gtk+-3.0`
int main( int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	GtkWidget *window = createwindow("icon", GTK_WIN_POS_CENTER, "test.png");
	show_and_destroy(window);
}
