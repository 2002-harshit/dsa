#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // vector<vector<int>> getSubsets(vector<int> &nums, int i)
    // {
    //     if (i == nums.size())
    //     {
    //         return {{}};
    //     }
    //     vector<vector<int>> subs = getSubsets(nums, i + 1);
    //     int n = subs.size();
    //     for (int j = 0; j < n; j++)
    //     {
    //         vector<int> temp = subs[j];
    //         temp.insert(temp.begin(), nums[i]);
    //         subs.push_back(temp);
    //     }

    //     return subs;
    // }
    // vector<vector<int>> subsets(vector<int> &nums)
    // {
    //     return getSubsets(nums, 0);
    // }
    vector<vector<int>> subsetsBasic(vector<int> &nums)
    {
        vector<vector<int>> output;
        output.push_back({});

        for (int &num : nums)
        {
            vector<vector<int>> newSubsets;
        }
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    for (auto &vec : (new Solution())->subsets(nums))
    {
        for (auto &val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}