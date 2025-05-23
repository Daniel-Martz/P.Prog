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
EXEC = proyecto

# Objetos principales
OBJS = \
  $(OBJ_DIR)/command.o \
  $(OBJ_DIR)/space.o \
  $(OBJ_DIR)/game_loop.o \
  $(OBJ_DIR)/game_actions.o \
  $(OBJ_DIR)/game.o \
  $(OBJ_DIR)/game_management.o \
  $(OBJ_DIR)/object.o \
  $(OBJ_DIR)/player.o \
  $(OBJ_DIR)/set.o \
  $(OBJ_DIR)/character.o \
  $(OBJ_DIR)/link.o \
  $(OBJ_DIR)/inventory.o \
  $(OBJ_DIR)/graphic_engine.o \
  $(OBJ_DIR)/game_rules.o

# Tests
TESTS = space_test set_test character_test link_test inventory_test object_test player_test

.PHONY: all clean run runv run_tests doxyfile docs debug cleandocs $(TESTS)

# Crear directorios necesarios
$(shell mkdir -p $(OBJ_DIR) $(LIB_DIR) $(DOC_DIR))

# Regla principal
all: $(EXEC)

# Compilación explícita de cada .c a .o
$(OBJ_DIR)/command.o: $(SRC_DIR)/command.c $(INC_DIR)/command.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/space.o: $(SRC_DIR)/space.c $(INC_DIR)/space.h $(INC_DIR)/types.h $(INC_DIR)/set.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/game_loop.o: $(SRC_DIR)/game_loop.c $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/game.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/object.h $(INC_DIR)/character.h $(INC_DIR)/game_actions.h $(INC_DIR)/graphic_engine.h $(INC_DIR)/game_management.h $(INC_DIR)/link.h $(INC_DIR)/inventory.h $(INC_DIR)/game_rules.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/game_actions.o: $(SRC_DIR)/game_actions.c $(INC_DIR)/game_actions.h $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/character.h $(INC_DIR)/game.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/object.h $(INC_DIR)/link.h $(INC_DIR)/inventory.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/game.o: $(SRC_DIR)/game.c $(INC_DIR)/game.h $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/object.h $(INC_DIR)/character.h $(INC_DIR)/game_management.h $(INC_DIR)/link.h $(INC_DIR)/inventory.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/game_management.o: $(SRC_DIR)/game_management.c $(INC_DIR)/game_management.h $(INC_DIR)/game.h $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/object.h $(INC_DIR)/character.h $(INC_DIR)/link.h $(INC_DIR)/inventory.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/object.o: $(SRC_DIR)/object.c $(INC_DIR)/object.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/player.o: $(SRC_DIR)/player.c $(INC_DIR)/player.h $(INC_DIR)/types.h $(INC_DIR)/inventory.h $(INC_DIR)/set.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/set.o: $(SRC_DIR)/set.c $(INC_DIR)/set.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/character.o: $(SRC_DIR)/character.c $(INC_DIR)/character.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/link.o: $(SRC_DIR)/link.c $(INC_DIR)/link.h $(INC_DIR)/types.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/inventory.o: $(SRC_DIR)/inventory.c $(INC_DIR)/inventory.h $(INC_DIR)/types.h $(INC_DIR)/set.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/graphic_engine.o: $(SRC_DIR)/graphic_engine.c $(INC_DIR)/graphic_engine.h $(INC_DIR)/game.h $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/object.h $(INC_DIR)/character.h $(INC_DIR)/libscreen.h $(INC_DIR)/link.h $(INC_DIR)/inventory.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/game_rules.o: $(SRC_DIR)/game_rules.c $(INC_DIR)/game_rules.h $(INC_DIR)/game.h $(INC_DIR)/command.h $(INC_DIR)/types.h $(INC_DIR)/space.h $(INC_DIR)/set.h $(INC_DIR)/player.h $(INC_DIR)/inventory.h $(INC_DIR)/object.h $(INC_DIR)/character.h $(INC_DIR)/link.h
	$(CC) $(CFLAGS) -c $< -o $@

# Enlazado final
$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# ===== TESTS (compilación y ejecución) =====

$(OBJ_DIR)/space_test.o: $(SRC_DIR)/space_test.c $(INC_DIR)/space_test.h $(INC_DIR)/space.h $(INC_DIR)/types.h $(INC_DIR)/set.h $(INC_DIR)/character.h $(INC_DIR)/test.h
	$(CC) $(CFLAGS) -c $< -o $@

space_test: $(OBJ_DIR)/space_test.o $(OBJ_DIR)/space.o $(OBJ_DIR)/set.o $(OBJ_DIR)/character.o
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

$(OBJ_DIR)/inventory_test.o: $(SRC_DIR)/inventory_test.c $(INC_DIR)/inventory_test.h $(INC_DIR)/inventory.h $(INC_DIR)/test.h $(INC_DIR)/set.h
	$(CC) $(CFLAGS) -c $< -o $@

inventory_test: $(OBJ_DIR)/inventory_test.o $(OBJ_DIR)/inventory.o $(OBJ_DIR)/set.o
	$(CC) -o $@ $^

# Reglas de test
testspace: space_test 
	./space_test 
	
testset: set_test 
	./set_test 

testplayer: player_test
	./player_test

testcharacter: character_test
	./character_test

testobject: object_test
	./object_test

testlink: link_test
	./link_test

testinventory: inventory_test
	./inventory_test

run_tests: $(TESTS)
	./space_test 
	./set_test 
	./player_test 
	./character_test 
	./object_test 
	./link_test 
	./inventory_test 

integration_test: $(EXEC)
	@echo "Ejecutando juego con comandos de prueba.cmd..."
	./$(EXEC) dat/cluedo1.dat -l -d output.txt < prueba.cmd
	@diff -q output.txt salida_esperada.txt && echo "✅ Test PASADO: Las salidas coinciden." || (echo "❌ Test FALLADO: Las salidas difieren."; echo "Diferencias:"; diff output.txt salida_esperada.txt)

#Ejecutables Cluedo
run1: $(EXEC)
	./$(EXEC) dat/cluedo1.dat

run1det: $(EXEC)
	./$(EXEC) dat/cluedo1.dat -d

run1log: $(EXEC)
	./$(EXEC) dat/cluedo1.dat -l output.txt

run1logdet: $(EXEC)
	./$(EXEC) dat/cluedo1.dat -l -d output.txt

run2: $(EXEC)
	./$(EXEC) dat/cluedo2.dat

run3: $(EXEC)	
	./$(EXEC) dat/cluedo3.dat

run4: $(EXEC)
	./$(EXEC) dat/cluedo4.dat
	
run5: $(EXEC)
	./$(EXEC) dat/cluedo5.dat

run6: $(EXEC)
	./$(EXEC) dat/cluedo6.dat

# Resto de Ejecutables del juego
run: $(EXEC)
	./$(EXEC) dat/anthill.dat

runlogc: $(EXEC)
	./$(EXEC) dat/cluedo1.dat -l output.txt

rundetc: $(EXEC)
	./$(EXEC) dat/cluedo1.dat -d

rundetlogc: $(EXEC)
	./$(EXEC) dat/cluedo1.dat -d -l output.txt

runlogdetc: $(EXEC)
	./$(EXEC) dat/cluedo1.dat -l -d output.txt 

runcastle: $(EXEC)
	./$(EXEC) dat/castle.dat


#Valgrinds generales
runv:
	valgrind --leak-check=full ./$(EXEC) dat/anthill.dat

runvcastle:
	valgrind --leak-check=full ./$(EXEC) dat/castle.dat

runvloganthill:
	valgrind --leak-check=full ./$(EXEC) dat/anthill.dat -l output.txt - log_input.txt

runvlogcastle:
	valgrind --leak-check=full ./$(EXEC) dat/castle.dat -l output.txt - log_input_castle.txt

#Logs
runloganthill:
	./$(EXEC) dat/anthill.dat -l output.txt - log_input.txt

runlogcastle:
	./$(EXEC) dat/castle.dat -l output.txt - log_input_castle.txt


#Valgrind cluedos
runvc1:
	valgrind --leak-check=full ./$(EXEC) dat/cluedo1.dat
runvc2:
	valgrind --leak-check=full ./$(EXEC) dat/cluedo2.dat
runvc3:
	valgrind --leak-check=full ./$(EXEC) dat/cluedo3.dat
runvc4:
	valgrind --leak-check=full ./$(EXEC) dat/cluedo4.dat
runvc5:
	valgrind --leak-check=full ./$(EXEC) dat/cluedo5.dat
runvc6:
	valgrind --leak-check=full ./$(EXEC) dat/cluedo6.dat

# Documentación
doxyfile:
	doxygen -g $(DOC_DIR)/Doxyfile

docs:
	doxygen $(DOC_DIR)/Doxyfile

cleandocs:
	rm -rf $(DOC_DIR)/html $(DOC_DIR)/latex

# Depuración
debug: $(EXEC)
	gdb -q --args ./$(EXEC) dat/anthill.dat

debugc: $(EXEC)
	gdb -q --args ./$(EXEC) dat/cluedo.dat

# Limpieza
clean:
	rm -f $(EXEC) $(OBJS) $(OBJ_DIR)/*.o $(TESTS)
