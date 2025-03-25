# Variables
CC = gcc
CFLAGS = -Wall -ansi -pedantic -g -c
OBJS = command.o space.o graphic_engine.o game_loop.o game_actions.o game.o game_reader.o object.o player.o set.o character.o
EXEC = proyecto

.PHONY: all clean
# Regla principal
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -L. -lscreen

# Compilacion de archivos individuales
space.o: space.c space.h types.h set.h
	$(CC) $(CFLAGS) -o space.o space.c

command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -o command.o command.c

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h types.h space.h set.h player.h object.h character.h libscreen.h
	$(CC) $(CFLAGS) -o graphic_engine.o graphic_engine.c

game_loop.o: game_loop.c command.h types.h game.h space.h set.h player.h object.h character.h game_actions.h graphic_engine.h game_reader.h
	$(CC) $(CFLAGS) -o game_loop.o game_loop.c

game_actions.o: game_actions.c game_actions.h command.h types.h character.h game.h space.h set.h player.h object.h
	$(CC) $(CFLAGS) -o game_actions.o game_actions.c

game.o: game.c game.h command.h types.h space.h set.h player.h object.h character.h game_reader.h
	$(CC) $(CFLAGS) -o game.o game.c

game_reader.o: game_reader.c game_reader.h game.h command.h types.h space.h set.h player.h object.h character.h 
	$(CC) $(CFLAGS) -o game_reader.o game_reader.c

object.o: object.h types.h object.c 
	$(CC) $(CFLAGS) -o object.o object.c

player.o: player.h types.h player.c 
	$(CC) $(CFLAGS) -o player.o player.c

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -o set.o set.c

character.o: character.c character.h types.h
	$(CC) $(CFLAGS) -o character.o character.c

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

link_test.o: link_test.c link_test.h test.h link.h types.h
	$(CC) $(CFLAGS) -o link_test.o link_test.c

player_test.o: player_test.c player_test.h player.h test.h types.h
	$(CC) $(CFLAGS) -o player_test.o player_test.c


	
# Limpiar archivos generados
clean:
	rm -f $(EXEC) $(OBJS) space_test space_test.o set_test set_test.o character_test character_test.o link_test.o

# Correr valgrind
runv :
	valgrind --leak-check=full ./$(EXEC) anthill.dat

# Ejecutar el programa
run: $(EXEC)
	./$(EXEC) anthill.dat

# Ejecutar el archivo de testeo space
testspace: space_test 
	./space_test 

# Ejecutar el archivo de testeo set
testset: set_test 
	./set_test 

testcharacter: character_test
	./character_test

testlink: link_test
	./link_test

# Ejecutar el valgrind con castle
crunv :
	valgrind --leak-check=full ./$(EXEC) castle.dat

# Ejecutar el programa con castle
crun: $(EXEC)
	./$(EXEC) castle.dat

