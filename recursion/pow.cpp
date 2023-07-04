#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 1)
        {
            return x;
        }
        if (n == -1)
        {
            return 1 / x;
        }

        if (n == 0)
        {
            return 1;
        }

        double fromLeft = myPow(x, n / 2);
        double fromRight = (n > 0) ? myPow(x, n - (n / 2)) : myPow(x, -(abs(n) - abs(n / 2)));
        return fromLeft * fromRight;
    }
};

int main()
{
    cout << (new Solution())->myPow(2, -3);
    return 0;
}