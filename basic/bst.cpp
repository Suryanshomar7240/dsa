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
struct Info
{
    int min;
    int max;
    int size;
    int ans;
    bool isbst;
};
Info largestbst(node *root)
{
    if (root == NULL)
    {
        return {INT_MAX, INT_MIN, 0, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {root->data, root->data, 1, 1, true};
    }
    Info left = largestbst(root->left);
    Info right = largestbst(root->right);
    Info curr;
    curr.size = left.size + right.size + 1;
    curr.min = min(left.min, min(right.min, root->data));
    curr.max = min(left.max, max(right.max, root->data));
    if (left.isbst && right.isbst && root->data > left.max && root->data < right.min)
    {
        curr.ans = curr.size;
        curr.isbst = true;
        return curr;
    }
    else
    {
        curr.ans = max(left.ans, right.ans);
        curr.isbst = false;

        return curr;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    node *root = buildbst(arr, 0, 7);
    // printinoder(root);
    cout << largestbst(root).max;
    return 0;
}
