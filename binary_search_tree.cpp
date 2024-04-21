#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define KEY(n) (n ? n->key : -1)
class Node
{
public:
    int key;
    Node *lchild, *rchild;
};
Node *getnewnode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = nullptr;
    return p;
}
Node *insert(Node *root, int key)
{
    if (root == nullptr)
        return getnewnode(key);
    if (key == root->key)
        return root;
    if (key < root->key)
    {
        root->lchild = insert(root->lchild, key);
    }
    else
    {
        root->rchild = insert(root->rchild, key);
    }
    return root;
}
Node *predcessor(Node *root)
{
    Node *temp = root->lchild;
    while (temp->rchild)
    {
        temp = temp->rchild;
    }
    return temp;
}
Node *erase(Node *root, int key)
{
    if (root == nullptr)
        return root;
    if (key > root->key)
    {
        root->rchild = erase(root->rchild, key);
    }
    else if (key < root->key)
    {
        root->lchild = erase(root->lchild, key);
    }
    else // 表示找到要删除的节点
    {
        //度为0
        if (root->lchild == nullptr && root->rchild == nullptr)
        {
            free(root);
            return NULL;
        }
        //度为1
        else if (root->lchild == nullptr || root->rchild == nullptr)
        {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        }
        //删除度大于1的结点，找到前驱或者后继替换后转换为删除度为1的结点的问题
        //前驱指的是中序遍历时按一定顺序排序的前面一个结点,一定出现在左子树中，而且是左子树中的最大值
        else
        {
            Node *temp = predcessor(root);//找到前驱结点
            root->key = temp->key;//把前驱节点的值赋值给当前节点
            root->lchild = erase(root->lchild, temp->key);//在左子树中删除值为tmp->key的节点
        }
    }
    return root;
}

void clear(Node *root)
{
    if (root == nullptr)
        return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
void output(Node *root)
{
    if (root == nullptr)
        return;
    cout << "(" << KEY(root) << ";" << KEY(root->lchild) << "," << KEY(root->rchild) << ")";
    //cout << root->key << " ";
    output(root->lchild);
    output(root->rchild);
}
void in_order(Node *root)
{
    if (root == nullptr)
        return;
    in_order(root->lchild);
    cout << root->key << " ";
    in_order(root->rchild);
}
int main(int argc, char const *argv[])
{
    srand(time(0));
#define MAX_OP 10
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++)
    {
        int key = rand() % 100;
        cout << "insert key " << key << " to BST\n";
        root = insert(root, key);
    }
    output(root);
    cout << "in order : ";
    in_order(root);
    cout << endl;
    int x;
    while (~scanf("%d", &x))
    {
        cout << "erase " << x << " from BST\n";
        root = erase(root, x);
        in_order(root);
    }
    return 0;
}
