#include <bits/stdc++.h>
using namespace std;

//* pq.size() works in o(1)

class MedianFinder
{
public:
    //* we will maintain 2 priorty queues, left one(max heap) will be the list for smaller half and the right one(min heap) will be for the larger half data
    priority_queue<int> *left = nullptr;
    priority_queue<int, vector<int>, greater<int>> *right = nullptr;

    MedianFinder()
    {
        left = new priority_queue<int>();
        right = new priority_queue<int, vector<int>, greater<int>>();
    }

    void addNum(int num)
    {
        if (right->size() > 0 and num > right->top())
        {
            //* fkin beautiful condition bc!!!, ki agar right mein bande hain,basically kya mei right mein aa sakta hoon
            right->push(num);
        }
        else
        {
            left->push(num);
        }

        //* agar kabhi bhi size difference 2 ya 2 se zyada ho jaye, toh ek ka uthaake doosre mein
        // cout << left->size() << endl;
        // cout << right->size() << endl;
        // cout << left->size() - right->size() << endl;
        // cout << right->size() - left->size() << endl;
        // cout << ((left->size() - right->size()) > 1) << endl;
        // cout << ((right->size() - left->size()) > 1) << endl;//* this operation might be wrong see why, when left.size=1 and right.size=0, size are of type size_t which are unsigned, now the whole calculation happens in unsigned, but -1 cannot be represented in unsigned, so it underflows to max value, hence tum chudh jaate ho!!!

        if ((left->size() - right->size()) == 2)
        {
            int val = left->top();
            left->pop();
            right->push(val);
        }
        else if ((right->size() - left->size()) == 2)
        {
            int val = right->top();
            right->pop();
            left->push(val);
        }
    }

    double findMedian()
    {
        //* pretty easy now

        if (left->size() > right->size())
        {
            return left->top();
        }
        else if (left->size() < right->size())
        {
            return right->top();
        }
        else if ((left->size() >= 1 || right->size() >= 1) && left->size() == right->size())
        {
            return (left->top() + right->top()) / 2.0;
        }
    }
};

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(10);
    // obj->addNum(20);
    // cout << obj->findMedian();
}