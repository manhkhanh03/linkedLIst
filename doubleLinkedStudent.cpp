#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int masv;
};

struct Node
{
    Student *data;
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

Student *createStudent()
{
    Student *Sv = new Student;
    cout << "Nhap ten Sinh vien: ", cin >> Sv->name;
    cin.ignore();
    cout << "Nhap ma Sinh vien: ", cin >> Sv->masv;
    return Sv;
}

Node *createNode(List &L)
{
    Node *p = new Node;
    p->data = createStudent();
    p->next = p->prev = NULL;
    return p;
}

void addFirst(List &L)
{
    Node *p = createNode(L);
    if (L.last == NULL)
        L.last = p;
    else
    {
        p->next = L.first;
        L.first->prev = p;
    }
    L.first = p;
}

void deleteFirst(List &L)
{
    Node *p = L.first;
    if (L.first != NULL)
    {
        L.first = p->next;
        L.first->prev = NULL;
        delete p;
    }
}

void deleteLast(List &L)
{
    Node *p = L.last;
    if (L.last != NULL)
    {
        L.last = p->prev;
        L.last->next = NULL;
        delete p;
    }
}

// xoa 1 phan tu dau tien giong
void deleteElement(List &L, Student &y)
{
    // Student *Sv;
    cout << "Nhap mssv can xoa: ", cin >> y.masv;
    Node *p = L.first;
    while (p != NULL)
    {
        if (p->data->masv == y.masv)
        {
            if (p == L.first)
                deleteFirst(L);
            else if (p == L.last)
                deleteLast(L);
            else
            {
                Node *front = p->prev;
                Node *behind = p->next;
                front->next = behind;
                behind->prev = front;
            }
            delete p;
            break;
        }
        p = p->next;
    }
}

// xoa toan bo ptu giong
void deleteFullElement(List &L, Student y, Node *address)
{
    Node *p = address;
    while (p != NULL)
    {
        if (p->data->masv == y.masv)
        {
            Node *front = p->prev;
            if (p == L.first)
                deleteFirst(L);
            else if (p == L.last)
                deleteLast(L);
            else
            {
                Node *behind = p->next;
                front->next = behind;
                behind->prev = front;
            }
            delete p;
            deleteFullElement(L, y, front);
            break;
        }
        p = p->next;
    }
}

void outFirst(List L)
{
    Node *p = L.first;
    if (L.first == NULL)
        cout << "Rong!\n";
    else
    {
        while (p != NULL)
        {
            Student *Sv = p->data;
            cout << "Name: " << Sv->name << endl;
            cout << "MSSV: " << Sv->masv << endl;
            p = p->next;
        }
    }
}

int main()
{
    List L;
    Student y;
    createList(L);

    int n, a[20];
    cout << "Nhap so ptu: ", cin >> n;
    for (int i = 0; i < n; i++)
        addFirst(L);

    outFirst(L);
    cout << "Nhap mssv can xoa: ", cin >> y.masv;
    deleteFullElement(L, y, L.first);
    outFirst(L);
}