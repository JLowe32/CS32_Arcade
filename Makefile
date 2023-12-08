# Makefile for Asteroid

# Compiler
CC = g++

# Compiler Flags
CFLAGS = -Wall -Wextra -std=c++11
LFLAGS = -lGL -lGLU -lglut

# Executable Name
EXE = AsteroidGame

# Source files
SOURCES = main.cpp window.cpp asteroid.cpp player.cpp bullet.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(EXE)

# Linking the executable
$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE) $(LFLAGS)

# Compiling source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Up
clean:
	rm -f $(EXE) $(OBJECTS)

# Dependencies
main.o: window.h
window.o: player.h asteroid.h bullet.h
asteroid.o: asteroid.h
player.o: player.h
bullet.o: bullet.h
