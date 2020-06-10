#include <iostream>

using namespace std;
class linkedlist
{
public:
    class Node
    {
    public:
        int data;
        Node *next = nullptr;

        Node(int data)
        {
            this->data = data;
        }
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    int size_()
    {
        return this->size;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }

    void display()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << "->";
            curr = curr->next;
        }
        cout << endl;
    }

    Node *getNodeAt(int pos) //Will return address so call getAt()
    {
        Node *curr = this->head;
        while (pos--)
        {
            curr = curr->next;
        }
        return curr;
    }

    // ADD functions in linkedlist*************************
    void addFirstNode(Node *node)
    {
        if (this->size == 0)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            node->next = head;
            this->head = node;
        }

        this->size++;
    }
    void addFirst(int data)
    {
        Node *node = new Node(data);
        addFirstNode(node);
    }

    void addLastNode(Node *node)
    {
        if (this->size == 0)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            tail->next = node;
            this->tail = node;
        }
        this->size++;
    }
    void addLast(int data)
    {
        Node *node = new Node(data);
        addLastNode(node);
    }
    void addAtNode(Node *node, int pos)
    {
        if (pos == 0)
        {
            addFirstNode(node);
        }
        else if (pos == size - 1)
        {
            addLastNode(node);
        }
        else
        {
            Node *prev = getNodeAt(pos - 1);
            prev->next = node;
            node->next = prev->next;
        }
        this->size++;
    }

    // Remove Functions####################################################

    int removeFirst()
    {
        if (this->size == 0)
        {
            cout << "EmptyList!!!" << endl;
            return -1;
        }
        Node *rnode = this->head;
        if (this->size == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            this->head = this->head->next;
            rnode->next = nullptr;
        }

        this->size--;
        return rnode->data;
    }

    int removeLast()
    {
        if (this->size == 0)
        {
            cout << "EmptyList!!!" << endl;
            return -1;
        }
        Node *rnode = this->tail;
        if (this->size == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            Node *secondLastnode = getNodeAt(size - 2);
            secondLastnode->next = nullptr;
            this->tail = secondLastnode;
        }
        this->size--;
        return rnode->data;
    }

    int removeAt(int pos)
    {
        if (pos >= this->size || pos < 0)
        {
            cout << "NullpointerException!!" << endl;
            return -1;
        }

        if (pos == 0)
        {
            return removeFirst();
        }
        else if (pos == this->size - 1)
        {
            return removeLast();
        }
        else
        {
            Node *prev = getNodeAt(pos - 1);
            Node *curr = prev->next;
            prev->next = curr->next;
            curr->next = nullptr;
            this->size--;
            return curr->data;
        }
    }

    // Get functions================================
    int getFirst()
    {
        if (this->size == 0)
        {
            cout << "EmpytyList" << endl;
            return -1;
        }
        return this->head->data;
    }

    int getLast()
    {
        if (this->size == 0)
        {
            cout << "EmptyList!!" << endl;
            return -1;
        }
        return this->tail->data;
    }

    int getAt(int pos)
    {
        if (pos >= this->size || pos < 0)
        {
            cout << "NullptrException1!!" << endl;
            return -1;
        }

        return getNodeAt(pos)->data;
    }
};
int main()
{
    linkedlist ll;
    for (int i = 1; i < 10; i++)
    {
        ll.addLast(i * 10);
    }
    ll.display();
    cout << ll.getFirst() << endl;
    cout << ll.getAt(-1) << endl;
    return 0;
}
