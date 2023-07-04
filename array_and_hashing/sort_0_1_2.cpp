#include <bits/stdc++.h>
using namespace std;

//* this does not maintain relative order

void sort_0_1_2(vector<int> &arr)
{
    int j = 0;
    int i = 0;
    int k = arr.size() - 1;

    //* now we have 3 pointers so 4 regions
    //*ji                   k
    //* i to k - unknown // same as 01 sort
    //* 0 to j-1 - zeros ka ilaaka // same as 01 sort
    //* j to i-1 - ones ka ilaaka // same as 01 sort
    //* k+1 to end - twos ka ilaaka

    while (i <= k)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[i] == 1)
        {
            i++;
        }
        else
        {
            swap(arr[i], arr[k]);
            k--;
        }
    }
}

int main()
{
    return 0;
}