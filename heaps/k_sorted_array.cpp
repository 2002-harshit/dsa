#include <bits/stdc++.h>
using namespace std;

vector<int> nearlySorted(int arr[], int n, int k)
{
    //* min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        if (pq.size() != k + 1)
        {
            pq.push(arr[i]);
        }
        else
        {
            arr[pos] = pq.top();
            pq.pop();
            pos++;
            pq.push(arr[i]);
        }
    }
}

int main()
{

    return;
}