#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        //lets understand what is a frequency map first
        //it is nothing but a map fo charcater and its frequency

        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //in this problem we will use a hashmap<freqency map,vector of strings matching that frequency map>

        map<map<char,int>,vector<string>> bigmap;
        vector<vector<string>> ans;


        for(string &str:strs)
        {
            map<char,int> temp;
            for(char &c:str)
            {
                temp[c]++;
            }

            bigmap[temp].push_back(str);
        }


        for(auto &pair:bigmap)
        {
            ans.push_back(pair.second);
        }

        return ans;

        //! n=no.of strings K= chars in each string

        //!!!!!!!!   O(n*k) if it would have been an undorderd map, but cpp does not allow unorderd mpas as key  !!!!BEST APPROACH
        //!!!!!!!!   0(n*         k*          log(n))   log(n) for isnertion in map(which used BST)
        
    }

    vector<vector<string>> groupAnagramsOther(vector<string>& strs) {
        
        unordered_map<string,vector<string>> bigmap;

        //here i have used the key as string because for an anagram its sorted string is considered as unique
        vector<vector<string>> ans;

        for(string &str:strs)
        {
            string original=str;
            sort(str.begin(),str.end());

            bigmap[str].push_back(original);
        }

        for(auto &pair:bigmap)
        {
            ans.push_back(pair.second);
        }

        return ans;


        //! time complecity O(n    *    k*log(k)*           1)//


    
    
    }


};

int main()
{
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};

    Solution sol;
    
    
    for(vector<string> &outer:sol.groupAnagramsOther(strs))
    {
        for(string str:outer)
        {
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;
}