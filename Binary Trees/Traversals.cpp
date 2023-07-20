#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *left;
  node *right;
  node(int d)
  {
    this->data=d;
    this->left=NULL;
    this->right=NULL;
  }
};

node * buildTree(node *root)
{
  
  int data;
  cout<<"Enter data"<<endl;

  cin>>data;
  root = new node(data);

  if(data==-1)
  return NULL;

  cout<<"Building left of "<<data<<endl;
  root->left=buildTree(root->left);

  cout<<"Building right of "<<data<<endl;
  root->right=buildTree(root->right);

  return root;

}

void inorder(node *root)
{
  if(root==NULL)
  return;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);;
}

void preorder(node *root)
{
  if(root==NULL)
  return;

  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)
  return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";

}

int main()
{
  node * root=NULL;

  //create a tree;
  root=buildTree(root);
  cout<<endl;
  inorder(root);
    cout<<endl;
  preorder(root);
      cout<<endl;
  postorder(root);



  return 0;
}