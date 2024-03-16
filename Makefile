SFMLINCLUDE = -I"C:\Users\Dell\Desktop\Project\SFML-2.6.1\include"
SFMLLIB= -L"C:\Users\Dell\Desktop\Project\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:sfml-app
	./sfml-app

startGame:
	./sfml-app
TetristeY.o: TetristeY.cpp
	g++ -c TetristeY.cpp $(SFMLINCLUDE)

sfml-app: TetristeY.o
	g++ TetristeY.o -o sfml-app $(SFMLLIB)
	
clean:
	rm TetristeY.o sfml-app