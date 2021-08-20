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
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }
    return 0;
}
node *buildtreepre(int inorder[], int preorder[], int start, int end)
{
    static int idx = 0;
    int curr = preorder[idx++];
    node *n = new node(curr);
    if (start == end)
    {
        return n;
    }
    int pos = search(inorder, start, end, curr);
    // cout<<pos<<" ";
    n->right = buildtreepre(inorder, preorder, start, pos - 1);
    n->left = buildtreepre(inorder, preorder, pos + 1, end);
    return n;
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
void printpreoder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printinoder(root->left);
    printinoder(root->right);
}
void printpostoder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printinoder(root->left);
    printinoder(root->right);
    cout << root->data << " ";
}
node *buildtreepost(int inorder[], int postorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    static int idx = end;
    int curr = postorder[idx--];
    node *n = new node(curr);
    if (start == end)
    {
        return n;
    }
    int pos = search(inorder, start, end, curr);
    n->right = buildtreepost(inorder, postorder, pos + 1, end);
    n->left = buildtreepost(inorder, postorder, start, pos - 1);
    return n;
}
void level(node *root)
{
    queue<node *> q;
    q.push(root);
    node *temp = root;
    while (!q.empty())
    {
        if (q.front() != NULL)
        {
            cout << q.front()->data << " ";
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        else if (q.front() == NULL)
        {
            q.pop();
            q.push(NULL);
        }
    }
}
int noofroots(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return noofroots(root->right) + noofroots(root->left) + 1;
}
int sumofroots(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sumofroots(root->left) + sumofroots(root->right) + root->data;
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max((lh + rh + 1), max(diameter(root->left), diameter(root->right)));
}
int sumreplacement(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    root->data = sumreplacement(root->left) + sumreplacement(root->right) + root->data;
    return root->data;
}
node *lca(node *root, node *p, node *q) //lowest common anseter
{
    if (root == NULL)
    {
        if (find(root, p) && find(root, q))
        {
            node *lc = lca(root->left, p, q);
            node *rc = lca(root->right, p, q);
            if (lc != NULL)
                return lc;
            else if (rc != NULL)
                return rc;
            else
                return root;
        }
        return NULL;
    }
}
bool find(node *root, node *p)
{
    if (root == NULL)
        return false;
    return (root == p) || find(root->left, p) || find(root->right, p);
}
int main()
{
    int inorder[] = {2, 1, 3};
    int postorder[] = {2, 3, 1};
    node *root = buildtreepost(inorder, postorder, 0, 2);
    cout << sumreplacement(root) << endl;
    printpreoder(root);
    return 0;
}