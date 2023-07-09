#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class customComparator
{
public:
    bool operator()(const ListNode *n1, const ListNode *n2)
    {
        return n1->val > n2->val;
    }
    //* mind you this is a min heap, but it takes the greater<int> comparator
};

class Solution
{
public:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    void addToList(ListNode *&node)
    {
        if (head == nullptr and tail == nullptr)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
            tail->next = nullptr;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        //* min heap;
        priority_queue<ListNode *, vector<ListNode *>, customComparator> min_heap;
        for (ListNode *&head : lists)
        {
            min_heap.push(head);
        }

        //* first element of each list is pushed
        while (min_heap.size() > 0)
        {
            ListNode *node = min_heap.top();

            min_heap.pop();

            if (node->next != nullptr)
            {
                min_heap.push(node->next);
            }

            //* i have top add nodes in the end of the loop, kyunki link toot raha hai mere addToList function mein
            addToList(node);
        }

        return this->head;
    }
};

int main()
{

    return 0;
}