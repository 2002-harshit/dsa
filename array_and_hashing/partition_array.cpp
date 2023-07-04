#include <bits/stdc++.h>
using namespace std;

void partition(vector<int> &vec, int pivot)
{
    int j = 0;
    int i = 0;

    //* these 2 pointers divide the arrayh into three regions
    //* 0 to j-1 - <=pivot,
    //* j to i-1 - >pivot
    //* i to end - unknowns

    while (i < vec.size())
    {
        if (vec[i] > pivot)
        {
            i++;
            //* toh j se i-1 wala area will increase, aur  unknown area decrease
        }
        else
        {
            swap(vec[i], vec[j]);
            //* main swap isliye karta hoon kyunki mujhe badhe walon ke afrfe ake left mein choti values daalni hai
            i++; //* unknown kam ho gaye
            j++; //* 0 se j-1 badh gaya(chota element aa gaya)
        }
    }
}

void separate_even_odd(vector<int> &arr)
{
    int j = 0;
    int i = 0;

    while (i < arr.size())
    {
        if (arr[i] % 2 != 0)
        {
            i++;
        }
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
}

int main()
{
    return 0;
}