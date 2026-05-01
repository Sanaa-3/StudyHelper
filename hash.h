#ifndef HASH_H
#define HASH_H

#include "node.h"
#include <fstream>
#include <string>
#include <vector>

/**
   Computes the hash code for a string.
   @param str a string
   @return the hash code
*/
int hash_code(const std::string &str);

/**
   This class implements a hash table using separate chaining.
*/
class HashTable {
public:
  /**
     Constructs a hash table.
     @param nbuckets the number of buckets
  */
  HashTable(int nbuckets);

  /**
     Tests for set membership.
     @param x the potential element to test
     @return 1 if x is an element of this set, 0 otherwise
  */
  int count(const std::string &x);

  /**
     Adds an element to this hash table if it is not already present.
     @param x the element to add
  */
  void insert(const std::string &x);

  /**
     Removes an element from this hash table if it is present.
     @param x the potential element to remove
  */
  void erase(const std::string &x);

  /**
     Gets the number of elements in this set.
     @return the number of elements
  */
  int size() const;

  std::vector<Node *> buckets;
  int current_size;

  void print();
};

// logging in functions \/ \/ \/

// allows people to make a new account
void sign_up();

// allows people to enter info to get see if there logged in or not
bool login();

// outputs result of making new accounts and logging in
int log_in();

// if the user wants enters a password or name with a space it will get rid of
// that space to make it one string
std::string check(std::string word);

#endif
