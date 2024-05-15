# Compiler
CC := gcc
# Compiler flags
CFLAGS := -Wall -Wextra -Iinclude
# Linker flags
LDFLAGS := -Llib
# Libraries to link
LIBS := -lexternal_lib1 -lexternal_lib2

# Source directories
SRCDIR := src
INCDIR := include
BINDIR := build
# Subdirectories within source
SUBDIRS := $(SRCDIR)/LinkedList $(SRCDIR)/main
# Source files
SOURCES := $(foreach dir,$(SUBDIRS),$(wildcard $(dir)/*.c))
# Object files
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SOURCES))
# Executable name
EXEC := $(BINDIR)/DATASTRUCT

# Default rule
all: $(EXEC)

# Rule to compile object files
$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into executable
$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

# Clean rule
clean:
	rm  -rf $(BINDIR)/*  
		    

# Phony targets
.PHONY: all clean
