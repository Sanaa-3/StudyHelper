#ifndef TIMER_H
#define TIMER_H
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

class timer {
public:
  // prints out the time
  void displayClock();

  // calculates time
  void time(int h, int m, int s);

  // resets hours minutes and seconds to 0
  void reset();

  // adds a noise for when a time is up
  void beep();

  // outputs times and asks of user inputs
  int run_time();

private:
  int hours = 0;

  int minutes = 0;

  int seconds = 0;
};

int check(int);

#endif
