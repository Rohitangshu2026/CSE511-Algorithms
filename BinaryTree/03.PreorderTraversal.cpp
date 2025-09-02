#include<iostream>
#include<vector>
using namespace std;

struct node 
{
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// recursive helper function to perform preorder traversal
void preOrder(node* root, vector<int>& traversalOrder)
{
    if(root == nullptr)
        return;
    traversalOrder.push_back(root -> data);
    preOrder(root -> left,traversalOrder);
    preOrder(root -> right,traversalOrder);
}

// wrapper function around preorder traversal
// creates a vector and deals with the travel sequence
vector<int> preorder(node* root)
{
    vector<int> traversalOrder;
    preOrder(root,traversalOrder);
    return traversalOrder;
}

int main()
{
    /*
        creating a sample binary tree:
                    1
                   / \
                  2   3
                 / \
                4   5
    */

    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);

    vector<int> preorderTraversal = preorder(root);
    for(int it : preorderTraversal)
        cout << it << " ";
    cout << endl;

    return 0;

}
