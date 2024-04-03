#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include <iostream>
#include "node.h"
#include "../../Piece/piece.h"

class CircularDoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    int taille;

public:
    CircularDoublyLinkedList();

    void addqueue(piece data);

    void addhead(piece data);

    void display();

    void supprimer(piece p);

    void shiftleft();

    void init();
};

#endif // CIRCULARDOUBLYLINKEDLIST_H
