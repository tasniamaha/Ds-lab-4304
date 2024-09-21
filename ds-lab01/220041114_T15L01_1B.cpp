#include<iostream>
#include<string>
using namespace std;
int top=-1;
bool isempty(){
    return top==-1;
}
bool isfull(int maxs){
    return top==maxs-1;
}
void push(int x,int max,int ar[]){
    if(isfull(max)){
        cout<<"Overflow !!!"<<endl;
        return ;
    }
    else{
        top++;
        ar[top]=x;
    }
}
void pop(int ar[]){
    if(isempty()){
        cout<<"Underflow !!!"<<endl;
        return ;
    }
    else{
        int popped=ar[top];
        top--;
        
    }
}
int size(){
    return top+1;
}
int topel(int ar[]){
    if(isempty()){
        return 0;
    }
    return ar[top];
}
void printstack(int ar[]){
    for(int i=0;i<top+1;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    char c;
    int ar[n];
    while(1){
        cin>>c;
        if(c=='/'){
            break;
        }
        else if(c=='+'){
            int b;
            cin>>b;
            push(b,n,ar);
            
        }
        else if(c=='-'){
            pop(ar);
        }
        cout<<"Size : "<<size()<<endl;
        cout<<"Stack elements : ";
        printstack(ar);
        cout<<"Top element : "<<topel(ar)<<endl;
        cout<<"isFull : ";
        if(isfull(n)){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
        cout<<"isEmpty : ";
        if(isempty()){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
    }
}