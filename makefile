# Variables
CC = gcc
CFLAGS = -Wall -ansi -pedantic -g -c
OBJS = command.o space.o graphic_engine.o game_loop.o game_actions.o game.o game_reader.o object.o player.o set.o character.o link.o inventory.o
EXEC = proyecto

.PHONY: all clean runv run runvlog runlog runvcastle runcastle testset testcharacter testspace testinventory testplayer testobject testlink crunv crun doxyfile
# Regla principal
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -L. -lscreen

# Compilacion de archivos individuales
space.o: space.c space.h types.h set.h
	$(CC) $(CFLAGS) -o space.o space.c

command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -o command.o command.c

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h types.h space.h set.h player.h object.h character.h libscreen.h link.h inventory.h
	$(CC) $(CFLAGS) -o graphic_engine.o graphic_engine.c

game_loop.o: game_loop.c command.h types.h game.h space.h set.h player.h object.h character.h game_actions.h graphic_engine.h game_reader.h link.h inventory.h
	$(CC) $(CFLAGS) -o game_loop.o game_loop.c

game_actions.o: game_actions.c game_actions.h command.h types.h character.h game.h space.h set.h player.h object.h link.h inventory.h
	$(CC) $(CFLAGS) -o game_actions.o game_actions.c

game.o: game.c game.h command.h types.h space.h set.h player.h object.h character.h game_reader.h link.h inventory.h
	$(CC) $(CFLAGS) -o game.o game.c

game_reader.o: game_reader.c game_reader.h game.h command.h types.h space.h set.h player.h object.h character.h link.h inventory.h
	$(CC) $(CFLAGS) -o game_reader.o game_reader.c

object.o: object.h types.h object.c 
	$(CC) $(CFLAGS) -o object.o object.c

player.o: player.h types.h player.c inventory.h
	$(CC) $(CFLAGS) -o player.o player.c

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -o set.o set.c

character.o: character.c character.h types.h
	$(CC) $(CFLAGS) -o character.o character.c

link.o: link.c link.h types.h
	$(CC) $(CFLAGS) -o link.o link.c

inventory.o: inventory.c inventory.h types.h set.h
	$(CC) $(CFLAGS) -o inventory.o inventory.c

space_test: space_test.o space.o set.o
	$(CC) -o space_test space_test.o space.o set.o

space_test.o: space_test.c space_test.h space.h types.h set.h test.h
	$(CC) $(CFLAGS) -o space_test.o space_test.c

set_test: set_test.o set.o
	$(CC) -o set_test set_test.o set.o

set_test.o: set_test.c set_test.h test.h set.h types.h
	$(CC) $(CFLAGS) -o set_test.o set_test.c

character_test: character_test.o character.o
	$(CC) -o character_test character_test.o character.o

character_test.o: character_test.c character_test.h character.h test.h types.h
	$(CC) $(CFLAGS) -o character_test.o character_test.c

link_test: link_test.o link.o
	$(CC) -o link_test link_test.o link.o

link_test.o: link_test.c link_test.h test.h link.h types.h
	$(CC) $(CFLAGS) -o link_test.o link_test.c

player_test: player_test.o player.o
	$(CC) -o player_test player_test.o player.o

player_test.o: player_test.c player_test.h player.h test.h types.h
	$(CC) $(CFLAGS) -o player_test.o player_test.c

object_test: object_test.o object.o
	$(CC) -o object_test object_test.o object.o

object_test.o: object_test.c object_test.h object.h test.h types.h
	$(CC) $(CFLAGS) -o object_test.o object_test.c

inventory_test: inventory_test.o inventory.o
	$(CC) -o inventory_test inventory_test.o inventory.o

inventory_test.o: inventory_test.c inventory_test.h inventory.h test.h
	$(CC) $(CFLAGS) -o inventory_test.o inventory_test.c


	
# Limpiar archivos generados
clean:
	rm -f $(EXEC) $(OBJS) space_test space_test.o set_test set_test.o character_test character_test.o link_test.o inventory_test inventory_test.o object_test object_test.o player_test player_test.o link_test link_test_o

# Correr valgrind
runv :
	valgrind --leak-check=full ./$(EXEC) anthill.dat

runvcastle :
	valgrind --leak-check=full ./$(EXEC) castle.dat

runvlog : 
	valgrind --leak-check=full ./$(EXEC) anthill.dat -l output.txt - log_input.txt

# Ejecutar el programa
run: $(EXEC)
	./$(EXEC) anthill.dat

runcastle: $(EXEC)
	./$(EXEC) castle.dat

runlog:
	$ ./$(EXEC) anthill.dat -l output.txt - log_input.txt

# Ejecutar el archivo de testeo space
testspace: space_test 
	./space_test 

# Ejecutar el archivo de testeo set
testset: set_test 
	./set_test 

# Ejecutar el archivo de testeo player
testplayer: player_test
	./player_test

# Ejecutar el archivo de testeo character
testcharacter: character_test
	./character_test

# Ejecutar el archivo de testeo object
testobject: object_test
	./object_test

# Ejecutar el archivo de testeo link
testlink: link_test
	./link_test

# Ejecutar el archivo de testeo inventory
testinventory: inventory_test
	./inventory_test

# Ejecutar doxygen
doxyfile: 
	Doxygen -g

# Depuración con anthill.dat
debug: $(EXEC)
	gdb -q --args ./$(EXEC) anthill.dat
