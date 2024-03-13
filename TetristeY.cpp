#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

typedef struct {
    string color;
    string shape;
} piece;

class Node {
public:
    piece *data;
    Node *prev;
    Node *next;

    Node(piece *data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class CircularDoublyLinkedList {
public:
    Node *head;
    Node *tail;
    int taille;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        taille = 0;
    }

    void addqueue(piece *data) {
        Node *newNode = new Node(data);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        tail->next = head;
        head->prev = tail;
        taille++;
    }

    void addhead(piece *data) {
        Node *newNode = new Node(data);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->next->prev = newNode;
            head = newNode;
        }

        tail->next = head;
        head->prev = tail;
        taille++;
    }

    void display() {
        Node *temp = head;

        if (head == nullptr) {
            cout << "Liste vide" << endl;
            return;
        }

        while (temp != tail) {
            cout << temp->data->color << " " << temp->data->shape <<"     ";
            temp = temp->next;
        }

        cout << temp->data->color << " " << temp->data->shape<< endl;
    }
void supprimer(piece *p){
if(head==tail&&head->data==p){
    delete head;
    head=tail=nullptr;
    taille--;
    return;
    }
if(head->data==p){
    Node *e=head;
    head->next->prev=tail;
    head=head->next;
    tail->next=head;
    delete(e);
    taille--;
    return;
}
Node *c=head->next;
while(c!=head){
    if(c->data!=p)
    c=c->next;
    else{
        c->prev->next=c->next;
        c->next->prev=c->prev;
    if(c==tail)
        tail=c->prev;
    delete c;
    taille--;
    return;
    }

}
}

    void shiftleft() {
        if (taille<2) {
            return;
        }

        Node *courant = head;
        piece temp = *head->data;
        while (courant->next != head) {
            *courant->data = *courant->next->data;
            courant = courant->next;
        }

        *tail->data = temp;
    }
};

class Cellule {
public:
    piece *valeur;
    Cellule *suivant;

    Cellule(piece *valeur) {
        this->valeur = valeur;
        suivant = nullptr;
    }
};

class ListeCirculaire {
public:
    Cellule *premier;
    Cellule *dernier;
    int taille;

public:
    ListeCirculaire() {
        premier = nullptr;
        dernier = nullptr;
        taille = 0;
    }

    bool estVide() {
        return premier == nullptr;
    }

    void ajouterEnTete(piece *valeur) {
        Cellule *nouvelleCellule = new Cellule(valeur);

        if (estVide()) {
            premier = dernier = nouvelleCellule;
        } else {
            nouvelleCellule->suivant = premier;
            premier = nouvelleCellule;
            dernier->suivant = premier;
        }
        taille++;
    }

    void ajouterEnFin(piece *valeur) {
        Cellule *nouvelleCellule = new Cellule(valeur);

        if (estVide()) {
            premier = dernier = nouvelleCellule;
        } else {
            dernier->suivant = nouvelleCellule;
            dernier = nouvelleCellule;
            dernier->suivant = premier;
        }
        taille++;
    }

    void afficher() {
        Cellule *temp = premier;
        for (int i = 0; i < taille; i++) {
            cout << temp->valeur->color << " " << temp->valeur->shape << "   ";
            temp = temp->suivant;
        }

        cout << endl;
    }
};

class game {
public:
    CircularDoublyLinkedList bleu, jaune, rouge, vert, carre, losange, rond, triangle;
    ListeCirculaire hand;
    int score;
game(){
score=0;
}
    piece nextcard() {
        piece p;
        string couleurs[] = {"bleu", "rouge", "vert", "jaune"};
        p.color = couleurs[std::rand() % 4];
        string shapes[] = {"losange", "rond", "carre", "triangle"};
        p.shape = shapes[std::rand() % 4];
        return p;
    }

    void inserer(char c,piece *p) {

        switch (p->color[0]) {
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

        switch (p->shape[0]) {
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

    void showhand() {
        hand.afficher();
    }

    void decalercouleur(char c) {
        switch (c) {
            case 'b':
                bleu.shiftleft();
                break;
            case 'j':
                jaune.shiftleft();
                break;
            case 'r':
                rouge.shiftleft();
                break;
            case 'v':
                vert.shiftleft();
                break;
        }
    }

    void decalershape(char s) {
        switch (s) {
            case 'l':
                losange.shiftleft();
                break;
            case 'c':
                carre.shiftleft();
                break;
            case 'r':
                rond.shiftleft();
                break;
            case 't':
                triangle.shiftleft();
                break;
        }
    }
void supp(piece *p) {

        switch (p->color[0]) {
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

        switch (p->shape[0]) {
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
void supprimer(){
if(hand.taille>=3){
Cellule *t1,*t2,*t3,*pred;
t1=hand.premier;t2=t1->suivant;t3=t2->suivant;pred=hand.dernier;
while(t3!=hand.premier){
    if(((t1->valeur->color==t2->valeur->color)&&(t1->valeur->color==t3->valeur->color))||((t1->valeur->shape==t2->valeur->shape)&&(t1->valeur->shape==t3->valeur->shape))){
        pred->suivant=t3->suivant;
        if(t1==hand.premier)
            hand.premier=t3->suivant;
        if(t3==hand.dernier)
            hand.dernier=pred;
        supp(t1->valeur);supp(t2->valeur);supp(t3->valeur);
        delete t1;delete t2;delete t3;
        hand.taille-=3;
        score+=5;
        return;
    }
 pred=t1;
 t1=t1->suivant; t2=t1->suivant ; t3=t2->suivant ;
}
}
}
    bool gameover() {
        return !(hand.taille == 15);
    }
};

int main() {
    bool gamestat = true;
    srand(static_cast<unsigned>(time(0)));

    game g;
    int choix1;
    char choix2;

    while (gamestat) {
        system("cls");
        piece *p = new piece(g.nextcard());
        cout << "Next piece: "<<p->color<<" "<<p->shape<<"                   "<<"Score  : "<< g.score<<endl;
        cout <<"\n" ;
        cout << "-----------My Hand (liste principale)------------" << endl;
        g.showhand();
        cout <<"------------Liste Color---------------\n" ;
        cout <<"\033[31mrouge: \033[0m" ;g.rouge.display();
        cout << "\033[34mbleu: \033[0m" ;g.bleu.display();
        cout << "\033[33mjaune: \033[0m" ;g.jaune.display();
        cout << "\033[32mvert: \033[0m" ;g.vert.display();
        cout <<"------------Liste Shape---------------\n" ;
        cout << "losange:" ;g.losange.display();
        cout << "carre:" ;g.carre.display();
        cout << "triangle:" ;g.triangle.display();
        cout << "rond:" ;g.rond.display();
        cout <<"------------Commandes Game---------------\n" ;
        cout << "1 decaler couleur" << endl;
        cout << "2 decaler shapes" << endl;
        cout << "3 inserer en tete" << endl;
        cout << "4 inserer en queue" << endl;
        cout << "=>";
        choix1=getch();

        switch (choix1-'0') {
            case 1:
                cout << "r selon rouges" << endl;
                cout << "v selon verts" << endl;
                cout << "j selon jaune" << endl;
                cout << "b selon bleu" << endl;
                cout << "=>";
                choix2=getch();
                g.decalercouleur(choix2);
                break;
            case 2:
                cout << "l selon losanges" << endl;
                cout << "c selon carre" << endl;
                cout << "r selon rond" << endl;
                cout << "t selon triangle" << endl;
                cout << "=>";
                choix2=getch();
                g.decalershape(choix2);
                break;
            case 3:
                g.inserer('g',p);
                break;
            case 4:
                g.inserer('d',p);
                break;
        }
        g.supprimer();
        gamestat=g.gameover();
    }

    return 0;
}
