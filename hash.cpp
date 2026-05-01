#include "hash.h"

int hash_code(const std::string &str) {
  int h = 0;
  for (int i = 0; i < str.length(); i++) {
    h = 31 * h + str[i];
  }
  return h;
}

HashTable::HashTable(int nbuckets) {
  for (int i = 0; i < nbuckets; i++) {
    buckets.push_back(nullptr);
  }
  current_size = 0;
}

int HashTable::count(const std::string &x) {
  int h = hash_code(x);
  h = h % buckets.size();
  if (h < 0) {
    h = -h;
  }

  Node *current = buckets[h];
  while (current != nullptr) {
    if (current->data == x) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

void HashTable::insert(const std::string &x) {
  int h = hash_code(x);
  h = h % buckets.size();
  if (h < 0) {
    h = -h;
  }

  Node *current = buckets[h];
  while (current != nullptr) {
    if (current->data == x) {
      return;
    }
    // Already in the set
    current = current->next;
  }
  Node *new_node = new Node;
  new_node->data = x;
  new_node->next = buckets[h];
  buckets[h] = new_node;
  current_size++;
}

void HashTable::erase(const std::string &x) {
  int h = hash_code(x);
  h = h % buckets.size();
  if (h < 0) {
    h = -h;
  }

  Node *current = buckets[h];
  Node *previous = nullptr;
  while (current != nullptr) {
    if (current->data == x) {
      if (previous == nullptr) {
        buckets[h] = current->next;
      } else {
        previous->next = current->next;
      }
      delete current;
      current_size--;
      return;
    }
    previous = current;
    current = current->next;
  }
}

int HashTable::size() const { return current_size; }

void HashTable::print() {
  for (int i = 0; i < size(); i++) {
    if (buckets[i] != nullptr) {
      if (buckets[i]->next == nullptr) {
        std::cout << i << ": " << buckets[i]->data << std::endl;
      } else {
        std::cout << i << ": " << buckets[i]->data;
        for (Node *trav = buckets[i]; trav->next != nullptr;
             trav = trav->next) {
          std::cout << " | " << trav->next->data << std::endl;
        }
        std::cout << std::endl;
      }
    } else {
      std::cout << i << ": " << std::endl;
    }
  }
}

// logging in functions  \/ \/ \/

void sign_up() {
  // outfiles that only output into a file and doesn't change it
  std::ofstream Soutfile("Sword.txt", std::ios_base::app);
  std::ofstream Toutfile("Tword.txt", std::ios_base::app);
  std::ifstream Sinfile("Sword.txt");
  std::ifstream Tinfile("Tword.txt");

  // asks user if there a teacher or student with data validation
  std::string choose;
  std::cout << "Are you a teacher or a student?\n";

  bool confirm = true;
  while (confirm) {
    std::cin>>choose;
    
    if (choose == "student" || choose == "teacher") {
      break;
    }
    std::cout << "please enter student or teacher: ";
  }
  
  // asks for last name
  std::string name;
  std::cout << "what is your name? ";
  std::cin.ignore();
  std::getline(std::cin,name);
  name = check(name);
  
  // asks for password
  std::string password;
  std::cout << "what is your password? ";
  std::getline(std::cin,password);
  password = check(password);
  
  // adds password and name into one string called word
  std::string word = name + "," + password;
  // if user is a student word will output into a seperate line in the students
  // txt file
   std::string l;
  // vector log is used to hold all of the strings from a certian txt file
  std::vector<std::string> log;

  // if its a student then it will store all the names and passwords from the
  // students txt file into the vector log
  if (choose == "student") {
    while (Sinfile >> l) {

      log.push_back(l);
    }
    Sinfile.close();
  }
  // if its a teacher then it will store all the names and passwords from the
  // teacher txt file into the vector log
  if (choose == "teacher") {
    while (Tinfile >> l) {
      log.push_back(l);
    }
    Tinfile.close();
  }

  // inserts all the names and passwords from the vector called log into the
  // hash table
  int counter=0;
  
  for (auto i = 0; i < log.size(); i++) {
 
    if(log[i]==word)
    {
      //if there is a matching user name and password in the txt file counter will add up by one
      counter++;
    }
  }
  //if there is no matching username or password 
 if (counter == 0 && choose == "student") {Soutfile << word << "\n";}
  
  //Soutfile << word << "\n";
  // if user is a teacher word will output into a seperate line in the teacher
  // txt file
  
  if (counter == 0 && choose == "teacher") {Toutfile << word << "\n";}
  
}

bool login() {
  // infiles that read from the student and teacher txt files seperatly
  std::ifstream Sinfile("Sword.txt");
  std::ifstream Tinfile("Tword.txt");
  std::ofstream outfile("ST.txt");
  // asks user if there a teacher or student with data validation
  std::string choose;
  std::cout << "Are you a teacher or a student? ";

  bool confirm = true;
  while (confirm) {
    std::cin>>choose;
    
    if (choose == "student" || choose == "teacher") {
      //outfile <<choose;
      break;
    }
    std::cout << "please enter student or teacher: ";
  }
  // user counter to get the size of the hash table
  int counter = 0;
  // string l is used to store all of the strings in the txt file
  std::string l;
  // vector log is used to hold all of the strings from a certian txt file
  std::vector<std::string> log;

  // if its a student then it will store all the names and passwords from the
  // students txt file into the vector log
  if (choose == "student") {
    while (Sinfile >> l) {

      log.push_back(l);
      // counter keeps track of how many strings are in the txt file
      counter++;
    }
    Sinfile.close();
  }
  // if its a teacher then it will store all the names and passwords from the
  // teacher txt file into the vector log
  if (choose == "teacher") {
    while (Tinfile >> l) {
      log.push_back(l);
      // counter keeps track of how many strings are in the txt file
      counter++;
    }
    Tinfile.close();
  }

  // declare hash table with the size counter so it won't segmentation fault wen
  // it trys looking for a password and name
  HashTable table(counter);

  // inserts all the names and passwords from the vector called log into the
  // hash table
  for (auto i = 0; i < log.size(); i++) {
    table.insert(log[i]);
  }

  // this was used for testing
  /*
//returns the size of the hash table
  std::cout << table.size() << "\n";

//prints out the vector's contents
  for (auto i = 0; i < log.size(); i++) {
    std::cout << log[i] << "\n"<< "\n";
  }

//prints out hash table
  table.print();
  */

  // asks for last name
  std::string name;
  std::cout << "enter your name: ";
  std::cin.ignore();
  std::getline(std::cin,name);
  name = check(name);
  
  outfile <<choose<<std::endl<<name;
  
  // asks for password
  std::string password;
  std::cout << "enter your password: ";
  std::getline(std::cin,password);
  password = check(password);

  // adds password and name into one string called word
  std::string word = name + "," + password;

  //used for testing to check if word is correct
  //std::cout<<word<<"\n";

  // string word2 is used to store the data that is in the index that we are
  // seaching for
  std::string word2;

  // gets the hash code from word to get what index its supposed to be in the
  // hash table
  int index = hash_code(word);
  index %= table.size();

  // if index is negitive make it positive so there won't be any segmentation
  // faults when searching for the data we need in the hash table
  if (index < 0) {
    index = index * -1;
  }

  // used for testing
  // prints out index
  // std::cout << index << "\n";

  // if the hash table bucket on our certian index isn't empty
  if (table.buckets[index] != nullptr) {

    // word2 will equal the first name and password that is in the bucket
    word2 = table.buckets[index]->data;

    bool found = false;

    if (word2 != word) {
      // for loop used to traverse through the bucket incase there are more
      // than find name and passwords in the same index
      for (Node *trav = table.buckets[index]; trav->next != nullptr;
           trav = trav->next) {
        // if the data is the same as word then the name and password the user
        // entered was found and they are logged in
        if (trav->next->data == word) {
          std::cout << "\n-----------You are logged in!------------\n";
          found = true;
          return true;
          break;
        }
      }
      // if there is no matching name or password in the bucket then they have
      // an incorrect login information
      if (found == false) {
        std::cout << "\nIncorrect login\n";
        return false;
      }
    }

    // if the word2 equals word then they are logged in
    if (word2 == word) {
      std::cout << "\n-----------You are logged in!------------\n";
      return true;
    }

  }
  // if word2 doesn't equal word then they're they have incorrect login info
  else { std::cout << "\nIncorrect login\n";return false;}
}

int log_in() {
  int num=0;
  // ask's the user if they would like to make a new account or login with data
  // validation
  std::string chooser;
  std::cout << "\n(1) Make a new account\n";
  std::cout << "(2) Log into an existing account\n";
	std::cout << "Please enter one of the above options: ";
  bool confirm = true;
  while (confirm) {
    std::cin >> chooser;

    if (chooser == "1") {
      // if they entered one then they will make a new account name and password
      // that will be saved in the approprate txt file
      std::cout<<"SIGN-UP:"<<std::endl;
      sign_up();

      chooser="2";
    }
    std::cout<<std::endl;
    
    if (chooser == "2") {
      // if the user enters 2 they try to login
      bool log = false;
      // they get to retry the login until they get it right or choose to quit
      while (log == false) {
         std::cout<<"LOGIN:"<<std::endl;
        log = login();
        // if the login info they entered was found then the loop ends
        if (log == true) {
          num++;
          break;
        }
        // if it wasn't found the user will be asked if they would like to retry
        // logging in
        else {
          std::string choose;
          // choose yes or no for relogging in with data validation
          std::cout << "would you like to retry the login? (y/n)\n";
          bool confirm = true;
          while (confirm) {
            std::cin >> choose;
            // if they said no then the loop ends and they quit the retry
            if (choose == "n") {
              log = true;
              break;
            }
            // if they said yes they get to loop back to the begining of the
            // login
            if (choose == "y") {
              break;
            }
            // if they don't enter y or n the program prompts them to try
            // entering the right input
            std::cout << "please enter y or n:\n";
          }
        }
      }
      break;
    }

    std::cout << "please enter 1 to make a new account or 2 to login:\n";
  }
  return num;
}

std::string check(std::string word)
{
  for(int i=0;i<word.length();i++)
  {
    //checks through every char to see if there is a space
    if(word[i]==' ')
    {
      //if there is a space replace it with -
      word[i]='-';
    }
  }
  return word;
}

/*
std::cin.ignore();
    std::getline(std::cin,choose);
    choose = check(choose);
    std::cout<<choose<<std::endl;
*/
