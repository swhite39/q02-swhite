#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  for(int i=0; i < BOARD_ROWS; i++)
  {
    for(int j=0; j < BOARD_COLS;j++)
    {
      board[i][j] = Blank;  
    }  
  }
  turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  for(int i=0; i < BOARD_ROWS; i++)
  {
    for(int j=0; j < BOARD_COLS;j++)
    {
      board[i][j] = Blank;  
    }  
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
  // If column is out of bounds return Invalid and the player forfeits their turn
  if(column > 3)
  {
    if(turn == X)
      turn = O;
    else if(turn == O)
      turn = X;
    return Invalid;
  }

  // Iterate through rows and try to set the appropriate piece on the board
  for(int i=0; i < BOARD_ROWS; i++)
  {
    if(board[i][column] == O || board[i][column] == X)
      continue;
    else if(board[i][column] == Blank)
    {
      if(turn == X)
      {
        board[i][column] = X;
        turn = O;
        return X;
      }
      else if(turn == O)
      {
        board[i][column] = O;
        turn = X;
        return O;
      }
    }
  }

  //If you made it this far the column is full so forfeit turn and return Blank
  if(turn == X)
    turn = O;
  else if(turn == O)
    turn = X;
  return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  if(column > 3 || column < 0 || row > 2 || row < 0)
    return Invalid;
  else if(board[row][column] == O)
    return O;
  else if(board[row][column] == X)
    return X;
  else 
    return Blank;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
  unsigned int tempX = 0;
  unsigned int tempO = 0;
  unsigned int maxX = 0;
  unsigned int maxO = 0;
  // Ensure the game is over and check max number of columns
  for(int i=0; i < BOARD_ROWS; i++)
  {
    for(int j=0; j < BOARD_COLS;j++)
    {
      if(board[i][j] == Blank || board[i][j] == Invalid)
        return Invalid;
      else if(board[i][j] == X)
        tempX++;
      else if(board[i][j] == O)
        tempO++; 
    }
    if(tempX > maxX)
      maxX  = tempX;
    if(tempO > maxO)
      maxO = tempO;
    tempX = 0;
    tempO = 0;
  }

  // Check the max number of rows
  for(int i=0; i < BOARD_COLS; i++)
  {
    for(int j=0; j < BOARD_ROWS;j++)
    {
      if(board[j][i] == X)
        tempX++;
      else if(board[j][i] == O)
        tempO++; 
    }
    if(tempX > maxX)
      maxX  = tempX;
    if(tempO > maxO)
      maxO = tempO;
    tempX = 0;
    tempO = 0;
  }

  // Check to see who the winner is
  if(maxX == maxO)
    return Blank;
  else if(maxX > maxO)
    return X;
  else if(maxX < maxO)
    return O;
}
