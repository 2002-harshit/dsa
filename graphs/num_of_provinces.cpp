#include <bits/stdc++.h>
using namespace std;

//* complete copy fo the get connected components

class Solution
{
public:
    void dfs(int src, vector<int> graph[], vector<bool> &isVisited)
    {
        isVisited[src] = true;

        for (int &nbr : graph[src])
        {
            if (!isVisited[nbr])
            {
                dfs(nbr, graph, isVisited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        //* we are given adjacency matrix, lets convert it to list;
        vector<int> graph[isConnected.size()];

        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected.size(); j++)
            {
                if (isConnected[i][j] == 1 and i != j)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int provinces = 0;
        vector<bool> isVisited(isConnected.size());
        for (int v = 0; v < isVisited.size(); v++)
        {
            if (!isVisited[v])
            {
                dfs(v, graph, isVisited);
                provinces++;
            }
        }

        return provinces;
    }
};
