#include<bits/stdc++.h>
using namespace std;

int pivotRotSort(vector<int> &arr)
{
    int left=0;
    int right=arr.size()-1;

    

    while(left<=right)//till the time my serach space is not exhausted or over
    {
        //* all distinct elements

        int mid=left+(right-left)/2;

        if(mid+1<arr.size() and arr[mid+1]<arr[mid])//in case of 1 size array
        {
            return mid+1;
            //!thats the pivot
        }
        else
        {
            //* now i can be in one any of the acsending parts where arr[mid]<arr[mid+1]

            if(arr[mid]>arr[right]) //! even i could have written a condition on left and mid, i just want to know i am on which chadhai right now 1 or 2
            {
                //* then i am in first ascendance
                //* pivot lies ahead so move forward;
                //* also mid is not the pivot because acc to waht i have defined
                //* even if mid points to the larest element, i still have to jump beyond it
                left=mid+1;
            }
            else if(arr[mid]<arr[right])
            {
                //* i am in second ascendance
                //* pivot lies behind
                right=mid;
                //* here mid can still be the pivot if mid is on the pivot itself
            }
            else
            {
                right=mid-1;//! what is this for
                /*
                * this is when arr[mid]==arr[right] which says all the three pointers are at same location
                * if u dry run this case only happens when you have a non rotated array
                * so to break off the loop when all three point at the same first element arr[0], this condition is used
                
                */
            }

            //! ALWAYS REMEMBER SEARCHING HAPPENS FROM LEFT TO RIGTH BOTH INCLUSIVE

        }



    }
        return 0;//! you will reach here in case of non rotated array ascending
}

int main()
{
    vector<int> nums={1,2,3,4,5,6};//roatated sorted array
    //* let the pivot be 1
    //* since it is sorted, binary search should ring your bell;
    cout<<pivotRotSort(nums);

    return 0;
}