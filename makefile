# Directorios
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIB_DIR = lib
DOC_DIR = doc

# Variables
CC = gcc
CFLAGS = -Wall -ansi -pedantic -g -I$(INC_DIR)
LDFLAGS = -L$(LIB_DIR) -lscreen
OBJS = $(addprefix $(OBJ_DIR)/, command.o space.o game_loop.o game_actions.o game.o game_reader.o object.o player.o set.o character.o link.o inventory.o graphic_engine.o game_rules.o)
EXEC = proyecto

.PHONY: all clean runv run runvloganthill runloganthill runvlogcastle runlogcastle runvcastle runcastle set_test character_test space_test inventory_test player_test object_test link_test crunv crun doxyfile docs debug cleandocs

# Regla principal
all: $(EXEC)

# Crear directorios si no existen
$(shell mkdir -p $(OBJ_DIR) $(LIB_DIR) $(DOC_DIR))

# Enlazado del ejecutable
$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

# Reglas de compilación para cada objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dependencias específicas para cada objeto
$(OBJ_DIR)/space.o: $(INC_DIR)/space.h $(INC_DIR)/types.h $(INC_DIR)/set.h
$(OBJ_DIR)/command.o: $(INC_DIR)/command.h $(INC_DIR)/types.h
$(OBJ_DIR)/game_loop.o: $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/game.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/object.h $(INC_DIR)/character.h $(INC_DIR)/game_actions.h $(INC_DIR)/graphic_engine.h $(INC_DIR)/game_reader.h $(INC_DIR)/link.h $(INC_DIR)/inventory.h $(INC_DIR)/game_rules.h
$(OBJ_DIR)/game_actions.o: $(INC_DIR)/game_actions.h $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/character.h $(INC_DIR)/game.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/object.h $(INC_DIR)/link.h $(INC_DIR)/inventory.h
$(OBJ_DIR)/game.o: $(INC_DIR)/game.h $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/object.h $(INC_DIR)/character.h $(INC_DIR)/game_reader.h $(INC_DIR)/link.h $(INC_DIR)/inventory.h
$(OBJ_DIR)/game_reader.o: $(INC_DIR)/game_reader.h $(INC_DIR)/game.h $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/object.h $(INC_DIR)/character.h $(INC_DIR)/link.h $(INC_DIR)/inventory.h
$(OBJ_DIR)/object.o: $(INC_DIR)/object.h $(INC_DIR)/types.h
$(OBJ_DIR)/player.o: $(INC_DIR)/player.h $(INC_DIR)/types.h $(INC_DIR)/inventory.h $(INC_DIR)/set.h
$(OBJ_DIR)/set.o: $(INC_DIR)/set.h $(INC_DIR)/types.h
$(OBJ_DIR)/character.o: $(INC_DIR)/character.h $(INC_DIR)/types.h
$(OBJ_DIR)/link.o: $(INC_DIR)/link.h $(INC_DIR)/types.h
$(OBJ_DIR)/inventory.o: $(INC_DIR)/inventory.h $(INC_DIR)/types.h $(INC_DIR)/set.h
$(OBJ_DIR)/graphic_engine.o: $(INC_DIR)/graphic_engine.h $(INC_DIR)/game.h $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/object.h $(INC_DIR)/character.h $(INC_DIR)/libscreen.h $(INC_DIR)/link.h $(INC_DIR)/inventory.h
$(OBJ_DIR)/game_rules.o: $(INC_DIR)/game_rules.h $(INC_DIR)/game.h $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/inventory.h $(INC_DIR)/object.h $(INC_DIR)/character.h $(INC_DIR)/link.h
 

# Reglas para tests
$(OBJ_DIR)/space_test.o: $(SRC_DIR)/space_test.c $(INC_DIR)/space_test.h $(INC_DIR)/space.h $(INC_DIR)/types.h $(INC_DIR)/set.h $(INC_DIR)/test.h
	$(CC) $(CFLAGS) -c $< -o $@

space_test: $(OBJ_DIR)/space_test.o $(OBJ_DIR)/space.o $(OBJ_DIR)/set.o
	$(CC) -o $@ $^

$(OBJ_DIR)/set_test.o: $(SRC_DIR)/set_test.c $(INC_DIR)/set_test.h $(INC_DIR)/test.h $(INC_DIR)/set.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) -c $< -o $@

set_test: $(OBJ_DIR)/set_test.o $(OBJ_DIR)/set.o
	$(CC) -o $@ $^

$(OBJ_DIR)/character_test.o: $(SRC_DIR)/character_test.c $(INC_DIR)/character_test.h $(INC_DIR)/character.h $(INC_DIR)/test.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) -c $< -o $@

character_test: $(OBJ_DIR)/character_test.o $(OBJ_DIR)/character.o
	$(CC) -o $@ $^

$(OBJ_DIR)/link_test.o: $(SRC_DIR)/link_test.c $(INC_DIR)/link_test.h $(INC_DIR)/test.h $(INC_DIR)/link.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) -c $< -o $@

link_test: $(OBJ_DIR)/link_test.o $(OBJ_DIR)/link.o
	$(CC) -o $@ $^

$(OBJ_DIR)/player_test.o: $(SRC_DIR)/player_test.c $(INC_DIR)/player_test.h $(INC_DIR)/player.h $(INC_DIR)/test.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) -c $< -o $@

player_test: $(OBJ_DIR)/player_test.o $(OBJ_DIR)/player.o $(OBJ_DIR)/inventory.o $(OBJ_DIR)/set.o
	$(CC) -o $@ $^

$(OBJ_DIR)/object_test.o: $(SRC_DIR)/object_test.c $(INC_DIR)/object_test.h $(INC_DIR)/object.h $(INC_DIR)/test.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) -c $< -o $@

object_test: $(OBJ_DIR)/object_test.o $(OBJ_DIR)/object.o
	$(CC) -o $@ $^

$(OBJ_DIR)/inventory_test.o: $(SRC_DIR)/inventory_test.c $(INC_DIR)/inventory_test.h $(INC_DIR)/inventory.h $(INC_DIR)/test.h
	$(CC) $(CFLAGS) -c $< -o $@

inventory_test: $(OBJ_DIR)/inventory_test.o $(OBJ_DIR)/inventory.o
	$(CC) -o $@ $^

# Limpiar archivos generados
clean:
	rm -f $(EXEC) $(OBJS) $(OBJ_DIR)/*.o space_test set_test character_test link_test inventory_test object_test player_test

cleandocs:
	rm -rf $(DOC_DIR)/html $(DOC_DIR)/latex
# Reglas de ejecución
runv:
	valgrind --leak-check=full ./$(EXEC) anthill.dat

runvcastle:
	valgrind --leak-check=full ./$(EXEC) castle.dat

runvloganthill:
	valgrind --leak-check=full ./$(EXEC) anthill.dat -l output.txt - log_input.txt

runvlogcastle:
	valgrind --leak-check=full ./$(EXEC) castle.dat -l output.txt - log_input_castle.txt

run: $(EXEC)
	./$(EXEC) anthill.dat

runc: $(EXEC)
	./$(EXEC) cluedo.dat

runcastle: $(EXEC)
	./$(EXEC) castle.dat

runloganthill:
	./$(EXEC) anthill.dat -l output.txt - log_input.txt

runlogcastle:
	./$(EXEC) castle.dat -l output.txt - log_input_castle.txt

# Reglas de test
space_test: space_test 
	./space_test 

set_test: set_test 
	./set_test 

player_test: player_test
	./player_test

character_test: character_test
	./character_test

object_test: object_test
	./object_test

link_test: link_test
	./link_test

inventory_test: inventory_test
	./inventory_test

# Documentación
doxyfile:
	doxygen -g $(DOC_DIR)/Doxyfile

docs:
	doxygen $(DOC_DIR)/Doxyfile

# Depuración
debug: $(EXEC)
	gdb -q --args ./$(EXEC) anthill.dat