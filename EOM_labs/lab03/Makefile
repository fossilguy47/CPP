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
	rm *.o main

run:
	./main

check: main
	valgrind ./main
	
