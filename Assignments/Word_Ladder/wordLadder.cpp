#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type

unordered_map<string, bool> visited;
unordered_map<string, string> pred;
unordered_map<string, int> dist;
unordered_map<string, vector<string>> nbrs;

int path_finder(string, string, vector<string>&);
void build_graph();

//Implement breadth-first search, refer to Lab 10 
void wordLadder(string s, string t, int &steps, vector<string> &p)
{
  build_graph();  // Calling build graph function
  queue<string> to_visit;
  to_visit.push(s);
  visited[s] = true;
  dist[s] = 0;
  while (!to_visit.empty()) {
    string curnode = to_visit.front();
    to_visit.pop();
    for (string n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
  steps = path_finder(s, t, p);
}

// This function should return the number of steps in the path from start to end
int path_finder(string start, string end,vector<string> &path) {

// Catch seg fault by ensuring that end node has a predecessor
  if(pred.find(end) == pred.end())
    return 0; // No path exists
  if(start.compare(end) != 0) {
    int step = 1 + path_finder(start, pred[end],path);
    path.push_back(end);  // Add end node to path
    return step;
  }
  else {
    path.push_back(end);  // Add end node to path
    return 0;
  }
}

void build_graph(void) {
  ifstream word_file ("wordlist05.txt");
  string current_word;
  // Read in words from wordlist05.txt
  while( word_file >> current_word ) {
    V.push_back( current_word );
  }
  // Build graph
  for(auto word : V) {
    // Add word to graph
    for(int place = 0; place < word.length(); place++) {
      // Change each letter in word
      for(char letter = 'a'; letter <= 'z'; letter++) {
        // Change letter at place
        if(letter == word.at(place))
          continue;
        // Create new word
        string current = word;
        current.at(place) = letter;
        nbrs[word].push_back(current);
      }
    }
  }
}

// int main(void)
// {
//   int steps = 0;
//   string s, t;
//   vector<string> path;
  
//   cout << "Source: ";
//   cin >> s;

//   cout << "Target: ";
//   cin >> t;

//   wordLadder(s, t, steps, path);

//   if (steps == 0)
//   {
//       cout << "No path!\n";
//   }
//   else
//   {
//       cout << "Steps: " << steps << "\n\n";
//       for (int i=0; i<path.size(); i++)
//       {
//           cout << path[i] << endl;
//       }
//   }
//   return 0;
// }
