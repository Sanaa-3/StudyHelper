#include "helper_functions.h"
#include "quick_sort.h"
#include "student.h"
//------------------------SORTS STRINGS---------------------
void swapnames(Student &x, Student &y) 
{
	//swaps two strings
		Student temp;
		temp = x; //temp holds x
		x = y; //x holds y
		y = temp; // y holds x now
}

int partitionnames(std::vector<Student> &file, int from, int to)
{
   std::string pivot = file[from].get_name();
   int i = from - 1;
   int j = to + 1;
   while (i < j)
   {
			i++; while (file[i].get_name() < pivot) { i++; }
			j--; while (file[j].get_name() > pivot) { j--; }
			if (i < j) { swapnames(file[i], file[j]); }
   }
   return j;
}

void quick_sortnames(std::vector<Student> &file, int from, int to)
{
	if (from >= to) { return; }
	int p = partitionnames(file, from, to);
	quick_sortnames(file, from, p);
	quick_sortnames(file, p + 1, to);
}

//------------------------SORTS INTEGERS---------------------

void swapscore(Student &x, Student &y)
{
		Student temp;
		temp = x;
		x = y;
		y = temp;
}

int partitionscore(std::vector<Student> &file, int from, int to)
{
   int pivot = file[from].get_quizscore();
   int i = from - 1;
   int j = to + 1;
   while (i < j)
   {
			i++; while (file[i].get_quizscore() < pivot) { i++; }
			j--; while (file[j].get_quizscore() > pivot) { j--; }
			if (i < j) { swapscore(file[i], file[j]); }
		 
   }
   return j;
}

void quick_sortscore(std::vector<Student> &file, int from, int to)
{
	if (from >= to) { return; }
	int p = partitionscore(file, from, to);
	quick_sortscore(file, from, p);
	quick_sortscore(file, p + 1, to);
}
