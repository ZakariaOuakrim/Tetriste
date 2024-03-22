#include "../h_files/node.h"

Node::Node(piece *data)
{
    this->data = data;
    prev = nullptr;
    next = nullptr;
}
