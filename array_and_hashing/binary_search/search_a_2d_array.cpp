#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int startrow=matrix.size()-1;
        int startcol=0;

        while(true)
        {
            if(matrix[startrow][startcol]==target)
            {
                return true;
            }
            else if(matrix[startrow][startcol]<target)
            {
                startcol++;
            }
            else
            {
                startrow--;
            }

            if(startcol>=matrix[0].size() or startcol<0)
            {
                break;
            }
            else if(startrow<0 or startrow>=matrix.size())
            {
                break;
            }
        }





        return false;//if not found return false
        
    }
};

int main()
{
    vector<vector<int>> nums={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<Solution().searchMatrix(nums,0);
    return 0;
}