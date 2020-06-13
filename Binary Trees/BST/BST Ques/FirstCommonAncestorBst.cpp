//O(N) time O(N) space
#include <iostream>
/*
Test case
// 5
// 5 3 2 4 6
// 2 5

o/p: - 1
*/
using namespace std;

class Node{
public:
    int key;
    Node* left;
    Node* right;
    Node(){}
    Node(int data): //member initializer list
        key(data),
        left(NULL),
        right(NULL)
        {

        }
};

class TreeNode{
public:
    Node* root;
    TreeNode(){
        root == NULL;
    }
    Node* Construct(Node* node,int data){
        if(node==NULL){
            Node* temp = new Node(data);
            return temp;
        }

        if(data < node->key){
            node->left = Construct(node->left,data);
        }
        else if(data > node->key){
            node->right = Construct(node->right,data);
        }
        else{
            return node;
        }
        return node;
    }

    void fca(int a,int b){
        Node* t = fcaUtil(this->root,NULL,a,b);
        int res = t!=NULL ? t->key:-1;
        cout<<res;
    }

    Node* fcaUtil(Node* node, Node* prev,int a,int b){

        if(node == NULL)
            return NULL;

        if(node->key > a && node->key > b){
            prev = node;
            return fcaUtil(node->left,prev,a,b);
        }
        else if(node->key < a && node->key < b){
            prev = node;
            return fcaUtil(node->right,prev,a,b);
        }
        else if(node->key == a || node->key == b)
        {
            return prev;
        }

        return node;
    }


};

int main(){
    TreeNode* b = new TreeNode();

    int n;
    cin>>n;
        for(int i = 0; i < n; i++){
            int num;
            cin>>num;
            b->root = b->Construct(b->root,num);
        }
    int a,c;
    cin>>a>>c;
    b->fca(a,c);
    return 0;
}
