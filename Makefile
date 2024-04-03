SFML_INCLUDE = -I"SFML-2.6.1\include"
SFML_LIB = -L"SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = sfml-app

SRC = TetristeY.cpp
OBJ = $(SRC:.cpp=.o) dataStructure/DoubleLinkedList/cpp_files/node.o dataStructure/DoubleLinkedList/cpp_files/CircularDoublyLinkedList.o dataStructure/SimpleLinkedList/cpp_files/Cellule.o dataStructure/SimpleLinkedList/cpp_files/ListeCirculaire.o Game/cpp_files/game.o Game/cpp_files/TerminalMode.o Game/cpp_files/Gui.o 

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $^ -o $@ $(SFML_LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SFML_INCLUDE)


startGame: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
