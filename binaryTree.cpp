#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *init_tree(int data)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->left = root->right = NULL;
    root->data = data;
    return root;
}

Node *create_node(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->left = node->right = NULL;
    node->data = data;
    return node;
}

void free_tree(Node *root)
{
    Node *tmp = root;
    if (!tmp)
    {
        return;
    }
    free_tree(tmp->left);
    free_tree(tmp->right);
    if (!tmp->left && !tmp->right)
    {
        free(tmp);
        return;
    }
}

int tree_height(Node *root)
{
    if (!root)
        return 0;
    else
    {
        int left_height = tree_height(root->left) + 1;
        int right_height = tree_height(root->right) + 1;
        if (left_height >= right_height)
            return left_height;
        else
            return right_height;
    }
}

void display_tree(Node *root)
{
    Node* tmp = root;
    if (!tmp)
    {
        return;
    }
    cout << tmp->data << endl;
    display_tree(root->left);
    display_tree(root->right);
}

int main()
{

    Node* root = init_tree(10);
    
    root->left = create_node(20);
    root->right = create_node(30);
    root->left->left = create_node(40);
    root->left->right = create_node(50);
    root->right->left = create_node(60);
    root->right->right = create_node(70);

    display_tree(root);

    return 0;
}