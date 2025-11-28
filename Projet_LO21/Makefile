OBJ_DIR = objects
BIN_DIR = bin
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(BIN_DIR)/main: $(OBJ)
	@mkdir -p $(BIN_DIR)
	gcc -o $@ $^
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	gcc -o $@ -c $<
clean:
	rm -f $(OBJ_DIR)/*.o
clean-all:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*