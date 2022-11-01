#include <bits/stdc++.h>
using namespace std;

struct Sinhvien
{
    int masv;
    string name;
};

struct Node
{
    Sinhvien *data;
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

Sinhvien *createSinhvien(Sinhvien *Sv)
{
    Sv = new Sinhvien;
    cout << "Nhap ten sinh vien: ", cin >> Sv->name;
    cin.ignore();
    cout << "Nhap ma sinh vien: ", cin >> Sv->masv;
    return Sv;
}

Node *createNode(Sinhvien *Sv)
{
    Node *p = new Node;
    p->data = createSinhvien(Sv);
    p->link = NULL;
    return p;
}

void addFirst(List &L, Sinhvien *Sv)
{
    Node *p = createNode(Sv);
    if (L.last == NULL)
        L.last = p;
    else
        p->link = L.first;
    L.first = p;
}

void addLast(List &L, Sinhvien *Sv)
{
    Node *p = createNode(Sv);
    if (L.first == NULL)
        L.first = p;
    else
        p->link = L.first;
    L.first = p;
}

void out(List L)
{
    Sinhvien *Sv;
    Node *p = L.first;
    while (L.first != NULL)
    {
        Sv = p->data;
        cout << Sv->name << ": " << Sv->masv << endl;
        p = p->link;
    }
}

int main()
{
    Sinhvien *Sv;
    List L;
    int n;
    createList(L);
    cout << "Nhap so sinh vien: ", cin >> n;
    for (int i = 0; i < n; i++)
        addFirst(L, Sv);
    out(L);
}