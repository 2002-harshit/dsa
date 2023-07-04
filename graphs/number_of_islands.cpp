#include <bits/stdc++.h>
using namespace std;

//* we knopow thatg we make the drawTree method, in which we let the src node to failna(stretch ) as much as it can

void drawTree(int sr, int sc, vector<vector<int>> &map, vector<vector<bool>> &isVisited)
{
    if (sr < 0 or sr == map.size() or sc < 0 or sc == map[0].size() or isVisited[sr][sc] or map[sr][sc] == 1)
    {
        return;
    }
    isVisited[sr][sc] = true;

    //* now in getConnectedComponents we used to travel to our unvisited neighbours
    drawTree(sr - 1, sc, map, isVisited);
    drawTree(sr, sc + 1, map, isVisited);
    drawTree(sr + 1, sc, map, isVisited);
    drawTree(sr, sc - 1, map, isVisited);

    //* again here also i wont mark isVisited[sr][sc] false, because i dont want to give these zeros more maukas to form their provinces when they are already part of some province.
}

int main()
{
    vector<vector<int>> map = {
        {0, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {1, 1, 1, 1, 0, 1, 1, 0},
        {1, 1, 1, 1, 0, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0},
    };

    //* but this is not a graph, it is !!!, consider every cell is a vertex., this is different from number_of_isalnds becuase we consider every cell as a vertex.
    //* and each of it has 4 edges
    //* this is very similar to getConnectedComponents

    int numberOfProvinces = 0;

    vector<vector<bool>> isVisited(map.size(), vector<bool>(map[0].size()));

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[0].size(); j++)
        {
            if (map[i][j] == 0 and !isVisited[i][j])
            {
                drawTree(i, j, map, isVisited);
                numberOfProvinces++;
            }
        }
    }

    cout << numberOfProvinces;
}