// #include <bits/stdc++.h>
// using namespace std;

// //* it can be used tok find the kth smallest aor the kth largest element

// //* this only works for distict elements, becuase you say if you want the 3 smallest element it will be on pos 2, but what about 1,2,2,3,4, 3rd smallest is on pos 3

// int do_partition(vector<int> &vec, int pivot, int l, int h)
// {
//     int j = l;
//     int i = l;

//     while (i <= h)
//     {
//         if (vec[i] > pivot)
//         {
//             i++;
//         }
//         else
//         {
//             swap(vec[i], vec[j]);
//             i++;
//             j++;
//         }
//     }

//     return j - 1; //* returns the pivot index
// }
// int kth_smallest(vector<int> &vec, int k, int l, int h)
// {
//     int pivot = vec[vec.size() - 1];
//     int pi = do_partition(vec, pivot, l, h);

//     if (k < pi)
//     {
//         return kth_smallest(vec, k, l, pi - 1);
//     }
//     else if (k > pi)
//     {
//         return kth_smallest(vec, k, pi + 1, h);
//     }
//     else
//     {
//         return vec[pi];
//     }
// }

// int main()
// {
//     vector<int> vec = {8, 3, 2, 5, 7, 6, 1, 4, 2};
//     int smallest = 3;
//     cout << kth_smallest(vec, smallest - 1, 0, vec.size() - 1);
//     return 0;
// }

//* lets solve the same problem but with with repeated elements also using quick select

#include <bits/stdc++.h>
using namespace std;

pair<int, int> do_partition(vector<int> &vec, int low, int high, int pivot)
{
    int i = low;
    int j = low;
    int k = high;

    while (i <= k)
    {
        if (vec[i] < pivot)
        {
            swap(vec[i], vec[j]);
            i++;
            j++;
        }
        else if (vec[i] == pivot)
        {
            i++;
        }
        else
        {
            swap(vec[i], vec[k]);
            k--;
        }
    }

    return {j, i - 1};
}

//* assuming k is 0 based

int findKthLargest(vector<int> &vec, int low, int high, int k)
{
    int pivot = vec[rand() % vec.size()];
    pair<int, int> range = do_partition(vec, low, high, pivot);
    int smallerEl = range.first - low;
    int equalEl = range.second - range.first + 1;
    int greaterEl = high - range.second;

    if (k < greaterEl)
    {
        return findKthLargest(vec, range.second + 1, high, k);
    }

    if (greaterEl + equalEl <= k)
    {
        return findKthLargest(vec, low, range.first - 1, k);
    }

    return pivot;
}

int main()
{
    vector<int> vec = {5, 8, 10, 4, 5, 5, 51, 2, 10, 8};
    do_partition(vec, 0, vec.size() - 1, 3);
    for (auto &val : vec)
        cout << val << " ";
}
