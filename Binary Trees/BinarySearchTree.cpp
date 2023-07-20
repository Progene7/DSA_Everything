#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    this->right = NULL;
    this->left = NULL;
  }
};
void LevelOrderTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL); // seperator for levels

  while (!q.empty())
  {
    Node *temp = q.front();
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
void InsertintoBST(Node *root, int data)
{
  if (root == NULL)
  {
    root = new Node(data);
    return;
  }
  if (data > root->data)
  {
    InsertintoBST(root->right, data);
  }
  else
    InsertintoBST(root->left, data);

    return;
}
void takeInput(Node *root)
{
  int data;
  cin >> data;
  while (data != -1)
  {
    InsertintoBST(root, data);
    cin >> data;
  }
  return;
}
int main()
{
  Node *root = NULL;
  cout << "Enter data" << endl;

  takeInput(root);

  cout << "printing BST" << endl;
  LevelOrderTraversal(root);
  return 0;
}