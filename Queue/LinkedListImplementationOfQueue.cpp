#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL)
    {
    }
};

class Queue{
public:
    Node *front, *rear;
    Queue() : front(NULL), rear(NULL)
    {
    }
    //O(1) time
    void enQueue(int val){
        Node* newNode = new Node(val);
        if(rear == NULL){
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }
    //O(1) time
    void deQueue(){
        if(front == NULL){
            cout<<"Queue Empty"<<endl;
            return;
        }

        Node* temp = front;
        front = temp->next;

        if(front == NULL){
            rear = NULL;
        }

        delete(temp);
    }
};

int main(){
    Queue q;
    q.deQueue();
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.deQueue();
    cout<< "Queue Front : " << q.front->data<<endl;
    cout<< "Queue Back : " << q.rear->data<<endl;
}
