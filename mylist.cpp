#include <bits/stdc++.h>
using namespace std;
namespace lala
{
    template <class T>
    struct _list_node
    {
        _list_node<T> *_next;
        _list_node<T> *_prev;
        T _data;
    };

    template <class T>
    class list
    {
        typedef _list_node<T> Node;

    public:
    //带头双向循环链表
        list()
        {
            _head=new Node;
            _head->next=_head;
            _head->prev=_head;
        }
        void push_back(const T& x)
        {
            Node* tail=head->_prev;
            Node* newnode=new Node(x);
            tail->_next=newnode;
            newnode->_prev=tail;
            newnode->_next=head;
            _head->_prev=newnode;
        }

    private:
    node* _head;
    };
}
