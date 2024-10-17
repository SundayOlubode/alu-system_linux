
# hnm_main: hnm_main.c
# 	gcc -static -o hnm_main hnm_main.c

# hnm: hnm_main
# 	./hnm_main ${ARGS}

# Makefile to compile and run hnm

# Variables
CC = gcc                      # The compiler
CFLAGS = -Wall -std=c99        # Compilation flags with C99 standard
TARGET = hnm                   # The final executable name
SRC = hnm_main.c               # The C source file

# Rule to compile the C file into an executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up compiled files
clean:
	rm -f $(TARGET)
