#include<iostream>
using namespace std;

class Stack{
    int data;
    Stack* prev;
    Stack* head=NULL;
    Stack* tail=NULL;
    public:
    Stack(){
        
    }
    Stack(int d){
        this->data=d;
        this->prev=NULL;
    }
    void push(int d){
        Stack* t=new Stack(d);
        if(head==NULL){
            head=tail=t;
        }else{
            t->prev=tail;
            tail=t;
        }
    }
    void pop(){
        if(head==NULL){
            cout<<"Stack is empty\n";
            return;
        }else{
            Stack* st=tail;
            if(tail==head){
                tail=tail->prev;
                head=NULL;
            }else{
                tail=tail->prev;
            }
            
            free(st);
        }
    }
    void show(){
        if(head==NULL){
            cout<<"Stack is empty\n";
            return;
        }else{
            Stack* t=tail;
            while(t!=NULL){
                cout<<t->data<<" ";
                t=t->prev;
            };
            cout<<endl;
        }
    }
    
    void top(){
        if(head==NULL){
            cout<<"Stack is empty\n";
            return;
        }else{
            cout<<tail->data<<endl;
        }
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }
};

int main(){
    int arr[]={9,0,1,6,2,8,3,4,5,7};
    Stack* st=new Stack();
    for(int a:arr){
        st->push(a);
    }
    st->show();
    st->push(11);
    st->show();
    st->top();
    st->pop();
    st->show();
    // for(int i: arr){
    //     st->pop();
    // }
    // st->pop();
    cout<<st->isEmpty();
    
    
    
    
    return 0;
}
