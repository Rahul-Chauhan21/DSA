#include <iostream>
using namespace std;
class MaxHeap{
    int capacity;
    int heap_size;
    int* arr;

    bool hasLeftChild(int parentIndex){return getLeftChildIndex(parentIndex) < heap_size;}
    bool hasRightChild(int parentIndex){return getRightChildIndex(parentIndex) < heap_size;}
    bool hasParent(int childIndex){return getParentIndex(childIndex) >= 0;}

    int getLeftChildIndex(int index){return 2*index + 1;}
    int getRightChildIndex(int index){return 2*index + 2;}
    int getParentIndex(int index){return (index - 1)/2;}

    int parent(int index){return arr[getParentIndex(index)];}
    int leftChild(int index){return arr[getLeftChildIndex(index)];}
    int rightChild(int index){return arr[getRightChildIndex(index)];}

    void swap(int IndexOne, int IndexTwo){
        int temp = arr[IndexOne];
        arr[IndexOne] = arr[IndexTwo];
        arr[IndexTwo] = temp;
    }

public:
    MaxHeap(){}
    MaxHeap(int n){
        capacity = n;
        heap_size = 0;
        arr = new int(capacity);
    }
    bool ensureCapacity();
    void buildHeap();
    void HeapifyUp();
    void HeapifyDown(int);
    void printHeap(int);
    void insertKey(int);
    void deleteKey();
    void HeapSort();
};

void MaxHeap:: buildHeap(){
    for(int i = 0; i < capacity; i++){
        cin>>arr[i];
        heap_size++;
    }

    for(int i = heap_size/2 - 1; i >= 0; i--){
        HeapifyDown(i);
    }
}
bool MaxHeap:: ensureCapacity(){
    if(heap_size == capacity)
        return true;
    return false;
}
void MaxHeap :: HeapifyDown(int index){
    //help building the heap and also deletion in the heap
    while(hasLeftChild(index)){
        int LargerChildIndex = getLeftChildIndex(index);
        if(hasRightChild(index)&&leftChild(index)<rightChild(index)){
            LargerChildIndex = getRightChildIndex(index);
        }

        if(arr[index] > arr[LargerChildIndex]){
            break;
        }
        else{
            swap(index,LargerChildIndex);
        }
        index = LargerChildIndex;
    }
}

void MaxHeap:: HeapifyUp(){
    int index = heap_size - 1;
    while(hasParent(index)&&parent(index) < arr[index]){
        swap(index,getParentIndex(index));
        index = getParentIndex(index);
    }
}

void MaxHeap:: printHeap(int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}

void MaxHeap :: insertKey(int key){
    //insertion in the heap
    if(ensureCapacity()){
        cout<<"\nOverflow Condition\n";
        return;
    }

    heap_size++;
    int index = heap_size - 1;
    arr[index] = key;

    HeapifyUp();
}

void MaxHeap:: deleteKey(){
    if(heap_size == 0){
        cout<<"\nUnderflow\n";
        return;
    }

    if(heap_size == 1){
        heap_size--;
        cout<<"\nHeap Empty// Extract min function returns INT_MAX";
    }

    arr[0] = arr[heap_size-1];
    heap_size--;

    HeapifyDown(0);
}
//O(nLog n) time | O(1) space
void MaxHeap:: HeapSort(){
    while(heap_size>0){
        int index = 0;
        swap(index,heap_size-1);
        heap_size--;
        HeapifyDown(0);
    }
}
int main(void){
    int n;
    cin>>n;
    MaxHeap h(n);
    h.buildHeap();

    cout<<"Heap is\n";
    h.printHeap(n);

    h.HeapSort();

    cout<<"\nAfter sort\n";
    h.printHeap(n);

return 0;
}
