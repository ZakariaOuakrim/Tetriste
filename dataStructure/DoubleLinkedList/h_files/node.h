#ifndef NODE_H
#define NODE_H
#include "../../Piece/piece.h"

class Node
{
public:
    piece *data;
    Node *prev;
    Node *next;

    Node(piece *data);
};
#endif
