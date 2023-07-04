#include <bits/stdc++.h>
using namespace std;

int main()
{
    //* by default a max heap
    priority_queue<int> pq1;

    pq1.push(2);
    pq1.push(3);
    pq1.push(4);
    pq1.push(100);
    cout << pq1.top();

    priority_queue<int, vector<int>, greater<int>> pq2; //* this is min heap

    pq2.push(100);
    pq2.push(3);
    pq2.push(2);
    pq2.push(4);

    cout << pq2.top();

    return 0;
}