#include <bits/stdc++.h>
using namespace std;

int max_score(vector<string> &words, vector<int> &freq, vector<int> &score, int pos)
{
    if (pos == words.size())
    {
        return 0;
    }
    //* if i am not(main kaun hoon, main hoon jo pos pe hai) included
    int scoreNo = 0 + max_score(words, freq, score, pos + 1);

    //* if i am included, pehle check toh karlo ki frequency hai bhi
    int mereWordKaScore = 0;
    bool canNextCallbeMade = true;
    string word = words[pos];
    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        if (freq[ch - 'a'] == 0)
        {
            canNextCallbeMade = false;
        }

        freq[ch - 'a']--;
        mereWordKaScore += score[ch - 'a'];
    }

    int scoreYes = 0;

    if (canNextCallbeMade)
    {
        scoreYes = mereWordKaScore + max_score(words, freq, score, pos + 1);
    }

    //* the below is the backtracking step, when you leave a level or iamgine if the tree is inverted, you will fall to the below level, so you have to revert back your changes
    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        freq[ch - 'a']++;
    }

    return max(scoreNo, scoreYes);
}

int main()
{
    vector<string> words = {"dog", "cat", "dad", "good"};
    vector<int> freq = {1, 1, 1, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << max_score(words, freq, score, 0);
    return 0;
}