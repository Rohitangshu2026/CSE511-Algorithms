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
// Traversal order: Left → Right → Root
void postOrder(node* root, vector<int>& traversalOrder)
{
    if(root == nullptr) return;
    postOrder(root -> left,traversalOrder);
    postOrder(root -> right, traversalOrder);
    traversalOrder.push_back(root -> data);
}


// Wrapper function: prepares vector and calls the recursive helper
vector<int> postorder(node* root)
{
    vector<int> traversalOrder;
    postOrder(root,traversalOrder);
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
    
    vector<int> postOrderTraversal = postorder(root);

    for(int it : postOrderTraversal)
        cout << it << " ";
    cout << endl;

    return 0;
}