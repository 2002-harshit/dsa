#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    int n;

    while(t--)
    {
        cin>>n;
        int arr[n];
        unordered_map<int,int> um;
        int maxf=0;
        int maxans;

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            um[arr[i]]++;
            //the above line uses the concept that entries are created when [] is used, it is then incremented also
            maxf=max(maxf,um[arr[i]]);
        }


        //the following set of code is wrong becase we have tok fulfil condition that if elements have same freq, that the one whihc occurs first in the array is answer, but in um, no order is maintained

        /*
        pair<int,int> max=*(um.begin());

        for(auto p:um)
        {
            if(p.second>max.second)
            {
                max=p;
            }
        }

        cout<<max.first<<endl;*/

        for(int i=0;i<n;i++)
        {
            if(um[arr[i]]==maxf)
            {
                maxans=arr[i];
                break;
            }
        }

        cout<<maxans;





    }
    return 0;
}
