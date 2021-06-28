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
class queue
{
    node* front;
    node* rear;
public:
    queue()
    {
        front= NULL;
        rear=NULL;
    }
    void push(int key)
    {
        node *n = new node(key);
        if (front== NULL)
        {
            front=n;
            rear=n;
            return;
        }
        rear->next=n;
        rear=n;
    }
    int Front()
    {
        if (front == NULL)
        {
          return -1;
        }
        else
        {

            return front->data;
        }
    }
    void pop()
    {
        if (front == NULL)
        {
            return;
        }
        node *todel =front;
        if (front->next == NULL)
        {
            front = NULL;
            rear=NULL;
        }
        else
        {
            front =front->next;
        }
        delete todel;
    }
};
int main()
{
    queue st;
    st.push(4);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Front() << " ";
    st.pop();
    cout << st.Front() << " ";
    st.pop();
    cout << st.Front() << " ";
    st.pop();
    cout << st.Front() << " ";
    st.pop();
    return 0;
}