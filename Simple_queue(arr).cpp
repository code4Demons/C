#include<iostream>
using namespace std;

class Queue{
    int arr[10];
    int front,rear;
    int cap;
    public:
    Queue(int s){
        cap=s;
        front=rear=-1;
    }
    
    bool isFull(){
        if(rear==Size()){
            return true;
        }
        return false;
    }
    int Size(){
        if(rear==-1)
        return 0;
        
        return rear+1;
    }
    
    bool isEmpty(){
        if(rear==-1){
            return true;
        }
        return false;
    }
    
    void enqueue(int d){
        if(Size()==rear)
        {
            cout<<"Queue is full/overflow\n";
            return;
        }else{
            if(rear==-1){
                (front)++;
                // rear++;
            }
            arr[++(rear)]=d;
        }
    }
    
    void dequeue(){
        if(front==-1){
            cout<<"Queue is empty/underflow\n";
        return;
        }else{
            (front)++;
        }
    }
    
    void Show(){
        if(rear==-1){
            cout<<"Queue is empty\n";
            return;
        }else{
            for(int i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
            
        }
        cout<<endl;
    }
};

int main(){
    int arr[]={0,5,8,2,9,3,6,1};
    Queue q(sizeof(arr)/sizeof(arr[0]));
    cout<<q.isFull()<<endl;
    cout<<q.isEmpty()<<endl;
    for(int a:arr){
        q.enqueue(a);
    }
    q.Show();
    cout<<q.isEmpty()<<endl;
    q.dequeue();
    q.Show();
    cout<<q.isFull()<<endl;
    return 0;
}

