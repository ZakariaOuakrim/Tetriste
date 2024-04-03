#ifndef GAME_H
#define GAME_H

#include "../../dataStructure/DoubleLinkedList/h_files/CircularDoublyLinkedList.h"
#include "../../dataStructure/SimpleLinkedList/h_files/ListeCirculaire.h"

class game {
public:
    CircularDoublyLinkedList bleu, jaune, rouge, vert, carre, losange, rond, triangle;
    ListeCirculaire hand;
    int score;

public:
    // Constructor
    game();

    // Generate next card
    piece nextcard();

    // Insert a piece into the appropriate circular doubly linked list
    void inserer(char c, piece p);

    // Correct the pieces in a circular doubly linked list based on the provided operation
    void corriger(CircularDoublyLinkedList a, int op);

    // Display the current hand
    void showhand();

    // Shift the circular doubly linked list for a specific color to the left
    void decalercouleur(char c);

    // Shift the circular doubly linked list for a specific shape to the left
    void decalershape(char s);

    // Remove a piece from the circular doubly linked lists
    void supp(piece p);

    // Remove a sequence of three identical pieces from the hand
    int supprimer();

    // Check if the game is over
    bool gameover();
};

#endif // GAME_H
