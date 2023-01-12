/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram_using_arr(string s, string t) {

        int sarr[26]={0};
        int tarr[26]={0};


        if(s.size()!=t.size())
        {
            return false;
        }

        for(int i=0;i<s.size();i++)
        {
            sarr[s[i]-'a']++;
            tarr[t[i]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(sarr[i]!=tarr[i])
            {
                return false;
            }
        }

        return true;
        
    }

    bool isAnagram_using_hashmap(string s, string t) {

        unordered_map<char,int> sm;
        unordered_map<char,int> tm;


        if(s.size()!=t.size())
        {
            return false;
        }

        for(int i=0;i<s.size();i++)
        {
            sm[s[i]]++;
            tm[t[i]]++;
        }

        for(auto it=sm.begin();it!=sm.end();it++)
        {
            if(it->second!=tm[it->first])
            {
                return false;
            }
        }


        return true;
        
    }
};

int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    Solution sol;
    cout<<sol.isAnagram_using_arr(s,t)<<endl;
    cout<<sol.isAnagram_using_hashmap(s,t)<<endl;
    return 0;
}