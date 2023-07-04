#include<bits/stdc++.h>
using namespace std;

pair<int,int> min_max(vector<int> &arr,int l,int r)
{

    pair<int,int> currentans;
    int minIndex;
    int maxIndex;

    if(l==r-1)
    {
        if(arr[l]<=arr[r]) currentans=make_pair(l,r);
        else if(arr[l]>arr[r]) currentans=make_pair(r,l);
        return currentans;
    }

    if(l==r)
    {
        currentans=make_pair(l,r);
        return currentans;
    }


    pair<int,int> leftans=min_max(arr,l,(l+r)/2);
    pair<int,int> rightans=min_max(arr,((l+r)/2)+1,r);

    if(arr[leftans.first]<=arr[rightans.first]) minIndex=leftans.first; else minIndex=rightans.first;

    if(arr[leftans.second]>=arr[rightans.second]) maxIndex=leftans.second; else maxIndex=rightans.second;

    currentans=make_pair(minIndex,maxIndex);
    return currentans;

}
//TODO return the indices of mina nd max element

int main()
{
    vector<int> nums={5,4,3,2,1};
    pair<int,int> ans=min_max(nums,0,nums.size()-1);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}