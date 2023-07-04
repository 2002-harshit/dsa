#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int,int> um;

        for(int num:nums)
        {
            um[num]++;
            if(um[num]==2)
            {
                return true;
            }
        }


        return false;

        
        
    }
};

int main()
{
    Solution s;

    vector<int> nums={1,2,3,4};
    cout<<s.containsDuplicate(nums);
}