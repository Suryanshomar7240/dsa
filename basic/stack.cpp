#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int key)
    {
        data = key;
        next = NULL;
    }
};
class stack
{
public:
    node *Top;
    stack()
    {
        Top = NULL;
    }
    void push(int key)
    {
        node *n = new node(key);
        if (Top == NULL)
        {
            Top = n;
            Top->next = NULL;
            return;
        }
        n->next = Top;
        Top = n;
    }
    int top()
    {
        if (Top == NULL)
        {
            return -1;
        }
        else
        {

            return Top->data;
        }
    }
    void pop()
    {
        if (Top == NULL)
        {
            return;
        }
        node *todel = Top;
        if (Top->next == NULL)
        {
            Top = NULL;
        }
        else
        {
            Top = Top->next;
        }
        delete todel;
    }
};
int main()
{
    stack st;
    st.push(4);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    return 0;
}