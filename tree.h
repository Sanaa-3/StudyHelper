#ifndef TREE_H
#define TREE_H

#include <fstream>
#include <iostream>
#include <map>
#include <string>

class Nodet {
public:
  int data;
  Nodet *left;
  Nodet *right;
  friend class BinaryTree;
};

/*
   A binary tree in which each node has two children.
*/
class BinaryTree {
public:
  /**
     Constructs an empty tree.
  */
  BinaryTree();

  /**
     Constructs a tree with one node and no children.
     @param root_data the data for the root
  */
  BinaryTree(int root_data);

  /**
     Constructs a binary tree.
     @param root_data the data for the root
     @param left the left subtree
     @param right the right subtree
  */
  BinaryTree(int root_data, BinaryTree left, BinaryTree right);

  /**
     Returns the height of this tree.
     @return the height
  */
  int height() const;

  /**
     Checks whether this tree is empty.
     @return true if this tree is empty
  */
  bool empty() const;

  /**
     Gets the data at the root of this tree.
     @return the root data
  */
  int data() const;

  /**
     Gets the left subtree of this tree.
     @return the left child of the root
  */
  BinaryTree left() const;

  /**
     Gets the right subtree of this tree.
     @return the right child of the root
  */
  BinaryTree right() const;

  // void addData(std::string rootdata, std::string animal1, std::string
  // animal2);

private:
  /**
     Returns the height of the subtree whose root is the given node.
     @param n a node or nullptr
     @return the height of the subtree, or 0 if n is nullptr
  */
  int height(const Nodet *n) const;

  Nodet *root;
};

//allows the teacher to make a quiz with up to ten questions then stores the questions and answers for each question and amount of questions made to there own txt file
void make_quiz();

//read quiz info txt files then stores the questions in a map and answers in an array then the user gets to traverse through a tree that will return a certian question if there answer is correct they will go to the right of the tree otherwise they will go to the lseft of the tree this will keep going until the user student reaches the end of the tree and then the program will return there score
double take_quiz();

#endif
