#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"

class GUI {
private:
    sf::RenderWindow window;
    sf::Music musicGame;
    sf::Sound insertSound, destroySound, swapSound, lostSound;
    sf::SoundBuffer bufferInsert, bufferDestroy, bufferSwap, bufferLost;
    sf::Event event;
    sf::Shape *shape;
    sf::Font scoreFont;
    sf::Text scoreText, nextText, lostText;
    piece *tab[3];
    game _game;
    int score;

    piece p;

    sf::Shape *createShape(std::string shape);
    void colorShape(std::string color, sf::Shape *shape);
    void soundImport();
    int handleShortcuts();
    void drawAllShapesThatAreInHand();
    void initTab();
    void drawWaitingElements();
    void initAllElementsOfTheGame();
    void topScores(int score);

public:
    GUI();
    void startWindowGame();
    void start();
};

#endif // GUI_H
