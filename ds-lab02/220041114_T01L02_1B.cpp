#include<iostream>

using namespace std;
int front=0,rear=0,count=0;
bool isempty(){
    return count==0;
}
bool isfull(int maxq){
    return count==maxq;
}
void enqueue(int x,int ar[],int maxq,int &count){
    if(count==maxq){
        cout<<"Overflow"<<endl;
        return ;
    }
    else{
        ar[rear]=x;
        rear=(rear+1)%maxq;
        count++;
    }
}
void dequeue(int arr[],int maxq,int &count){
    if(count==0){
        cout<<"Underflow"<<endl;
        return ;
    }
    else{
        front=(front+1)%maxq;
        count--;
    }
}
int size(){
    return count;
}
int retfront(int arr[]){
    return arr[front];
}
void display(int ar[],int maxq){
    if(isempty()){
        cout<<"Empty"<<endl;
        return ;
    }
    else{
        int i=front;
        for(int j=0;j<count;j++){
            cout<<ar[i]<<" ";
            i=(i+1)%maxq;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    int q[n];
    while(1){
        int a;
        cin>>a;
        if(a==-1){
            cout<<"Exit"<<endl;
            break;
        }
        switch(a){
            case 1:{
                int b;
                cin>>b;
                if(isfull(n)){
                    cout<<"EnQueue: Overflow"<<endl;
                    continue;
                }
                else{
                    enqueue(b,q,n,count);
                    cout<<"Enqueue: ";
                    display(q,n);
                }
                break;
            }
            case 2:{
                if(isempty()){
                    cout<<"DeQueue: Underflow"<<endl;
                    continue;
                }
                else{
                    dequeue(q,n,count);
                    cout<<"Dequeue: ";
                    display(q,n);
                }
                break;
            }
            case 3:{
                if(isempty()){
                    cout<<"isEmpty: True"<<endl;
                    continue;
                }
                else{
                    cout<<"isEmpty: False"<<endl;
                    continue;
                }
                break;
            }
            case 4:{
                if(isfull(n)){
                    cout<<"isFull: True"<<endl;
                    continue;
                }
                else{
                    cout<<"isFull: False"<<endl;
                    continue;
                }
                break;
            }
            case 5:{
                cout<<"Size: "<<size()<<endl;
                continue;
                break;
            }
            case 6:{
                cout<<"Front: "<<retfront(q)<<endl;
                continue;
                break;
            }
            default:{
                cout<<"Invalid input"<<endl;
                break;
            }
        }
        
    }
}