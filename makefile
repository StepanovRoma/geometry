.PHONY: clean all
CC = g++
CXXFLAGS = -Wall -Werror --std=c++17
EXE = bin/geometry
TESTS = bin/test
DIR_SRC = build/src
DIR_TEST = build/test
GTEST_D = thirdparty/googletest
LD_FLAGS = -L $(GTEST_D)/lib -lgtest_main -lpthread
CFLAG += -isystem $(GTEST_D)/include
CXX += -g -Wall -Wextra -pthread -std=c++17

all: $(EXE) $(TESTS)

$(EXE): $(DIR_SRC)/main.o $(DIR_SRC)/Coord.o $(DIR_SRC)/function.o
	$(CC) $(CXXFLAGS) $(DIR_SRC)/main.o $(DIR_SRC)/Coord.o $(DIR_SRC)/function.o -o $(EXE)

$(DIR_SRC)/main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c src/main.cpp -o $(DIR_SRC)/main.o

$(DIR_SRC)/Coord.o: src/Coord.cpp
	$(CC) $(CXXFLAGS) -c src/Coord.cpp -o $(DIR_SRC)/Coord.o

$(DIR_SRC)/function.o: src/function.cpp
	$(CC) $(CXXFLAGS) -c src/function.cpp -o $(DIR_SRC)/function.o

$(TESTS) : $(DIR_SRC)/Coord.o $(DIR_SRC)/function.o $(DIR_TEST)/test.o
	$(CXX) $(CFLAG) $(LD_FLAGS) $(DIR_SRC)/Coord.o $(DIR_SRC)/function.o  $(DIR_TEST)/test.o -o $(TESTS)

$(DIR_TEST)/test.o: test/test.cpp
	$(CXX) $(CFLAG) -I $(GTEST_D)/include -I src -c test/test.cpp -o $(DIR_TEST)/test.o
	

clean:
	rm -rf $(DIR_SRC)/*.o 
	rm -rf $(DIR_TEST)/*.o
	bin/*.exe
