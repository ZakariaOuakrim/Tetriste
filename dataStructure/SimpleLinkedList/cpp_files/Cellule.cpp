#include "../h_files/Cellule.h"

// Constructor definition
Cellule::Cellule(piece valeur) {
    this->valeur = valeur;
    suivant = nullptr;
}
