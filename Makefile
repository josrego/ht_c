# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c11

# Source files
SRCS = src/main.c src/hash_table.c src/prime.c

# Header files
HEADERS = src/hash_table.h src/prime.h

# Output executable
TARGET = build/main

# Build target
$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Clean target
clean:
	rm -f $(TARGET)
