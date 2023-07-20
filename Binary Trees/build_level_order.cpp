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

void levelOrder(node *&root)
{
  queue<node *> q;
  int data;
  cout<<"enter data of root"<<endl;
  cin >> data;
  root = new node(data);
  q.push(root);

  while (!q.empty())
  {
    node *temp = q.front();
    q.pop();
    cout << "Data for left of :" << temp->data << endl;
    int leftD;
    cin >> leftD;

    if (leftD != -1)
    {
      temp->left = new node(leftD);
      q.push(temp->left);
    }

    cout << "Data for right of :" << temp->data << endl;
    int rightD;
    cin >> rightD;

    if (rightD != -1)
    {
      temp->left = new node(rightD);
      q.push(temp->left);
    }
  }
}
int main()
{
  node *root = NULL;

  // create a tree;
  // root = buildTree(root);
  levelOrder(root);
  return 0;
}