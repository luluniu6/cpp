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
//1与2是利用前序遍历中左右的顺序，将代码左右互换，成为中右左，然后反转数组为左右中实现
//3与4基本一模一样
//1.
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
//2.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*>st;
        TreeNode* cur=root;
        while(cur||!st.empty())
        {
            if(cur)
            {
                st.push(cur);
                ret.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                cur=st.top();
                st.pop();
                cur=cur->left;
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
//3.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* lastnode = nullptr;
        while (cur || !st.empty()) 
        {
            while (cur) 
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();
            if (top->right == nullptr || lastnode == top->right) 
            {
                ret.push_back(top->val);
                lastnode = top;
                st.pop();
            } 
            else 
            {
                cur = top->right;
            }
        }
        return ret;
    }
};
//4.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* lastnode = nullptr;
        while (cur || !st.empty()) 
        {
            if (cur) 
            {
                st.push(cur);
                cur = cur->left;
            } 
            else 
            {
                TreeNode* top = st.top();
                if (top->right == nullptr || lastnode == top->right) 
                {
                    ret.push_back(top->val);
                    lastnode = top;
                    st.pop();
                } 
                else 
                {
                    cur = top->right;
                }
            }
        }
        return ret;
    }
};