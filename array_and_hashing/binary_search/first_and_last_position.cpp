#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first=-1;
        int last=-1;

        int left=0;
        int right=nums.size()-1;

        vector<int> ans;


        //* first oocurence
        while(left<=right)
        {
            int mid=(left+right)/2;

            if(target==nums[mid])
            {
                first=mid;
                //* i found gthe element here
                //* let me check in  the left part also because i am searching for first occurence
                right=mid-1;
            }
            else if(target>nums[mid])
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

        //* last occurence

        left=0;
        right=nums.size()-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(target==nums[mid])
            {
                //* i found an oocurence;
                last=mid;
                //* let me check in the right half also;
                left=mid+1;
            }
            else if(target>nums[mid])
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};

int main()
{
    vector<int> nums={5,7,7,8,10,10,10};

    vector<int> ans=Solution().searchRange(nums,11);
    
    for(int &val:ans)
    {
        cout<<val<<" ";
    }
}