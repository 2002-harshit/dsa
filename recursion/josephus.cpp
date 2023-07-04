#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    // todo some base case
    if (n == 1)
    {
        return 0;
    }

    int neecheWaleLevelSeAnswer = josephus(n - 1, k);
    int apneLevelKaAnswer = (k + neecheWaleLevelSeAnswer) % n; //* this is the transformation to convert neechewalelevelseanswer to apnelevelkaanser
    //* expectation: josephus(5,3)
    //* faith: josephus(4,3) ka answer pata hai, but usse humare mein map karlo
    return apneLevelKaAnswer;
}

int main()
{
    cout << "The person who will be saved is" << josephus(5, 3);
}