#include <bits/stdc++.h>
using namespace std;

class trieNode
{
public:
  char data;
  trieNode *children[26];
  bool isTerminal;

  trieNode(char ch)
  {
    data = ch;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

class trie
{
public:
  trieNode *root;

  trie(char ch)
  {
    root = new trieNode(ch);
  }

  void insertUtil(trieNode *root, string word)
  {
    if (word.length() == 0) /////All words are present
    {
      cout<<"inserted";
      root->isTerminal = true;
      return;
    }

    //***Assumption***:::word in caps
    int index = word[0] - 'A';
    trieNode *child;

    // present
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    // absent
    else
    {
      child = new trieNode(word[0]);
      root->children[index] = child;
    }

    // resursion
    insertUtil(child, word.substr(1));
  }

  void insertWord(string word)
  {
    cout<<"inserted";
    insertUtil(root, word);
    return;
  }

  bool searchUtil(trieNode *root, string word)
  {
    if (word.length() == 0) /// all char present
    {
      return root->isTerminal;
    }
    int index = word[0] - 'A';
    trieNode *child;

    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      return false;
    }

    return searchUtil(child, word.substr(1));
  }
  bool search(string word)
  {
    return searchUtil(root, word);
  }
};

int main()
{

  trie *t = new trie('\0');
  t->insertWord("abcd");
cout<<"check";
  cout << "P or A" << t->search("abcd") << endl;
  cout<<"check";
  return 0;
}