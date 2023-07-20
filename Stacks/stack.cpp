#include <iostream>
// #include <stack>
using namespace std;

class stack
{
public:
  int *arr;
  int top;
  int size;

  stack(int size)
  {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int a)
  {
    if (size - top > 1)
      top++;
    else
      cout << "Stack Overflow" << endl;
    arr[top] = a;
  }

  void pop()
  {
    if (top >= 0)
      top--;

    else
      cout << "Stack underflow" << endl;
  }

  bool empty()
  {
    if (top == -1)
      return true;

    else
      return false;
  }

  int peak()
  {
    if (top >= 0)
      return arr[top];

    else
      cout << "Stack is empty" << endl;
    return 0;
  }
};
typedef class stack stack;

int main()
{
  stack st(5);
  st.push(60);
  st.push(70);
  st.push(80);
  st.push(100);
  cout<<st.peak();
  st.pop();
  st.pop();
  cout << st.peak();
}
