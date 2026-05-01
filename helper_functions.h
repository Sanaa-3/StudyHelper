#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "student.h"
#include <iostream>

#include <vector>

/** 
  greeting funciton to get name of user and introduce program.
	@param none
  no return value
*/
void greeting();


/** 
  use_program funciton to ask user if they want to run the program
	@param none
	return value --> boolean check
*/
bool use_program();

/** 
  repeat_program funciton to ask user if they want to repeat the program
	@param none
	retun value --> boolean check
*/
bool repeat_program();

/** 
  confirm funciton to ask user the question in parameter and ask if the answer is yes or no
	@param none
	retun value --> boolean confirm
*/
bool confirm(const std::string &prompt);


/** 
  student_or_teacher function, asks user if their a student or teacher with data validation
	@param none
	return value: user's answer
*/
std::string student_or_teacher();

/** 
  read_student_names function that reads in the data from student file and stores uses accessors to store data.
	@param bool reversed, user's choice of how they want data sorted
	no return value
*/
void read_student_names(bool reversed);


/** 
  read_student_grades function that reads in the data from student file and stores uses accessors to store data.
	@param bool reversed, user's choice of how they want data sorted
	no return value
*/
void read_student_grades(bool reversed);


/** 
  see_data function, asks user what student data they would like to see and calls appropriate funcitons. 
	@param none
	no return value
*/
void see_data();


/** 
  teacher_options function, gives the teacher options for their account and calls appropriate functions inside, returns 4 if logout 
	@param none
	return value -> logout
*/
int teacher_options(std::string name);

/** 
  function to ask user if they want to see grades in ascending or descending order and calls appropriate funtion.
	@param reversed, user's sorting choice
	no return value
*/
void view_grades(bool reversed);

/** 
  Function to ask user if they want to see names in a-z or z-a order and calls appropriate funtion.
	@param reversed, user's sorting choice
	no return value
*/
void view_names(bool reversed);

/** 
  modify_option function, asks teacher if they would like to modify student data and if they would like to remove or edit data 
	@param none
	no return value
*/
void modify_option();

/** 
  Function that reads in students' data and changes their reward booleans to true if score 90 or above
	@param none
	no return value
*/
void give_rewards();

/** 
  addoredit function, asks user for a student name and based on if the student is already present will call a function to add or edit a student
	@param none
	no return value
*/
void addoredit();

/** 
  remove_student function, removes a student from the class and calls a function to reset the text file data
	@param none
	no return value
*/
void remove_student();

/** 
  assign_score function, updates the score of a student after a test
	@param none
	no return value
*/
void assign_score(std::string, double);

/** 
  assign_studytime function, updates the studytime after studying
	@param none
	no return value
*/
void assign_studytime(std::string, double);


#endif
