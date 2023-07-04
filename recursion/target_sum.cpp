//* this seems a classic backtracing problem
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void getTargetSumWays(vector<int> &nums, int index, int currSum, int target, int &ans)
    {
        //* classic levels and options
        //* + ki call
        if (index == nums.size())
        {
            if (currSum == target)
                ans++;

            return;
        }

        getTargetSumWays(nums, index + 1, currSum + nums[index], target, ans);

        getTargetSumWays(nums, index + 1, currSum - nums[index], target, ans);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int ans = 0;
        getTargetSumWays(nums, 0, 0, target, ans);
        return ans;
    }
};

int main()
{
    return 0;
}