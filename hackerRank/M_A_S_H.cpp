#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct node
{
    int key;
    struct node *next;
};

struct node *buildList(int s)
{
    struct node *head = nullptr;
    struct node *tail = nullptr;

    for (int i = 1; i <= s; i++)
    {
        struct node *n = new struct node;
        n->key = i;
        n->next = nullptr;

        if (head == nullptr)
        {
            head = n;
            tail = n;
        }
        else
        {   
            tail->next = n;
            tail = tail->next;
        }
    }

    return head;
}

int main()
{
    int n, i = 1;

    while (cin >> n)
    {
        struct node *head = buildList(n);

        int lucky;
        cin >> lucky;

        int cards[20];
        for (int i = 0; i < 20; i++)
            cin >> cards[i];
 
        int card = 0;
        struct node *it = head;
        struct node *prev = nullptr;

        while (card < 20 && n > lucky)
        {
            int step = cards[card];
            bool finish = false;

            if (n < step)
                finish = true;
            else
            {
                for (int i = 1; i < step; i++)
                {
                    if (it == nullptr || it->next == nullptr)
                    {
                        finish = true;
                        break;
                    }
                    prev = it;
                    it = it->next;
                }
            }

            if (!finish)
            {
                struct node *temp = it;
                struct node *nextNode = it->next;

                if (prev == nullptr)
                {
                    head = nextNode;
                }
                else
                {
                    prev->next = nextNode;
                }

                it = nextNode;
                delete temp;
                n--;
            }
            else
            {
                it = head;
                prev = nullptr;
                card++;
            }
        }

        cout << "Selection #" << i << endl;
        i++;

        while (head != nullptr)
        {
            cout << head->key << " ";
            struct node *temp = head;
            head = head->next;
            delete temp;
        }

        cout << endl
             << endl;
    }

    return 0;
}
