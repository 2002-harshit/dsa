#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int i=0;
        int j=numbers.size()-1;

        int leftInd=-1;
        int rightInd=-1;

        while(i<j)
        {
            if(numbers[i]+numbers[j]==target)
            {
                leftInd=i;
                rightInd=j;
                break;
            }
            else if(numbers[i]+numbers[j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        vector<int> ans;
        ans.push_back(leftInd+1);
        ans.push_back(rightInd+1);

        return ans;

        
    }
};


int main()
{
    return 0;
}