#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

struct List
{
    Node *first;
    Node *last;
};

void createList(List &L)
{
    L.first = NULL;
    L.last = NULL;
}

Node *createNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->link = NULL;
    return p;
}

void addFirst(List &L, int x)
{
    Node *p = createNode(x);
    if (L.last == NULL)
        L.last = p;
    else
        p->link = L.first;
    L.first = p;
}

void deleteFirst(List &L)
{
    if (L.first != NULL)
    {
        if (L.first == L.last)
            L.last = NULL;
        Node *p = L.first;
        L.first = p->link;
        delete p;
    }
}

void deleteLast(List &L)
{
    Node *p = L.last;

    if (L.first == L.last)
        L.first = L.last = NULL;
    else
    {
        Node *q = L.first;
        while (q->link != L.last)
            q = q->link;
        L.last = q;
        L.last->link = NULL;
    }
    delete p;
}

void deleteElement(List &L, int y)
{
    Node *p = L.first;
    while (p != NULL)
    {
        if (p->data == y)
        {
            if (p == L.first)
            {
                deleteFirst(L);
                deleteElement(L, y);
            }
            else if (p == L.last)
            {
                deleteLast(L);
                deleteElement(L, y);
            }
            else
            {
                Node *front = L.first;
                while (front->link != p)
                    front = front->link;
                front->link = p->link;
                delete p;
            }
            deleteElement(L, y);
            break;
        }
        p = p->link;
    }
}

void addLast(List &L, int x)
{
    Node *p = createNode(x);
    if (L.first == NULL)
        L.first = p;
    else
        L.last->link = p;
    L.last = p;
}

void out(List L)
{
    Node *p = L.first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->link;
    }
}

int main()
{
    List L;
    createList(L);

    int a[10000];
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        a[i] = rand() % 10;
        cout << a[i] << " ";
        addFirst(L, a[i]);
    }

    int y;
    // out(L);
    // deleteFirst(L);
    // deleteLast(L);
    cout << "\nNhap phan tu can xoa: ", cin >> y;
    deleteElement(L, y);
    cout << endl;
    out(L);
}