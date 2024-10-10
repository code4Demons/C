#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node (int d){
        this->data=d;
        this->next=NULL;
    }
};

Node* insert(Node* head,int d){
    // cout<<d;
    Node* t=new Node(d);
    if(head==NULL){
        head=t;
    }else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=t;
    }
    
    
    // cout<<temp->data;
    return head;
}
void show(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int findLenght(Node* head){
    Node* t=head;
    int c=0;
    while(t!=NULL){
        t=t->next;
        c++;
    }
    return c;
}

string search(Node* head,int d){
    Node* t=head;
    while(t!=NULL){
        if(t->data==d){
            return "present";
        }
        t=t->next;
    }
    
    return "not present";
    
}

Node* insertAt(Node* head, int d ,int pos){
    Node* t=new Node(d);
    if(pos==0){
        t->next=head;
        head=t;

    }else if(pos>findLenght(head)){
        head=insert(head,d);

    }else{
        Node* prev=NULL;
        Node* temp=head;
        while(pos>0){
            pos--;
            prev=temp;
            temp=temp->next;
        }
        
        prev->next=t;
        t->next=temp;

    }
    
    
    return head;
}

int index(Node* head,int d){
    Node* t=head;
    int c=0;
    bool present=false;
    while(t!=NULL){
        if(t->data==d){
            present=true;
            break;
        }
        c++;
        t=t->next;
    }
    if(present)
        return c;
    else return  c-1;
}

Node* Delete(Node* head, int d){
    if(head==NULL){
        cout<<"No data available";
    }else{
        int pos=index(head,d);
        if(pos==0){
            head=head->next;
        }else{
            Node* t=head;
            Node* prev=NULL;
            Node* next=NULL;
            while(pos>0){
                pos--;
                prev=t;
                t=t->next;
                next=t->next;    
            }
            prev->next=next;
        }
        
    }
     return head;
}


int main(){
  
  int arr[]={6,2,7,4,5};

  
  Node* head=NULL;
    for(auto a: arr){
    //   insertion
    head=insert(head,a);
    
  }
//   cout<<head->data;
  
// Traversal
//show(head);

// length
// cout<<"lenght is : "<<findLenght(head);
  

//searching
// cout<<"Given node is " <<search(head,7);

// Insert at position
cout<<"\nBefore : ";
show(head);


// head=insertAt(head,7,8);
// Delete
head=Delete(head,6);
cout<<"\nAfter : ";
show(head);




  
  
    
    
    return 0;
}
