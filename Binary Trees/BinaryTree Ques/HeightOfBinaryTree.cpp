#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to find the height of a binary tree.
    // O(n) time | O(h) ~O(n) -> in case of skew tree.
    int height(struct Node* node){
        
        if(node == nullptr) return 0;
        
        int left = height(node -> left);
        int right = height(node -> right);
        
        return max(left, right) + 1;
    }
};