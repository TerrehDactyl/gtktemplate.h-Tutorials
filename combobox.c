#include "gtktemplate.h"
//compile with gcc -Wall -g combobox.c -o combobox `pkg-config --cflags --libs gtk+-3.0`
void on_changed(GtkComboBox *combo_box, gpointer user_data);

int main(int argc, char *argv [])
{
	gchar *combo_labels[] = {"first label", "second label", "third label"};
	size_t combo_size = arraysize(combo_labels);

	gtk_init(&argc, &argv); //starting gtk 

	GtkWidget *window = createwindow("tportman", GTK_WIN_POS_CENTER);
	GtkComboBox *combo_box = create_combobox(combo_labels,  combo_size, on_changed);
	gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(combo_box));  

	show_and_destroy(window); //shows all widgets, connects the callback for the window and starts gtkmain
}

void on_changed(GtkComboBox *combo_box, gpointer user_data)
{
	if (gtk_combo_box_get_active (combo_box) != 0) 
	{
		gchar *selection = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(combo_box));
		if(strcmp(selection, "first label") == 0)
		{
			g_print("you selected the first label");
		}
		else if(strcmp(selection, "second label") == 0)
		{
			g_print("you selected the second label");
		}
		else if(strcmp(selection, "third label") == 0)
		{
			g_print("you selected the third label");
		}
	}
}