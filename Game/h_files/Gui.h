#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"
#include <queue>
using namespace std;

class GUI
{
private:
    sf::RenderWindow window;
    sf::Music musicGame;
    sf::Sound insertSound, destroySound, swapSound, lostSound;
    sf::SoundBuffer bufferInsert, bufferDestroy, bufferSwap, bufferLost;
    sf::Event event;
    sf::Shape *shape;
    sf::Font scoreFont;
    sf::Text scoreText, nextText, lostText, doubleText, countDownText;
    game _game;
    int score;
    queue<piece> nextElements; //this one is used for seeing the next elements that the user will have in hand 
    bool timeUp=false;
    int currentTime=60;
    piece p;

    sf::Shape *createShape(char shape);
    void colorShape(char color, sf::Shape *shape);
    void soundImport();
    int handleShortcuts();
    void drawAllShapesThatAreInHand();
    void initAllElementsOfTheGame();
    void topScores(int score);
    void displayPieceInTheQueue();
    bool countDown(int seconds);
public:
    GUI();
    void startWindowGame();
    void start();
};

#endif // GUI_H
