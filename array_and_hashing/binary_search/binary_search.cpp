#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l=0;
        int r=nums.size()-1;
        int mid;

        while(l<=r)
        {
            mid=(l+r)/2;
            
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(target>nums[mid])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }

        }

        return -1;
        
    }
};


int main()
{
    vector<int> nums={-1,0,3,5,9,12};
    cout<<Solution().search(nums,9);
    return 0;
}