#include <bits/stdc++.h>
using namespace std;

void print_subs(string ques, string ans)
{
    //* now we wont store any of the subsequences but will print them once they are made
    if (ques.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = ques[0];
    string restOfQues = ques.substr(1);

    print_subs(restOfQues, ans + "");
    print_subs(restOfQues, ans + ch);
}

int main()
{
    print_subs("abc", "");
    return 0;
}