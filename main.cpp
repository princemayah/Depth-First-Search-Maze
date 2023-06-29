#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

class Maze {
private:
  int seed;
  int w;
  int h;
  vector<vector<int>> maze;
  vector<vector<int>> edges;

public:
  // Initialize the maze grid and edges vectors based on row width and height
  Maze(int rowWidth, int rowHeight, int seed) : w(rowWidth - rowWidth % 2 + 1), h(rowHeight - rowHeight % 2 + 1), maze(h, vector<int>(w, 1)), edges(), seed(seed) {
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(i % 2 == 0 && j % 2 != 0) {
          edges.push_back({i, j}); // Add horizontal edges
        }
        else if(i % 2 != 0 && j % 2 == 0) {
          edges.push_back({i, j}); // Add vertical edges
        }
        else {
          maze[i][j] = 0; // Set the cells inside the maze as walls
        }
      }
    }
    srand(seed); // Set the random seed
  }

// Generate the maze using a randomized Prim's algorithm
  void generate() {
    vector<vector<int>> visited(h, vector<int>(w, 0));
    stack<pair<int, int>> st;
    int start_row = rand() % (h/2) * 2 + 1; // Pick a random starting row
    int start_col = rand() % (w/2) * 2 + 1; // Pick a random starting column
    visited[start_row][start_col] = 1;
    st.push({start_row, start_col});

    while(!st.empty()) {
      auto curr = st.top();
      st.pop();
      int row = curr.first;
      int col = curr.second;
      vector<vector<int>> neighbors = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
      random_shuffle(neighbors.begin(), neighbors.end()); // Randomly shuffle the neighbors

      // Visit the neighbors randomly
      for(auto& neighbor : neighbors) {
        int next_row = row + neighbor[0];
        int next_col = col + neighbor[1];
        if(next_row >= 0 && next_row < h && next_col >= 0 && next_col < w && !visited[next_row][next_col]) {
          int mid_row = row + neighbor[0] / 2;
          int mid_col = col + neighbor[1] / 2;
          maze[mid_row][mid_col] = 0; // Carve a path between the current cell and the next cell
          visited[next_row][next_col] = 1;
          st.push({next_row, next_col});
        }
      }
    }
  }
  
  // Print the maze
  void print() {
    cout << " ";
    for(int i = 0; i < w; i++) {
      if (i == 0) {
        cout << "  ";
      }
      cout << "\u2588"; // Print a full block character to represent walls
    }
    cout << endl;

    for(int row = 0; row < h; row++) {
      if (row == 0) {
        cout << " ";
      }
      cout << "\u2588"; // Print a full block character to represent walls
      for(int col = 0; col < w; col++) {
        if (maze[row][col] == 1) {
          cout << "\u2588"; // Print a full block character to represent walls
        }
        else {
          cout << " "; // Print a space character to represent open paths
        }
      }
      cout << "\u2588" << endl; // Print a full block character to represent walls
    }

    for(int i = 0; i < w-2; i++) {
      if (i == w + 1) {
        cout << " ";
      }
      else {
        cout << "\u2588"; // Print a full block character to represent walls
      }
    }
    cout << endl;
  }
  
  // Connect all cells in the maze using depth-first search
  void connect() {
    vector<vector<int>> visited(h, vector<int>(w, 0));
    dfs(1, 1, visited);
  }

  // Depth-first search to connect neighboring cells in the maze
  void dfs(int row, int col, vector<vector<int>>& visited) {
    visited[row][col] = 1;
    maze[row][col] = 0;

    vector<vector<int>> neighbors = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
    random_shuffle(neighbors.begin(), neighbors.end()); // Randomly shuffle the neighbors

    // Perform depth-first search to connect all cells
    for(auto& neighbor : neighbors) {
      int next_row = row + neighbor[0];
      int next_col = col + neighbor[1];
      if(next_row >= 0 && next_row < h && next_col >= 0 && next_col < w && !visited[next_row][next_col] && maze[next_row][next_col]) {
        int mid_row = row + neighbor[0] / 2;
        int mid_col = col + neighbor[1] / 2;
        maze[mid_row][mid_col] = 0; // Carve a path between the current cell and the next cell
        dfs(next_row, next_col, visited);
      }
    }
  }
};

int main() {
  int rowWidth, rowHeight, seed;

  cout << "\033[2J\033[1;1H"; // Clear the console

  cout << "Enter the row width: ";
  cin >> rowWidth;

  cout << "Enter the row height: ";
  cin >> rowHeight;

  cout << "Enter the seed value: ";
  cin >> seed;

  cout << "\033[2J\033[1;1H"; // Clear the console

  Maze maze(rowWidth, rowHeight, seed);
  maze.generate(); // Generate the maze
  maze.connect(); // Connect all cells in the maze
  maze.print(); // Print the maze

  return 0;
}