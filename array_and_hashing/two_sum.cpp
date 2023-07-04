#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSumbrute(vector<int>& nums, int target) {

        vector<int> ans(2);
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans[0]=i;
                    ans[1]=j;
                    return ans;
                }
            }
        }
    }

    vector<int> twoSumSort(vector<int> &nums,int target)
    {
        vector<int> ans;
        vector<int> original=nums;
        sort(nums.begin(),nums.end());

        int left=0;
        int right=nums.size()-1;

        while(nums[left]+nums[right]!=target)
        {
            if(nums[left]+nums[right]>target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        int leftFound=0;
        int rightrFound=0;

        for(int i=0;i<original.size();i++)
        {
            if( !leftFound and original[i]==nums[left])
            {
                leftFound=1;
                ans.push_back(i);
                continue;
            }

            if(!rightrFound and original[i]==nums[right])
            {
                rightrFound=1;
                ans.push_back(i);
                continue;
            }
        }

        return ans;
        
    }

    vector<int> twoSumHash(vector<int> &nums,int target)
    {
        unordered_map<int,int> um;
        vector<int> ans;

        for(int i=0;i<nums.size();i++)
        {
            if(um.count(target-nums[i]))
            {
                ans.push_back(i);
                ans.push_back(um[target-nums[i]]);
            }
            else
            {
                um.insert(make_pair(nums[i],i));
                //um[nums[i]]=i equivalent to abive line
            }
        }

        return ans;

    }
};

int main()
{

    vector<int> vec={3,2,4};
    int target=6;
    Solution s1;
    for(int val:s1.twoSumSort(vec,target))
    {
        cout<<val<<" ";
    }

    return 0;
}