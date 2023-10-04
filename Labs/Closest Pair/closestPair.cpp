/*
 * Name: Himanshu Pallath
 * Date Submitted: 3/13/2023
 * Lab Section: 001
 * Assignment Name: Lab 6 Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
  double x;
  double y;
};

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename);
double checkClosestPoint(point onePoint, vector<point> points);
double checkMin(double min, double dist);

// int main()
// {
//     double min;
//     string filename;
//     cout << "File with list of points within unit square: ";
//     cin >> filename;
//     min = closestPair(filename);
//     cout << setprecision(16);
//     cout << "Distance between closest pair of points: " << min << endl;
//     return 0;
// }
/**
  This function takes in a point and a vector of points and returns the distance
  @param onePoint is the point that is being compared to the points in the vector
  @param points is the vector of points that is being compared to the point
  @return the distance between the point and the closest point in the vector
*/
double checkClosestPoint(point onePoint, vector<point> points) {
  double min = 1;
  // x1 and y1 are the coordinates of the point
  double x1 = onePoint.x;
  double y1 = onePoint.y;
  // x2 and y2 are the coordinates of the point in the vector
  for (int i = 0; i < points.size(); i++) {
    double x2 = points[i].x;
    double y2 = points[i].y;
    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // distance formula
    // if the distance is less than the current min and not 0, then set min to dist
    if (dist < min && dist != 0) {
      min = dist;
    }
  }
  return min; // return the min distance
}
/**
  This function takes in a double and a double and returns the smaller of the two
  @param min is the current min distance
  @param dist is the distance that is being compared to the min
  @return the smaller of the two distances
*/
double checkMin(double min, double dist) {
  if (dist < min && dist != 0) {
    min = dist;
  }
  return min;
}

/**
  This function takes in a string and returns the distance between the closest pair of points
  @param filename is the name of the file that is being read
  @return the distance between the closest pair of points
*/
double closestPair(string filename) {
  ifstream infile;
  infile.open(filename);  // open the file
  int numPoints;
  infile >> numPoints; // read in the number of points
  int b = sqrt(numPoints); // b is the number of cells
  double interval = 1 / (double) b; // interval is the length of each cell
  vector<vector<vector<point>>> plane(b, vector<vector<point>>(b));
  double x, y;
  while (infile >> x >> y) {    
    int xIndex = floor(x / interval); // xIndex is the index of the cell in the x direction
    int yIndex = floor(y / interval); // yIndex is the index of the cell in the y direction
    plane[xIndex][yIndex].push_back({x, y}); // add the point to the cell
  }
  double min = 1;
  
  // check the distance between the points in the same cell
  for (int i = 0; i < b; i++) {   // loop through the rows
    for (int j = 0; j < b; j++) { // loop through the columns
      for (int k = 0; k < plane[i][j].size(); k++) {  // loop through the points in the cell
        // check the distance between the point and the points in the same cell
        double newMin = checkClosestPoint(plane[i][j][k], plane[i][j]);
        min = checkMin(min, newMin);
        // check the distance between the point and the points in the cell to the right
        if (j+1 < b) {
          newMin = checkClosestPoint(plane[i][j][k], plane[i][j+1]);
          min = checkMin(min, newMin);
        }
        // check the distance between the point and the points in the cell to the left
        if (j-1 >= 0) {
          newMin = checkClosestPoint(plane[i][j][k], plane[i][j-1]);
          min = checkMin(min, newMin);
        }
        // check the distance between the point and the points in the cell below
        if (i+1 < b) {
          newMin = checkClosestPoint(plane[i][j][k], plane[i+1][j]);
          min = checkMin(min, newMin);
        }
        // check the distance between the point and the points in the cell bottom right
        if (i+1 < b && j+1 < b) {
          newMin = checkClosestPoint(plane[i][j][k], plane[i+1][j+1]);
          min = checkMin(min, newMin);
        }
        // check the distance between the point and the points in the cell bottom left
        if (i+1 < b && j-1 >= 0) {
          newMin = checkClosestPoint(plane[i][j][k], plane[i+1][j-1]);
          min = checkMin(min, newMin);
        }
      }
      plane[i][j].clear();  // clear the cell
    }
  }
  return min;   // return the min distance
}