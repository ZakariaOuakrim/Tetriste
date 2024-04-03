#include "../h_files/ListeCirculaire.h"
#include <iostream>

using namespace std;

// Constructor definition
ListeCirculaire::ListeCirculaire() {
    premier = nullptr;
    dernier = nullptr;
    taille = 0;
}

// Check if the list is empty
bool ListeCirculaire::estVide() {
    return premier == nullptr;
}

// Add an element at the beginning of the list
void ListeCirculaire::ajouterEnTete(piece valeur) {
    Cellule* nouvelleCellule = new Cellule(valeur);

    if (estVide()) {
        premier = dernier = nouvelleCellule;
    } else {
        nouvelleCellule->suivant = premier;
        premier = nouvelleCellule;
        dernier->suivant = premier;
    }
    taille++;
}

// Add an element at the end of the list
void ListeCirculaire::ajouterEnFin(piece valeur) {
    Cellule* nouvelleCellule = new Cellule(valeur);

    if (estVide()) {
        premier = dernier = nouvelleCellule;
    } else {
        dernier->suivant = nouvelleCellule;
        dernier = nouvelleCellule;
        dernier->suivant = premier;
    }
    taille++;
}

// Display the list
void ListeCirculaire::afficher() {
    Cellule* temp = premier;
    for (int i = 0; i < taille; i++) {
        cout << temp->valeur.color << " " << temp->valeur.shape << "   ";
        temp = temp->suivant;
    }
    cout << endl;
}

// Initialize the list
void ListeCirculaire::init() {
    premier = nullptr;
    dernier = nullptr;
    taille = 0;
}
