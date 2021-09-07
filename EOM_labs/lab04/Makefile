 SRC = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJ := $(patsubst %.cpp,%.o,$(SRC))
CC = g++
CXXFLAGS = -Wall -pedantic

all: main run 
	rm *.o main


main: $(OBJ) $(HEADERS)
	$(CC) $(CXXFLAGS) $(OBJ) -o main

clean:
	rm -f vgcore* main.o

run:
	./main

check: main
	valgrind ./main
	