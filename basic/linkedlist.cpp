#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertatail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertathead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
    }
    return false;
}
void del(node *&head, int key)
{
    if (head == NULL)
    {
        return;
    }
    if (head->data == key)
    {
        if (head->next == NULL)
        {
            head = NULL;
            return;
        }
        else
        {
            head = head->next;
            return;
        }
    }
    node *temp = head;
    while (temp->next->data != key && temp->next != NULL)
    {
        temp = temp->next;
    }
    node *todel = temp->next;
    temp->next = temp->next->next;
    delete todel;
}
void makecycle(node *&head, int index)
{
    node *temp = head;
    int count = 0;
    while (temp->next != NULL && count++ < index)
    {
        temp = temp->next;
    }
    node *n = temp;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
int Detectcycle(node *head)
{
    node *fast = head;
    node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return 1;
        }
    }
    return 0;
}
node *reverse(node *head)
{
    node *previous = NULL;
    node *curr = head;
    node *nextptr;
    while (curr != NULL)
    {
        nextptr = curr->next;
        curr->next = previous;
        previous = curr;
        curr = nextptr;
    }
    return previous;
}
node *recreverse(node *&head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }
    node *newunit = recreverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newunit;
}
node *reversek(node *&head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    int count = 0;

    node *previous = NULL;
    node *curr = head;
    node *nextptr;
    while (curr != NULL && count < k)
    {
        nextptr = curr->next;
        curr->next = previous;
        previous = curr;
        curr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reversek(nextptr, k);
    }
    return previous;
}
void removecycle(node *&head)
{
    node *fast = head;
    node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
        fast = head;
        while (fast->next != slow->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = NULL;
    }
}
void appendk(node *&head, int k)
{
    node *temp = head;
    int count = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    k = k % count;
    temp->next = head;
    temp = head;
    for (int i = 1; i < count - k; i++)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
}
node *mergenode(node *head1, node *head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *dummy = new node(-1);
    node *ptr3 = dummy;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data > ptr2->data)
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        else
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        ptr3 = ptr3->next;
    }
    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
     while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr1->next;
        ptr2 = ptr3->next;
    }
    return dummy->next;
}
int main()
{
    // node *head = NULL;
    // insertatail(head, 1);
    // insertatail(head, 2);
    // insertatail(head, 3);
    // insertathead(head, 4);
    // insertatail(head, 5);
    // insertathead(head, 6);
    // display(head);
    // appendk(head, 3);
    // display(head);
    //head= recreverse(head);
    // display(head);
    //head = recreverse(head);
    //display(head);
    // head=reversek(head,2);
    //   display(head);
    node *head1 = NULL;
    node *head2 = NULL;
    insertatail(head1, 1);
    insertatail(head1, 3);
    insertatail(head1, 5);
    insertatail(head2, 2);
    insertatail(head2, 4);
    insertatail(head2, 6);
    display(head1);
    display(head2);
    node *merge = mergenode(head2, head1);
    display(merge);
    return 0;
}