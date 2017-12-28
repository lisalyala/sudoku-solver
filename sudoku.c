#include "sudoku.h"

//-------------------------------------------------------------------------------------------------
// Introduction: This code implements three helper functions that are called by one main 
// function that is ultimately used in the recursive backtracking function "solve sudoku" to slowly
// but surely get the right answer on the sudoku game each single time. (Who knew you could do that ?!)
// The is_val_in_row, is_val_in_3x3_zone and the is_val_in_col implement the "you can't have the same 
// number in a row, column, or 3x3 zone" rules and return 1 if the value for one sudoku instance conflicts 
// with any of these rules. Finally, is_val_valid takes these three functions and utilizes their return values
// to check if a value is about to be placed within an open spot that violates the game rules. The magic happens
// when the solve_sudoku function is called for an instance to not only holla at its best bud is_val_valid
// to check if the rules aren't violated, but it also backtracks to place the number in the right spot if 
// it needs to. Through out our code, we used for loops, if statements, assertions, and 2D arrays.
//-------------------------------------------------------------------------------------------------


// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) 
{
	assert(i>=0 && i<9);

  // BEG TODO
  	
	int j;
	for(j = 0; j <= 8; j++)        //loop through each column while keeping the row constant
	{
		if(sudoku[i][j] == val)       //compare every value in the row to the value entered by the user. If found, return 1.
		{
			return 1;
		}
	}
	
  
  return 0;
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) 
{

  assert(j>=0 && j<9);

  // BEG TODO
  
  	int i;
	for(i = 0; i <= 8; i++)         //loop through each row while keeping the column constant 
	{
		if(sudoku[i][j] == val)         //compare every value in the column to the value entered by the user. If found, return 1.
		{
			return 1;
		}
	}
  
  return 0;
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) 
{
   
  //assert(i>=0 && i<9);
    assert(i>=0 && i<9 && j>=0 && j<9);
  
  // BEG TODO
  	
	int n, m;
	int r = i - (i % 3);          //calculation to locate which "3x3 box" the value is in.
	int c = j - (j % 3);         //We subtract the result of the modulus to locate the proper index in the sudoku.

	for(n = r; n <= r + 2; n++)        //loop through the row and columns starting at r and ending at r + 2 (the width and height of the box).
	{
		for(m = c; m <= c + 2; m++)
		{
			if(sudoku[n][m] == val)    //if the value is already in the 3x3 box, return 1.
			{
				return 1;
			}
		}	
	}
  
  return 0;
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);
  
    // BEG TODO
  if(!is_val_in_col(val, j, sudoku) && !is_val_in_row(val, i, sudoku) && !is_val_in_3x3_zone(val, i, j, sudoku))  //check all three of our helper methods to make sure the value is valid
  {
 	return 1; 	//if all three return fasle, the number is no where on the row, col, or 3x3, and return 1.
  }

  return 0;
  // END TODO
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) 
{

  // BEG TODO.
  
  int count = 0;       //instantiate all counting and loop variables
  int i, j;
  int r, c;
  int num;
  for(r = 0; r <= 8; r++)
  {
  	for(c = 0; c <= 8; c++)
	{
		if(sudoku[r][c] == 0)
		{
			count++;               // begin by looping through grid and increment count when an empty cell is found
			i = r;								// set (r, c) to (i, j) if empty cell is found
			j = c;
		}
	}
  }
  
  if(count == 0)         // if count is 0, all cells have been filled and game is finished
  {
  	return 1;
  }
  
  for(num = 1; num <= 9; num++)
  {
  	if(is_val_valid(num, i, j, sudoku))       //loop through all possible values (1-9) and check if possible value is valid at (i, j)
	{
		sudoku[i][j] = num;									    // if value is valid at (i, j) , set num.
		if(solve_sudoku(sudoku))                //call solve_sudoku again to check if num is in the correct cell
		{
			return 1;
		}
		sudoku[i][j] = 0;                  // if this line is reached, then the placed num value contradicted another num value and it is not
                                       // in the correct place
	}
  }
  

  return 0;
  // END TODO.
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}
