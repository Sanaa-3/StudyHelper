//Program made by Eshaan, Sanaa, Mateen
//Date: 11/22/2021
//Sources used: Textbook,
#include "helper_functions.h"
#include "student.h"
#include <iostream>
#include <vector>
#include "timer.h"
#include "hash.h"
#include "tree.h"


int main() {	
	greeting();
  bool run = use_program();
  while (run) {
		//comment to explain what this does
    std::string username;
    int num=log_in();
    if(num==0) { break; }
    
    std::string user_type;
    std::ifstream in;
    in.open("ST.txt");
    in >> user_type;
    if(user_type == "student") {
      
      //bool valid = student_login(username);
			std::string delimiter = "-";
			std::string line;
		
			if(in.is_open()){
        in >> line;
        std::cout << line << ".";
			}
      username = line.substr(0, line.find(delimiter));
      
      std::cout << "\nHello " << username << ", welcome to the portal.\n";
      while(num == 1) {
        Student ohlone1;
        int choice = ohlone1.student_options(username);
  			if(choice == 1) {
					double score = take_quiz();
          std::cout << "You got a " << score << "% out of 100%\n";					
          assign_score(username, score);
				}
        else if(choice == 2)  {
          ohlone1.findStudent(username);
          ohlone1.print();
        }
        else if(choice == 3)  {
           timer t;
					// asks for user inputs for break time study time and amount of rounds then
					// outputs timer for them and alerts the user when the time is done
          int minutes = t.run_time();
          assign_studytime(username, minutes);
        }
        else if(choice == 4) {
					std::cout << "Logging out...";
					break;}
      }
  		
    } else if(user_type == "teacher") {
			std::string username;
			bool valid = true;
      std::cout << "\nHello" << username << ", welcome to the portal.\n";
      while(valid)
      {
        int choice2 = teacher_options(username); //presents menu of options
        Student temps;
        std::vector<Student> temp = temps.getdata();
        if (choice2 == 4) { 
					std::cout << "Logging out...";
    			break;}
      }
		}
		run = repeat_program();
	}
}

//NOTES - ESHAAN
//This code below is some code that calls the getdata function to return a vector of the student data
  // Student temps;
  // std::vector<Student> temp = temps.getdata();

//This code below is some code to get the data of a student whos name is the parameter
  //  Student temp;
  // temp.findStudent("Sanaa"); THE STUDENT IN THE PARAMETER MUST EXIST OTHERWISE THERE WILL BE AN ERROR
