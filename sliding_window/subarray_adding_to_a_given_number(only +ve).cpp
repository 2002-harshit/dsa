#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> get_subarrays(vector<int> &vec, int num)
{
    int left = 0;
    int right = 0;
    int curr_sum = vec[left];

    vector<pair<int, int>> ans;

    while (right != vec.size())
    {
        if (curr_sum == num)
        {
            ans.push_back({left, right});
            right++;
            curr_sum = curr_sum + vec[right];
        }
        else if (curr_sum < num)
        {
            right++;
            curr_sum = curr_sum + vec[right];
        }
        else
        {
            left++;
            curr_sum = curr_sum - vec[left - 1];
        }
    }

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