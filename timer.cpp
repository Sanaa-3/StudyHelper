#include "timer.h"
#include "student.h"

void timer::displayClock(){
  // pints out TIME:
  std::cout << std::setfill(' ') << std::setw(55) << "         TIME:        \n";
  std::cout << std::setfill(' ') << std::setw(29);
  // Prints out hours
  std::cout << "| " << std::setfill('0') << std::setw(2) << hours << " hrs | ";
  // Prints out minutes
  std::cout << std::setfill('0') << std::setw(2) << minutes << " min | ";
  // Prints out seconds
  std::cout << std::setfill('0') << std::setw(2) << seconds << " sec |"
            << std::endl;
  std::cout << std::endl;
}

void timer::time(int h, int m, int s){
  int counter=0;

  if(s<59)
  {counter++;}

  while (true) {
    // outputs hours minutes and seconds
    displayClock();

    // makes a one second delay
    sleep(1);
    //clears screen
    std::system("clear");
    // adds to seconds
    seconds++;

    // if seconds equal to 60 add one to minutes
    if (seconds == 60) {
      minutes++;
      // if minutes equal to 60 add one to hours
      if (minutes == 60) {
        hours++;
        minutes = 0;
      }
      seconds = 0;
    }

    // if hours, minutes, and seconds equal given time from user the loop will
    // end
    if (hours == h && minutes == m && seconds == s+counter ) {
      break;
    }
  }
}

// resets hours, minutes, and seconds to zero
void timer::reset() {
  hours = 0;
  minutes = 0;
  seconds = 0;
}

void timer::beep() {
  // it can only make two beeps idk why it cant do more in a row
  for (int i = 0; i < 2; i++) {
    std::cout << '\a'; // makes beep sound
  }
}

int timer::run_time() {
bool confirm=true;
  int totalminutes = 0;
  // enter study time and input the hours, minutes, and seconds you want
  std::cout << "enter your study time:\n";

  int h;
  std::cout << "hours:\n";
  std::cin >> h;
	while (std::cin.fail()){
	  std::cout << "Error! Please enter a positive integer: ";
    std::cin.clear(); 
    std::cin.ignore();
  	std::cin >> h;
	}

  int m;
  std::cout << "minutes:\n";
  m=check(m);

  int s;
  std::cout << "seconds:\n";
  s=check(s);
  std::cout << std::endl;

  // enter break time and input the hours, minutes, and seconds you want
  std::cout << "Enter your break time:\n";

  int bh;
  std::cout << "Hours: ";
  std::cin >> bh;
	while (std::cin.fail()){
	  std::cout << "Error! Please enter a positive integer: ";
    std::cin.clear(); 
    std::cin.ignore();
  	std::cin >> bh;
	}

  int bm;
  std::cout << "Minutes: ";
  bm=check(bm);

  int bs;
  std::cout << "Seconds: ";
  bs=check(bs);
  std::cout << std::endl;
  totalminutes = bm + (bh*60) + (bs/60);

  
  
  // enter how amny rounds you want
  int rounds;
  std::cout << "Enter how many study rounds you want: ";
  std::cin >> rounds;
	while (std::cin.fail()){
	  std::cout << "Error! Please enter a positive integer: ";
    std::cin.clear(); 
    std::cin.ignore();
  	std::cin >> rounds;
	}

  totalminutes = totalminutes * rounds;
  
  // while its less than rounds amount
  for (int i = 0; i < rounds; i++) {

    // output timer with given study time hours, minutes, and seconds
    time(h, m, s);
    // makes beep sound after the timer is done
    beep();

    // if its the last round no need for a break so after the last study round
    // just end the loop and say good job
    if (i == rounds - 1) {
      std::cout << "Your all done good job!\n";
      beep();
      break;
    }

    std::cout << "Time for a break!\n";

    // resets hours minutes and seconds to zero so the count restarts for break
    // time
    reset();
    sleep(3);
    // after study time is done output timer for break time with given break
    // stop time
    time(bh, bm, bs);

    // makes beep noise
    beep();

    std::cout << "Your break is over time to study agian.\n";

    // resets hours minutes and seconds to zero so the count restarts for study
    // time
    reset();
    sleep(3);
  }
  return totalminutes;
}

int check(int t){
  bool confirm=true;
  while(confirm){
  	std::cin >> t;
		while (std::cin.fail()){
	  	std::cout << "Error! Please enter a positive integer: ";
	    std::cin.clear(); 
	    std::cin.ignore();
	  	std::cin >> t;
		}
	   if(t<60) 
	   {break;}
	    std::cout << "Please enter a value less than 60:\n";
  }
  return t;
}
