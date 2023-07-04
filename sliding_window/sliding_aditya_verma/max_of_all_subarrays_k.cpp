#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarr_k(vector<int> &arr, int k)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    // int max_val = INT_MIN;
    queue<int> maxes;

    while (j < arr.size())
    {
        //* do some calculations here
        // max_val = max(max_val, arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            //* now from the calculation done above, compute an answer
            ans.push_back(max_val);

            if (max_val == arr[i])
            {
                max_val = max()
            }

            i++;
            j++;
        }
    }
}

int main()
{
    return 0;
}