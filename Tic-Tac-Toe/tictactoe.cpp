#include <iostream>

using namespace std;
int currentPlayer;
char currentMarker;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void DrawBoard()
{
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
  cout << "---|---|---\n";
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
  cout << "---|---|---\n";
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;
}
bool PlaceMarker(int slot)
{
  int row = (slot - 1) / 3;
  int col = (slot - 1) % 3;

  if (board[row][col] != 'X' && board[row][col] != 'O')
  {
    board[row][col] = currentMarker;
    return true;
  }
  else
  {
    return false;
  }
}

int Winner()
{

  // rows
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
    {
      return currentPlayer;
    }
  }

  // columns
  for (int i = 0; i < 3; i++)
  {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
    {
      return currentPlayer;
    }
  }

  // diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
  {
    return currentPlayer;
  }

  if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
  {
    return currentPlayer;
  }

  return 0;
}

void SwapPlayerAndMarker()
{
  if (currentMarker == 'X')
  {
    currentMarker = 'O';
  }
  else
  {
    currentMarker = 'X';
  }
  if (currentPlayer == 1)
  {
    currentPlayer = 2;
  }
  else
  {
    currentPlayer = 1;
  }
}

bool MarkerInput(char ch)
{
  if (ch == 'x' || ch == 'X' || ch == 'o' || ch == 'O')
  {
    return true;
  }
  else
  {
    return false;
  }
}
void game()
{
  char markerP1;
  char temp;
  cout << "Player1 Choose Your Marker [X or O] :-";
  cin >> temp;
  if (MarkerInput(temp))
  {
    if (temp == 'o' || temp == 'O')
    {
      temp = 'O';
    }
    else if (temp == 'x' || temp == 'X')
    {
      temp = 'X';
    }
  }
  else
  {
    cout << "!!!-----Failed To Featch The Marker-----!!!" << endl;
    cout << endl;
    cout << "<-------Please Restart The Game------->";
    cout << endl;
    return;
  }
  markerP1 = temp;
  currentPlayer = 1;
  currentMarker = markerP1;
  DrawBoard();
  int PlayerWon;
  for (int i = 0; i < 9; i++)
  {
    cout << "its Player:- " << currentPlayer << "'s Turn, Enter Your Slot :- ";
    int slot;
    cin >> slot;
    if (slot < 1 || slot > 9)
    {
      cout << "It is Not a Valid Slot, You may try again" << endl;
      i--;
      continue;
    }
    if (!PlaceMarker(slot))
    {
      cout << "Slot Is Occupied,  You may try again" << endl;
      i--;
      continue;
    }
    DrawBoard();
    PlayerWon = Winner();
    if (PlayerWon == 1)
    {
      cout << "Player 1 Won the Match.";
      break;
    }
    if (PlayerWon == 2)
    {
      cout << "Player 2 Won the Match.";
      break;
    }
    SwapPlayerAndMarker();
  }
  if (PlayerWon == 0)
  {
    cout << "Aaah! Match Tie..." << endl;
  }
}
void ResetBoard()
{
  char val = '1';
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      board[i][j] = val++;
    }
  }
}

int main()
{
  int choice;

  do
  {
    ResetBoard(); // har baar new board
    game();

    cout << "\nPress 1 to play again or 0 to exit: ";
    cin >> choice;

  } while (choice == 1);
  cout << endl;

  cout << "--------Thanks for playing!--------";
  return 0;
}