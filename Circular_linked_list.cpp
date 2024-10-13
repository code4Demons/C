#include<bits/stdc++.h>
using namespace std;
class Node{
    int data;
    Node* next;
    Node* head=nullptr;
    int l=0;
    
    public:
    Node(){
    this->data=0;
    this->next=nullptr;
    }
    Node(int d){
        this->data=d;
        this->next=nullptr;
    }
    
    void insert(int d){
        Node* t=new Node(d);
        if(head==NULL){
            head=t;
        }else{
            Node* temp=head;
            while(temp!=NULL){
                temp=temp->next;
                if(temp->next==head){
                    temp->next=t;
                    break;
                }
            }
        }
        t->next=head;
    }
    
    void show(){
        Node* t=head;
        
        while(t!=NULL){
            cout<<t->data<<" ";
            t=t->next;
            if(t==head)
            {
                // cout<<"reached the last node\n";
                break;
            }
        }
    }
    
    int length(){
        if(head==NULL)
        return l;
        else{
            Node* t=head;
            while(t!=NULL){
                l++;
                if(t->next==head){
                    break;
                }
                t=t->next;
                
            }
            return l;
        }
    }
    
    bool search(int d){
        
        if(head==NULL)
        return false;
        else{
            Node* t=head;
            while(t!=NULL){
                if(t->data==d)
                return true;
                if(t->next==head)
                break;
                
                t=t->next;
            }
        }
        return false;
    }
    
    int index(int d){
        int c=0;
        if(head==NULL)
        return -1;
        
        if(head->data==d)
        return 0;
        else{
            Node* t=head;
            while(t!=NULL){
                if(t->data==d){
                    return c;
                }
                c++;
                if(t->next==head)
                break;
                t=t->next;
            }
            return c;
        }
    }
    
    Node* node(int pos){
        Node * t=head;
        int l=length();
        if(pos<2){
            while(t->next!=head){
                t=t->next;
            }
            return t;
        }else{
            while(pos>2){
                pos--;
                if(t->next==head)
                break;
                t=t->next;
            } 
            return t;
        }
    }
    
    void insertAt(int d,int pos){
        int l=length();
        if(pos%l==0){
            pos=l;
        }else{
            pos=pos%l;
        }
        
        
        
        if(pos==1){
         head->data=d;
        }else{
            Node* t=new Node(d);
             Node* prev = node(pos);
            Node* nextNode = prev->next;
            prev->next = t;  // Insert new node after 'prev'
            t->next = prev->next; 
            // delete nextNode;
        }
       // Link new node to the next one
    }
    
    void Delete(int d){
        Node* t=head;
        if(head->data==d){
            while(t->next!=head){
                t=t->next;
            }
            head=head->next;
            t->next=head;
        }else{
            int idx=index(d);
            Node* prev;
            while(idx>0){
                prev=t;
                idx--;
                t=t->next;
            }
            prev->next=t->next;
        }
        
    }
    
    
};

int main(){
    int arr[]={1,7,9,2,5,8,6};
    Node* obj=new Node();
    for(int a :arr){
        obj->insert(a);
    }
    obj->show();
    cout<<endl;
    // cout<<obj->length();
    // cout<<obj->search(6);
    // cout<<obj->index(5);
    // obj->insertAt(19,1);
    obj->Delete(6);
    obj->show();
    
    
    return 0;
}





