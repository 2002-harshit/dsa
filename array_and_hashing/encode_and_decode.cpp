#include<bits/stdc++.h>
using namespace std;

//! the below code is wrong because i did not consider if the count of string greater than 9, then it would take up two chars
//! so there should be a delimiter between count and the string also
/*class Solution {
public:
    
    
    string encode(vector<string> &strs) {
        
        string ans;
        for(string &str:strs)
        {
            ans.push_back(str.size()+'0');
            ans=ans+str;
        }

        return ans;
    }

    vector<string> decode(string &str) {


        int i=0;
        vector<string> ans;
        while(i<str.size())
        {
            string temp=str.substr(i+1,str[i]-'0');
            // cout<<temp<<endl;
            ans.push_back(temp);
            i=i+(str[i]-'0')+1;            
        }

        return ans;
        
    }
};*/

class Solution {
public:
    
    //! let the delimiter be $
    string encode(vector<string> &strs) {
        
        string encoded;
        for(string &str:strs)
        {
            encoded=encoded+to_string(str.size());
            encoded.push_back('$');
            encoded+=str;
        }

        return encoded;
        
    }

    vector<string> decode(string &str) {
        
        vector<string> ans;
        string num;

        int i=0;
        while(i<str.size())
        {
            while(str[i]!='$')
            {
                num+=str[i];
                i++;
            }

            i++;//go beyond dollar
            ans.push_back(str.substr(i,stoi(num)));
            i=i+stoi(num);
            num.erase();
        }
        //! it is worthy noting that the above loop is O(n) and not n^2

        return ans;

        
    }
};

int main()
{
    Solution s;
    vector<string> strs={"harshitkhanna","23"};
    string encoded=s.encode(strs);

    // cout<<encoded;
    
    
    for(string &str:s.decode(encoded))
    {
        cout<<str<<endl;
    }
}