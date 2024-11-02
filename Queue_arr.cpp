#include<iostream>
#include <climits>
using namespace std;

class Queue{

    public:
    int front,rear,cap;
    unsigned size;
    int *arr;
};

Queue* createQueue(int cap){
    Queue* queue=new Queue();
    queue->cap=cap;
    queue->size=0;
    queue->front=0;
    queue->rear=cap-1;
    queue->arr= new int[(queue->cap*sizeof(int))];
    return queue;
}

bool isFull(Queue* q){
    if(q->size==q->cap)
    return true;
    return false;
    
}
bool isEmpty(Queue* q){
    if(q->size==0)
    return true;
    
    return false;
}

void Enqueue(Queue* q,int d){
    if(isFull(q)){
        cout<<"Queue is completely filled.\n";
        return;
    }else{
        q->rear=(q->rear+1)%q->cap;
        q->arr[(q->rear)]=d;
        q->size=q->size+1;
    }
}

int Dequeue(Queue* q){
    if(isEmpty(q)){
        cout<<"Queue is empty.\n";
        return INT_MIN;
    }else{
        int item=q->arr[q->front];
        q->front=(q->front+1)%q->cap;
        q->size=q->size-1;
        return item;
    }
}
int front(Queue* q){
    if(q->size==0)
    return INT_MIN;
    else{
        int item=q->arr[q->front];
        return item;
    }
}
int rear(Queue* q){
    if(q->size==0)
    return INT_MIN;
    else{
        int item=q->arr[q->rear];
        return item;
    }
}
void show(Queue* q){
    if(isEmpty(q)){
        cout<<"Empty Queue.\n";
    }else{
        for(int i=q->front;i<=q->rear;i++){
            cout<<q->arr[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Queue* q=createQueue(100);
    int arr[]={8,0,9,7,1,5,3,2,4,6};
    for(int a:arr){
        Enqueue(q,a);
    }
    
    show(q);
    
    // cout<<Dequeue(q);
    cout<<front(q)<<endl;
    cout<<rear(q)<<endl;
    return 0;
}
