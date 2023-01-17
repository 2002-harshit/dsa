#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaBrute(vector<int>& height) {

        int maxArea=0;
        int area=0;
        
        for(int i=0;i<height.size();i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
                area=(j-i)*min(height[i],height[j]);
                
                maxArea=max(area,maxArea);

            }
        }

        return maxArea;

        //! O(n^2)

    }

    int maxAreaBest(vector<int>& height) {

        int left=0;
        int right=height.size()-1;

        int maxarea=0;
        int area=0;

        while(left<right)
        {
            area=(right-left)*min(height[left],height[right]);

            maxarea=max(area,maxarea);

            if(height[left] < height[right]) left++;
            else right--;
        }

        return maxarea;

    }

    //! mast O(n) solution





};

int main()
{
    vector<int> height={1,1};
    cout<<Solution().maxAreaBrute(height);
}