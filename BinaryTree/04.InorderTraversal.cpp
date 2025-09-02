#include<iostream>
#include<vector>
using namespace std;

// structure definition of a node in a binary tree
struct node
{
    int data;
    node *left,*right;
    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Recursive helper function to perform postorder traversal
// Traversal order: Left -> Root -> Right 
void inOrder(node* root, vector<int>& traversalOrder)
{
    if(root)
    {
        inOrder(root -> left,traversalOrder);
        traversalOrder.push_back(root -> data);
        inOrder(root -> right, traversalOrder);
    }
}


// Wrapper function: prepares vector and calls the recursive helper
vector<int> inorder(node* root)
{
    vector<int> traversalOrder;
    inOrder(root,traversalOrder);
    return traversalOrder;
}

int main()
{
    /* 
        creating a sample binary tree:
                    1
                   / \
                  3   5
                 / \
                7   9
    */
    node* root = new node(1);
    root -> left = new node(3);
    root -> right = new node(5);
    root -> left -> left = new node(7);
    root -> left -> right = new node(9);
    
    vector<int> inOrderTraversal = inorder(root);

    for(int it : inOrderTraversal)
        cout << it << " ";
    cout << endl;

    return 0;
}
