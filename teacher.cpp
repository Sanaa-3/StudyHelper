#include "helper_functions.h"
#include "tree.h"
#include <iostream>

//Option 1 Make a Quiz    Option 2 View Student Data     Option 3 Logout
int teacher_options(std::string name) //By Sanaa using Eshaan's starter code
{
  std::cout << "\nHello " << name << ", welcome to the portal. What would you like to do today?\n";
  std::cout << "Option 1: Make a Practice Quiz\nOption 2: View Student Data\n";
  std::cout << "Option 3: Give Rewards\n" << "Option 4: Logout\n";
  int input = 0;
  bool corr = false;
  std::string temp;
  while(!corr) //While user input is not valid
  {
    input = 0;
    std::cout << "Enter the number of the option(1, 2, 3, 4): ";
    std::cin >> input; //takes in inpit
    while((input <= 0 || input > 4 || std::cin.fail())) //input validation loop
    {
      std::cout << "That was not a valid option. Please enter a valid option: ";
      std::cin.clear();   //cin clear and ignore to clear the cache
      std::cin.ignore();
      std::cin >> input; //user is prompted to enter an option # again
    }
    temp = "Would you like to continue with option " + std::to_string(input) + "?";
    corr = confirm(temp); //confirm function gets input for parameters question and returns boolean true or false
  }
  if(input == 1) { //if teacher wants to make a practice quiz
    make_quiz();
  }
	if(input == 2){ //if teacher wants to see student data
		see_data();
	}
	if(input ==  3){ //if teacher wants to give rewards
		give_rewards();
	}
  return input;
}


void see_data(){ 
	bool reversed = false;
	std::string topic;
	std::cout << "\nWould you like to see student grades or names? ";
	std::cin >> topic; //user chooses if they want to see names or grades

	//data validation
	while (topic != "grades" && topic != "names"){
		std::cout << "Please enter either grades or names: "; 
		std::cin >> topic; //reprompts user for valid input
	}

	if (topic == "grades"){
		view_grades(reversed); //call to function to view grades with user's reversed choice passed
	}
	else if(topic == "names"){
		view_names(reversed); //call to funciton to view names with user's reversed choice passed
	}
	
	modify_option(); //allow teacher to modify any data after viewing the data
}

//function to ask teacher if they would like to modify student data
void modify_option(){
	std::string modify = "";
	std::cout << "\nWould you like to modify the data? (y/n): ";
	std::cin >> modify;

	//data validation
	while (modify != "y" && modify != "n"){
	  std::cout << "Please enter either y  or n: ";
  	std::cin >> modify;
	}
	
	if(modify == "y"){ //if teacher wants to modify
    std::string edit = "";
    std::cout << "\nWill you be changing a student's data or removing a student? (edit/remove): ";
    std::cin >> edit;
    while (edit != "edit" && edit != "remove"){ //asking user if they would like to edit or remove data
	    std::cout << "Please enter either edit or remove: ";
    	std::cin >> edit;
	  }
    if(edit == "edit") {
      addoredit(); //enter addoredit function
    } else {
      remove_student(); //enter remove function
    }
	}
	else{  //if teacher chooses not to modify data
		std::cout << "Okay, you chose not modify any student data. ";
		return; 
	}
}


void give_rewards(){
	
	std::cout << "\nOkay! you can give rewards based on students' grades";
	std::cout << "\nThe students with grades 90 and above will recieve rewards.\n";

	Student temps; //makes a student object
	std::vector<Student> data = temps.getdata(); // gets student data and stores it inn a vector
  
	std::cout << "\nBelow are the names of the students who just received rewards!\n";
  
	for(int i = 0; i < data.size(); i++){ //goes through each student's grades
		if(data[i].get_quizscore() >= 90){ //if quiz score is 90 or above
			data[i].set_reward(true); //change student's reward boolean to true
			std::cout << data[i].get_name() << "\n"; //outputs to console the names of the students who just received rewards.
		}
	}
	temps.move_data(data); //call to function to update student data in text file.
}

//function to sort names in user's prefered order
void view_names(bool reversed){
	std::string option;
	std::cout << "would you like to see the students' names from A-Z (a) or Z-A (z) order? enter a or z: ";
	std::cin >> option;
	
	//data validation
	while (option != "a" && option != "z"){ //while input is not valid
	  std::cout << "Please enter either a for A-Z or z for Z-A order: ";
  	std::cin >> option; //reprompts user for valid input
	}
	
	if (option == "a"){ //if user wants to sort names alphabetically 
		reversed = false; //data does not have to be reversed.
		read_student_names(reversed); //student names is printed from A-Z
	}
	else if (option == "z"){ //if user does not want names sorted alphabetically
		reversed = true; //data needs to be reversed using a stack
		read_student_names(reversed);  //student names is printed from Z-A
	}
}

//function to sort grades in user's prefered order
void  view_grades(bool reversed){
	std::string option;
	std::cout << "Would you like to see your grades in ascending or descending order? (a/d): ";
	std::cin >> option;
	
	//data validation
	while (option != "a" && option != "d"){//while input is not valid
	  std::cout << "Please enter either a for ascending or d for descending: ";
  	std::cin >> option;//reprompts user for valid input
	}
	
	if (option == "a"){ //if user wants to sort grades in ascending order 
		reversed = false;  //data does not have to be reversed.
		read_student_grades(reversed);//student grades is printed in ascending order
	}
	else if (option == "d"){ //if user wants to sort grades in descending order 
		reversed = true; //data needs to be reversed using a stack
		read_student_grades(reversed); //student grades is printed in descending order
	}
}


void addoredit()
{
  std::cout << "Please give the name of the student that you would like to edit.\n";
  std::cout << "If the student does not exist, then a new student will be made and added\n";
  bool goodname = true; //if the name entered is found in textfile, goodname = true
  std::string studentname;
  while(goodname) { //loop for input validation
    goodname = false;
    std::cout << "What is the name?: ";
    std::cin >> studentname; 
    for(int i = 0; i < studentname.size(); i++) //looks through characters of student name
    {
      if(isdigit(studentname[i])) {  //if there are digit's in the name
        goodname = true;
        std::cout << "Please enter a name with no numbers involved: ";
        break;
      }
    }
  }
  Student temps;
  std::vector<Student> temp = temps.getdata(); //gets student's data and stores in a vector
  bool neworedit = true;
  for(int i = 0; i < temp.size(); i++){ //check if the stundet already exists
    if(studentname == temp[i].get_name()) { //if student exists
      neworedit = false;
      temps.edit_student(temp, i); //edit that student in another function
      break;
    }
  }

  if(neworedit) { //if student doesn't exist
    temps.new_student(temp, studentname); //add student in another function
  }
  temps.move_data(temp); //transfer data to text file
}

//function to edit student at given index in parameter
void Student::edit_student(std::vector<Student>& temp, int i)
{
  Student editable = temp[i]; //creat a student to edit
  std::string name = editable.get_name();
  std::cout << "\nWhat part of " << name << "'s data would you like to edit?\n";
  std::cout << "Would you like to edit there score or manually give them a reward?(score/reward): ";
  std::string input;
  std::cin >> input; //take input on data to be edited
  while(input != "score" && input != "reward") //input validation
  {
    std::cout << "Please enter either reward or score!: ";
    std::cin >> input;
  }
  if(input == "reward") //if teacher would like to edit reward it just toggles the reward
  {
    if(editable.get_reward()) //changes reward from true to false
    {
      std::cout << "This student has just been made eligible for another reward.\nThey will be told that there is no reward waiting for them.\n";
      editable.set_reward(false);
    } else { //changes reward from false to true
      std::cout << "This student has just been made ineligible for another reward.\nThey will be told that there is a reward waiting for them.\n";
      editable.set_reward(true);
    }
  } else if(input == "score") { //if the teacher edits score
    std::cout << name << "'s current score is " << editable.get_quizscore() << ".\n";
    std::cout << "What would you like to change the score to: ";
    int newscore;
    std::cin >> newscore;
    while(std::cin.fail() || (newscore < 0)) { //loop for input validation
      std::cin.clear(); //clear and ignore to clear cache
      std::cin.ignore();
      std::cout << "Please enter a valid score greater than 0: ";
      std::cin >> newscore;
    }
    editable.set_quizscore(newscore);
    std::cout << "The score has been changed to " << newscore << ".\n";
  }
  
  temp[i] = editable; //add the updated student back to the vector
}


//function to make a new student for a teacher
void Student::new_student(std::vector<Student>& temp, std::string studentname) {
  std::cout << "That student name is not present in the class. Would you like to add this student? (y/n): ";
  std::string cont;
  std::cin >> cont;
  while (cont != "y" && cont != "n"){ //input validation
	  std::cout << "Please enter either y  or n: ";
  	std::cin >> cont;
	}
  if(cont == "n") { return; } //if teacher would like to cancel

  Student newstudent; //create a new student
  newstudent.set_name(studentname);
  
  std::cout << "What would you like to make this students quiz score: ";
  int newscore;
  std::cin >> newscore;
  while(std::cin.fail() || (newscore < 0)) { //input validation for students quiz score
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Please enter a valid score greater than 0: ";
    std::cin >> newscore;
  }
  newstudent.set_quizscore(newscore);
  newstudent.set_studytime(0);
  std::cout << "The score has been made " << newscore << ".\n";
  std::cout << "Student " << studentname << "has been created.\n";

  temp.push_back(newstudent);
}

//function to move data from vector to text file student data
void Student::move_data(std::vector<Student>& temp) {
  std::ofstream out; //creat ofstream and open studentEX.txt
  out.open("studentEX.txt");
  for(int i = 0; i < temp.size() ; i++){ //for each index in array move data to text file
		out << temp[i].get_name() << " ";
		out << temp[i].get_quizscore() << " ";
		out << temp[i].get_studytime() << " ";

		if(temp[i].get_reward()==true){
			out << "true" << std::endl;
		}
		else{
			out << "false" << std::endl;
		}		
	} 
}

//function to remove a student from class
void remove_student() {
  std::cout << "What is the name of the student that you would like to remove.\n";
  std::string name;
  Student temps;
  std::vector<Student> temp = temps.getdata(); //gets all of the student data
  bool invalid = true;
  int posremove = 0;
  while(invalid) { //input validation loop for students name
    std::cout << "To cancel enter 100.\n";
    std::cout << "Enter name here: ";
    std::cin >> name;
    for(int i = 0; i < temp.size(); i++) { //finds the student to be removed in the vector
      if(temp[i].get_name() == name) {
        invalid = false;
        posremove = i;
        break;
      }
    }
    if(name == "100") { return; } //if user enters 100 it exits this function
    if(invalid) { std::cout << "Please enter a valid name.\n"; }
  }
  std::cout << "You have chosen to remove " << name << ". Would you like to continue?(y/n): ";
  std::string cont;
  std::cin >> cont;
  while (cont != "y" && cont != "n"){ //ask user if they would like to continue removing the student they selected
	  std::cout << "Please enter either y  or n: ";
  	std::cin >> cont;
	}
  if(cont == "n") { return; }

  //swaps the final element and the one to be removed in the vector and pops the back of it
  Student temp2;
	temp2 = temp[posremove]; //temp holds x
	temp[posremove] = temp[temp.size()-1]; //x holds y
	temp[temp.size()-1] = temp2;
  temp.pop_back();
  temps.move_data(temp);
}
