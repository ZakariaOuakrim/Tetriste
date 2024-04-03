#ifndef CELLULE_H
#define CELLULE_H

#include "../../Piece/piece.h"

class Cellule {
public:
    piece valeur;
    Cellule* suivant;

    // Constructor
    Cellule(piece valeur);
};

#endif // CELLULE_H
