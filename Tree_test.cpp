// #include <iostream>
// #include <vector>
// #include <unordered_set>
// #include <stack>
// #include <queue>
// #include <algorithm>
// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// // 利用栈模拟递归
// // 先序遍历：根左右
// vector<int> preorderTraversal(TreeNode *root)
// {
//     vector<int> ret;
//     stack<TreeNode *> st;
//     TreeNode *cur = root;
//     while (cur || !st.empty())
//     {
//         if (cur)
//         {
//             st.push(cur);
//             ret.push_back(cur->val);
//             cur = cur->left;
//         }
//         else
//         {
//             cur = st.top();
//             st.pop();
//             cur = cur->right;
//         }
//     }
//     return ret;
// }
// // 中序遍历：左根右
// vector<int> inorderTraversal(TreeNode *root)
// {
//     vector<int> ret;
//     stack<TreeNode *> st;
//     TreeNode *cur = root;
//     while (cur || !st.empty())
//     {
//         if (cur)
//         {
//             st.push(cur);
//             cur = cur->left;
//         }
//         else
//         {
//             cur = st.top();
//             st.pop();
//             ret.push_back(cur->val);
//             cur = cur->right;
//         }
//     }
//     return ret;
// }
// // 后序遍历：左右根
// vector<int> postorderTraversal(TreeNode *root)
// {
//     vector<int> ret;
//     stack<TreeNode *> st;
//     TreeNode *cur = root;
//     while (cur || !st.empty())
//     {
//         if (cur)
//         {
//             st.push(cur);
//             ret.push_back(cur->val);
//             cur = cur->right;
//         }
//         else
//         {
//             cur = st.top();
//             st.pop();
//             cur = cur->left;
//         }
//     }
//     reverse(ret.begin(), ret.end());
//     return ret;
// }

// // 层序遍历
// vector<vector<int>> levelOrder(TreeNode *root)
// {
//     vector<vector<int>> ret;
//     queue<TreeNode *> q;
//     if (root != nullptr)
//         q.push(root);
//     while (!q.empty())
//     {
//         int size = q.size();
//         vector<int> v;
//         while (size--)
//         {
//             TreeNode *front = q.front();
//             q.pop();
//             v.push_back(front->val);
//             if (front->left != nullptr)
//                 q.push(front->left);
//             if (front->right != nullptr)
//                 q.push(front->right);
//         }
//         ret.push_back(v);
//     }
//     return ret;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <iostream>
// #include <vector>
// using namespace std;
// typedef char DataType;
// typedef struct Node
// {
//     DataType data;
//     struct Node *Lchild;
//     struct Node *Rchild;
// } BiTNode, *BiTree;

// BiTree CreatBiTree(); // 用扩展先序遍历序列创建二叉链表
// int main()
// {
//     string s;
//     cin >> s;
//     BiTree root;
//     root = CreatBiTree();
// }
// BiTree CreatBiTree(string &s) // 用扩展先序遍历序列创建二叉链表
// {
//     BiTree bt;

//     if (ch == '#')
//         return NULL;
//     bt = (BiTree)malloc(sizeof(BiTNode));
//     bt->data = ch;
//     printf("%c", ch);
//     bt->Lchild = CreatBiTree();
//     bt->Rchild = CreatBiTree();
//     return bt;
// }

// #include <iostream>
// #include <vector>
// #include <unordered_set>
// #include <stack>
// #include <queue>
// #include <algorithm>
// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// TreeNode *createTree()
// {
//     //TreeNode *root = new TreeNode;
//     TreeNode * root = (TreeNode*)malloc(sizeof( struct TreeNode));
//     char ch;
//     scanf("%c", &ch);
//     if (ch != '#')
//     {
//         root->val = ch;
//         root->left = createTree();
//         root->right = createTree();
//     }
//     else
//         root = nullptr;
//     return root;
// }
// vector<char> preorderTraversal(TreeNode *root)
// {
//     vector<char> ret;
//     if (root == nullptr)
//         return {};
//     ret.push_back(root->val);
//     preorderTraversal(root->left);
//     preorderTraversal(root->right);
//     return ret;
// }

// vector<char> inorderTraversal(TreeNode *root)
// {
//     vector<char> ret;
//     if (root == nullptr)
//         return {};
//     inorderTraversal(root->left);
//     ret.push_back(root->val);
//     inorderTraversal(root->right);
//     return ret;
// }

// vector<char> postorderTraversal(TreeNode *root)
// {
//     vector<char> ret;
//     if (root == nullptr)
//         return {};
//     postorderTraversal(root->left);
//     postorderTraversal(root->right);
//     ret.push_back(root->val);
//     return ret;
// }
// int main()
// {
//     TreeNode *root = createTree();
//     vector<char> pre = preorderTraversal(root);
//     for (char i : pre)
//         cout << i << " ";
//     cout << endl;
//     vector<char> in = inorderTraversal(root);
//     for (char i : in)
//         cout << i << " ";
//     cout << endl;
//     vector<char> post = postorderTraversal(root);
//     for (char i : post)
//         cout << i << " ";
//     cout << endl;
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct TreeNode {
// 	char value;
// 	struct TreeNode* lChild;
// 	struct TreeNode* rChild;
// } * BT_Node;

// // 创建(先序)
// BT_Node Create_BinaryTree() {
// 	BT_Node root = (BT_Node)malloc(sizeof( struct TreeNode));
// 	char temp;
// 	scanf("%c", &temp);
// 	if (temp != '#') {
// 		root->value = temp;
// 		root->lChild = Create_BinaryTree();
// 		root->rChild = Create_BinaryTree();
// 	} else {
// 		root = NULL;
// 	}
// 	return root;
// }
// void Preorder_traverse(BT_Node root) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	printf("%c", root->value);
// 	Preorder_traverse(root->lChild);
// 	Preorder_traverse(root->rChild);
// }
// void Inorder_traverse(BT_Node root) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	Inorder_traverse(root->lChild);
// 	printf("%c", root->value);
// 	Inorder_traverse(root->rChild);
// }
// void Postorder_traverse(BT_Node root) {
// 	if (root == NULL) {
// 		return;
// 	}
// 	Postorder_traverse(root->lChild);
// 	Postorder_traverse(root->rChild);
// 	printf("%c", root->value);
// }
// int main() {
// 	BT_Node root;
// 	root = Create_BinaryTree();
// 	Preorder_traverse(root);
// 	printf("\n");
// 	Inorder_traverse(root);
// 	printf("\n");
// 	Postorder_traverse(root);
// }

// #include <iostream>
// #include <stack>
// #include <string>
// #include <vector>

// using namespace std;

// struct TreeNode
// {
//     char val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
// };

//     TreeNode *createTree(const string &preorder, int &index)
//     {
//         if (index >= preorder.size() || preorder[index] == '#')
//         {
//             index++;
//             return nullptr;
//         }
//         TreeNode *node = new TreeNode(preorder[index++]);
//         node->left = createTree(preorder, index);
//         node->right = createTree(preorder, index);
//         return node;
//     }
//     void postorder(TreeNode *root, vector<char> &arr)
//     {
//         if (root == nullptr)
//             return;
//         postorder(root->left, arr);
//         postorder(root->right, arr);
//         arr.push_back(root->val);
//     }
//     vector<char> postorderTraversal(TreeNode *root)
//     {
//         vector<char> ret;
//         postorder(root, ret);
//         return ret;
//     }
//     void inorder(TreeNode *root, vector<char> &arr)
//     {
//         if (root == nullptr)
//             return;
//         postorder(root->left, arr);
//         arr.push_back(root->val);
//         postorder(root->right, arr);
//     }
//     vector<char> inorderTraversal(TreeNode *root)
//     {
//         vector<char> ret;
//         postorder(root, ret);
//         return ret;
//     }
//     void preorder(TreeNode *root, vector<char> &arr)
//     {
//         if (root == nullptr)
//             return;
//         arr.push_back(root->val);
//         postorder(root->left, arr);
//         postorder(root->right, arr);
//     }
//     vector<char> preorderTraversal(TreeNode *root)
//     {
//         vector<char> ret;
//         postorder(root, ret);
//         return ret;
//     }

// int main()
// {
//     string preorder;
//     cin >> preorder;
//     int index = 0;
//     TreeNode *root = createTree(preorder, index);
//     vector<char> pre = preorderTraversal(root);
//     for (char i : pre)
//         cout << i;
//     cout << endl;
//     vector<char> in = inorderTraversal(root);
//     for (char i : in)
//         cout << i;
//     cout << endl;
//     vector<char> post = postorderTraversal(root);
//     for (char i : post)
//         cout << i;
//     cout << endl;

//     return 0;
// }
// #include <iostream>
// #include <stack>
// #include <string>
// #include <vector>
// #include <queue>
// using namespace std;
// struct TreeNode
// {
//     char val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
// };
// TreeNode *createTree(const string &preorder, int &index)
// {
//     if (index >= preorder.size() || preorder[index] == '#')
//     {
//         index++;
//         return nullptr;
//     }
//     TreeNode *node = new TreeNode(preorder[index++]);
//     node->left = createTree(preorder, index);
//     node->right = createTree(preorder, index);
//     return node;
// }

// int d0 = 0, d1 = 0, d2 = 0;
// string s;
// void calculate(TreeNode *root)
// {
//     vector<char> ret;
//     if(root == nullptr)
//         return;
//     if (root->left == nullptr && root->right == nullptr)
//     {
//         d0++;
//         s+=root->val;
//     }
//     if (root->left != nullptr && root->right == nullptr || root->left == nullptr && root->right != nullptr)
//         d1++;
//     if (root->left != nullptr && root->right != nullptr)
//         d2++;
//     calculate(root->left);
//     calculate(root->right);
// }

// int main()
// {
//     string preorder;
//     cin >> preorder;
//     int index = 0;
//     TreeNode *root = createTree(preorder, index);
//     calculate(root);
//     cout << d0 << " " << d1 << " " << d2 << endl;
//     cout << s;
//     return 0;
// }

// #include <iostream>
// #include <stack>
// #include <string>
// #include <vector>
// #include <queue>
// using namespace std;
// struct TreeNode
// {
//     char val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
// };
// TreeNode *createTree(const string &preorder, int &index)
// {
//     if (index >= preorder.size() || preorder[index] == '#')
//     {
//         index++;
//         return nullptr;
//     }
//     TreeNode *node = new TreeNode(preorder[index++]);
//     node->left = createTree(preorder, index);
//     node->right = createTree(preorder, index);
//     return node;
// }

// void preorderTraversal(TreeNode *root)
// {
//     if (root)
//     {
//         cout << root->val;
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);
//     }
// }

// void inorderTraversal(TreeNode *root)
// {
//     if (root)
//     {
//         inorderTraversal(root->left);
//         cout << root->val;
//         inorderTraversal(root->right);
//     }
// }

// void postorderTraversal(TreeNode *root)
// {
//     if (root)
//     {
//         postorderTraversal(root->left);
//         postorderTraversal(root->right);
//         cout << root->val;
//     }
// }
// int levelOrder(TreeNode *root)
// {
//     queue<TreeNode *> q;
//     int high=0;
//     if (root != nullptr)
//         q.push(root);
//     while (!q.empty())
//     {
//         int size = q.size();
//         high++;
//         vector<char> v;
//         while (size--)
//         {
//             TreeNode *front = q.front();
//             q.pop();
//             v.push_back(front->val);
//             if (front->left != nullptr)
//                 q.push(front->left);
//             if (front->right != nullptr)
//                 q.push(front->right);
//         }
//     }
//     return high;
// }
// int main()
// {
//     string preorder;
//     cin >> preorder;
//     int index = 0;
//     TreeNode *root = createTree(preorder, index);
//     int high = levelOrder(root);
//     cout << high << endl;

//     return 0;
// }

// #include <iostream>
// #include <stack>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// struct TreeNode
// {
//     char val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
// };
// TreeNode *createTree(const string &preorder, int &index)
// {
//     if (index >= preorder.size() || preorder[index] == '#')
//     {
//         index++;
//         return nullptr;
//     }
//     TreeNode *node = new TreeNode(preorder[index++]);
//     node->left = createTree(preorder, index);
//     node->right = createTree(preorder, index);
//     return node;
// }

// vector<char> pre(TreeNode *root)
// {
//     vector<char> ret;
//     stack<TreeNode *> st;
//     TreeNode *cur = root;
//     while (cur || !st.empty())
//     {
//         if (cur)
//         {
//             st.push(cur);
//             ret.push_back(cur->val);
//             cur = cur->left;
//         }
//         else
//         {
//             cur = st.top();
//             st.pop();
//             cur = cur->right;
//         }
//     }
//     return ret;
// }

// vector<char> in(TreeNode *root)
// {
//     vector<char> ret;
//     stack<TreeNode *> st;
//     TreeNode *cur = root;
//     while (cur || !st.empty())
//     {
//         if (cur)
//         {
//             st.push(cur);
//             cur = cur->left;
//         }
//         else
//         {
//             cur = st.top();
//             st.pop();
//             ret.push_back(cur->val);
//             cur = cur->right;
//         }
//     }
//     return ret;
// }
// vector<char> post(TreeNode *root)
// {
//     vector<char> ret;
//     stack<TreeNode *> st;
//     TreeNode *cur = root;
//     while (cur || !st.empty())
//     {
//         if (cur)
//         {
//             st.push(cur);
//             ret.push_back(cur->val);
//             cur = cur->right;
//         }
//         else
//         {
//             cur = st.top();
//             st.pop();
//             cur = cur->left;
//         }
//     }
//     reverse(ret.begin(), ret.end());
//     return ret;
// }
// int main()
// {
//     string preorder;
//     cin >> preorder;
//     int index = 0;
//     TreeNode *root = createTree(preorder, index);
//     vector<char> prev = pre(root);
//     for (char c : prev)
//         cout << c;
//     cout << endl;
//     vector<char> inv = in(root);
//     for (char c : inv)
//         cout << c;
//     cout << endl;
//     vector<char> postv = post(root);
//     for (char c : postv)
//         cout << c;
//     cout << endl;
//     return 0;
// }

// #include <iostream>
// #include <stack>
// #include <string>
// #include <vector>
// #include <queue>

// struct TreeNode
// {
//     char val;
//     TreeNode *left;
//     TreeNode *right;
// };
// TreeNode* createTree()
// {
//     TreeNode* root = new TreeNode;
//     char temp;
//     scanf("%c", &temp);
//     if(temp!='#')
//     {
//         root->val = temp;
//         root->left = createTree();
//         root->right = createTree();
//     }
//     else root = nullptr;
//     return root;
// }
// void Inorder(TreeNode* root)
// {
//     if(root==nullptr) return;
//     printf("%c",root->val);
//     Inorder(root->left);
//     Inorder(root->right);
// }
// int main()
// {
//     TreeNode *root;
//     root = createTree();
//     Inorder(root);
//     return 0;
// 
