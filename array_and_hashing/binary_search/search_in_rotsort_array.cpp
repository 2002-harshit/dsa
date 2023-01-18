/*
* pretty basic algo
* 1. find the pivot
* 2. apply normal binary search in any of the two chadhaans
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int findPivot(vector<int> &nums)
    {
        int left=0;
        int right=nums.size()-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(mid<nums.size()-1 and nums[mid+1]<nums[mid])
            {
                //pivot is found
                return mid+1;
            }
            else
            {
                //now you are in one of the ascending branches

                if(nums[left]<nums[mid])
                {
                    //you are in first branch
                    left=mid+1;
                }
                else if(nums[left]>nums[mid])
                {
                    //you are in second branch
                    right=mid;
                }
                else
                {
                    left=mid+1;
                }
            }
        }

        return 0;//in case of monotonic array control reaches here
    }
    int binarySearch(vector<int> &nums,int l,int r,int target)
    {
        // int l=0;
        // int r=nums.size()-1;
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
    int search(vector<int>& nums, int target) {

        int pivotIndex=findPivot(nums);

        if(pivotIndex!=0 and nums[0]<=target and target<=nums[pivotIndex-1])
        {
            return binarySearch(nums,0,pivotIndex-1,target);
        }
        else
        {
            return binarySearch(nums,pivotIndex,nums.size()-1,target);
        }


         
        
    }
};

int main()
{
    vector<int> nums={1,3};
    cout<<Solution().search(nums,1);
    return 0;
}
