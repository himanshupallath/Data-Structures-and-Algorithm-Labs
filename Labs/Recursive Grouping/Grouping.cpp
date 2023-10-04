/*
 * Name: Himanshu Pallath
 * Date Submitted: 2/10/2023
 * Lab Section: 001
 * Assignment Name: Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping(string fileName) {
    ifstream file;
    file.open(fileName);    // Opens the inputed file
    for (int i = 0; i < 10; i++) {
        string line = "";   // Gets the line from each row
        getline(file, line);
        // Loops through each column in the row
        for (int j = 0; j < 10; j++) {
            if (line[j] == '.') {
                grid[i][j] = 0;     // a 0 for every '.'
                cout<<grid[i][j];
            } else {
                grid[i][j] = 1;     // a 1 for every 'X'
                cout<<grid[i][j];
            }
        }
        cout<<endl;
    }
    // Loops through the grid looping for the 1s
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 1) {
                vector<GridSquare> group;   // Create a vector for a group
                findGroup(i, j, group);     // Call the recursive function
                groups.push_back(group);    // Add the group to the groups vector
            }
        }
    }
}

void Grouping::findGroup(int r, int c, vector<GridSquare> &group) {
    group.push_back(GridSquare(r,c));   // Adds the grid square to the group vector
    grid[r][c] = 0; // Replaces the 1 with a 0 so it doesn't check it again
    // Checks the value below the current value
    if (r+1 < 10 && grid[r+1][c] == 1) {    // Checks to see if in bounds
        findGroup(r+1, c, group);   // Calls recursive function
    }
    // Checks the value above the current value
    if (r-1 >= 0 && grid[r-1][c] == 1) {    // Checks to see if in bounds
        findGroup(r-1, c, group);   // Calls recursive function
    }
    // Checks the value to the right of the current value
    if (c+1 < 10 && grid[r][c+1] == 1) {    // Checks to see if in bounds
        findGroup(r, c+1, group);   // Calls recursive function
    }
    // Checks the value to the left of the current value
    if (c-1 >= 0 && grid[r][c-1] == 1) {    // Checks to see if in bounds
        findGroup(r, c-1, group);   // Calls recursive function
    }
}



//Simple main function to test Grouping
//Be sure to comment out main() before submitting
// int main()
// {
//     Grouping input1("input1.txt");
//     input1.printGroups();
    
//     return 0;
// }

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    return groups;
}