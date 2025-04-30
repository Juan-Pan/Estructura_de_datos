#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct node
{
    int key;
    node *next;
};

struct node *buildList(int n)
{
    node *head = nullptr, *tail = nullptr;
    for (int i = 2; i <= n; i++)
    {
        node *newNode = new node;
        newNode->key = i;
        newNode->next = nullptr;
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct node *next(struct node *it, struct node *head)
{
    if (it->next == nullptr)
        return head;
    return it->next;
}

void solver(int n)
{
    int m = 1;

    while (true)
    {
        m++;
        struct node *head = buildList(n);
        struct node *it1 = head;
        struct node *prev = nullptr;
        int cnt = n - 1; 

        while (cnt > 1)
        {
            for (int i = 1; i < m; i++)
            {
                prev = it1;
                it1 = next(it1, head);
            }

            // borrar it1
            if (it1 == head)
            {
                head = head->next;
                delete it1;
                it1 = head;
                prev = nullptr;
            }
            else
            {
                prev->next = it1->next;
                struct node *temp = it1;
                it1 = it1->next;
                delete temp;
                if (it1 == nullptr)
                    it1 = head;
            }

            cnt--;
        }

        if (head && head->key == 2)
        {
            cout << m << endl;
            delete head;
            break;
        }

        if (head)
            delete head;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    while (n)
    {
        solver(n);
        cin >> n;
    }

    return 0;
}
