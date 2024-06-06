#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <class K>
struct BSTreeNode
{
    BSTreeNode<K> *_left;
    BSTreeNode<K> *_right;
    K _key;

    BSTreeNode(const K &key)
        : _left(nullptr), _right(nullptr), _key(key)
    {
    }
};
template <class K>
class BSTree
{
    typedef BSTreeNode<K> Node;

public:
    bool Insert(const K &key)
    {
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }
        else
        {
            Node *parent = nullptr;
            Node *cur = _root;
            while (cur)
            {
                if (cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (cur->_key < key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else
                {
                    return false;
                }
            }
            cur = new Node(key);
            if (parent->_key < key)
            {
                parent->_right = cur;
            }
            else
            {
                parent->_left = cur;
            }
            return true;
        }
    }
    bool Find(const K &key)
    {
        Node *cur = _root;
        while (cur)
        {
            if (cur->_key < key)
            {
                cur = cur->_right;
            }
            else if (cur->_key > key)
            {
                cur = cur->_left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    bool Erase(const K &key)
    {
        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                // 找到了，开始删除
                if (cur->_left == nullptr)
                {
                    if (cur == _root)
                    {
                        _root = cur->_right;
                    }
                    else
                    {
                        if (parent->_right == cur)
                            parent->_right = cur->_right;
                        else
                            parent->_left = cur->_right;
                    }
                    delete cur;
                }
                else if (cur->_right == nullptr)
                {
                    if (cur == _root)
                    {
                        _root = cur->_left;
                    }
                    else
                    {
                        if (parent->_left == cur)
                            parent->_left = cur->_left;
                        else
                            parent->_right = cur->_left;
                    }
                    delete cur;
                }
                else
                {
                    Node *rightMinParent = cur;
                    Node *rightMin = cur->_right;
                    while (rightMin->_left)
                    {
                        rightMinParent = rightMin;
                        rightMin = rightMin->_left;
                    }
                    // 替代删除
                    cur->_key = rightMin->_key;
                    // 转换成删除rightMin(rightMin是左为空，父亲指向他的右)
                    if (rightMin == rightMinParent->_left)
                        rightMinParent->_left = rightMin->_right;
                    else
                        rightMinParent->_right = rightMin->_right;
                    delete rightMin;
                }
                return true;
            }
        }
        return false;
    }
    void _InOrder(Node *_root)
    {
        if (_root == nullptr)
            return;
        _InOrder(_root->_left);
        cout << _root->_key << " ";
        _InOrder(_root->_right);
    }
    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }

private:
    Node *_root = nullptr;
};
void TestBSTree()
{
    BSTree<int> t;
    int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};
    for (auto e : a)
    {
        t.Insert(e);
    }
    t.InOrder();
    t.Erase(7);
    t.Erase(1);
    t.Erase(3);
    t.Erase(4);
    t.Erase(5);
    t.Erase(6);
    t.Erase(0);
    t.Erase(8);
    t.Erase(9);
    t.InOrder();
    t.Erase(2);
    t.InOrder();
    // t.Erase(8);
    // t.InOrder();
    // t.Erase(5);
    // t.InOrder();
}
int main()
{
    TestBSTree();
    return 0;
}
