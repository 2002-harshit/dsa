#include <bits/stdc++.h>
using namespace std;

int dfs(int sr, int sc, vector<vector<int>> &map, vector<vector<bool>> &isVisited)
{
    if (sr < 0 or sr == map.size() or sc < 0 or sc == map[0].size() or map[sr][sc] == 0 or isVisited[sr][sc])
    {
        return 0;
    }
    isVisited[sr][sc] = true;

    //* now traverse to all your neighboors
    int topAns = dfs(sr - 1, sc, map, isVisited);
    int rightAns = dfs(sr, sc + 1, map, isVisited);
    int bottomAns = dfs(sr + 1, sc, map, isVisited);
    int leftAns = dfs(sr, sc - 1, map, isVisited);

    //* again i dont have to mark isVisited[sr][sc]= false in the post order because i dont want to visit it again since it is already part of some island.

    return map[sr][sc] + topAns + rightAns + bottomAns + leftAns;
}

int main()
{
    vector<vector<int>> map = {{0, 1, 4, 2, 8, 2}, {4, 3, 6, 5, 0, 4}, {1, 2, 4, 1, 4, 6}, {2, 0, 7, 3, 2, 2}, {3, 1, 5, 9, 2, 4}, {2, 7, 0, 8, 5, 1}};

    //* again this is a problem of getConnectedComponents but in a matrix
    vector<vector<bool>>
        isVisited(map.size(), vector<bool>(map[0].size()));

    int maxGold = INT_MIN;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[0].size(); j++)
        {
            if (map[i][j] != 0 and !isVisited[i][j])
            {
                maxGold = max(maxGold, dfs(i, j, map, isVisited));
            }
        }
    }

    cout << maxGold;
}