CC=g++

CFLAGS=-c -std=c++2a -Wall -Wextra -Wpedantic -O2

OUTPUT=bin/a.out

INPUTS=obj/main.o

LINK=-lGL -lGLEW -lsfml-window -lsfml-system

LFLAGS=-o $(OUTPUT) $(LINK)

.PHONY: all link clean

########################
#       MAKE ALL       #
########################
all: link

########################
#     LINKER PHASE     #
########################
link: obj/main.o bin
	$(CC) $(INPUTS) $(LFLAGS)

########################
#   COMPILER PHASE 1   #
########################
obj/main.o: obj
	$(CC) $(CFLAGS) src/main.cpp -o obj/main.o

bin:
	mkdir -p bin

obj:
	mkdir -p obj

########################
#   CLEAN EVERYTHING   #
########################
clean:
	rm -rf obj bin

#############################
#        USAGE NOTES        #
#############################
# Build app using $make all #
# Clean using $make clean   #
#############################

