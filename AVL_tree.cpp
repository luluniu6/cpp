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

struct Node
{
    int key, h;
    Node *left, *right;
};
Node __NIL;
#define NIL (&__NIL)
#define K(n) (n->key)
#define H(n) (n->h)
#define L(n) (n->left)
#define R(n) (n->right)
__attribute__((constructor)) // 设置下面函数的属性，使其无需手动调用先于主函数执行
void init_NIL()
{
    NIL->key = -1;
    NIL->h = 0;
    NIL->left = NIL->right = NIL;
    return;
}
Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->left = p->right = NIL;
    return p;
}
void update_height(Node *root)
{
    H(root) = H(L(root)) > H(R(root)) ? H(L(root)) + 1 : H(R(root)) + 1;
}
Node *left_rotate(Node *root)
{
    printf("left rotate : %d\n", root->key);
    Node *new_node = root->right; // 新根节点
    root->right = new_node->left;
    new_node->left = root;
    update_height(root);
    update_height(new_node);
    return new_node;
}
Node *right_rotate(Node *root)
{
    printf("right rotate : %d\n", root->key);
    Node *new_node = root->left; // 新根节点
    root->left = new_node->right;
    new_node->right = root;
    update_height(root);
    update_height(new_node);
    return new_node;
}
const char *type_str[5] = {
    "",
    "maintain type : LL",
    "maintain type : LR",
    "maintain type : RR",
    "maintain type : RL"};
Node *maintain(Node *root)
{
    if (abs(H(L(root)) - H(R(root))) <= 1) // 判断是否需要调整
        return root;
    int type = 0;
    if (H(L(root)) > H(R(root))) // L
    {
        if (H(R(L(root))) > H(L(L(root)))) // 左子树的右子树高度大于左子树的左子树，LR型
        {
            root->left = left_rotate(root->left); // 左旋
            type += 1;
        }
        root = right_rotate(root); // 右旋
        type += 1;
    }
    else // R
    {
        type = 2;
        if (H(L(R(root))) > H(R(R(root)))) // 右子树的左子树高度高于右子树的右子树，RL型
        {
            root->right = right_rotate(root->right); // 右旋
            type += 1;
        }
        root = left_rotate(root); // 左旋
        type += 1;
    }
    printf("%s\n", type_str[type]);
    return root;
}
Node *Insert(Node *root, int key)
{
    if (root == NIL)
        return getNewNode(key);
    if (root->key == key)
        return root;
    if (key < root->key)
    {
        root->left = Insert(root->left, key);
    }
    else
        root->right = Insert(root->right, key);
    update_height(root);
    return maintain(root);
}
Node *predcessor(Node *root)
{
    Node *temp = root->left;
    while (temp->right!=NIL)
    {
        temp = temp->right;
    }
    return temp;
}
Node *erase(Node *root, int key)
{
    if (root == NIL)
        return root;
    if (key > root->key)
    {
        root->right = erase(root->right, key);
    }
    else if (key < root->key)
    {
        root->left = erase(root->left, key);
    }
    else // 表示找到要删除的节点
    {
        // 度为1
        if (root->left == NIL || root->right == NIL)
        {
            Node *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        // 删除度大于1的结点，找到前驱或者后继替换后转换为删除度为1的结点的问题
        // 前驱指的是中序遍历时按一定顺序排序的前面一个结点,一定出现在左子树中，而且是左子树中的最大值
        else
        {
            Node *temp = predcessor(root);             // 找到前驱结点
            root->key = temp->key;                     // 把前驱节点的值赋值给当前节点
            root->left = erase(root->left, temp->key); // 在左子树中删除值为tmp->key的节点
        }
    }
    update_height(root);
    return maintain(root);
}
Node *find(Node *root, int key)
{
    if (root == NIL)
        return NIL;
    if (root->key == key)
        return root;
    if (key < root->key)
        return find(root->left, key);
    return find(root->right, key);
}
void clear(Node *root)
{
    if (root == NIL)
        return;
    clear(root->left);
    clear(root->right);
    free(root);
}
void output(Node *root)
{
    if (root == NIL)
        return;
    printf("(%d[%d] | %d %d)\n", K(root), H(root), K(L(root)), K(R(root)));
    output(root->left);
    output(root->right);
    return;
}
int main(int argc, char const *argv[])
{
    srand(time(0));
    Node *root = NIL;
    int x;
    // insert
    while (~scanf("%d", &x))
    {
        if (x == -1)
            break;
        printf("Insert %d to avl tree\n", x);
        root = Insert(root, x);
        output(root);
    }
    
    // erase
    while (~scanf("%d", &x))
    {
        if (x == -1)
            break;
        printf("erase %d from avl tree\n", x);
        root = erase(root, x);
        output(root);
    }
    // find
    
    while (~scanf("%d", &x))
    {
        if (x == -1)
            break;
        printf("find %d in avl : %d\n", x, find(root, x) != NIL);
    }
    
    return 0;

}
