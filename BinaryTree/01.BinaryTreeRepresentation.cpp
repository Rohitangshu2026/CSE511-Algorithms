#include<iostream>
using namespace std;

// structure definition of a node in a binary tree
struct node
{
    int data;       // stores data value
    node* left;     // stores pointer to left child
    node* right;    // stores pointer to right child

    // initialize the node with a value
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int main()
{   
    // creating root to the binary tree
    node* root = new node(1);
    /*
        creating the binary tree:
                1
               / \
              2   3
               \
                5
    */
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> right = new node(5);

    return 0;
}
