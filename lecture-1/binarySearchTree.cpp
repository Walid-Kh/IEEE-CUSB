#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int value;
    Node *left, *right;
};
class BST
{

    Node *root;
    Node *destroyTree(Node *root);
    Node *createNode(int x);
    Node *insert(Node *&root, int x);
    Node *remove(Node *&root, int x);
    const Node *search(const Node *root, int x);

public:
    BST();
    ~BST();
    void insert(int x);
    void remove(int x);
    Node *getRoot();
    void printDFS();
    void printBST();
    const Node *search(int x);
    int height(Node *node);
};

BST::BST()
{
    this->root = nullptr;
}
void BST::insert(int x)
{
    insert(this->root, x);
}
Node *BST::insert(Node *&root, int x)
{
    if (root == nullptr)
    {
        Node *node = createNode(x);
        root = node;
    }
    else if (root->value >= x)
    {
        root->left = insert(root->left, x);
    }
    else if (root->value < x)
    {
        root->right = insert(root->right, x);
    }
    return root;
}
Node *BST::getRoot()
{
    return root;
}
BST::~BST()
{
    destroyTree(root);
}
Node *BST::destroyTree(Node *root)
{
    if (root != nullptr)
    {
        destroyTree(root->left);
        destroyTree(root->right);
    }
    delete root;
}
Node *BST::createNode(int x)
{
    Node *node = new Node();
    node->value = x;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
const Node *BST::search(int x)
{
    return search(this->root, x);
}
const Node *BST::search(const Node *root, int x)
{
    try
    {
        if (root == nullptr)
            return nullptr;
        if (root->value == x)
        {
            const Node *res = root;
            return res;
        }
        else if (x > root->value)
            search(root->right, x);
        else if (x <= root->value)
            search(root->left, x);
    }
    catch (const std::exception &e)
    {
        return NULL;
    }
}
void BST::remove(int x)
{
    remove(this->root, x);
}
Node *BST::remove(Node *&root, int x)
{
    if (root == nullptr)
        return nullptr; // corner case empty tree
    else if (root->value < x)
        root->right = remove(root->right, x);
    else if (root->value > x)
        root->left = remove(root->left, x);
    else
    {
        // NO CHILD
        if (root->left == nullptr and root->right == nullptr) // leaf
        {
            delete root;
            root = nullptr;
        }
        // ONE CHILD
        else if (root->left == nullptr)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // TWO CHILDREN
        else
        {
            Node * temp = root->left; 
            while (temp->right != nullptr)
                temp = temp->right; 
            root->value = temp->value; 
            remove(root->left, temp->value);
        }
        return root; // to reset the parent's pointer
    }
}
int main()
{
    BST *a = new BST;
    a->insert(10);
    a->insert(5);
    a->insert(4);
    a->insert(6);
    a->insert(15);
    a->insert(12);
    a->insert(16);
    a->insert(11);
    a->insert(14);
    a->insert(13);
    a->remove(15);

    return 0;
}