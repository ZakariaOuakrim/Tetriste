#ifndef LISTECIRCULAIRE_H
#define LISTECIRCULAIRE_H

#include "Cellule.h"

class ListeCirculaire {
public:
    Cellule* premier;
    Cellule* dernier;
    int taille;

public:
    // Constructor
    ListeCirculaire();

    // Check if the list is empty
    bool estVide();

    // Add an element at the beginning of the list
    void ajouterEnTete(piece valeur);

    // Add an element at the end of the list
    void ajouterEnFin(piece valeur);

    // Display the list
    void afficher();

    // Initialize the list
    void init();
};

#endif // LISTECIRCULAIRE_H
