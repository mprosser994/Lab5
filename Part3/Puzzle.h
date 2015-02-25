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
    Puzzle();			 // Default constructor
    void print();		 // Print the puzzle to the screen
    void play();		 // Function to let a user play Sudoku
    int isValid(int, int, int);	 // Function to check if a move is valid and make the move (or not)
    int isDone();		 // Checks if the game is over
  private:
    vector<vector <T> > puzzle;	 // The puzzle
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
      infile1 >> tempVar;	// Read current int into temporary variable
      tempVec.push_back(tempVar); // Add tempVar to a temporary vector
    }

    puzzle.push_back(tempVec);	// Add tempVec to puzzle
    tempVec.clear();	// Clear tempVec so it can be reused
  }
}

// Function to print the puzzle
template<typename T>
void Puzzle<T>::print(){

  // Print column labels
  cout << "   ";
  for(int i = 0; i < 9; i++)
    cout << i << " ";
  cout << endl;

  // Print rows with labels
  for(int i = 0; i < 9; i++){
    cout << i << ": ";
    for(int j = 0; j < 9; j++){
      cout << puzzle[i][j] << " ";
    }
    cout << endl;
  }
}

// Function to check if a move is valid
template<typename T>
int Puzzle<T>::isValid(int i, int j, int x){
  // Only allow changes to empty spaces
  if(puzzle[i][j] != 0){
    cout << "Sorry! You can't change a number that's already there!" << endl;
    return 0;
  }

  // Check row
  for(int k = 0; k < 9; k++){
    if(puzzle[i][k] == x) cout << "Invalid move!" << endl;
    return 0;
  }

  // Check column
  for(int k = 0; k < 9; k++){
    if(puzzle[k][j] == x) cout << "Invalid move!" << endl;
    return 0;
  }

  // Check current square
  if(i < 3 && j < 3){
    for(int k = 0; k < 3; k++){
      for(int m = 0; m < 3; m++){
        if(puzzle[k][m] == x) cout << "Invalid move!" << endl;
        return 0;
      }
    }
  }else if(i < 3 && j < 6){
    for(int k = 0; k < 3; k++){
      for(int m = 3; m < 6; m++){
        if(puzzle[k][m] == x) cout << "Invalid move!" << endl;
        return 0;
      }
    }
  }else if(i < 3 && j < 9){
    for(int k = 0; k < 3; k++){
      for(int m = 6; m < 9; m++){
        if(puzzle[k][m] == x) cout << "Invalid move!" << endl;
        return 0;
      }
    }
  }else if(i < 6 && j < 3){
    for(int k = 3; k < 6; k++){
      for(int m = 0; m < 3; m++){
        if(puzzle[k][m] == x) cout << "Invalid move!" << endl;
        return 0;
      }
    }
  }else if(i < 6 && j < 6){
    for(int k = 3; k < 6; k++){
      for(int m = 3; m < 6; m++){
        if(puzzle[k][m] == x) cout << "Invalid move!" << endl;
        return 0;
      }
    }
  }else if(i < 6 && j < 9){
    for(int k = 3; k < 6; k++){
      for(int m = 6; m < 9; m++){
        if(puzzle[k][m] == x) cout << "Invalid move!" << endl;
        return 0;
      }
    }
  }else if(i < 9 && j < 3){
    for(int k = 6; k < 9; k++){
      for(int m = 0; m < 3; m++){
        if(puzzle[k][m] == x) cout << "Invalid move!" << endl;
        return 0;
      }
    }
  }else if(i < 9 && j < 6){
    for(int k = 6; k < 9; k++){
      for(int m = 3; m < 6; m++){
        if(puzzle[k][m] == x) cout << "Invalid move!" << endl;
        return 0;
      }
    }
  }else if(i < 9 && j < 9){
    for(int k = 6; k < 9; k++){
      for(int m = 6; m < 9; m++){
        if(puzzle[k][m] == x) cout << "Invalid move!" << endl;
        return 0;
      }
    }
  }

  // If no conflict, change current entry to desired value and return 1
  puzzle[i][j] = x;
  return 1;
}

// Function to check if the game is over
template<typename T>
int Puzzle<T>::isDone(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(puzzle[i][j] != 0) return 0;
    }
  }

  // If there is no 0 left on the board, return 1
  return 1;
}

// Function to play a game of Sudoku
template<typename T>
void Puzzle<T>::play(){
  int row, column, entry;

  cout << "Welcome!" << endl;

  while(!isDone()){
    cout << "In this version of Sudoku, pretend you're playing with a pen." << endl;
    cout << "That means once you enter a number, you can't change it," << endl;
    cout << "and if you make a mistake you'll have to start over. Good luck!" << endl;

    print();

    do{
      do{
        cout << "Enter the row of the element you'd like to change: ";
        cin >> row;
      }while(row < 0 || row > 8);

      do{
        cout << "Enter the column of the element you'd like to change: ";
        cin >> column;
      }while(column < 0 || column > 8);

      do{
        cout << "Enter the value you'd like to place here: ";
        cin >> entry;
      }while(entry < 1 || entry > 9);
    }while(isValid(row, column, entry));

    cout << endl;
  }

  /* Since it is only possible to complete a puzzle with a valid move, we can
     assume that isDone returning 1 means the puzzle has been solved. */
  cout << "Congratulations, you solved it!" << endl;
}

#endif
