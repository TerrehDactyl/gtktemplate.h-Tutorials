#include "gtktemplate.h"
// compile with gcc -Wall -g menu.c -o menu `pkg-config --cflags --libs gtk+-3.0`
void callback();

int main(int argc, char *argv [])
{
gchar *headers [] = {"File", "Edit", "Help"};
gchar *menu1 [] = {"button 1"};
gchar *menu2 [] = {"button 1", "button 2"};
gchar *menu3 [] = {"button 1", "button 2", "button 3"};
size_t header_len = arraysize(headers);
size_t menu1_len = arraysize(menu1);
size_t menu2_len = arraysize(menu2);
size_t menu3_len = arraysize(menu3);
void *menu_callbacks[] = {callback, callback, callback};

gtk_init(&argc, &argv); //starting gtk 

GtkWidget *window = createwindow("Menu", GTK_WIN_POS_CENTER, "test.png");
GtkWidget *menu_bar = gtk_menu_bar_new ();
GtkWidget *root_menu;

for(int i = 0; i < header_len; i++)
{
	switch(i)
	{
	case 0:root_menu = createmenu(headers[i], menu1, menu1_len, menu_callbacks);
	break;

	case 1:root_menu = createmenu(headers[i], menu2, menu2_len, menu_callbacks);
	break;

	case 2:root_menu = createmenu(headers[i], menu3, menu3_len, menu_callbacks);
	break;

	default:
	break;
	}
	gtk_menu_shell_append (GTK_MENU_SHELL (menu_bar), root_menu);
}

gtk_container_add(GTK_CONTAINER(window), menu_bar); //adds the vbox to the window 

show_and_destroy(window); //shows all widgets, connects the callback for the window and starts gtkmain
}

void callback()
{
	g_print("you selected a menu item");
}
