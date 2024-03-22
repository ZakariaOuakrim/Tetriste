SFML_INCLUDE = -I"C:\Users\Dell\Desktop\Project\SFML-2.6.1\include"
SFML_LIB = -L"C:\Users\Dell\Desktop\Project\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = sfml-app

SRC = TetristeY.cpp
OBJ = $(SRC:.cpp=.o) dataStructure/DoubleLinkedList/cpp_files/node.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $^ -o $@ $(SFML_LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SFML_INCLUDE)

# Rule to compile circularDoubledLinkedList.cpp into circularDoubledLinkedList.o

startGame: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
