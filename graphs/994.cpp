#include<bits/stdc++.h>
using namespace std;
 

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> queue;
        int count_fresh = 0;

        // Put the position of all rotten oranges in the queue and count the fresh
        // oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    queue.push({i, j});
                } else if (grid[i][j] == 1) {
                    count_fresh++;
                }
            }
        }

        // If there are no fresh oranges, return 0
        if (count_fresh == 0)
            return 0;

        // Call BFS to spread the rot and count the number of minutes taken
        return bfs(grid, queue, count_fresh);
    }

private:
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& queue, int& count_fresh) {
        int count = 0;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int rows = grid.size();
        int cols = grid[0].size();

        // BFS from the initial rotten oranges
        while (!queue.empty()) {
            ++count;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                auto point = queue.front();
                queue.pop();
                for (const auto& dir : dirs) {
                    int x = point.first + dir.first;
                    int y = point.second + dir.second;

                    // Check if x, y is out of bounds or already rotten or empty
                    if (x < 0 || y < 0 || x >= rows || y >= cols ||
                        grid[x][y] == 0 || grid[x][y] == 2) {
                        continue;
                    }

                    // Mark the orange as rotten
                    grid[x][y] = 2;
                    queue.push({x, y});
                    count_fresh--;
                }
            }
        }

        return count_fresh == 0 ? count - 1 : -1;
    }
};


int main(){
    
 cout << endl;
return 0;
}