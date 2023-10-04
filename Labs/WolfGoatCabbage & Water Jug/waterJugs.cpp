/*
 * Name: Himanshu Pallath
 * Date Submitted: 4/17/2023
 * Lab Section: 001
 * Assignment Name: Lab 10
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from source_node)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;
  
  while (!to_visit.empty()) {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n";
  } else {
    cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
  }
}

void build_graph()
{
  //Implement this function
  for (int i = 0; i <= 3; i++) {  // I indicates A
    for (int j = 0; j <= 4; j++) {  // J indicates B
      // FILL A
      if (i < 3) {
        nbrs[make_pair(i,j)].push_back(make_pair(3,j));
        edge_label[make_pair(make_pair(i,j), make_pair(3,j))] = actions[0];
      }
      // FILL B
      if (j < 4) {
        nbrs[make_pair(i,j)].push_back(make_pair(i, 4));
        edge_label[make_pair(make_pair(i,j), make_pair(i,4))] = actions[1];
      }
      // EMPTY A
      if (i > 0) {
        nbrs[make_pair(i,j)].push_back(make_pair(0,j));
        edge_label[make_pair(make_pair(i,j), make_pair(0,j))] = actions[2];
      }
      // EMPTY B
      if (j > 0) {
        nbrs[make_pair(i,j)].push_back(make_pair(i,0));
        edge_label[make_pair(make_pair(i,j), make_pair(i,0))] = actions[3];
      }
      // POUR A->B
      if (i > 0 && j < 4) {
        nbrs[make_pair(i,j)].push_back(make_pair(max(i+j-4,0), min(i+j,4)));
        edge_label[make_pair(make_pair(i,j), make_pair(max(i+j-4,0), min(i+j,4)))] = actions[4];
      }
      // POUR B->A
      if (i < 3 && j > 0) {
        nbrs[make_pair(i,j)].push_back(make_pair(min(i+j,3), max(i+j-3,0)));
        edge_label[make_pair(make_pair(i,j), make_pair(min(i+j,3), max(i+j-3,0)))] = actions[5];
      }
    }
  }
}

// int main(void)
// {
//   build_graph();

//   state start = make_pair(0,0);
  
//   for (int i=0; i<5; i++)
//     nbrs[make_pair(i,5-i)].push_back(make_pair(-1,-1));
//   search (start);
//   if (visited[make_pair(-1,-1)]) 
//     print_path (start, pred[make_pair(-1,-1)]);
//   else
//     cout << "No path!\n";
//   return 0;
// }
