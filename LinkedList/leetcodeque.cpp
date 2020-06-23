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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

// leetcode reverse nodes in K groups  25 =======================================LINKED LIST  IMP TECHNIQUE
ListNode *th = nullptr;
ListNode *tt = nullptr;

ListNode *oh = nullptr;
ListNode *ot = nullptr;
void addfirst(ListNode *node)
{
    if (th == nullptr)
    {
        th = node;
        tt = node;
    }
    else
    {
        node->next = th;
        th = node;
    }
}
int length(ListNode *head)
{
    int count = 0;
    while (head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}
ListNode *reverseKGroup(ListNode *head, int k)
{

    if (head == nullptr || head->next == nullptr || k == 0 || k == 1)
        return head;

    int len = length(head);
    if (len < k)
        return head;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        int count = k;

        //Reversing happens of group size of k
        while (count--)
        {
            ListNode *next = curr->next;
            curr->next = nullptr;
            addfirst(curr);
            curr = next;
        }
        /*after reversing len decremented by k to the amount still left to be reversed
            such as len=5,k=2 then len=5-2->3so after that len=3 ,the len=1 it will come out of loop 
            see last check of len < k  */
        len -= k;

        // First if condition will run when first group comes after reversing otherwise else
        if (ot == nullptr)
        {
            oh = th;
            ot = tt;
        }
        else
        {
            ot->next = th;
            ot = tt;
        }

        // Again making temp head and temp tail nullptr as it will use again in reversing next group
        th = nullptr;
        tt = nullptr;

        if (len < k)
        {
            ot->next = curr;
            curr = nullptr;
        }
    }
    return oh;
}

// LeetCode 92 reverse in between m to n   (Passed with 0ms using fast io)
ListNode *th = nullptr;
ListNode *tt = nullptr;
void addfirst(ListNode *node)
{
    if (th == nullptr)
    {
        th = node;
        tt = node;
    }
    else
    {
        node->next = th;
        th = node;
    }
}
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (head == nullptr || head->next == nullptr || m == n)
        return head;

    int idx = 1;
    ListNode *curr = head, *orghead = head, *prev = nullptr;
    while (curr != nullptr)
    {
        while (idx >= m && idx <= n)
        {
            ListNode *next = curr->next;
            curr->next = nullptr;
            addfirst(curr);
            curr = next;
            idx++;
        }

        if (tt != nullptr)
        {
            tt->next = curr;
            if (prev != nullptr)
                prev->next = th;
            else
                orghead = th;

            break;
        }

        prev = curr;
        curr = curr->next;
        idx++;
    }

    return orghead;
}
int main()
{
    return 0;
}
