#include <bits/stdc++.h>
using namespace std;

//* this kind of array intersection is beneficial using hashmapl when the arrays are not sorted, if they arffe sorted we can go for 2 pointers , one pointer for each array

void gc1(vector<int> &a1, vector<int> &a2)
{
    unordered_map<int, int> freq;
    for (int &val : a1)
    {
        freq[val]++;
    }

    //* we create a frequency map of a1;
    //* then iteratge over a2
    for (int &val : a2)
    {
        if (freq.count(val))
        {
            cout << val << " ";
            freq.erase(val);
        }
    }
}

void gc2(vector<int> &a1, vector<int> &a2)
{
    unordered_map<int, int> freq;
    for (int &val : a1)
    {
        freq[val]++;
    }

    for (int &val : a2)
    {
        if (freq[val] > 0)
        {
            cout << val;
            freq[val]--;
        }
    }
}

int main()
{
    vector<int> a1 = {5, 5, 9, 8, 5, 5, 8, 0, 3};
    vector<int> a2 = {9, 7, 1, 0, 3, 6, 5, 9, 1, 1, 8, 0, 2, 4, 2, 9, 1, 5};
    gc2(a1, a2);
    return 0;
}