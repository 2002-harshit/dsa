#include <bits/stdc++.h>
using namespace std;

void print_abbrevations(string &str, string currAns, int count, int pos)
{
    if (pos == str.size())
    {
        cout << currAns + ((count > 0) ? to_string(count) : "") << endl;
        return;
    }

    print_abbrevations(str, currAns + "", count + 1, pos + 1);
    //* jab koi character nahi atta toh count badhta hai, jo ki upar hua
    print_abbrevations(str, currAns + ((count > 0) ? to_string(count) : "") + str[pos], 0, pos + 1);
    //* jab koi character phir aana chahta hai, woh apne se pehle count check karta hai, ki achha tum sab nahi aaye toh lo tumhara count jod deta hoon, but ab mere se count 0 ho jayega
}

int main()
{
    string str = "pep";
    print_abbrevations(str, "", 0, 0);
    return 0;
}