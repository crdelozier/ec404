#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

/*
 * This initializes the board to all empty spaces
 */
void initBoard(char board[3][3]){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j] = ' ';
    }
  }
}

/*
 * This prints the board for the player.
 */
void printBoard(char board[3][3]){
  for(int i = 0; i < 3; i++){
    cout << " ";
    for(int j = 0; j < 3; j++){
      cout << board[i][j];
      if(j <= 1){
	cout << " | ";
      }
    }
    if(i <= 1){
      cout << "\n------------\n";
    }else{
      cout << "\n";
    }
  }
}

/*
 * Returns true if the board has an X or O at the (x,y) position
 * Returns false if no X or O has been played at that position yet
 */
bool isSet(char board[3][3], int x, int y){
  return board[x][y] != ' ';
}

/*
 * Check board for win conditions
 * X or O wins if there are all X's or O's in a row, 
 * column, or diagonal
 * Returns X or O if one of them wins
 * If all spaces are filled and nobody wins, it's a draw (D)
 * If spaces remain to be filled, returns N
 */
char checkBoard(char board[3][3]){
  // Check Rows
  for(int i = 0; i < 3; i++){
    if(isSet(board,i,0) &&
       board[i][0] == board[i][1] &&
       board[i][1] == board[i][2]){
      return board[i][0];
    }
  }

  // Check columns
  for(int j = 0; j < 3; j++){
    if(isSet(board,0,j) &&
       board[0][j] == board[1][j] &&
       board[1][j] == board[2][j]){
      return board[0][j];
    }
  }

  // Check diagonal left to right
  if(isSet(board,0,0) &&
     board[0][0] == board[1][1] &&
     board[1][1] == board[2][2]){
    return board[0][0];
  }

  // Check diagonal right to left
  if(isSet(board,2,0) &&
     board[2][0] == board[1][1] &&
     board[1][1] == board[0][2]){
    return board[2][0];
  }

  // Check if there are moves left to make
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(!isSet(board,i,j)){
	return 'N';
      }
    }
  }

  // If there are no moves left to make and nobody wins, it's a draw
  return 'D';
}

/*
 * Copies the current state from source to destination
 * Uses memcpy for efficiency (man memcpy if you're curious)
 */
void copyBoard(char destination[3][3], char source[3][3]){
  memcpy((void*)destination,(void*)source,9);
}

/*
 * Returns the opposite of the input
 */
char flipTurn(char turn){
  if(turn == 'X'){
    return 'O';
  }else{
    return 'X';
  }
}

/*
 * Recursive function to evaluate a move for wins, losses, and draws
 */
void evaluateMoveHelper(char board[3][3], int x, int y, char turn, int *win, int *lose, int *draw, int *total){
  // Create a new board and copy it to avoid interfering with other move evaluations
  char myBoard[3][3];
  copyBoard(myBoard,board);

  // Execute the move that we're evaluating
  myBoard[x][y] = turn;

  // Figure out what happens!
  char outcome = checkBoard(myBoard);
  if(outcome == 'N'){
    // If nobody wins yet, try all other moves that remain
    int score = 0;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
	if(!isSet(board,i,j)){
	  // Swap turn, win, and lose for the next move
	  evaluateMoveHelper(myBoard,i,j,flipTurn(turn), lose, win, draw,total);
	}
      }
    }
  }else{
    // If there's a win, loss, or draw, add to the total
    // (and increment the total outcomes evaluated)
    if(outcome == turn){
      (*win)++;
    }else if(outcome == flipTurn(turn)){
      (*lose)++;
    }else{
      (*draw)++;
    }
    (*total)++;
  }
}

// Main function for evaluating moves
// Creates all counters and calls the helper for each potential
// top level move
void evaluateMoves(char board[3][3], char turn){
  cout << "\nMove scores: x,y = Win - Lose - Draw\n";
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(!isSet(board,i,j)){
	int win = 0;
	int lose = 0;
	int draw = 0;
	int total = 0;
	evaluateMoveHelper(board,i,j,turn,&win,&lose,&draw,&total);
	cout << setprecision(2) <<
	  i << "," << j << ": " << (float)win/(float)total << " - " <<
	  (float)lose/(float)total << " - " << (float)draw/(float)total << "\n";  
      }
    }
  }
}

int main(){
  char board[3][3]; // a 3x3 grid of spaces for tic-tac-toe
  char turn = 'X';
  initBoard(board);
  char outcome = ' ';
  
  while((outcome = checkBoard(board)) == 'N'){
    int x, y;
    printBoard(board);

    evaluateMoves(board,turn);
    
    cout << "\nEnter your move as x y coordinates: ";
    cin >> x >> y;

    // Check that the move is valid and apply it if it is
    if(x >= 0 && x < 3 &&
       y >= 0 && y < 3 && !isSet(board,x,y)){
      board[x][y] = turn;
      turn = flipTurn(turn); // Switch turns for the next round
    }
  }
  
  if(outcome == 'X'){
    cout << "\nX wins!\n";
  }else if(outcome == 'O'){
    cout << "\nO wins!\n";
  }else if(outcome == 'D'){
    cout << "\nIt's a draw!\n";
  }else{
    cerr << "\nWhat?\n";
  }
  
  return 0;
}
