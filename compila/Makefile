all: clean tads compila_exec tree run
	@echo "FIM!	"

clean:
	@echo "\n# Excluindo os programas (executáveis) e os arquivos intermediários..."
	rm -rf ./bin/main
	rm -rf ./obj/1.o
	rm -rf ./obj/2.o
	rm -rf ./obj/3.o
	rm -rf ./obj/ec_imprime.o
	@sleep 2

tads:
	@echo "\n# Compilação dos TADS (Tipos abstratos de dados)..."
	gcc -c ./src/1.c -I ./include/ -o ./obj/1.o
	gcc -c ./src/2.c -I ./include/ -o ./obj/2.o
	gcc -c ./src/3.c -I ./include/ -o ./obj/3.o
	gcc -c ./src/ec_imprime.c -I ./include/ -o ./obj/ex_imprime.o
	@sleep 2

compila_exec:
	@echo "\n# Compilação dos Aplicativos (Executáveis)..."
	gcc ./apps/main.c ./obj/* -I ./include/ -fsanitize=undefined -o ./bin/main
	@sleep 2

run:
	./bin/main

tree:
	tree