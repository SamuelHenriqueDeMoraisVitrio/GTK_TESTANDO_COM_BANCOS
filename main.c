#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void destroyT();

void destroyT(){
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){

  GtkBuilder *arquivo;

  gtk_init(&numArgs, &nomArgs);

  arquivo = gtk_builder_new_from_file("teste.glade");
  GtkWidget *tela = GTK_WIDGET(gtk_builder_get_object(arquivo, "telaIU"));

  gtk_widget_show(tela);

  g_signal_connect(tela, "destroy", G_CALLBACK(destroyT), NULL);

  gtk_main();

}
