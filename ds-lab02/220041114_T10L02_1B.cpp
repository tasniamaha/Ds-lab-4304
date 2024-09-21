#include<iostream>
using namespace std;
int front=-1,rear=0,m=10000,s=0;

bool isempty(){
    return front==-1 ;
}
void push_front(int ar[],int key){
    if(front==-1){
        front=rear=0;
    }
    else{
        front=(front-1+m)%m;
    }
    ar[front]=key;
    s++;
}
void push_back(int ar[],int key){
    if(front==-1){
        front=rear=0;
    }
    else{
        rear=(rear+1)%m;
    }
    ar[rear]=key;
    s++;
}
void pop_front(int ar[]){
    if(front==rear){
        front=rear=-1;
        
    }
    else{
        front=(front+1)%m;
    }
    s--;
}
void pop_back(int ar[]){
    if(front==rear){
        front=rear=-1;
    }
    else{
        rear=(rear+1)%m;
    }
    s--;
}
int size_deque(){
    return s;
}
void display(int ar[]){
    if(isempty()){
        cout<<"Empty"<<endl;
        return ;
    }
    else{
        int i=front;
        for(int j=0;j<s;j++){
            cout<<ar[i]<<" ";
            i=(i+1)%m;
        }
        cout<<endl;
    }
}
int main(){
    int ar[m];
    while(1){
        int a;
        cin>>a;
        
        if(a==1){
            int b;
            cin>>b;
            push_front(ar,b);
            display(ar);
        }
        else if(a==2){
            int b;
            cin>>b;
            push_back(ar,b);
            display(ar);
        }
        else if(a==3){
            if(isempty()){
                cout<<"Error"<<endl;
                continue;
            }
            else{
                pop_front(ar);
                display(ar);
            }
        }
        else if(a==4){
            if(isempty()){
                cout<<"Error"<<endl;
                continue;
            }
            else{
                pop_back(ar);
                display(ar);
            }
        }
        else if(a==5){
            cout<<size_deque()<<endl;
        }
        else if(a==6){
            break;
        }
    }
}