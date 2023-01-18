#include<bits/stdc++.h>
using namespace std;

pair<int,int> ceil_and_floor_binary(vector<int> &nums,int target)
{
    int left=0;
    int right=nums.size()-1;

    int ceil=-1;
    int floor =-1;

    pair<int,int> ans=make_pair(floor,ceil);

    while(left<=right)
    {
        int mid=(left+right)/2;

        if(nums[mid]==target)
        {
            ceil=floor=mid;
            break;
        }
        else if(target>nums[mid])
        {
            floor=mid;
            left=mid+1;
        }
        else
        {
            ceil=mid;
            right=mid-1;
        }
    }

    ans.first=floor;
    ans.second=ceil;

    return ans;

    


}

int main()
{
    vector<int> nums={2,3,5,9,14,16,18};
    pair<int,int> ans=ceil_and_floor_binary(nums,120);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}