#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int data)
{
    if(root==NULL)
    {
        return new Node(data);
    }

    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }

    return root;

}

void printInorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

bool search(Node* root, int data)
{
    if(root==NULL) return false;
    if(root->data==data) return true;
    if(data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}

int main()
{
    Node *root = NULL;
    int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(int x : a)
    {
        root = insert(root, x);
    }

    printInorder(root);
    cout << endl;
    bool ans = search(root, 12);

    if(ans==true)
    {
        cout << "Element exists";
    }
    if(ans==false)
    {
        cout << "Element doesn't exist";
    }
    

    return 0;
}