#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

class Node {
public:
  Node(std::string data) {
    this->data = data;
    next = nullptr;
  }
  Node() { next = nullptr; }
  std::string data;
  Node *next;
};

#endif
