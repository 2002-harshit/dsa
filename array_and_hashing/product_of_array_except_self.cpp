#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelfBrute(vector<int>& nums) {
        //!O(n^2)
        return vector<int>();
    }
    vector<int> productExceptSelfPrefixProduct(vector<int>& nums)
    {
        vector<int> answer(nums.size());
        vector<int> leftProd;
        vector<int> rightProd(nums.size());

        int prod=1;
        for(int i=0;i<nums.size();i++)
        {
            prod*=nums[i];
            leftProd.push_back(prod);
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {   
            prod*=nums[i];
            rightProd[i]=prod;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                answer[i]=rightProd[1];
            }
            else if(i==nums.size()-1)
            {
                answer[i]=leftProd[nums.size()-2];
            }
            else
            {

                 answer[i]=leftProd[i-1]*rightProd[i+1];
            }
        }


        return answer;

        //! time complexity O(n)
        //! space complexity 0(n)
    }

    vector<int> productExceptSelfBest(vector<int>& nums)
    {
        //we can skip the left prosuct and the right product array also, lets see how
        vector<int> answer(nums.size());
        
        //first we will store the left prod in answer
        int product=1;
        for(int i=0;i<nums.size();i++)
        {
            product=product*nums[i];
            answer[i]=product;
        }

        //now answer contains the left consecutive product
        //now we will traverse the original arrayh from right to left

        answer[nums.size()-1]=answer[nums.size()-2];
        //setting the last answer
        product=nums[nums.size()-1];


        for(int i=nums.size()-2;i>=1;i--)
        {
            answer[i]=answer[i-1]*product;
            product=product*nums[i];
        }

        answer[0]=product;

        return answer;



    }
    
};

int main()
{
    Solution s; 
    vector<int> nums={1,2,3,4};

    for(int val:s.productExceptSelfBest(nums))
    {
        cout<<val<<" ";
    }    

    return 0;
}