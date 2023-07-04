#include <bits/stdc++.h>
using namespace std;

void sort01(vector<int> &vec)
{
    int j = 0;
    int i = 0;

    while (i < vec.size())
    {
        if (vec[i] == 1)
        {
            i++;
        }
        else
        {
            swap(vec[i], vec[j]);
            i++;
            j++;
        }
    }
}

int main()
{
    vector<int> vec = {1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0};
    sort01(vec);
    for (int val : vec)
    {
        cout << val << " ";
    }
}