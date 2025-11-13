CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=++98

all: target

target: main.o
	CXX $(CXXFLAGS) main.o -o target 

main.o: main.c
	CXX $(CXXFLAGS) -c main.c