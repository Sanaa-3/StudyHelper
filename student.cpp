#include "student.h"
//accessor and mutator for the name variable of student class
void Student::set_name(std::string nname)
{
  name = nname;
}
std::string Student::get_name() const
{
  return name;
}

//accessor and mutator for the quizscore variable of student class
void Student::set_quizscore(int quizscore) 
{
  rec_quizscore = quizscore;
}
int Student::get_quizscore() const 
{
  return rec_quizscore;
}

//accessor and mutator for the reward variable of student class
void Student::set_reward(bool nreward) 
{
  reward = nreward;
}
bool Student::get_reward() const  
{
  return reward;
}

//accessor and mutator for the studytime variable of student class
void Student::set_studytime(int nstudytime) 
{
  studytime = nstudytime;
}
int Student::get_studytime() //Eshaan
{
  return studytime;
}


//This function presents the student a set of options and returns an integer based on user input
//Option 1 Practice Quiz    Option 2 View Data    Option 3 Study    Option 4 Logout
int Student::student_options(std::string name) 
{
  std::cout << "\nWhat would you like to do today?\n";
  std::cout << "\nOption 1: Take a Practice Quiz\nOption 2: See Grades and Check Rewards\n";
  std::cout << "Option 3: Study\nOption 4: Logout\n";
  int input = 0;
  bool corr = false;
  std::string temp;
  while(!corr) //while user input is not valid
  {
    input = 0;
    std::cout << "Enter the number of the option(1, 2, 3, 4): ";
    std::cin >> input; //take user input
    while((input <= 0 || input > 4 || std::cin.fail())) //input validation loop
    {
      std::cout << "That was not a valid option. Please enter a valid option: ";
      std::cin.clear();  //cin clear and ignore to clear the cache
      std::cin.ignore();
      std::cin >> input;
    }
    temp = "Would you like to continue with option " + std::to_string(input) + "?";
    corr = confirm(temp); //confirm function gets input for parameters question and returns boolean true or false
  }
  return input; //return the users choice
}

//function to return a vector of all the present students data
std::vector<Student> Student::getdata()
{
  std::ifstream in; //create an ifstream variable and assign the text file studentEX.txt to it
  in.open("studentEX.txt");
  std::string temp;
  std::vector<Student> finalvector; //create a vector to hold the students
  
  while(getline(in, temp)) //while still receiving lines
  {
	 if(temp=="") //if the text file is empty this will be true on the first loop
	 {break;} //break which will exit the while and return the empty vector
    std::string::size_type i = 0; //size_type is an integer dataype large enough to represent any possible string size
    std::string::size_type j = temp.find(" ");
    std::vector<std::string> v; //create a vector of strings to separate the long string taken from text file
    while (j != std::string::npos) { //n::pos means not found so while j is not equal to not found (while j is found)
      v.push_back(temp.substr(i, j-i));
      i = ++j;
      j = temp.find(" ", j); //trys to find j (find is actually a size_type return value)

      if (j == std::string::npos) // if j is not found then it is the last word in string so push the entirety of the string
         v.push_back(temp.substr(i, temp.length()));
    }
    Student newStudent; //create a new student and fill it with the data found
    newStudent.set_name(v[0]);
    newStudent.set_quizscore(stoi(v[1]));
    newStudent.set_studytime(stoi(v[2]));
    if(v[3] == "true") { newStudent.set_reward(true); }
    else if(v[3] == "false") { newStudent.set_reward(false); }
    else { std::cout << "ERROR"; }
    finalvector.push_back(newStudent); //add the new student to the vector to be returned
  }
  return finalvector; //return the vector
}


//function to find a certain student in the text file and it assigns the data to implicit parameter
void Student::findStudent(std::string name) 
{
  std::ifstream in_file; //create ifstream and open the studentEX.txt with it
	in_file.open("studentEX.txt");
	std::string student_name;

	std::string line; //line read in from file is "Eshaan 89 180 true"
	std::string delimiter = " ";
  bool registered = false;
	if(in_file.is_open()) //if the file is valid
  {
		while(std::getline(in_file, line)) //while still getting data
		{
			student_name = line.substr(0, line.find(delimiter)); // get the name which is the first word of every line
      if(name == student_name) { //if the name matches the student being searched for
        registered = true; //set registered to true (student is present)
        break;  //exit the while loop
      }
		}
	}
	else{
		std::cout << "Error reading in student names from file.";
		exit(0);
	}

  if(!registered) { //if the student is not registered
    std::cout << "You are an unregistered student with no file. Please speak to your teacher about fixing this issue.\n";
    return; //end function
  }
  std::string::size_type i = 0;
  std::string::size_type j = line.find(" ");
  std::vector<std::string> v;
  while (j != std::string::npos) { //while j is still found
    v.push_back(line.substr(i, j-i));
    i = ++j;
    j = line.find(" ", j);
    if (j == std::string::npos) //if j is not found add the rest of the line to the vector
       v.push_back(line.substr(i, line.length()));
  }
  this->name = v[0]; //move data from vector to implicit parameter
  this->rec_quizscore = stoi(v[1]);
  this->studytime = (stoi(v[2]));
  if(v[3] == "true") { this->reward = true; }
  else if(v[3] == "false") { this->reward = false; }
  else { std::cout << "ERROR"; }
}

//function to print the data of the student in the implicit parameter
void Student::print() 
{
  std::cout << "\nName: " + this->name; //prints name
  std::cout << "\nQuiz Score: " << this->rec_quizscore; //prints quizscore
  std::cout << "\nStudy Time: " << this->studytime << "\n"; //prints studytime
  if(this->reward) //if the stundet has a reward give a congrats message
  {
    //might try GUI later here - Eshaan
    std::cout << "Congratulations! There is a reward waiting for you!\n";  
    std::cout << "Please talk to your teacher about receiving your reward.\n";
  } else { //if the student has no reward support them and give them an encouraging statement
    std::cout << "There is no reward to be claimed now.\n";
    std::cout << "Keep pushing forward and trying to get that reward.\n";
    std::cout << "You can do it!\n";
  }
}
