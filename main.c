#include "h/main.h"

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

GtkEntry *label_in;
GtkLabel *label1;
GtkLabel *label2;
GtkLabel *label3;
char labels[6][28];
const char *label_IN;

void on_salvar1IU_clicked() {
  gtk_label_set_text(label1, label_IN);
}

void on_salvar2IU_clicked() {
  gtk_label_set_text(label2, label_IN);
}

void on_salvar3IU_clicked() {
  gtk_label_set_text(label3, label_IN);
}

void on_reset1IU_clicked() {
  gtk_label_set_text(label1, labels[0]);
}

void on_reset2IU_clicked() {
  gtk_label_set_text(label2, labels[1]);
}

void on_reset3IU_clicked() {
  gtk_label_set_text(label3, labels[2]);
}

void on_resetIU_clicked() {
  FILE *arquivo_txt_salvar;
  char pula_linha[30];

  arquivo_txt_salvar = fopen("banco/banco.txt", "r+");

  short l = 3;
  for (short i = 1; i <= 9; i++) {
    if (i > 6) {
      fprintf(arquivo_txt_salvar, "%s\n", labels[l]);
      l++;
    } else {
      fgets(pula_linha, sizeof(pula_linha), arquivo_txt_salvar);
    }
  }

  fclose(arquivo_txt_salvar);

  gtk_main_quit();
}

void on_exitIU_clicked() {
  const char *label_tempo;

  label_tempo = gtk_label_get_text(label1);
  strcpy(labels[0], label_tempo);
  label_tempo = gtk_label_get_text(label2);
  strcpy(labels[1], label_tempo);
  label_tempo = gtk_label_get_text(label3);
  strcpy(labels[2], label_tempo);

  FILE *arquivo_txt_salvar;
  char pula_linha[30];

  arquivo_txt_salvar = fopen("banco/banco.txt", "r+");

  short l = 0;
  for (short i = 1; i <= 9; i++) {
    if (i > 6) {
      fprintf(arquivo_txt_salvar, "%s\n", labels[l]);
      l++;
    } else {
      fgets(pula_linha, sizeof(pula_linha), arquivo_txt_salvar);
    }
  }

  fclose(arquivo_txt_salvar);

  gtk_main_quit();
}

void on_telaIU_destroy() {
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]) {
  FILE *arquivo_txt;
  char linha[40];

  arquivo_txt = fopen("banco/banco.txt", "r");

  if (arquivo_txt == NULL) {
    printf("\n\n\t\x1b[91mBanco de dados inexistente!\x1b[0m\n\n");
    return 1;
  }

  fgets(linha, sizeof(linha), arquivo_txt);

  for (short i = 3; i < 6; i++) { fgets(labels[i], sizeof(labels[i]), arquivo_txt); }

  fgets(linha, sizeof(linha), arquivo_txt);
  fgets(linha, sizeof(linha), arquivo_txt);

  for (short i = 0; i < 3; i++) { fgets(labels[i], sizeof(labels[i]), arquivo_txt); }

  for (short i = 0; i < 6; i++) { labels[i][strcspn(labels[i], "\n")] = '\0'; }

  fclose(arquivo_txt);

  GtkBuilder *arquivo;

  gtk_init(&numArgs, &nomArgs);

  arquivo = gtk_builder_new_from_file("IU/teste.glade");
  GtkWidget *tela = GTK_WIDGET(gtk_builder_get_object(arquivo, "telaIU"));
  label_in = GTK_ENTRY(gtk_builder_get_object(arquivo, "INnomIU"));
  label1 = GTK_LABEL(gtk_builder_get_object(arquivo, "palavra1"));
  label2 = GTK_LABEL(gtk_builder_get_object(arquivo, "palavra2"));
  label3 = GTK_LABEL(gtk_builder_get_object(arquivo, "palavra3"));
  label_IN = gtk_entry_get_text(label_in);

  gtk_label_set_text(label1, labels[0]);
  gtk_label_set_text(label2, labels[1]);
  gtk_label_set_text(label3, labels[2]);

  gtk_builder_add_callback_symbols(
      arquivo, "on_telaIU_destroy", G_CALLBACK(on_telaIU_destroy), "on_salvar1IU_clicked",
      G_CALLBACK(on_salvar1IU_clicked), "on_salvar2IU_clicked", G_CALLBACK(on_salvar2IU_clicked),
      "on_salvar3IU_clicked", G_CALLBACK(on_salvar3IU_clicked), "on_reset1IU_clicked",
      G_CALLBACK(on_reset1IU_clicked), "on_reset2IU_clicked", G_CALLBACK(on_reset2IU_clicked),
      "on_reset3IU_clicked", G_CALLBACK(on_reset3IU_clicked), "on_resetIU_clicked",
      G_CALLBACK(on_resetIU_clicked), "on_exitIU_clicked", G_CALLBACK(on_exitIU_clicked), NULL);

  gtk_builder_connect_signals(arquivo, NULL);

  gtk_widget_show_all(tela);

  gtk_main();
}
