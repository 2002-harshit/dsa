#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void makeCombos(vector<int> &arr, int index, int target, int currSum, vector<int> &currCombo, vector<vector<int>> &allCombos)
    {
        if (currSum > target or index == arr.size())
        {
            return;
        }

        if (currSum == target)
        {
            allCombos.push_back(currCombo);
            return;
        }
        //* khud ko calls, dekho chutiye jaise subset mein take not take hota tha, yeh bh wohi hai, jo khud ko calls hai jab woh backtrack hoke finally first level pe aayengi, toh line 23 wali call chalegi which is not take, so this kinda multiple take(jismein one take included hai), aur no take
        currCombo.push_back(arr[index]);
        makeCombos(arr, index, target, currSum + arr[index], currCombo, allCombos);
        currCombo.pop_back();

        makeCombos(arr, index + 1, target, currSum, currCombo, allCombos);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> currCombo;
        vector<vector<int>> allCombos;
        makeCombos(candidates, 0, target, 0, currCombo, allCombos);
        return allCombos;
    }
};

int main()
{
    return 0;
}