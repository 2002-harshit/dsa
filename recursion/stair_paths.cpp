#include <bits/stdc++.h>
using namespace std;

void print_stair_paths(int stairsNum, string currPath)
{
    if (stairsNum == 0)
    {
        cout << currPath << endl;
        return;
    }
    else if (stairsNum < 0)
    {
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        print_stair_paths(stairsNum - i, currPath + (char)(i + '0'));
    }

    //* idhar i am maaring andhi calls, lets go for smart calls
}

void smarter_stairs_path(int stairsNum, string currPath)
{
    if (stairsNum == 0)
    {
        cout << currPath << endl;
        return;
    }
    for (int i = 1; i <= min(stairsNum, 3); i++)
    {
        smarter_stairs_path(stairsNum - i, currPath + (char)(i + '0'));
    }
}

int main()
{
    smarter_stairs_path(3, "");
    return 0;
}