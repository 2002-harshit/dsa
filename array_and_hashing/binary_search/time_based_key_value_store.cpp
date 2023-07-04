#include<bits/stdc++.h>
using namespace std;

class TimeMap {
public:

    unordered_map<string,vector<pair<string,int>>> *ds;
    TimeMap() {

        ds= new unordered_map<string,vector<pair<string,int>>>();    
    }
    
    void set(string key, string value, int timestamp) {

        (*ds)[key].push_back({value,timestamp});
        //! O(1)
        
    }
    
    string get(string key, int timestamp) {

        int left=0;
        int right=(*ds)[key].size()-1;
        string potentialAns="";

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if((*ds)[key][mid].second==timestamp)
            {
                return (*ds)[key][mid].first;
            }
            else if((*ds)[key][mid].second > timestamp)
            {
                right=mid-1;
            }
            else
            {   
                potentialAns=(*ds)[key][mid].first;
                left=mid+1;
            }
        }

        return potentialAns;

        //! 0(logn)
        
    }
};

int main()
{
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout<<timeMap.get("foo", 1)<<endl;
    
    cout<<timeMap.get("foo", 3); 
    timeMap.set("foo", "bar2", 4);
    cout<<timeMap.get("foo", 4);
    cout<<timeMap.get("foo", 5);         
    
    return 0;
}