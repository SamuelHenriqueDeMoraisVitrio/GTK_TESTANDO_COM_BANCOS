#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void on_telaIU_destroy();

void on_telaIU_destroy(){
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){

  GtkBuilder *arquivo;

  gtk_init(&numArgs, &nomArgs);

  arquivo = gtk_builder_new_from_file("teste.glade");
  GtkWidget *tela = GTK_WIDGET(gtk_builder_get_object(arquivo, "telaIU"));

  gtk_builder_add_callback_symbols(arquivo, 
    "on_telaIU_destroy", G_CALLBACK(on_telaIU_destroy),
    "on_salvarIU_clicked", G_CALLBACK(on_telaIU_destroy),
    "on_salvar1IU_clicked", G_CALLBACK(on_telaIU_destroy),
    "on_salvar2IU_clicked", G_CALLBACK(on_telaIU_destroy),
    "on_salvar3IU_clicked", G_CALLBACK(on_telaIU_destroy),
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

}
