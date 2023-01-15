/*
* Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

* You must write an algorithm that runs in O(n) time.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutiveBrute(vector<int>& nums) {

        if(nums.size()==0)
        {
            return 0;
        }
        
        sort(nums.begin(),nums.end());

        int ans,maxans;
        ans=maxans=1;


        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==1+nums[i-1])
            {
                ans++;
            }
            else if(nums[i]==nums[i-1])
            {
                continue;
            }
            else
            {
                //you answer gets consolidated here
                //so if there is a sequence like 1,2,3,4
                //the flow will never reach else, so return max(maxnas,ans) is required
                maxans=max(maxans,ans);
                ans=1;
            }
        }

        return max(maxans,ans);
        //! time complexity O(nlogn) for sorting
    }

    int longestConsecutiveOptimal(vector<int>& nums) {

        if(nums.size()==0)return 0;
        
        unordered_map<int,bool> whetherPresent;

        for(int &val:nums)
        {
            whetherPresent[val]=true;
        }
        //the above loop filled the hashmap

        for(int &val:nums)
        {
            if(whetherPresent.count(val-1))
            {
                whetherPresent[val]=false;
            }
        }
        //the above loop marked the elements that are sequence starters

        int maxl=0;
        int maxsp=0;

        for(int &val:nums)
        {
            if(whetherPresent[val])
            {
                int tl=1;//temporary length
                int tsp=val;//temporaray start point

                while(whetherPresent.count(tsp+tl))
                {
                    tl++;
                }

                if(tl>maxl)
                {
                    maxl=tl;
                    maxsp=tsp;
                }

                
            }
        }


        return maxl;

        // for(auto pair:whetherPresent)
        // {
        //     cout<<pair.first<<" "<<pair.second<<endl;
        // }

    
    
    }
};

int main()
{
    vector<int> nums={0,1,1,2};
    cout<<Solution().longestConsecutiveOptimal(nums);
    return 0;
}