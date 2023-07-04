#include <bits/stdc++.h>
using namespace std;

void cyclic_sort(vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        while (vec[i] != i + 1)
        {
            swap(vec[i], vec[f])
        }
    }
}

int main()
{
    vector<int> vec = {3, 2, 1, 5, 4};
    cyclic_sort(vec);
    return 0;
}