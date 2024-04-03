#include "../h_files/CircularDoublyLinkedList.h"

CircularDoublyLinkedList::CircularDoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    taille = 0;
}

void CircularDoublyLinkedList::addqueue(piece data) {
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

void CircularDoublyLinkedList::addhead(piece data) {
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

void CircularDoublyLinkedList::display() {
    Node *temp = head;

    if (head == nullptr) {
        std::cout << "Liste vide" << std::endl;
        return;
    }

    while (temp != tail) {
        std::cout << temp->data.color << " " << temp->data.shape << "     ";
        temp = temp->next;
    }

    std::cout << temp->data.color << " " << temp->data.shape << std::endl;
}

void CircularDoublyLinkedList::supprimer(piece p) {
    if (head == tail && (head->data.color == p.color && head->data.shape == p.shape)) {
        delete head;
        head = tail = nullptr;
        taille--;
        return;
    }
    if (head->data.color == p.color && head->data.shape == p.shape) {
        Node *e = head;
        head->next->prev = tail;
        head = head->next;
        tail->next = head;
        delete (e);
        taille--;
        return;
    }
    Node *c = head->next;
    while (c != head) {
        if ((c->data.color == p.color && c->data.shape == p.shape))
            c = c->next;
        else {
            c->prev->next = c->next;
            c->next->prev = c->prev;
            if (c == tail)
                tail = c->prev;
            delete c;
            taille--;
            return;
        }
    }
}

void CircularDoublyLinkedList::shiftleft() {
    if (taille < 2) {
        return;
    }

    Node *courant = head;
    piece temp = head->data;
    while (courant->next != head) {
        courant->data = courant->next->data;
        courant = courant->next;
    }
    tail->data = temp;
}

void CircularDoublyLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    taille = 0;
}
