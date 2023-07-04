// todo , lets fucking do the kadanes algo!!!

#include <bits/stdc++.h>
using namespace std;

//* brute force O(n^3),
//* better approach O(n^2)
//* optimal approach using kadanes O(n)\

pair<int, int> kadanes(vector<int> &vec)
{
    int csum = vec[0];
    int osum = vec[0];

    pair<int, int> ans;
    pair<int, int> temp = {0, 0};

    for (int i = 1; i < vec.size(); i++)
    {
        if (csum >= 0)
        {
            csum += vec[i]; //* peeche se train mein jud jaayo
            temp.second = i;
        }
        else
        {
            //* agar peeche se negative aa raha hai, toh main chahe(vec[i]) + houn ya neg, csum ghatega hi, toh i will start my wn chain
            csum = vec[i];
            temp = {i, i};
        }

        if (csum > osum)
        {
            osum = csum;
            ans = temp;
        }
    }

    return ans;
}

int main()
{

    // vector<int> vec = {4, 3, -2, 6, -14, 7, -1, 4, 5, 7, -10, 2, 9, -10, -5, -9, 6, 1};
    vector<int> vec = {-4, -3, -2, -1};
    pair<int, int> ans = kadanes(vec);
    cout << ans.first << " " << ans.second;

    return 0;
}