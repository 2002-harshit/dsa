#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void drawSubsetTreeDup(vector<int> &nums, int index, vector<int> &currSub, vector<vector<int>> &res)
    {

        if (index == nums.size())
        {
            res.push_back(currSub);
            return;
        }

        //* all subsets that include nums[index]
        currSub.push_back(nums[index]);
        drawSubsetTreeDup(nums, index + 1, currSub, res);
        currSub.pop_back();

        //* now we skip all the copies of nums[i] becauese we already made a call where we included nums[i], now we dont want any nums[i] , so skip all of them.
        int val = nums[index];
        index += 1;
        while (index < nums.size() and nums[index] == val)
        {
            index++;
        }

        //* all subsets that do not include nums[index]
        drawSubsetTreeDup(nums, index, currSub, res);
    }

    vector<vector<int>>
    subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end(), less_equal<int>());
        drawSubsetTreeDup(nums, 0, temp, res);
        return res;
    }
};

int main()
{
    vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (auto &vec : (new Solution())->subsetsWithDup(arr))
    {
        for (int val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}