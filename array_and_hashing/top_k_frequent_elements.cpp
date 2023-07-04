#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        vector<int> ans;
        vector<vector<int>> arr(nums.size()+1);

        for(int &val:nums)
        {
            freq[val]++;
        }
        //frequency map is createdd, now the frequenies can be mapped to the index of the array

        for(auto &pair:freq)
        {
            arr[pair.second].push_back(pair.first);
        }

        // for(auto &outer:arr)
        // {
        //     for(int &val:outer)
        //     {
        //         cout<<val<<" ";
        //     }
        //     cout<<endl;
        // }


        //this is a reverse iterator
        for(auto rit=arr.rbegin();rit!=arr.rend();rit++)
        {
            for(int &val:*rit)
            {
                if(k)
                {
                    ans.push_back(val);
                    k--;
                }
            }
        }

        return ans;

        //! Lets see the time complexity:
        //! O(n)
        


    }
};


int main()
{
    Solution s;
    vector<int> nums={1};


    for(int &ans:s.topKFrequent(nums,1))
    {
        cout<<ans<<" ";
    }
    return 0;
}