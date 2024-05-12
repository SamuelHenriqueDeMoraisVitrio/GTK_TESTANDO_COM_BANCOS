COMP = clang
OPC = -Wall
GTK = `pkg-config --cflags --libs gtk+-3.0`
NOME = EXE
START = echo "" && echo "Compilação concluida. Iniciando..." && echo "" && echo "" && ./$(NOME)

nome: clear
	$(COMP) $(OPC) -o $(NOME) main.c $(GTK) -rdynamic
	@$(START)

compile: clear
	$(COMP) $(OPC) -o $(NOME) *.c $(GTK) -rdynamic

clear:
	rm -rf EXE .*.glade.swp .*.c.swp *.glade~ .*.h.swp .cache
	clear
	@echo ""
	@ls -alh --color=auto
	@echo ""

run:
	@$(START)
	@echo ""
