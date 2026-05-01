#ifndef STACK_H
#define STACK_H

#include <string>
#include "student.h"

class Stack
{
public:   
   /** 
      Constructs an empty stack.
   */
   Stack();

   /**
      Adds an element to the top of the stack.
      @param element the element to add
   */
   void push(Student element);

   /**
      Yields the element on the top of the stack.
      @return the top element
   */
   Student top() const;

   /**
      Removes the element from the top of the stack.
   */
   void pop();

   /**
      Yields the number of elements in this stack.
      @return the size
   */
   int size() const;
  
private:
   void grow_if_necessary();
   
   Student* buffer;
   int len;
   int capacity;
};

//--------------------STACK FOR INTEGERS-------------------------
class IntStack
{
public:   
   /** 
      Constructs an empty stack.
   */
   IntStack();

   /**
      Adds an element to the top of the stack.
      @param element the element to add
   */
   void push(Student element);

   /**
      Yields the element on the top of the stack.
      @return the top element
   */
   Student top() const;

   /**
      Removes the element from the top of the stack.
   */
   void pop();

   /**
      Yields the number of elements in this stack.
      @return the size
   */
   int size() const;
  
private:
   void grow_if_necessary();
   
   Student* buffer;
   int len;
   int capacity;
};

#endif
