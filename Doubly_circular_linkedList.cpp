#include<bits/stdc++.h>
using namespace std;


class Node{
    int data;
    Node* next;
    Node* prev;
    public:
    Node(){
        
    }
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    
    Node* insertAtBeg(Node* head,int d){
        Node* t=new Node(d);
        if(head==NULL){
            t->next=t->prev=t;
            head=t;
        }else{
            Node* last=head->prev;
            t->next=head;
            t->prev=last;
            head->prev=t;
            last->next=t;
            head=t;
        }
        return head;
    }
    Node* insertAtEnd(Node* head,int d){
        Node* t=new Node(d);
        if(head==NULL){
            t->next=t->prev=t;
            head=t;
        }else{
            Node* last=head->prev;
            t->prev=last;
            t->next=head;
            last->next=t;
            head->prev=t;
        }
        return head;
    }
    
    void Show(Node* head){
        if(head==NULL){
            cout<<"Empty list";
            return;
        }else{
            Node* temp=head;
            do{
                cout<<temp->data<<" ";
                temp=temp->next;
            }while(temp!=head);
        }
    }
    
    int Index(Node* head,int d){
        if(head==NULL){
            return -1;
        }else{
            int c=0;
            Node* t=head;
            do{
                if(t->data==d){
                    return c;
                }
                c++;
                t=t->next;
            }while(t!=head);
        }
        return -1;
    }
    void deleteAtBeg(Node** head){
        Node* temp=*head;
        Node* last=temp->prev;
        if (*head==NULL){
            return;
        }else if(temp==last){
            *head=NULL;
            free(temp);
        }
        else{
            *head=temp->next;
            last->next=*head;
            (*head)->prev=last;
            free(temp);
            
        }
    }
    
    void deleteAtPos(Node** head,int pos){
        
    }
};
int main(){
    int arr[]={9,0,4,1,7,2,6,3};
    Node* obj=new Node();
    Node* head=NULL;
    for(int a:arr){
        // head=obj->insertAtBeg(head,a);
        head=obj->insertAtEnd(head,a);
    }
    
    obj->Show(head);
    cout<<endl;
    obj->deleteAtBeg(&head);
    obj->Show(head);
    
    // Search & index
    // cout<<"\nGiven element is found at:"<<obj->Index(head,3); 
    
    return 0;
}
