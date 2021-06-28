#include <iostream>
using namespace std;
class tree
{
public:
    int data;
    tree *left;
    tree *right;
};
void insertinbst(tree *&root, int element)
{
    tree *n = new tree;
    n->data = element;
    n->left = NULL;
    n->right = NULL;
    if (root == NULL)
    {
        root = n;
        return;
    }
    else
    {
        if (element > root->data)
        {
            insertinbst(root->right, element);
        }
        else
        {
            insertinbst(root->left, element);
        }
    }
}
int height(tree *root)
{
    if (root == NULL)
        return 0;
    else
    {

        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) + 1;
    }
}
tree *rightrotation(tree *&root)
{
    tree *a = root->left->right;
    tree *newroot = root->left;
    newroot->right = root;
    root->left = a;
    return newroot;
}
tree *leftrotation(tree *&root)
{
    tree* a=root->right->left;
    tree* newroot=root->right;
    newroot->left=root;
    root->right=a;
    return newroot;
}
void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
tree *insert_in_avl(tree *&root, int element)
{
    tree *n = new tree;
    n->data = element;
    n->left = NULL;
    n->right = NULL;
    if (root == NULL)
    {
        root=n;
        return root;
    }
    else
    {
        if (element > root->data)
        {
            root->right = insert_in_avl(root->right, element);
        }
        else if (element < root->data)
        {
            root->left = insert_in_avl(root->left, element);
        }
        else
            return root;
    }

    int height_difference = height(root->left) - height(root->right);
    
    if (height_difference > 1 && element < root->left->data)
        return rightrotation(root);
    if (height_difference < -1 && element > root->right->data)
        return leftrotation(root);
    if (height_difference > 1 && element > root->left->data)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if (height_difference < -1 && element < root->right->data)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
    return root;
}
int main()
{
    int size, element;
    tree *root = NULL;
    cin >> size;
    while (size--)
    {
        cin >> element;
        root=insert_in_avl(root, element);
    }
    inorder(root);
}