#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "main.h"

GtkEntry *label_in;
GtkLabel *label1;
GtkLabel *label2;
GtkLabel *label3;
char labels[3][28];
const char *label_IN;

void on_salvar1IU_clicked(){

  gtk_label_set_text(label1, label_IN);
  strcpy(labels[0], label_IN);
}

void on_salvar2IU_clicked(){

  gtk_label_set_text(label2, label_IN);
  strcpy(labels[1], label_IN);
}

void on_salvar3IU_clicked(){

  gtk_label_set_text(label3, label_IN);
  strcpy(labels[2], label_IN);
}

void on_telaIU_destroy(){
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){

  GtkBuilder *arquivo;

  gtk_init(&numArgs, &nomArgs);

  arquivo = gtk_builder_new_from_file("teste.glade");
  GtkWidget *tela = GTK_WIDGET(gtk_builder_get_object(arquivo, "telaIU"));
  label_in = GTK_ENTRY(gtk_builder_get_object(arquivo, "INnomIU"));
  label1 = GTK_LABEL(gtk_builder_get_object(arquivo, "palavra1"));
  label2 = GTK_LABEL(gtk_builder_get_object(arquivo, "palavra2"));
  label3 = GTK_LABEL(gtk_builder_get_object(arquivo, "palavra3"));
  label_IN = gtk_entry_get_text(label_in);

  gtk_builder_add_callback_symbols(arquivo, 
    "on_telaIU_destroy", G_CALLBACK(on_telaIU_destroy),
    "on_salvar1IU_clicked", G_CALLBACK(on_salvar1IU_clicked),
    "on_salvar2IU_clicked", G_CALLBACK(on_salvar2IU_clicked),
    "on_salvar3IU_clicked", G_CALLBACK(on_salvar3IU_clicked),
    "on_reset1IU_clicked", G_CALLBACK(on_telaIU_destroy),
    "on_reset2IU_clicked", G_CALLBACK(on_telaIU_destroy),
    "on_reset3IU_clicked", G_CALLBACK(on_telaIU_destroy),
    "on_resetIU_clicked", G_CALLBACK(on_telaIU_destroy),
    "on_exitIU_clicked", G_CALLBACK(on_telaIU_destroy),
    NULL
    );

  gtk_builder_connect_signals(arquivo, NULL);

  gtk_widget_show_all(tela);

  gtk_main();

  printf("\n\t%s\n\t%s\n\t%s\n\n", labels[0], labels[1], labels[2]);

}
