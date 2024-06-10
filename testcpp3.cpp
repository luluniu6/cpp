#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
int main(int argc, char const *argv[])
{
    TreeNode root(3);
    root.left->val=9;
    root.right->val=20;
    TreeNode* ershi=root.right;
    ershi->left->val=15;
    ershi->right->val=7;
    cout << maxDepth(&root);
    return 0;
}
