#include "gtktemplate.h"
// compile with gcc -Wall -g progressbar.c -o progressbar `pkg-config --cflags --libs gtk+-3.0`
static gboolean fill_progress (GtkWidget *widget);

int main(int argc, char *argv [])
{

gtk_init(&argc, &argv); //starting gtk 

GtkWidget *window = createwindow("progress bar", GTK_WIN_POS_CENTER, "test.png");
GtkWidget *progress = create_progress_bar(fill_progress);
gtk_container_add(GTK_CONTAINER(window), progress); //adds the vbox to the window 

show_and_destroy(window); //shows all widgets, connects the callback for the window and starts gtkmain
}

static gboolean fill_progress (GtkWidget *widget)
{
  gdouble fraction;
  fraction = gtk_progress_bar_get_fraction (GTK_PROGRESS_BAR (widget)); //Get the current progress
  fraction += 0.01;//Increase the bar by 1% each time this function is called
  gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR (widget), TRUE);//Fill in the bar with the new fraction
  gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR (widget), fraction);

  if (fraction < 1.0) //Ensures that the fraction stays below 1.0
  {
    return TRUE;
  }
  return FALSE;
}
