#include "../h_files/game.h"
#include "string"
using namespace std;


// Constructor definition
game::game() {
    score = 0;
}

// Generate next card
piece game::nextcard() {
    piece p;
    string couleurs[] = {"bleu", "rouge", "vert", "jaune"};
    p.color = couleurs[std::rand() % 4];
    string shapes[] = {"losange", "rond", "carre", "triangle"};
    p.shape = shapes[std::rand() % 4];
    return p;
}

// Insert a piece into the appropriate circular doubly linked list
void game::inserer(char c, piece p) {
    switch (p.color[0]) {
        case 'b':
            if (c == 'g')
                bleu.addhead(p);
            else
                bleu.addqueue(p);
            break;
        case 'j':
            if (c == 'g')
                jaune.addhead(p);
            else
                jaune.addqueue(p);
            break;
        case 'r':
            if (c == 'g')
                rouge.addhead(p);
            else
                rouge.addqueue(p);
            break;
        case 'v':
            if (c == 'g')
                vert.addhead(p);
            else
                vert.addqueue(p);
            break;
    }

    switch (p.shape[0]) {
        case 'l':
            if (c == 'g')
                losange.addhead(p);
            else
                losange.addqueue(p);
            break;
        case 'c':
            if (c == 'g')
                carre.addhead(p);
            else
                carre.addqueue(p);
            break;
        case 'r':
            if (c == 'g')
                rond.addhead(p);
            else
                rond.addqueue(p);
            break;
        case 't':
            if (c == 'g')
                triangle.addhead(p);
            else
                triangle.addqueue(p);
            break;
    }

    if (c == 'd')
        hand.ajouterEnFin(p);
    else
        hand.ajouterEnTete(p);
}

// Correct the pieces in a circular doubly linked list based on the provided operation
void game::corriger(CircularDoublyLinkedList a, int op) {
    Node *temp = a.head;
    Cellule *c = hand.premier;
    if (op == 1) {
        do {
            if (c->valeur.color[0] == temp->data.color[0]) {
                c->valeur.shape = temp->data.shape;
                temp = temp->next;
            }
            c = c->suivant;
        } while (c != hand.premier);
    }
    if (op == 2) {
        do {
            if (c->valeur.shape[0] == temp->data.shape[0]) {
                c->valeur.color = temp->data.color;
                temp = temp->next;
            }
            c = c->suivant;
        } while (c != hand.premier);
    }
}

// Display the current hand
void game::showhand() {
    hand.afficher();
}

// Shift the circular doubly linked list for a specific color to the left
void game::decalercouleur(char c) {
    switch (c) {
        case 'b':
            bleu.shiftleft();
            corriger(bleu, 1);
            break;
        case 'j':
            jaune.shiftleft();
            corriger(jaune, 1);
            break;
        case 'r':
            rouge.shiftleft();
            corriger(rouge, 1);
            break;
        case 'v':
            vert.shiftleft();
            corriger(vert, 1);
            break;
    }
}

// Shift the circular doubly linked list for a specific shape to the left
void game::decalershape(char s) {
    switch (s) {
        case 'l':
            losange.shiftleft();
            corriger(losange, 2);
            break;
        case 'c':
            carre.shiftleft();
            corriger(carre, 2);
            break;
        case 'r':
            rond.shiftleft();
            corriger(rond, 2);
            break;
        case 't':
            triangle.shiftleft();
            corriger(triangle, 2);
            break;
    }
}

// Remove a piece from the circular doubly linked lists
void game::supp(piece p) {
    switch (p.color[0]) {
        case 'b':
            bleu.supprimer(p);
            break;
        case 'j':
            jaune.supprimer(p);
            break;
        case 'r':
            rouge.supprimer(p);
            break;
        case 'v':
            vert.supprimer(p);
            break;
    }

    switch (p.shape[0]) {
        case 'l':
            losange.supprimer(p);
            break;
        case 'c':
            carre.supprimer(p);
            break;
        case 'r':
            rond.supprimer(p);
            break;
        case 't':
            triangle.supprimer(p);
            break;
    }
}

// Remove a sequence of three identical pieces from the hand
int game::supprimer() {
    if (hand.taille >= 3) {
        Cellule *t1, *t2, *t3, *pred;
        t1 = hand.premier;
        t2 = t1->suivant;
        t3 = t2->suivant;
        pred = hand.dernier;
        while (t3 != hand.premier) {
            if (((t1->valeur.color == t2->valeur.color) && (t1->valeur.color == t3->valeur.color)) || ((t1->valeur.shape == t2->valeur.shape) && (t1->valeur.shape == t3->valeur.shape))) {
                pred->suivant = t3->suivant;
                if (t1 == hand.premier)
                    hand.premier = t3->suivant;
                if (t3 == hand.dernier)
                    hand.dernier = pred;
                supp(t1->valeur);
                supp(t2->valeur);
                supp(t3->valeur);
                delete t1;
                delete t2;
                delete t3;
                hand.taille -= 3;
                score += 5;
                return 1;
            }
            pred = t1;
            t1 = t1->suivant;
            t2 = t1->suivant;
            t3 = t2->suivant;
        }
    }
    return 0;
}

// Check if the game is over
bool game::gameover() {
    return !(hand.taille == 15);
}
