#include <iostream>
#include <stack>

using namespace std;

class Queue{
stack<int> inStack;
stack<int> outStack;

public:
    // O(1) time
    void enQueue(int val){
        inStack.push(val);
    }
    //O(N) time
    int deQueue(){
        if(outStack.empty()){
            while(!inStack.empty()){
                int insertFromTop = inStack.top();
                inStack.pop();
                outStack.push(insertFromTop);
            }
        }

        if(outStack.empty()){
            cout<<"Cannot dequeue from empty queue"<<endl;
            return INT_MIN;
        }

        int res = outStack.top();
        outStack.pop();
        return res;
    }
};

int main(){
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout<< q.deQueue() << '\n';
    cout<< q.deQueue() << '\n';
    cout<< q.deQueue() << '\n';
    cout<< q.deQueue() << '\n';

return 0;
}
