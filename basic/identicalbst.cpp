#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node *buildbst(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);
    root->left = buildbst(arr, start, mid - 1);
    root->right = buildbst(arr, mid + 1, end);
    return root;
}
void printinoder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printinoder(root->left);
    cout << root->data << " ";
    printinoder(root->right);
}
bool identicalbst(node *root1, node *root2)
{
    if(root1==NULL&&root2==NULL)
        return true;
    if(root1==NULL||root2==NULL)
        return false;
    bool left = identicalbst(root1->left, root2->left);
    bool right = identicalbst(root1->right, root2->right);
    return (root1->data == root2->data) && left && right;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[]={1,2,3,4,5,6,7,8};
    node *root1 = buildbst(arr, 0, 7);
    node *root2 = (buildbst(arr2, 0, 7));
    cout<<identicalbst(root1,root2);
    return 0;
}
