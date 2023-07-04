//* we will be using adjacency list
#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src;
    int nbr;
    int weight;

    Edge(int src, int nbr, int weight) : src(src), nbr(nbr), weight(weight) {}
};

class Graph
{
public:
    int vertices;
    int edges;
    vector<vector<Edge *>> graph;
    string smallestPath;
    int smallestPathWeight = INT_MAX;
    string largestPath;
    int largestPathWeight = INT_MIN;
    string ceilPath;
    int ceilPathWeight = INT_MAX;
    string floorPath;
    int floorPathWeight = INT_MIN;

    Graph(int ver, int ed, vector<vector<Edge *>> &graph) : vertices(ver), edges(ed), graph(graph) {}

    //* lets solve the first question- hasPath
    bool hasPath(int src, int dest, vector<bool> isVisited)
    {
        //* we will us the expectaion faith
        //* faith: ki mere neighbours ko batana aata hai ki dest tak ka rasta hai ya nahi
        if (src == dest)
        {
            //* aap khud bhi nhai ho;
            return true;
        }

        isVisited[src] = 1;

        for (Edge *e : graph[src])
        {
            if (!isVisited[e->nbr])
            {
                bool doesNeighbourHavePath = hasPath(e->nbr, dest, isVisited);
                if (doesNeighbourHavePath)
                {
                    return true;
                }
            }
        }

        //* aapko apne neightbours se bhi nahi mila

        return false;
    }

    void printAllPaths(int src, int dest, string currPath, vector<bool> &isVisited)
    {
        if (src == dest)
        {
            cout << currPath << endl;
            return;
        }

        isVisited[src] = true;
        for (Edge *e : graph[src])
        {
            if (!isVisited[e->nbr])
            {
                printAllPaths(e->nbr, dest, currPath + to_string(e->nbr), isVisited);
            }
        }

        //* now here it is important to undo you steps becuase you might want to visit the current node(src) again because a different path may exist, in hasPath() this wasnt important, if lets assume the node you are on is A, and a path exists between A and destination, now you wont visit A again , because you already know that a path exists between A and dest.
        isVisited[src] = false;

        //* if you pass the isVisisted by value, the above step is not required, because when a call returns , you have your own copy/state of isVisited in which your neighbour wont be marked because you sent a copy in the call, but if its by refernce, then the above step is required, because its the same array of state that is carried along all the funtion calls;
    }

    void multisolver(int src, int dest, vector<bool> &isVisisted, string currPath, int cumWeight, int ceilCriteria, int floorCriteria)
    {
        if (src == dest)
        {
            //* for smallest weight path
            if (cumWeight < smallestPathWeight)
            {
                smallestPath = currPath;
                smallestPathWeight = cumWeight;
            }
            //* for largest weight path
            if (cumWeight > largestPathWeight)
            {
                largestPath = currPath;
                largestPathWeight = cumWeight;
            }

            //* for ceil path
            if (cumWeight >= ceilCriteria and cumWeight < ceilPathWeight)
            {
                ceilPath = currPath;
                ceilPathWeight = cumWeight;
            }
            //* for floor path
            if (cumWeight <= floorCriteria and cumWeight > floorPathWeight)
            {
                floorPath = currPath;
                floorPathWeight = cumWeight;
            }
            return;
        }

        isVisisted[src] = true;

        for (Edge *&e : graph[src])
        {
            if (!isVisisted[e->nbr])
            {
                multisolver(e->nbr, dest, isVisisted, currPath + to_string(e->nbr), cumWeight + e->weight, ceilCriteria, floorCriteria);
            }
        }

        isVisisted[src] = false;
    }

    void makeComponent(int src, vector<int> &component, vector<bool> &isVisited)
    {
        component.push_back(src);
        isVisited[src] = true;

        for (Edge *e : graph[src])
        {
            if (!isVisited[e->nbr])
            {
                makeComponent(e->nbr, component, isVisited);
            }
        }

        //* yahan pe mujhe isVisited[src]=false, nahi karna kyunki assume agar 1- 2 , yeh ek component hai aur agar call se wapas aate hue main 2 ka false kar doon toh getComponentedComponents mein 2 ke liye bhi call lagegi which is wrong kyunki 2 already visited hai
    }

    vector<vector<int>> getConnectedComponents(vector<bool> &isVisited)
    {
        vector<vector<int>> components;
        //* wee give mauka to all the vertices failna ka, taaki woh apne components dhoondh le
        for (int v = 0; v < vertices; v++)
        {
            if (!isVisited[v])
            {
                vector<int> component;
                makeComponent(v, component, isVisited);
                components.push_back(component);
            }
        }

        return components;
    }
};

int main()
{
    int vertices = 7;
    int edges = 8;
    // vector<vector<Edge *>> graph = {
    //     {new Edge(0, 1, 10), new Edge(0, 3, 40)},
    //     {new Edge(1, 0, 10), new Edge(1, 2, 10)},
    //     {new Edge(2, 1, 10), new Edge(2, 3, 10)},
    //     {new Edge(3, 2, 10), new Edge(3, 0, 40), new Edge(3, 4, 2)},
    //     {new Edge(4, 3, 2), new Edge(4, 5, 3), new Edge(4, 6, 8)},
    //     {new Edge(5, 4, 3), new Edge(5, 6, 3)},
    //     {new Edge(6, 5, 3), new Edge(6, 4, 8)}};
    vector<vector<Edge *>> graph = {
        {new Edge(0, 1, 10)},
        {new Edge(1, 0, 10)},
        {new Edge(2, 3, 10)},
        {new Edge(3, 2, 10)},
        {new Edge(4, 5, 10), new Edge(4, 6, 10)},
        {new Edge(5, 4, 10), new Edge(5, 6, 10)},
        {new Edge(6, 5, 10), new Edge(6, 4, 10)}};

    vector<bool>
        isVisited(vertices);
    Graph g(vertices, edges, graph);

    // g.hasPath(0, 6, isVisited);
    // g.printAllPaths(0, 6, "0", isVisited);
    // string currPath = "0";
    // g.multisolver(0, 6, isVisited, currPath, 0, 42, 39);
    // cout << g.ceilPath << "@" << g.ceilPathWeight << "\n";
    // cout << g.floorPath << "@" << g.floorPathWeight;
    for (auto &vec : g.getConnectedComponents(isVisited))
    {
        for (int &v : vec)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}