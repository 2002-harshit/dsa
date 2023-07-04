#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSumBrute(vector<int> &nums)
    {

        vector<vector<int>> ans;
        set<vector<int>> us;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        sort(temp.begin(), temp.end());
                        us.insert(temp);

                        temp.clear();
                    }
                }
            }
        }

        for (auto &vec : us)
        {
            ans.push_back(vec);
        }

        // for(auto it:mp)
        // {
        //     ans.push_back(it.first);
        // }
        //! thi sis brute force n^3*log(m) for insertion in set if m is unique triplets
        return ans;
    }

    vector<vector<int>> threeSumBetter(vector<int> &nums)
    {

        //* using hash map

        unordered_map<int, int> fm;
        set<vector<int>> helper;
        vector<vector<int>> ans;

        for (int &val : nums)
        {
            fm[val]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            fm[nums[i]]--; // this indicates that this element is taken for consideration beacause they cannot be taken again
            for (int j = i + 1; j < nums.size(); j++)
            {
                fm[nums[j]]--; // again element chosen for consideration

                if (fm[-(nums[i] + nums[j])] >= 1)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(-nums[i] - nums[j]);
                    sort(temp.begin(), temp.end());
                    helper.insert(temp);
                    temp.clear();
                }

                fm[nums[j]]++;
            }
            fm[nums[i]]++;
        }

        for (vector<int> vec : helper)
        {
            ans.push_back(vec);
        }

        return ans;
        //! tc O(n^2 * log(m)) // m unique triplets
    }

    vector<vector<int>> threeSumBest(vector<int> &nums)
    {

        //* using the two pointer approach

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int left = -1;
        int right = -1;

        for (int i = 0; i < nums.size(); i++)
        {

            if (i == 0 or (i > 0 and nums[i] != nums[i - 1]))
            {

                left = i + 1;
                right = nums.size() - 1;

                while (left < right)
                {
                    if ((nums[left] + nums[right]) == -nums[i])
                    {
                        vector<int> temp;

                        temp.push_back(nums[i]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);

                        ans.push_back(temp);

                        while(left<right and nums[left]==nums[left+1])  left++;
                        while(left<right and nums[right-1]==nums[right])  right--;

                        left++;
                        right--;
                    }
                    else if ((nums[left] + nums[right]) > -nums[i])
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }

        return ans;

        //! O(n*n)
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    for (auto outer : s.threeSumBest(nums))
    {
        for (int &val : outer)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}