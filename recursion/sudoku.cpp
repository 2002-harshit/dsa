#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, int option)
{
    //* in column;
    for (int j = 0; j <= 8; j++)
    {
        if (board[row][j] == (char)('0' + option))
        {
            return false;
        }
    }

    //* in row
    for (int i = 0; i <= 8; i++)
    {
        if (board[i][col] == (char)('0' + option))
        {
            return false;
        }
    }

    //* in box
    pair<int, int> topLeftOfSubMatrix = {3 * (row / 3), 3 * (col / 3)};
    for (int i = topLeftOfSubMatrix.first; i < topLeftOfSubMatrix.first + 3; i++)
    {
        for (int j = topLeftOfSubMatrix.second; j < topLeftOfSubMatrix.second + 3; j++)
        {
            if (board[i][j] == (char)('0' + option))
            {
                return false;
            }
        }
    }

    return true;
}

// void solve(int i, int j, vector<vector<char>> &board)
// {
//     if (i == 9)
//     {
//         return;
//     }
//     int new_i = 0;
//     int new_j = 0;

//     if (j == 8)
//     {
//         new_i = i + 1;
//         new_j = 0;
//     }
//     else
//     {
//         new_i = i;
//         new_j = j + 1;
//     }

//     if (board[i][j] != '.')
//     {
//         solve(new_i, new_j, board);
//     }
//     else
//     {
//         //* then you can fill something so the levels and options game
//         for (int possibleOptions = 1; possibleOptions <= 9; possibleOptions++)
//         {
//             if (isValid(board, i, j, possibleOptions))
//             {
//                 board[i][j] = (char)(possibleOptions + '0');
//                 solve(new_i, new_j, board);
//                 //* now the postorder or teh backtrack code
//                 board[i][j] = '.';
//             }
//         }
//     }
// }
//* the below solution will top once you found out the solution, the above one just backtracks everything to normal once the solution is found, so you have to print the board in the base case and no other option
bool solve(int i, int j, vector<vector<char>> &board)
{
    if (i == 9)
    {
        return true;
    }
    int new_i = 0;
    int new_j = 0;

    if (j == 8)
    {
        new_i = i + 1;
        new_j = 0;
    }
    else
    {
        new_i = i;
        new_j = j + 1;
    }

    if (board[i][j] != '.')
    {
        return solve(new_i, new_j, board);
    }
    else
    {
        //* then you can fill something so the levels and options game
        for (int possibleOptions = 1; possibleOptions <= 9; possibleOptions++)
        {
            if (isValid(board, i, j, possibleOptions))
            {
                board[i][j] = (char)(possibleOptions + '0');
                if (solve(new_i, new_j, board))
                {
                    return true;
                }
                //* the control will only come here if the call's result was false,which would happen when you have tried all the possible options, so we need to undo what we did
                board[i][j] = '.';
            }
        }

        return false;
    }
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solve(0, 0, board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}