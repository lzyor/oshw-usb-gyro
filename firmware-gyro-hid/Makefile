# Makefile template for stc8h projects using SDCC

# Compiler and linker flags
CFLAGS = -mmcs51 --std-sdcc2x --model-large --opt-code-speed \
		 --code-size 0xffff --xram-size 0x2000

# Define the compiler and the linker
# CC = sdcc
CC := $(if $(shell echo $$SDCC_PATH),$(shell echo $$SDCC_PATH),sdcc)

# Define the project directories
SRCDIR = src
INCDIR = inc
BINDIR = bin

# Define the target name
TARGET = $(BINDIR)/main.ihx
ENTRY = main.c

# Define the C source and header files
SRC := $(filter-out $(SRCDIR)/$(ENTRY), $(wildcard $(SRCDIR)/*.c))
OBJ = $(SRC:$(SRCDIR)/%.c=$(BINDIR)/%.rel)
INC = -I$(INCDIR)

# Define the phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Link the object files into the final binary
$(TARGET): $(OBJ) $(SRCDIR)/$(ENTRY)
	$(CC) $(CFLAGS) $(INC) -o $(TARGET) $^
	@cat $(BINDIR)/main.mem

# Compile the source files into object files
$(BINDIR)/%.rel: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Clean up the build files
clean:
	rm -f ./$(BINDIR)/*
