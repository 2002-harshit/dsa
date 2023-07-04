#include <bits/stdc++.h>
using namespace std;

// todo find the maximum sum subarray of the required size, this was statically sized window

pair<int, int> max_sum_subarray_fixed(vector<int> &vec, int &size)
{
    int left = 0;
    int right = left + size - 1;
    int curr_sum = accumulate(vec.begin(), vec.begin() + size, 0);
    int max = curr_sum;
    pair<int, int> ans = make_pair(left, right);

    while (right != vec.size() - 1)
    {
        left++;
        right++;
        curr_sum = curr_sum - vec[left - 1] + vec[right];
        if (curr_sum > max)
        {
            max = curr_sum;
            ans = {left, right};
        }
    }

    return ans;
}

int main()
{
    vector<int> vec = {-1, 2, 3, 1, -3, 2};
    int size = 5;
    pair<int, int> ans = max_sum_subarray_fixed(vec, size);
    cout << ans.first << " " << ans.second;

    return 0;
}