#include <bits/stdc++.h>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string currPath)
{
    if (sr > dr || sc > dc)
    {
        return;
    }
    if (sr == dr and sc == dc)
    {
        cout << currPath << endl;
        return;
    }

    printMazePaths(sr, sc + 1, dr, dc, currPath + 'h');
    printMazePaths(sr + 1, sc, dr, dc, currPath + 'v');
}

void printMazePathsJumps(int sr, int sc, int dr, int dc, string currPath)
{
    if (sr == dr and sc == dc)
    {
        cout << currPath << endl;
        return;
    }
    for (int i = 1; i <= dr - sr; i++)
    {
        printMazePathsJumps(sr + i, sc, dr, dc, currPath + "h" + (char)(i + '0'));
    }
    for (int i = 1; i <= dc - sc; i++)
    {
        printMazePathsJumps(sr, sc + i, dr, dc, currPath + "v" + (char)(i + '0'));
    }
}

int main()
{
    printMazePathsJumps(0, 0, 2, 2, "");
}