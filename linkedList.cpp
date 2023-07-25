#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void addElement(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        // if list is empty:
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        // if list is NOT empty:
        Node *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }

    void addElementAtIndex(int data, int index)
    {
        if (index < 0)
        {
            cout << "can't insert element with negative index" << endl;
            return;
        }
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *tmp = head;
        int count = index;
        while (count > 1 && tmp->next != nullptr)
        {
            tmp = tmp->next;
            count--;
        }

        if (tmp->next == nullptr && count > 1)
        {
            cout << "index out of range" << endl;
            return;
        }

        newNode->next = tmp->next;
        tmp->next = newNode;
    }

    void addElementAtIndex2(int data, int index)
    {
        if (index == 0)
        {
            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *previousNode = getNodeAt(index - 1);

        if (previousNode == nullptr)
        {
            cout << "Index out of range" << endl;
            return;
        }

        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }

    Node *getNodeAt(int index)
    {
        Node *tmp = head;
        int count = index;

        while (count > 0 && tmp != nullptr)
        {
            tmp = tmp->next;
            count--;
        }

        return tmp;
    }

    void removeElement(int data)
    {
        // case 1: remobing the first node (head)
        if (head != nullptr && head->data == data)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
            return;
        }

        // case 2: removing a node that is not the first node
        Node *current = head;
        Node *previous = nullptr;
        while (current != nullptr && current->data != data)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "element with given data {" << data << "} was not found" << endl;
            return;
        }
        // now the current node is the desired one to delete
        previous->next = current->next;
        delete current;
    }

    int getSize()
    {
        int result = 0;
        Node *current = head;
        while (current != nullptr)
        {
            result++;
            current = current->next;
        }
        return result;
    }

    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }

    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        return current;
    }

    void clear()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *tmp = current->next;
            delete current;
            current = tmp;
        }
        head = nullptr;
    }

    int findElement(int data)
    {
        int index = 0;
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                return index;
            }
            index++;
            current = current->next;
        }
        return -1;
    }

    void removeElementAtIndex(int index)
    {
        if (index == 0)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        Node *previous = getNodeAt(index - 1);
        if (previous == nullptr || previous->next == nullptr)
        {
            cout << "No Node found at index {" << index << "}" << endl;
            return;
        }
        Node *tmp = previous->next;
        previous->next = tmp->next;
        delete tmp;
    }

    // void reverse()

    // void getNthFromEnd()

    // void removeDuplicates()

    void display()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data;
            if (tmp->next != nullptr)
            {
                cout << " -> ";
            }
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkedList mylist;
    mylist.addElement(10);
    mylist.addElement(20);
    mylist.addElement(30);
    mylist.addElement(40);
    mylist.addElement(50);
    mylist.addElement(60);
    mylist.addElement(70);

    mylist.display();
    mylist.removeElementAtIndex(2);
    mylist.display();

    return 0;
}