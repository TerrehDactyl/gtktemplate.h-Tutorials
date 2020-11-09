#include "gtktemplate.h"

void print_entries();

gchar *labels[] = {"entry 1", "entry 2", "entry 3"};                       // creates labels for the entrys                               //creates callback array
size_t len = arraysize(labels); 
GtkWidget *entries[3];
const gchar *entry_text[3];

int main(int argc, char *argv[])
{
	gchar *button_label[] = {"Get Entries"};
	void *callback[] ={print_entries};

	gtk_init(&argc, &argv);                                                        //initialize gtk

	GtkWidget *window = createwindow("Entries", GTK_WIN_POS_CENTER);           //create window with title entry grid
	GtkWidget *entry_labels = createlabels(labels, len);
	set_spacing(entry_labels, 10,20); 
	GtkWidget *entrygrid = gtk_grid_new();
	create_entries(len, entries, entrygrid);
	GtkWidget *button = createsinglesizegrid(button_label, callback, 1, 1);

	GtkWidget *entrybox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1); //creates a horizontal box without autosizing
	GtkWidget *buttonbox =  gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	gtk_container_add(GTK_CONTAINER(window), buttonbox);
	gtk_box_pack_start(GTK_BOX(buttonbox),  entrybox, FALSE, FALSE, 0); 
	gtk_box_pack_start(GTK_BOX(entrybox),  entry_labels, FALSE, FALSE, 0); 
	gtk_box_pack_start(GTK_BOX(entrybox),  entrygrid, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(buttonbox),  button, FALSE, FALSE, 0); 

	show_and_destroy(window);                          
}

void print_entries()
{
	get_entry_text(entries, entry_text, len); //need to work on this

	for(int i = 0; i<len; i++)
	{
		g_print("entry %d is %s\n", i+1, entry_text[i]);
	}
}