#ifndef QUICK_SORT_H
#define  QUICK_SORT_H
#include <iostream>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>
#include <cstdlib>
#include "student.h"

/**
   Swaps two strings.
   @param x the first string to swap
   @param y the second string to swap
*/
void swapnames(Student &x, Student &y);
void swapscore(Student &x, Student &y); //integer version


/**
 Partitions a portion of a vector.
 @param file the vector to partition
 @param from the first index of the portion to be partitioned
 @param to the last index of the portion to be partitioned
 @return the last index of the first partition
*/
int partitionnames(std::vector<Student> &file, int from, int to);
int partitionscore(std::vector<Student> &file, int from, int to); //integer version

/**
 Sorts a portion of a vector, using quick sort.
 @param file the vector to sort
 @param from the first index of the portion to be sorted
 @param to the last index of the portion to be sorted
*/
void quick_sortnames(std::vector<Student> &file, int from, int to);
void quick_sortscore(std::vector<Student> &file, int from, int to); //integer version


#endif
