#include <iostream>
#include <unordered_map>

using namespace std;

class Node{
public:
    int key;
    Node* left;
    Node* right;
    Node(){}
    Node(int data):
        key(data),
        left(NULL),
        right(NULL)
        {

        }
};

Node* buildTreeUtil(int *A, int *B, int inStartIdx, int inEndIdx, unordered_map<int,int>& mp){
    //Not valid index
    if(inStartIdx > inEndIdx){
        return NULL;
    }
    static int preIdx = 0;
    Node* root = new Node(*(A + preIdx));
    preIdx++;
    //No more children
    if(inStartIdx == inEndIdx){
        return root;
    }
    int inIndex = mp[root->key]; // O(1) lookup
    root->left = buildTreeUtil(A, B, inStartIdx, inIndex -1, mp);
    root->right = buildTreeUtil(A, B, inIndex + 1, inEndIdx, mp);

    return root;
}
//O(N) time | O(N) space
Node* buildTree(int *A, int *B, int size){
    unordered_map<int, int> mp;
    for(int i = 0; i < size; i++){
        mp[*(B+i)] = i;
    }
    return buildTreeUtil(A,B,0,size -1, mp);
}

void postOrder(Node* node){
    if(node == NULL){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->key<<" ";
}


int main(void){
    int n;
    cin>>n;
    int A[n],B[n];

        for(int i = 0; i < n; i++){
            scanf("%d", &A[i]);
        }

        for(int i = 0; i < n; i++){
            scanf("%d", &B[i]);
        }
    Node* res = buildTree(A,B,n);
    postOrder(res);
    return 0;
}

