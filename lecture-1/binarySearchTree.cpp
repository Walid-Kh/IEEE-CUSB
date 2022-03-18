#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
using namespace std;
struct Node
{
  int value;
  Node *left, *right;
};
class BST
{
  // private methods and attributes

  Node *root;

  void destroyTree(Node *root)
  {
    if (root)
    {
      destroyTree(root->left);
      destroyTree(root->right);
      root->left = nullptr;
      root->right = nullptr;
      delete root; 
    }
  }

  Node *createNode(int x)
  {
    Node *node = new Node();
    node->value = x;
    node->left = nullptr;
    node->right = nullptr;
    return node;
  }

  Node *insert(Node *&root, int x)
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

  Node *remove(Node *&root, int x)
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
        Node *temp = root->left;
        while (temp->right != nullptr)
          temp = temp->right;
        root->value = temp->value;
        remove(root->left, temp->value);
      }
    }
    return root; // to reset the parent's pointer
  }
  Node *search(Node *root, int x)
  {
    // try and catch blocks in case the value isn't found
    try
    {
      if (root == nullptr)
        return nullptr;
      if (root->value == x)
      {
        return root;
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

public:
  BST()
  {
    this->root = nullptr;
  }
  ~BST()
  {
    destroyTree(root);
  }
  void insert(int x)
  {
    insert(this->root, x);
  }
  void remove(int x)
  {
    remove(this->root, x);
  }
  Node *getRoot()
  {
    return root;
  }
  void printDFS();
  Node *search(int x)
  {
    return search(this->root, x);
  }
  int height(Node *node);
};

int main()
{
  //remember to debug the code to show its validity
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
  a->remove(12);
  delete a;
  set<int> x;
  return 0;
}