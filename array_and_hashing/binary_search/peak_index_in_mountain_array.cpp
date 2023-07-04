#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int left=0;
        int right=arr.size()-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(arr[mid-1]<arr[mid] and arr[mid] > arr[mid+1])
            {
                return mid;
                //* voila its a peak
            }
            else if(arr[mid]<arr[mid+1])
            {
                //* then i am ascending the mountain
                left=mid+1;
                //! mid+1 can be a peak, therefore left=mid+1, because search in binary search in inclusive of left and right
            }
            else if(arr[mid]>arr[mid+1])
            {
                //* i am in the descending part
                right=mid;
                //! here mid can b ethe peak
            }
            //! two elements cannot be equal in the given chadhai or dhalan 
        }

        return 1;//useless because constraint was answer is always there
        //the control never reaches here


        
    }
};

int main()
{
    vector<int> nums={0,1,2,3,5,2,0};
    cout<<Solution().peakIndexInMountainArray(nums);
    return 0;
}