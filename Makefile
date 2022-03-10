include config.mk

all: $(OBJ)
	$(CC) $? -o $(BIN_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r *.o *.s $(BIN_NAME)