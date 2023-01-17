#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindromeTwoPtr(string s) {
        
        if(s.size()==0)return true;

        s.erase(remove_if(s.begin(),s.end(),[](char c){ if(!isalnum(c))return true;   return false;  }),s.end());
        transform(s.begin(),s.end(),s.begin(),::tolower);
        //the abive line calls the tolower() from global scope;

        int i=0;
        int j=s.size()-1;

        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {

             return false;
            }

        }
        return true;
    }
};

int main()
{

    string str="Abcba";
    cout<<Solution().isPalindromeTwoPtr(str);
    // cout<<isalnum(' ');
    return 0;
}