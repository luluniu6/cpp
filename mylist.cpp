#include <bits/stdc++.h>
using namespace std;
namespace lala
{
    template <class T>
    struct __list_node
    {
        __list_node<T> *_next;
        __list_node<T> *_prev;
        T _data;

        __list_node(const T &x = T())
            : _data(x), _next(nullptr), _prev(nullptr)
        {
        }
    };
    //__list_iterator<T,T&,T*>  -> iterator
    //__list_iterator<T,const T&,const T*>  ->const_iterator
    template <class T, class Ref, class Ptr>
    struct __list_iterator
    {
        typedef __list_node<T> Node;
        typedef __list_iterator<T, Ref, Ptr> Self;
        Node *_node;
        __list_iterator(Node *node)
            : _node(node)
        {
        }
        Ref operator*() // 解引用
        {
            return _node->_data;
        }
        Ptr operator->()
        {
            return &_node->_data;
        }
        Self &operator++() //++it
        {
            _node = _node->_next;
            return *this;
        }
        Self operator++(int) // it++ //后置++运算符重载,注意需要加int来与前置++重载做区分，语法这样规定。 //为什么返回值不用引用，因为不可以返回局部变量
        {
            Self tmp(*this);
            //_node = _node->_next;
            ++(*this);
            return tmp;
        }
        Self &operator--() //--it
        {
            _node = _node->_prev;
            return *this;
        }
        Self operator--(int) // it--
        {
            Self tmp(*this);
            //_node = _node->_prev;
            --(*this);
            return tmp;
        }
        //(it != l.end())
        bool operator!=(const Self &it)
        {
            return _node != it._node;
        }
        bool operator==(const Self &it)
        {
            return _node == it._node;
        }
    };
    template <class T>
    class list
    {
        typedef __list_node<T> Node;

    public:
        typedef __list_iterator<T, T &, T *> iterator;
        typedef __list_iterator<T, const T &, const T *> const_iterator;

        iterator begin()
        {
            return iterator(_head->_next);
        }
        iterator end()
        {
            return iterator(_head);
        }
        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }
        const_iterator end() const
        {
            return const_iterator(_head);
        }
        // 带头双向循环链表
        list()
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
        }
        void push_back(const T &x)
        {
            // Node *tail = _head->_prev;
            // Node *newnode = new Node(x);
            // tail->_next = newnode;
            // newnode->_prev = tail;
            // newnode->_next = _head;
            // _head->_prev = newnode;
            // // 结构设计的优势，有没有节点插入都一样
            insert(end(), x);
        }
        void pop_back();
        void push_front(const T &x)
        {
            insert(begin(), x);
        }
        void pop_front();
        void erase(iterator pos)
        {
            
        }
        void insert(iterator pos, const T &x)
        {
            Node *cur = pos._node;
            Node *prev = cur->_prev;
            Node *newnode = new Node(x);

            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
        }

    private:
        Node *_head;
    };

    void print_list(const list<int> &lt)
    {
        list<int>::const_iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
    void test_list2()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        print_list(lt);
    }
}
int main()
{
    // lala::test_list1();
    lala::test_list2();
    return 0;
}
