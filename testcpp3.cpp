#include <bits/stdc++.h>
using namespace std;
struct DLinkListNode
{
    int val;
    DLinkListNode *prev;
    DLinkListNode *next;
    DLinkListNode(int _val) : val(_val), prev(nullptr), next(nullptr) {}
};
class MyLinkedList
{
public:
    MyLinkedList()
    {
        head = new DLinkListNode(0);
        head->prev = nullptr;
        head->next = nullptr;
        size = 0;
    }
    ~MyLinkedList()
    {
        DLinkListNode *cur = head->next;
        while (cur != nullptr)
        {
            DLinkListNode *next = cur->next;
            delete cur;
            cur = next;
        }
        head->next = nullptr;
        head->prev = nullptr;
        delete head;
    }
    DLinkListNode *ListFind(int index)
    {
        if (index > size - 1 || index < 0)
            return nullptr;
        DLinkListNode *cur = head->next;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur;
    }

    int get(int index)
    {
        DLinkListNode *cur = ListFind(index);
        if (cur == nullptr)
            return -1;
        return cur->val;
    }
    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        DLinkListNode *pos = ListFind(index);
        if (pos == nullptr)
            return;
        DLinkListNode *prepos = pos->prev;
        DLinkListNode *newnode = new DLinkListNode(val);
        prepos->next = newnode;
        newnode->prev = prepos;
        newnode->next = pos;
        pos->prev = newnode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index > size - 1 || index < 0)
            return;
        DLinkListNode *pos = ListFind(index);
        if (pos == nullptr)
            return;
        DLinkListNode *prepos = pos->prev;
        DLinkListNode *nextpos = pos->next;
        prepos->next = nextpos;
        nextpos->prev = prepos;
        size--;
    }
    void print()
    {
        if (head->next != nullptr)
        {
            DLinkListNode *cur = head->next;
            while (cur->next != head)
            {
                cout << cur->val << " ";
            }
        }
    }

private:
    DLinkListNode *head;
    int size;
};
// int main(int argc, char const *argv[])
// {
//     MyLinkedList myLinkedList = MyLinkedList();
//     myLinkedList.addAtHead(1);
//     myLinkedList.addAtTail(3);
//     myLinkedList.addAtIndex(1, 2); // 链表变为 1->2->3
//     myLinkedList.get(1);           // 返回 2
//     myLinkedList.deleteAtIndex(1); // 现在，链表变为 1->3
//     myLinkedList.get(1);           // 返回 3
//     myLinkedList.print();
//     return 0;
// }
// class A
// {
// public:
//     void PrintA()
//     {
//         cout << _a << endl;     //this->a
//     }
//     void Show()
//     {
//         cout << "Show()" << endl;
//     }

// private:
//     int _a;
// };
// int main()
// {
//     A *p = NULL;
//     p->PrintA();//这一行会引发什么？编译不通过？程序崩溃？正常运行？    //崩溃
//     p->Show();//这一行会引发什么？编译不通过？程序崩溃？正常运行？    //正常运行
//     //成员函数存在公共的代码段，所以p->Show()这里不会去p指向的对象上找
//     //this指针存在哪里？(也就是存在进程地址空间的哪个区域？)
//     //答：栈上，因为它是一个形参(ps：vs下是在ecx这个寄存器来传递)
//     return 0;
// }