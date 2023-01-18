#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        
        int left=0;
        int right=x;
        int ans;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(mid*mid==x)
            {
                return mid;
            }
            else if(mid*mid>x)
            {
                right=mid-1;
                //* here note that mid cannot be the answer, there is no potential, therefore we exclude it from our next search space
            }
            else
            {
                //* here mid*mid<x
                //* since we have to return floor value this can be the potential answer
                ans=mid;
                left=mid+1;
            }
        }

        return ans;
    }
};

double morePrecision(int number,int integerPart,int precision)
{
    double ans=integerPart;
    double factor=1;

    for(int i=0;i<precision;i++)
    {
        factor=factor/10;

        for(double j=ans;j*j<number;j+=factor)
        {
            ans=j;
        }

    }

    return ans;
}




int main()
{
    int integerPart=Solution().mySqrt(37);
    // cout<<integerPart;
    cout<<morePrecision(37,integerPart,4);
    return 0;
}