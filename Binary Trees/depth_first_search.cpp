#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
  int data;
  node *left;
  node *right;
  node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};
node *buildTree(node *root)
{

  int data;
  cout << "Enter data" << endl;

  cin >> data;
  root = new node(data);

  if (data == -1)
    return NULL;

  cout << "Building left of " << data << endl;
  root->left = buildTree(root->left);

  cout << "Building right of " << data << endl;
  root->right = buildTree(root->right);

  return root;
}
void LevelOrderTraversal(node *root)
{
  queue<node *> q;
  q.push(root);
  q.push(NULL); // seperator for levels

  while (!q.empty())
  {
    node *temp = q.front();
    q.pop();
    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
        q.push(NULL); //
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left != NULL)
      {
        q.push(temp->left);
      }
      if (temp->right != NULL)
      {
        q.push(temp->right);
      }
    }
  }
}

int main()
{
  node *root = NULL;

  // create a tree;
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  root = buildTree(root);
  cout << "Printing level order traversal..." << endl;
  LevelOrderTraversal(root);
  return 0;
}