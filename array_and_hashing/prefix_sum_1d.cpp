#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;

    int prefix_sum[n+1];
    prefix_sum[0]=0;

    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;
        prefix_sum[i]=prefix_sum[i-1]+val;
    }

    //badically every index(i) stores, stores some of first i elememts;

    // for(int i=0;i<n+1;i++)
    // {
    //     cout<<prefix_sum[i]<<" ";
    // }

    int q;cin>>q;
    int l,r;

    while(q--)
    {
        cin>>l>>r;

        cout<<prefix_sum[r]-prefix_sum[l-1]<<endl;
    }
    return 0;
}