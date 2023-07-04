#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int left = 0;
        int right = 1;
        int max_profit = INT_MIN;

        while (right < prices.size())
        {
            if (prices[right] < prices[left])
            {
                left = right;
                right++;
            }
            else
            {
                max_profit = max(max_profit, prices[right] - prices[left]);
                right++;
            }
        }

        return max_profit;
    }
};

int main()
{

    Solution s;
    vector<int> vec = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(vec);
    return 0;
}