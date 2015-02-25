/* Mason Prosser		2/24/15
Puzzle.h
Puzzle class to hold a Sudoku or Wordoku board and play a simple game */

#ifndef PUZZLE_H
#define PUZZLE_H
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<typename T>	// Templated class
class Puzzle{
  public:
    Puzzle();			// Default constructor
    void print();		// Print the puzzle to the screen
  private:
    vector<vector <T> > puzzle;	// The puzzle
};

// Default constructor
template<typename T>
Puzzle<T>::Puzzle(){
  ifstream infile1;
  string inf;

  cout << "Type the name of the file containing the puzzle: ";
  cin >> inf;
  infile1.open(inf.c_str());

  T value;
  T tempVar;
  vector<T> tempVec;

  while(!infile1.eof()){

    for(int i = 0; i < 9; i++){
      infile1 >> tempVar;
      tempVec.push_back(tempVar);
    }

    puzzle.push_back(tempVec);
    tempVec.clear();
  }
}

// Function to print the puzzle
template<typename T>
void Puzzle<T>::print(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cout << puzzle[i][j] << " ";
    }
    cout << endl;
  }
}

#endif
