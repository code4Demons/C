#include<iostream>
#include<climits>
using namespace std;

class Node{
    
    public: 
    int data;
    Node* next;
    Node(){
        
    }
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
class Queue{
    Node *front,*rear;
    public:
    int Size=0;
    Queue(){
        front=rear=NULL;
    }
    
    
    
    bool isempty(){
        if(front==NULL) {
            return true;
        }
        return false;
    }
    
    void enqueue(int d){
        this->Size++;
        Node* t=new Node(d);
        if(front==NULL){
            front=rear=t;
            return;
        }else{
           rear->next=t;
           rear=t;
        }
    }
    
    void dequeue(){
        if(front==NULL){
            cout<<"Queue is empty.\n";
            return;
        }else{
            Node* t=front;
            front=front->next;
            if(front==NULL){
                rear=NULL;
            }
             this->Size--;
            delete t;
        }
    }
    
    int Front(){
        if(front==NULL){
            cout<<"Queue is empty.\n";
            return INT_MIN;
        }else{
            int item=front->data;
            return item;
        }
    }
    
    int Rear(){
        if(front==NULL){
            cout<<"Queue is empty.\n";
            return INT_MIN;
        }else{
            int item=rear->data;
            return item;
        }
    }
    
    void show(){
        if(front==NULL){
            cout<<"Queue is empty.\n";
            return;
        }else{
            Node* t=front;
            while(t!=NULL){
               
                cout<<t->data<<" ";
                t=t->next;
            }
        }
        cout<<endl;
    }
};


int main(){
    int arr[]={6,1,5,7,3,4,0,8};
    Queue* q=new Queue();
    // cout<<q->isempty();
    for(int a:arr){
        q->enqueue(a);
        
    }
    q->show();
    q->dequeue();
    q->show();
    q->enqueue(11);
    q->show();
    cout<<"length of queue is : "<<q->Size;
    return 0;
}



























