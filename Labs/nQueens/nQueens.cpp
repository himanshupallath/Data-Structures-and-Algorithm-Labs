/*
 * Name: Himanshu Pallath
 * Date Submitted: 4/15/2023
 * Lab Section: 001
 * Assignment Name: Lab 9
 */

#include <iostream>
#include <vector>

using namespace std;

bool checkSafe(vector<vector<int>> board, int row, int col, int n)
{
    //if the row is 0, then it is the first row and there is no need to check
    if (row == 0) {
        return true;
    }
    //Check if there is a queen in the same column
    for (int i = row; i >= 0; i--) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    //Check if there is a queen in the same diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    //Check if there is a queen in the same diagonal
    for (int i = row, j = col; j < n && i >= 0; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

void checkRow(int row, vector<vector<int>> &board, int &solutions, int n) {
    if (row == board.size()) {
        solutions++;    // If the row is equal to the size of the board, then a solution has been found
    } else {
        // loop through all the columns in the row
        for (int i = 0; i < n; i++) {
            // if the position is safe, then place a queen there and check the next row
            if (checkSafe(board, row, i, board.size())) {
                board[row][i] = 1;  // place a queen
                checkRow(row + 1, board, solutions, n);     // check the next row
                board[row][i] = 0;  // remove the queen
            }
        }
    }
}
//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    vector<vector<int>> board(n, vector<int>(n));   // create a board
    int solutions = 0; // initialize the number of solutions to 0
    for (int i = 0; i < n; i++) {  // initialize the board to all 0s
        for (int j = 0; j < n; j++) {
            board[i].push_back(0);
        }
    }
    checkRow(0, board, solutions, n);  // check the first row
    return solutions;  // return the number of solutions
}
/*
int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}
*/