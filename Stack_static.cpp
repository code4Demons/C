#include<iostream>
#include<stdio.h>
using namespace std;
static int top=-1;
struct Stack{
    // static top=-1;
    int st[10];
    void push(int d){
        if(top==9&& top!=-1){
            cout<<"Stack is full\n";
            return ;
        }else{
            st[++top]=d;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is empty\n";
            return;
        }else{
            cout<<"Deleted element is "<<st[top--]<<endl;
        }
        // cout<<top<<endl;
    }
    void Top(){
        if(top==-1){
            cout<<"Stack is empty\n";
            return;
        }else{
            cout<<st[top]<<endl;
        }
    }
    void show(){
        int temp=top;
        while(temp>=0){
            cout<<st[temp]<<" ";
            temp--;
        }
        cout<<endl;
    }
    
};
int main(){
    int arr[]={9,0,1,6,2,8,3,4,5,7};
    Stack st;
    for(int a:arr){
        st.push(a);
    }
    
    st.show();
    st.pop();
    
    st.push(10);
    // st.show();
    // for(int i:arr){
    //     st.pop();
    // }
    // st.pop();
    st.show();
    st.push(7);
    st.Top();
    return 0;
}
