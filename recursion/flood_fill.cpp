#include <bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int>> &maze, int sr, int sc, string currPath, vector<vector<bool>> &isVisited)
{
    if (sr < 0 or sc < 0 or sr == maze.size() or sc == maze[0].size() or maze[sr][sc] == 1 or isVisited[sr][sc] == true)
    {
        return;
    }
    if (sr == maze.size() - 1 and sc == maze[0].size() - 1)
    {
        cout << currPath << endl;
        return;
    }
    isVisited[sr][sc] = true;
    floodfill(maze, sr - 1, sc, currPath + "t", isVisited);
    floodfill(maze, sr, sc - 1, currPath + "l", isVisited);
    floodfill(maze, sr + 1, sc, currPath + "d", isVisited);
    floodfill(maze, sr, sc + 1, currPath + "r", isVisited);
    isVisited[sr][sc] = false;
}

int main()
{
    vector<vector<int>> maze = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}, {0, 0, 0}};
    vector<vector<bool>> isVisited(maze.size(), vector<bool>(maze[0].size()));
    floodfill(maze, 0, 0, "", isVisited);
    return 0;
}