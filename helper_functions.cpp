#include "helper_functions.h"
#include "quick_sort.h"
#include "stack.h"
#include <fstream>
#include <vector>


//greeting function to take in user's name and provide program description.
void greeting()
{
	std::cout << "Welcome!"; //no need for name input with login system
	std::cout << "\nThis program will help you take practice quizzes and work on your study habits as a student. As a teacher, it will help you track your student's progress as well as give rewards when appropriate. " << std::endl;
}


//function to ask user if they want to run program. Includes data validation. 
bool use_program()
{
	bool continues = false; //boolean for the while loop
	bool check = false;//boolean for the return 
	
	while (!continues)
	{
		std:: cout<< "\nWould you like to run the program? (y/n) ";
		std:: string use; 
		std:: cin>> use; 
		
		if (use == "y"|| use== "Y") // if correct input
		{
			continues = true; 
			check = true; //returns true, function ends
		}
		else if(use == "n"|| use=="N" ) // if correct input
		{
			continues = true;
			check = false; //returns false, function ends
			std:: cout<< "Goodbye, have a nice day!"<< std:: endl;
			return check;
		}
		else
		{
			std::cout<<"Please enter yes or no "<<std::endl; //reprompts user
		}
	}
	return check;
}


//function to ask user if they want to repeat program. Includes data validation. 
bool repeat_program()
{
	bool continues = false; //boolean for the while loop
	bool check = false;//boolean for the return 
	
	while (!continues){
		std:: cout<< "\n\nWould you like to repeat the program? (y/n) ";
		std:: string repeat;
		std:: cin>> repeat;
		
		if (repeat == "y"|| repeat== "Y"){ // if correct input
			continues = true; //returns true, function ends
			check = true; 
		}
		else if(repeat == "n"|| repeat=="N" ){ // if correct input
			continues = true;
			check = false;  //returns false, function ends
			std:: cout<< "Goodbye, have a nice day!"<< std:: endl;
			return check;
		}
		else{
			std::cout<<"Please enter yes or no "<<std::endl; //reprompts user for input
		}
	}
	return check;
}


//function to ask user the given string and take input
bool confirm(const std::string &prompt) {
  while (true) {
    // Receive raw input from user
    std::string input;
    std::cout << prompt << ": ";
    std::cin >> input;

    if (!std::cin.fail() && !input.empty()) {
      // Check if the first character
      // is either y/n and serialize
      // to a boolean
      char c = tolower(input[0]);
      switch (c) {
      case 'y':
        return true;
      case 'n':
        return false;
      }
    }
    std::cout << "Invalid input (only enter y/n).\n";
    std::cin.clear();
    std::cin.ignore();
  }
}

//function to ask user if they are a student or a teacher
std::string student_or_teacher()
{
  std::string input = ""; 
	//asks user i f they're a student or teacher
  std::cout << "\nHello user! Are you a student or a teacher using our program today?: ";
  std::cin >> input;
  while(input != "student" && input != "teacher"){ //while invalid input
    std::cout << "Please enter either student or teacher: ";
    std::cin >> input; //reprompts user
  }
  return input;
}


//funtion to read student names from file and call quick sort.
void read_student_names(bool reversed){ 
  Student temps;
  std::vector<Student> temp = temps.getdata();

  if(temp.size()==0) //if there are no registered students yet
  {std::cout<<"There is no current student data"<<std::endl;}
  
	quick_sortnames(temp, 0, temp.size()-1); //call to quick sort with vector start and end as parameters
  
	Stack stack; 
	if (reversed) { // if user wants data in reversed order
		for(int i = 0; i < temp.size(); i++)	{ //add ordered data to stack
			stack.push(temp[i]);  //adds data to stack
		}
		while(stack.size() > 0)	{ //print stack to reverse data
			std::cout << stack.top().get_name() << ": " <<  stack.top().get_quizscore() << "\n";
			stack.pop(); 
		}
	}
	else{
		//prints the names that were sorted using the quick_sort call
		for(int i = 0; i < temp.size(); i++) {
			std::cout << temp[i].get_name() << ": " << temp[i].get_quizscore() << "\n";
		}
	}
}

//funtion to read student names from file and call quick sort.
void read_student_grades(bool reversed){
	Student temps;
  std::vector<Student> temp = temps.getdata(); //call to quick sort with vector start and end as parameters
  
  if(temp.size()==0) //if there are no registered students yet
  {std::cout<<"There is no current student data"<<std::endl;}
	
	quick_sortscore(temp, 0, temp.size()-1);  

	IntStack intstack; 
	if (reversed) {  // if user wants data in reversed order
		for(int i = 0; i < temp.size(); i++)	{ //add ordered data to stack
			intstack.push(temp[i]); //adds data to stack
		}
		while(intstack.size() > 0)	{ //print stack to reverse data
			std::cout << intstack.top().get_name() << ": " << intstack.top().get_quizscore() << "\n";
			intstack.pop();
		}
	}
	else{
		//prints the names that were sorted using the quick_sort call
		for(int i = 0; i < temp.size(); i++) {
			std::cout << temp[i].get_name() << ": " << temp[i].get_quizscore() << "\n";
		}
	}
}

//function to update the score based on the parameters given and update the text file
void assign_score(std::string username, double score) {
  Student temps;
  std::vector<Student> temp = temps.getdata(); //get data from text file to a vector
  bool unregistered = true;
  int i;
  for(i = 0; i < temp.size(); i++) { //find the student to update
    if(username == temp[i].get_name()) { unregistered = false;  break; }
  }

  if(unregistered) {
    std::cout << "You are an unregistered student and the score will not be recorded.\n";
    return;
  } else { 
    std::cout << "Your score has been recorded and you eligible to get a reward.\n";
    temp[i].set_quizscore(score); //update the score
    temp[i].set_reward(false); //reset reward stat
  }

  temps.move_data(temp); //calls function to update the text file
}

//function to update the studytime of student (follows the same format as assign score)
void assign_studytime(std::string username, double studytime) {
  Student temps;
  std::vector<Student> temp = temps.getdata(); //reads in student data and stores in a vector
  bool unregistered = true;
  int i;
  for(i = 0; i < temp.size(); i++) { //goes through data for each student
    if(username == temp[i].get_name()) { unregistered = false;  break; } //if datat is found, break and then move data to textt file
  }

  if(unregistered) { //if name is not found in the data
    std::cout << "You are an unregistered student and the study time will not be recorded.\n";
    return;
  } else {
    std::cout << "Your studytime has been recorded.\n";
    int newstudytime = temp[i].get_studytime() + studytime; //recoreds the study time
    temp[i].set_studytime(newstudytime); //sets the study time for the student
  }

  temps.move_data(temp);  //move data to text file
}
