//* the optimal solution is using hashmap, remember its not a subarray, its a sequence means elements need not be contigous
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, bool> isSeqStarter;
    for (int &val : nums)
    {
        isSeqStarter[val] = true;
    }

    for (int &val : nums)
    {
        if (isSeqStarter.count(val - 1))
        {
            isSeqStarter[val] = false;
        }
    }

    int maxLen = INT_MIN;

    for (int &val : nums)
    {
        if (isSeqStarter[val])
        {
            int currLen = 1;
            int temp = val;

            while (isSeqStarter.count(temp + 1))
            {
                currLen++;
                temp += 1;
            }

            maxLen = max(maxLen, currLen);
        }
    }

    return maxLen;
}

int main()
{
    return 0;
}