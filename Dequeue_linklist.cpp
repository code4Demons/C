#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    Node* prev;
    Node* front;
    Node* rear;
    public:
    int l=0;
    Node(){
        
    }
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    
    void insertAtFront(int d){
        Node* t=new Node(d);
        if(t==NULL){
            cout<<"Not created\n";
            return;
        }
        if(front==NULL){
            front=rear=t;
        }else{
            t->next=front;
            front->prev=t;
            front=t;
        }
    }
        void insertAtRear(int d){
        Node* t=new Node(d);
        if(t==NULL){
            cout<<"Not created\n";
            return;
        }
        if(front==NULL){
            front=rear=t;
        }else{
            rear->next=t;
            t->prev=rear;
            rear=t;
        }
    }
    
    void deleteAtFront(){
        if(rear==NULL){
            cout<<"Empty.\n";
            return;
        }else{
            Node* t=front;
            front=front->next;
            front->prev=NULL;
            free(t);
            this->l--;
        }
    }
        void deleteAtRear(){
        if(rear==NULL){
            cout<<"Empty.\n";
            return;
        }else{
            Node* t=rear;
            rear=rear->prev;
            rear->next=NULL;
            free(t);
            this->l--;
        }
    }
    bool isempty(){
        if(this->l==0)
        return true;
        
        return false;
    }
    void erase(){
        if(front==NULL)
        {
            cout<<"Already empty.\n";
            return;
        }else{
            Node* t=front;
            while(t!=NULL){
                Node* temp=t;
                t=t->next;
                free(temp);
            }
            front=rear=NULL;
            
        }
        cout<<"All data erased.\n";
    }
    
    void show(){
        if(front==NULL){
            cout<<"Empty Queue.\n";
            return;
        }else{
            Node* t=front;
            while(t!=NULL){
                cout<<t->data<<" ";
                t=t->next;
                this->l++;
            }
        }
        cout<<endl;
    }
    int size(){
        return this->l;
    }
};

int main(){
    int arr[]={3,7,4,2,0,8};
    Node* obj=new Node();
    for(int a:arr){
        // obj->insertAtFront(a);
        obj->insertAtRear(a);
    }
    obj->show();
    cout<<"length: "<<obj->l<<"\n";
    obj->deleteAtFront();
    obj->deleteAtRear();
    obj->show();
    cout<<obj->isempty()<<"\n";
    cout<<"Size: "<<obj->size()<<"\n";
    obj->erase();
    obj->show();
    return 0;
}


