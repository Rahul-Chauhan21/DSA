#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int key;
    Node* next;
    Node(){}
    Node(int data) : key(data), next(NULL){
    }
};

void printList(Node* head){
    while(head != NULL){
        cout<< head -> key <<" ";
        head = head->next;
    }
    cout<<endl;
}

void detectAndRemove(Node* head){
    if(head == NULL || head->next == NULL){
        return;
    }
    Node* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow -> next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    // if loop present
    if(slow == fast){
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

void appendList(Node ** head, int data){
    Node* temp = new Node(data);
    if(*head==NULL)
    {
        *head=temp;
    }
    else
        {
            Node* p=*head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
        }
}

int main(){
    Node* head = NULL;
    int n = 6;
        for(int i = 1; i <= n; i++){
            appendList(&head, i);
        }
    //create a condition for loop
    //6 points to 3
    head->next->next->next->next->next->next = head->next->next;
    detectAndRemove(head);

    printf("Linked List after removing loop \n");
    printList(head);

return 0;
}
