#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int minK=1;
        int maxK=*(max_element(piles.begin(),piles.end()));
        
        int left=minK;
        int right=maxK;

        int ans;

        //* 1..30

        while(left<=right)
        {
            int k=left+(right-left)/2;
            int currTime=0;

            for(double val:piles)
            {
                currTime+=ceil(val/k);
            }      

            if(currTime>h)
            {
                //!k is less koko is slow
                left=k+1;
            } 
            else
            {
                //!if currentTime is <=h
                //* its a potential answer
                //* but search for lesser k also
                ans=k;
                right=k-1;
            } 
        }

        return ans;
        
    }
};

int main()
{
    vector<int> nums={3,6,7,11};
    cout<<Solution().minEatingSpeed(nums,8);
}