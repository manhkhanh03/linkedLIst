#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
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
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void addFirst(List &L, int x)
{
    Node *p = createNode(x);
    if (L.last == NULL)
        L.last = p;
    else
    {
        L.first->prev = p;
        p->next = L.first;
    }
    L.first = p;
}

void addLast(List &L, int x)
{
    Node *p = createNode(x);
    if (L.first == NULL)
        L.first = p;
    else
    {
        L.last->next = p;
        p->prev = L.last;
    }
    L.last = p;
}

void deleteFirst(List &L)
{

    if (L.first != NULL)
    {
        if (L.last == L.first)
            L.last = NULL;
        Node *p = L.first;
        L.first = p->next;
        L.first->prev = NULL;
        delete p;
    }
}

void deleteLast(List &L)
{

    if (L.last != NULL)
    {
        if (L.first == L.last)
            L.first = NULL;
        Node *p = L.last;
        L.last = p->prev;
        L.last->next = NULL;
        delete p;
    }
}

void deleteElement(List &L, int y, Node *address)
{
    Node *p = address;
    while (p != NULL)
    {
        if (p->data == y)
        {
            Node *front = p->prev;
            if (p == L.first)
            {
                deleteFirst(L);
                deleteElement(L, y, L.first);
            }
            else if (p == L.last)
            {
                deleteLast(L);
                deleteElement(L, y, L.last);
            }
            else
            {
                Node *behind = p->next;
                front->next = behind;
                behind->prev = front;
                delete p;
            }
            deleteElement(L, y, front);
            break;
        }
        p = p->next;
    }
}

void outFirst(List L)
{
    Node *p = L.first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void outLast(List L)
{
    Node *p = L.last;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->prev;
    }
}

int main()
{
    List L;
    createList(L);

    int n, a[10000];
    srand(time(NULL));
    cout << "Nhap so phan tu: ", cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
        addFirst(L, a[i]);
        cout << a[i] << " ";
    }

    cout << endl;
    // deleteFirst(L);
    // deleteLast(L);
    int y;
    cout << "Nhap phan tu muon xoa: ", cin >> y;
    deleteElement(L, y, L.first);
    outLast(L);
    cout << endl;
    // outFirst(L);
}