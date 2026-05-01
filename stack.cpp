#include "stack.h"


//--------------------STACK FOR STRINGS-------------------------
Stack::Stack()
{
   const int INITIAL_CAPACITY = 5;
   buffer = new Student[INITIAL_CAPACITY];
   capacity = INITIAL_CAPACITY;
   len = 0;
}

void Stack::push(Student element)
{
   grow_if_necessary();
   buffer[len] = element;
   len++;
}

Student Stack::top() const
{
   return buffer[len-1];
}

void Stack::pop()
{
   len--;
}

int Stack::size() const
{
   return len;
}

void Stack::grow_if_necessary()
{
   if (len == capacity)
   {
      capacity = 2 * capacity;
      Student* larger_buffer = new Student[capacity];
      for (int i = 0; i < len; i++) 
      { 
         larger_buffer[i] = buffer[i]; 
      }      
      buffer = larger_buffer;
   }
}

//--------------------STACK FOR INTEGERS-------------------------

IntStack::IntStack()
{
   const int INITIAL_CAPACITY = 5;
   buffer = new Student[INITIAL_CAPACITY];
   capacity = INITIAL_CAPACITY;
   len = 0;
}

void IntStack::push(Student element)
{
   grow_if_necessary();
   buffer[len] = element;
   len++;
}

Student IntStack::top() const
{
   return buffer[len-1];
}

void IntStack::pop()
{
   len--;
}

int IntStack::size() const
{
   return len;
}

void IntStack::grow_if_necessary()
{
   if (len == capacity)
   {
      capacity = 2 * capacity;
      Student* larger_buffer = new Student[capacity];
      for (int i = 0; i < len; i++) 
      { 
         larger_buffer[i] = buffer[i]; 
      }      
      buffer = larger_buffer;
   }
}
