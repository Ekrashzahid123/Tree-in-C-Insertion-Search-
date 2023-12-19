#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
};

Node *Insert(Node *root, int val) {
    Node *newnode = new Node();
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) {
        return newnode;
    }

    Node *curr = root;
    Node *parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (val < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (val < parent->data) {
        parent->left = newnode;
    } else {
        parent->right = newnode;
    }

    return root;
}

Node *Search(Node *root,int key)
{
    Node *curr=root;
    while(curr!=NULL)
    {
        if(key==curr->data)
        {
            return curr;

        }
        else if(key>curr->data)
        {
            curr=curr->right;
        }
        else
        {
            curr=curr->right;
        }
        
    }
    return NULL;
}

void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node *root = NULL;
    root = Insert(root, 7);
    root = Insert(root, 9);
    root = Insert(root, 89);

    cout << "Display" << endl;
    postorder(root);
int search;
cout<<"Enter the ELement to search:"<<endl;
cin>>search;

Node *temp=Search(root,search);
if(temp==NULL)
{
    cout<<"no key found:"<<endl;

}
else

{
    cout<<"Key Found:"<<endl;
}
    return 0;
}
