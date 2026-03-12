# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDE = -Iinclude
BUILD = build
SRC = src
EXAMPLES = list main

# Library
LIB = $(BUILD)/libnlib.a
LIB_SRC = $(wildcard $(SRC)/*.c)
LIB_OBJ = $(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(LIB_SRC))

# Default target
all: $(LIB) $(EXAMPLES:%=$(BUILD)/%)

# Build object files for library
$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Build static library
$(LIB): $(LIB_OBJ)
	ar rcs $@ $^

# Build example programs
$(BUILD)/%: examples/%.c $(LIB)
	@mkdir -p $(BUILD)
	# Compile example .c to object first
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(BUILD)/$*.o
	# Link example object with library
	$(CC) $(BUILD)/$*.o $(LIB) -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD)/*

main: $(BUILD)/main
	./$<
list: $(BUILD)/list
	./$<


.PHONY: all clean