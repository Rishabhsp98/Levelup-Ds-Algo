#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int data)
    {
        this->data = data;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{
    if (idx >= arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
}
void display(Node *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr) ? to_string(node->left->data) : ".");
    str += "<-" + to_string(node->data) + "->";
    str += ((node->right != nullptr) ? to_string(node->right->data) : ".");
    cout << str << endl;

    display(node->left);
    display(node->right);
}

// =============================================
class tpair
{
public:
    Node *node = nullptr;
    bool selfDone = false;
    bool leftDone = false;
    bool rightDone = false;
    tpair(Node *node, bool selfDone, bool leftDone, bool rightDone)
    {
        this->node = node;
        this->selfDone = selfDone;
        this->leftDone = leftDone;
        this->rightDone = rightDone;
    }
};

// We can change it by our convienience by changing order of selfdone
// on top==preorder,middle=inor,last=postorder
void Iterativetraversaloftree(Node *node)
{
    stack<tpair> st;
    st.push(tpair{node, false, false, false});

    while (st.size() != 0)
    {
        if (st.top().leftDone == false)
        {
            st.top().leftDone = true;
            if (st.top().node->left != nullptr)
            {
                st.push(tpair{st.top().node->left, false, false, false});
            }
        }
        else if (st.top().selfDone == false)
        {
            st.top().selfDone = true;
            cout << st.top().node->data << " ";
        }

        else if (st.top().rightDone == false)
        {
            st.top().rightDone = true;
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

Node *Inorderpred(Node *node, Node *curr)
{
    while (node->right != nullptr && node->right != curr)
        node = node->right;
    return node;
}

//Morris ALgorithm
void morrisInorder(Node *node)
{
    Node *curr = node;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *predecessor = Inorderpred(curr->left, curr);
            if (predecessor->right == nullptr)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

void solve()
{
    vector<int> arr{10, 20, 40, -1, -1, 50, 80, -1, -1, 90, -1, -1, 30, 60, 100, -1, -1, -1, 70, 110, -1, -1, 120, -1, -1};
    Node *root = constructTree(arr);
    // display(root);
    Iterativetraversaloftree(root);
    cout << endl;
    morrisInorder(root);
}

int main()
{
    solve();
    return 0;
}