#include "tree.h"
#include <algorithm>
#include <bits/stdc++.h>

BinaryTree::BinaryTree() { root = nullptr; }

BinaryTree::BinaryTree(int root_data) {
  root = new Nodet;
  root->data = root_data;
  root->left = nullptr;
  root->right = nullptr;
}

BinaryTree::BinaryTree(int root_data, BinaryTree left, BinaryTree right) {
  root = new Nodet;
  root->data = root_data;
  root->left = left.root;
  root->right = right.root;
}

int BinaryTree::height(const Nodet *n) const {
  if (n == nullptr) {
    return 0;
  } else {
    return 1 + std::max(height(n->left), height(n->right));
  }
}

int BinaryTree::height() const { return height(root); }

bool BinaryTree::empty() const { return root == nullptr; }

int BinaryTree::data() const { return root->data; }

BinaryTree BinaryTree::left() const {
  BinaryTree result;
  result.root = root->left;
  return result;
}

BinaryTree BinaryTree::right() const {
  BinaryTree result;
  result.root = root->right;
  return result;
}


void make_quiz() {
  //used to output quiz info to some txt file
  std::ofstream Aoutfile("A.txt");
  std::ofstream Qoutfile("Q.txt");
  std::ofstream sizeout("size.txt");
  //there can only be up to ten questions
	int max_size = 10;
  std::cout << "You will have to enter 2 times the amount of questions the student has to answer minus one question.\n";
  std::cout << "Enter the number of questions you want the student to answer(only up to " << max_size << "): ";
  int size; 
  //teacher enters the amount of questions they want to make
	std::cin >> size;
  int numquest = (size*2)-1;
  //data validation
	while (size <= 0 || size > max_size || std::cin.fail()){
	  std::cout << "Error! Please enter an integer no greater than " << max_size << " and no less than 1: ";
    std::cin.clear(); 
    std::cin.ignore();
  	std::cin >> size;
	}
  std::cin.ignore(); 
  //arrays used to store questions and answers
  std::string question[size];
  std::string answer[size];
	for (int i = 0; i < size; i++) {
		std::string q;
    if(i%2==0 && i!=0)
      //asks teacher to make some questions harder so when a sudent gets an answer correct they would have to answer those harder questions
    {std::cout<<"Please enter a more challenging question for this one. ";}
		std::cout << "\nQuestion " << i + 1 << ":\n";
		std::getline(std::cin, q);
		 while(q.empty()){ //to make sure an answer for each option is entered
			 std::cout << "Please enter a question: ";
				std::getline(std::cin, q);
			}
    //makes all questions and options one string
		q = q + "\n";
		std::string o;
		for (int i = 0; i < 4; i++) {
			std::string l;
			if (i + 1 == 1) { l = "A"; }
			if (i + 1 == 2) { l = "B"; }
			if (i + 1 == 3) { l = "C"; }
			if (i + 1 == 4) { l = "D"; }
			std::cout << "option " << l << ": ";
			std::getline(std::cin, o);
			while(o.empty()){ //to make sure an answer for each option is entered
				std::cout << "Error: This option cannot be blank.\nPlease enter an option: ";
				std::getline(std::cin, o);
			}
      //options A-D plus options that the teacher entered
			o = l + ") " + o;
      //questions plus options
			q = q + o + "\n";
		}
    //asks teacher for the answer
			std::cout << "Which option is the answer for Question " << i + 1 << "? Enter A, B, C, or D: ";
			std::string a;
			std::cin >> a;
    //data validationand makes all lowercased responses uppercase
		  transform(a.begin(), a.end(), a.begin(), ::toupper);
			while(a != "A" && a != "B" && a != "C" && a != "D"){
				std::cout << "Please enter a valid option (A, B, C, or D): ";
				std::cin >> a;
			}
    //stores all the questions answers
			answer[i] = a;
			std::cout << std::endl;
    //stores questions with options from A-D to question array
			question[i] = q;
		}
  std::string q, a;
  //turns all of questions and answers into one string
  for (int i = 0; i < size; i++) {
    q = q + question[i] + ",";
    a = a + answer[i] + ",";
  }
  //stores all the questions, answers, and amount of questions in seperate txt files
  Qoutfile << q;
  Aoutfile << a;
  sizeout << size;
}


double take_quiz() {
 //binary tree filled with numbers 
  BinaryTree tree(0, BinaryTree(1, BinaryTree(3, BinaryTree(5, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))), BinaryTree(6, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))))), BinaryTree(4, BinaryTree(5, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))), BinaryTree(6, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))))),   BinaryTree(2, BinaryTree(3, BinaryTree(5, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))), BinaryTree(6, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))))), BinaryTree(4, BinaryTree(5, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))), BinaryTree(6, BinaryTree(7, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))))), BinaryTree(8, BinaryTree(9, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))), BinaryTree(10, BinaryTree(11, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18)))), BinaryTree(12, BinaryTree(13, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))), BinaryTree(14, BinaryTree(15, BinaryTree(17), BinaryTree(18)), BinaryTree(16, BinaryTree(17), BinaryTree(18))))))))));   

  //takes in amount of questions from a txt file
  std::ifstream Sizein, Qinfile, Ainfile;
  Sizein.open("size.txt");
  int size = 0;
  Sizein >> size;
  //std::ifstream Qinfile;
  //takes in questions from a txt file and stores it back into question array
  Qinfile.open("Q.txt");
  std::string question[size];
  for (int i = 0; i < size; i++) {
    std::string q;
    getline(Qinfile, q, ',');
    question[i] = q;
  }
  //std::ifstream Ainfile;
  //stores the answers from a txt file into an array
  Ainfile.open("A.txt");
  std::string answer[size];
  for (int i = 0; i < size; i++) {
    std::string a;
    getline(Ainfile, a, ',');
    answer[i] = a;
  }
  //stores all the question in a map
  std::map<int, std::string> map;
  for (int i = 0; i < size; i++) {
    map[i] = question[i];
  }
  std::cout << std::endl;
  //changes the size so it equals the height of the tree
  size = size - 1;
  size = size / 2;
  size = size + 1;
  //final score the student gets
  double score = 0.0;
  //counts which question the student is on
  int count = 0;
  bool done = false;
  while (!done) {
    //makse left and right of the tree
    BinaryTree left = tree.left();
    BinaryTree right = tree.right();
    //if the children of the node that the student is on is empty then the quiz stops
    if (left.empty() && right.empty()) {
      std::cout << tree.data() << std::endl;
      done = true;
    } else {
      std::string response;
      do {
        //outputs question from the map with given tree index
        std::cout << map[tree.data()] << std::endl;
        //data validation
        std::cout<<"Note: please enter a valid input (A,B,C,or D):\n";
        //response from student to answer the question
        std::cin >> response;
        //makes sure the students response is uppercase so it wont see a lowercase a-d as incorrect
        transform(response.begin(), response.end(), response.begin(), ::toupper);
        //data validation makes sure the user inputs A-D
        if(response != "A" && response != "B" && response != "C" && response != "D") { 
          std::cout << "INVALID INPUT!\n\n";
          continue;
        }
        //if there response is the same as the answer there score goes up by one
        if (response == answer[tree.data()]) { score++; }
        count++;
        //if the count equals the size the quiz ends
        if (count == size) {
          done = true;
          break;
        }
				//data validation  for lowercase
      } while (response != "A" && response != "B" && response != "C" &&
               response != "D" && response != "a" && response != "b" && response != "c" &&
               response != "d");
      //if there response is correct the studnet traverses to the right of the tree
      if (response == answer[tree.data()]) {
        tree = right;
              //if there response is incorrect the studnet traverses to the left of the tree
      } else if (response != answer[tree.data()]) {
        tree = left;
      }
    }
  }
  //returns the score percentage out of 100%
  score=score/size;
  score=score*100;
  return score;
}
