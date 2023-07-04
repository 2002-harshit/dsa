#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> get_subarrays(vector<int> &vec, int num)
{
    int left = 0;
    int right = 0;
    int curr_sum = vec[0];

    vector<pair<int, int>> ans;

    //* this is the fkin brute force approach
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     for (int j = i; j < vec.size(); j++)
    //     {
    //         curr_sum = (i == j) ? vec[i] : curr_sum + vec[j];
    //         if (curr_sum == num)
    //         {
    //             ans.push_back({i, j});
    //         }
    //     }
    // }

    //* sliding window approach

    return ans;
}

int main()
{
    vector<int> vec = {1, 7, 4, 3, 1, 2, 1, 5, 1};
    int num = 7;
    for (pair<int, int> &p : get_subarrays(vec, num))
    {

        cout << p.first << " " << p.second << endl;
    }
    return 0;
}