#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// leetcode 94 ,144,145  passed 4ms,4ms,0ms(just change the order of selfdone) According to LNR,NLR,LRN
class tpair
{
public:
    TreeNode *node = nullptr;
    bool selfdone = false;
    bool leftdone = false;
    bool rightdone = false;
    tpair(TreeNode *node, bool selfdone, bool leftdone, bool rightdone)
    {
        this->node = node;
        this->selfdone = selfdone;
        this->leftdone = leftdone;
        this->rightdone = rightdone;
    }
};
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<tpair> st;
    st.push(tpair{root, false, false, false});

    while (st.size() != 0)
    {

        if (st.top().leftdone == false)
        {
            st.top().leftdone = true;
            if (st.top().node->left != nullptr)
            {
                st.push(tpair{st.top().node->left, false, false, false});
            }
        }
        else if (st.top().selfdone == false)
        {
            st.top().selfdone = true;
            ans.push_back(st.top().node->val);
        }
        else if (st.top().rightdone == false)
        {
            st.top().rightdone = true;
            if (st.top().node->right != nullptr)
            {
                st.push(tpair{st.top().node->right, false, false, false});
            }
        }
        else
        {
            st.pop();
        }
    }
}
// leetcode 106 ================BST from inorder and postorder

TreeNode *constructTree(vector<int> &post, int psi, int pei, vector<int> &in, int isi, int iei)
{
    if (psi > pei || isi > iei)
        return nullptr;

    TreeNode *node = new TreeNode(post[pei]);
    int idx = isi;
    while (in[idx] != post[pei])
        idx++;
    int tnel = idx - isi;
    node->left = constructTree(post, psi, psi + tnel - 1, in, isi, idx - 1);
    node->right = constructTree(post, psi + tnel, pei - 1, in, idx + 1, iei);

    return node;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return constructTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
}

// leetcode 889 Medium ==================BST from pre and post

TreeNode *constuctTreePrePost(vector<int> &pre, int psi, int pei, vector<int> &post, int ppsi, int ppei)
{
    if (psi > pei || ppsi > ppei)
        return nullptr;

    if (psi == pei)
        return new TreeNode(pre[psi]);
    TreeNode *node = new TreeNode(pre[psi]);
    int idx = 0;
    while (pre[psi + 1] != post[idx])
        idx++;

    int tnel = idx - ppsi + 1;
    node->left = constuctTreePrePost(pre, psi + 1, psi + tnel, post, ppsi, idx);
    node->right = constuctTreePrePost(pre, psi + tnel + 1, pei, post, idx + 1, ppei - 1);

    return node;
}
TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
{
    return constuctTreePrePost(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
}

// leetcode 105 ===================== BST from Inorder and preorder

TreeNode *constructTree(vector<int> &pre, int psi, int pei, vector<int> &in, int isi, int iei)
{
    if (psi > pei || isi > iei)
        return nullptr;

    TreeNode *node = new TreeNode(pre[psi]);
    int idx = isi;
    while (in[idx] != pre[psi])
        idx++;

    int tnel = idx - isi;

    node->left = constructTree(pre, psi + 1, psi + tnel, in, isi, idx - 1);
    node->right = constructTree(pre, psi + tnel + 1, pei, in, idx + 1, iei);

    return node;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int psi = 0, pei = preorder.size() - 1;
    int isi = 0, iei = inorder.size() - 1;
    return constructTree(preorder, psi, pei, inorder, isi, iei);
}

int main()
{
    return 0;
}
