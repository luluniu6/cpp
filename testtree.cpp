//https://leetcode.cn/problems/binary-tree-preorder-traversal/description/ 144. 二叉树的前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        while(cur||!st.empty())
        {
            if(cur)
            {
                ret.push_back(cur->val);
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=st.top();
                st.pop();
                cur=cur->right;
            }
            
        }
        return ret;
    }
};

//2.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return result;
    }
};

//https://leetcode.cn/problems/binary-tree-inorder-traversal/description/ 94. 二叉树的中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            if (cur) 
            {
                st.push(cur);
                cur = cur->left;
            } 
            else 
            {
                cur = st.top();
                st.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret;
    }
};

//https://leetcode.cn/problems/binary-tree-postorder-traversal/description/ 145. 二叉树的后序遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        if(root==nullptr) return ret;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node=st.top();
            st.pop();
            ret.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};