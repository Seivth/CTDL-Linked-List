#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    string name;
    node *next;
};

// tao node
node *CreateNode()
{
    node *tmp;
    tmp = new node;
    tmp->next = NULL;
    cout << "Nhap ten: ";
    fflush(stdin);
    getline(cin, tmp->name);
    cout << "Nhap chieu cao: ";
    cin >> tmp->data;
    return tmp;
}
// chen node vao vi tri dau tien
void insertHead(node *&head)
{
    node *tmp = CreateNode();
    tmp->next = head;
    head = tmp;
}
// chen node vao vi tri cuoi cung
void insertTail(node *&head)
{
    node *tmp = CreateNode();
    if (head == NULL)
    {
        head = tmp;
        return;
    }
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = tmp;
}
// chen node vao vi tri sau node co gia tri data1
// chen vao cuoi cung neu khong tim thay
void insertAfter(node *&head, int data1)
{
    node *p = head, *before;
    while (p != NULL && p->data != data1)
    {
        before = p;
        p = p->next;
    }
    node *tmp = CreateNode();
    if (p == head)
    {
        tmp->next = p;
        head = tmp;
        return;
    }
    if (p == NULL)
    {
        before->next = CreateNode();
        return;
    }
    tmp->next = p->next;
    p->next = tmp;
}
// chen node vao vi tri truoc node co gia tri data1
// chen vao cuoi cung neu khong tim thay
void insertBefore(node *&head, int data1)
{
    node *p = head, *before;
    node *tmp = CreateNode();
    while (p != NULL && p->data != data1)
    {
        before = p;
        p = p->next;
    }
    if (p == head)
    {
        tmp->next = p;
        head = tmp;
        return;
    }
    before->next = tmp;
    tmp->next = p;
}
// chen node sap xep theo ten
void insertSort(node *&head)
{
    node *tmp = CreateNode();
    node *p = head, *before;
    while (p != NULL && tmp->name > p->name)
    {
        before = p;
        p = p->next;
    }
    if (p == head)
    {
        tmp->next = p;
        head = tmp;
        return;
    }
    before->next = tmp;
    tmp->next = p;
}
// chen node tai vi tri pos
void insertAt(node *&head, int pos)
{
    int idx = 1; // danh sach bat dau tai vi tri 1
    node *p = head, *before;
    while (p != NULL && idx != pos)
    {
        before = p;
        p = p->next;
        idx++;
    }
    if (p == NULL)
    {
        cout << "Vi tri nam ngoai danh sach" << endl;
        return;
    }
    node *tmp = CreateNode();
    if (p == head)
    {
        tmp->next = p;
        head = tmp;
    }
    else
    {
        before->next = tmp;
        tmp->next = p;
    }
}
// xoa node dau tien co gia tri data
void eraseFirst(node *&head, int data)
{
    node *p = head, *before;
    while (p != NULL && p->data != data)
    {
        before = p;
        p = p->next;
    }
    if (p != NULL)
    {
        if (p == head)
        {
            head = p->next;
        }
        else
        {
            before->next = p->next;
        }
        delete p;
    }
}
// xoa tat ca cac node co gia tri data
void eraseAll(node *&head, int data)
{
    node *p = head, *before;
    while (p != NULL)
    {
        if (p->data == data)
        {
            node *delNode = p;
            if (p == head)
            {
                head = p->next;
            }
            else
            {
                before->next = p->next;
            }
            p = p->next;
            delete delNode;
            continue;
        }
        before = p;
        p = p->next;
    }
}
// xoa node o vi tri pos
void eraseAt(node *&head, int pos)
{
    int idx = 1; // danh sach bat dau tai vi tri 1
    node *p = head, *before;
    while (p != NULL && idx != pos)
    {
        before = p;
        p = p->next;
        idx++;
    }
    if (p == NULL)
    {
        cout << "Vi tri nam ngoai danh sach" << endl;
        return;
    }
    if (p == head)
    {
        head = p->next;
    }
    else
    {
        before->next = p->next;
    }
    delete p;
}
// tim kiem node dau tien trong danh sach co chua ten=name
// tra ve con tro den node do
// tra ve NULL neu khong tim thay
node *find(node *head, string name)
{
    int idx = 1; // danh sach bat dau tai vi tri 1
    node *p = head;
    while (p != NULL && p->name != name)
    {
        p = p->next;
        idx++;
    }
    if (p != NULL)
    {
        cout << "Vi tri " << idx << endl;
        cout << "Ten:" << p->name << endl;
        cout << "Chieu cao: " << p->data << endl;
    }
    else
    {
        cout << "Khong tim thay" << endl;
    }
    return p;
}
// tim kiem tat ca node trong danh sach co chua ten=name
void findAll(node *head, string name)
{
    int idx = 1; // danh sach bat dau tai vi tri 1
    node *p = head;
    while (p != NULL)
    {
        if (p->name == name)
        {
            cout << "Vi tri " << idx << endl;
            cout << "Ten:" << p->name << endl;
            cout << "Chieu cao: " << p->data << endl;
        }
        p = p->next;
        idx++;
    }
}
// khoi tao danh sach
void init(node *&head)
{
    if (head != NULL)
    {
        cout << "Danh sach da duoc khoi tao" << endl;
        return;
    }
    cout << "nhap so luong: ";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        insertTail(head);
    }
}
// Hien thi danh sach lien ket
void display(node *head)
{
    if (head == NULL)
    {
        cout << "Danh sach rong" << endl;
        return;
    }
    cout << "--------Danh sach-----------" << endl;
    node *p = head;
    while (p != NULL)
    {
        cout << "Ten:" << p->name << endl;
        cout << "Chieu cao: " << p->data << endl;
        p = p->next;
    }
}
// tim gia tri data max
// tra ve -1 neu danh sach rong
int findMaxHeight(node *head)
{
    node *p = head;
    int Max = -1;
    while (p != NULL)
    {
        Max = max(Max, p->data);
        p = p->next;
    }
    return Max;
}
// tim tong data
int sumHeight(node *head)
{
    node *p = head;
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int main()
{
    node *head = NULL;
    // init(head);
    // cout << "----" << endl;
    // display(head);
    // cout << "Chieu cao lon nhat: " << findMaxHeight(head) << endl;
    // eraseAll(head, 3);
    // display(head);
    // int choice;
    while (1)
    {
        cout << "\n-----------------Menu------------------\n";
        cout << "\n1. init\n";
        cout << "\n2. display\n";
        cout << "\n3. insertHead\n";
        cout << "\n4. insertTail\n";
        cout << "\n5. insertAfter\n";
        cout << "\n6. insertBefore\n";
        cout << "\n7. insertSort\n";
        cout << "\n8. insertAt\n";
        cout << "\n9. findMaxHeight\n";
        cout << "\n10. sumHeight\n";
        cout << "\n--------------------------------------\n";
        cout << "\nEnter your choice:\t";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            init(head);
            break;
        case 2:
        {
            display(head);
            system("pause");
            break;
        }
        case 3:
            insertHead(head);
            break;
        case 4:
            insertTail(head);
            break;
        case 5:
        {

            int data;
            cout << "Nhap gia tri: ";
            cin >> data;
            insertAfter(head, data);
            break;
        }
        case 6:
        {
            int data;
            cout << "Nhap gia tri: ";
            cin >> data;
            insertBefore(head, data);
            break;
        }
        case 7:
            insertSort(head);
            break;
        case 8:
        {
            int pos;
            cout << "Nhap vi tri: ";
            cin >> pos;
            insertAt(head, pos);
            break;
        }
        case 9:
            cout << "Chieu cao lon nhat: " << findMaxHeight(head) << endl;
            break;
        case 10:
            cout << "Tong chieu cao: " << sumHeight(head) << endl;
            break;
        default:
            cout << "\nWrong choice!\n";
            break;
        }
    }
    return 0;
}