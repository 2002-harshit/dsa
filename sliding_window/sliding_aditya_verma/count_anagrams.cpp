#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(string pat, string txt)
    {

        int count = 0;
        unordered_map<char, int> pattern_map;
        for (char &ch : pat)
        {
            pattern_map[ch]++;
        }
        unordered_map<char, int> txt_map;

        int i = 0;
        int j = 0;  
        while (j < txt.length())
        {
            //* some calculation for window expansion on your right
            txt_map[txt[j]]++;

            if (j - i + 1 < pat.length())
            {
                j++;
            }
            else if (j - i + 1 == pat.length())
            {
                //* now use the calculation done above
                if (txt_map == pattern_map)
                {
                    count++;
                }

                //*
                txt_map[txt[i]]--;
                if (txt_map[txt[i]] == 0)
                    txt_map.erase(txt[i]);

                i++;
                j++;
            }
        }

        return count;
    }
};

int main()
{
    cout << (new Solution())->search("forxxorfxdofr", "for");
    return 0;
}