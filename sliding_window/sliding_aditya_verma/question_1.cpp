#include <bits/stdc++.h>
using namespace std;

int max_sum_subarray_k(vector<int> vec, int k)
{
    int i = 0;
    int j = 0;
    int max_sum = 0;
    int sum = 0;

    while (j < vec.size())
    {
        sum += vec[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            max_sum = max(max_sum, sum);
            sum -= vec[i];
            i++;
            j++;
        }
    }

    return max_sum;
}

int main()
{
    cout << max_sum_subarray_k({2, 3, 1, 0, 1, 1, 10}, 3);
    return 0;
}