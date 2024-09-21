#include<iostream>
#include<vector>
using namespace std;
int top1=-1,top2=-1,count=0;
vector<int> s1,s2;
void push1(int x){
    if(top1==s1.size()-1){
        cout<<"Overflow"<<endl;
        return ;
    }
    else{
        s1[++top1]=x;
    }
}
void push2(int x){
    if(top2==s2.size()-1){
        cout<<"Overflow"<<endl;
        return ;
    }
    else{
        s2[++top2]=x;
    }
}
void pop1(){
    if(top1==-1){
        cout<<"Underflow"<<endl;
    }
    else{
        int popped=s1[top1];
        top1--;
    }
}
void pop2(){
    if(top2==-1){
        cout<<"Underflow"<<endl;
    }
    else{
        int popped=s2[top2];
        top2--;
    }
}
void enqueue(int x){
    if(top2==s1.size()-1){
        cout<<"Overflow"<<endl;
        return ;
    }
    else{
        push1(x);
        count++;
    }
}
void dequeue(){
    if(top1==-1 && top2==-1){
        cout<<"empty"<<endl;
        return ;
    }
    else{
        if(top2==-1){
            while(top1!=-1){
                push2(s1[top1]);
                pop1();
            }
        }
        if(top2!=-1){
            pop2();
            count--;
        }
    }
}
void display(){
    if(top1==-1 && top2==-1){
        cout<<"Empty"<<endl;
    }
    for(int i=top2;i>=0;i--){
        cout<<s2[i]<<" ";
    }
    for(int i=0;i<=top1;i++){
        cout<<s1[i]<<" ";
    }
    cout<<endl;
}
int size(){
    return count;
}
bool isempty(){
    return (top1==-1 && top2==-1);
}
int main(){
    int n,t;
    cin>>n>>t;
    s1.resize(n);
    s2.resize(n);
    while(t--){
        int a;
        cin>>a;
        if(a==1){
            int b;
            cin>>b;
            if(count>=n){
                cout<<"Size:"<<size()<<" Elements: Overflow!"<<endl;
                continue;
            }
            else{
                enqueue(b);
                cout<<"Size:"<<size()<<" Elements: ";
                display();
            }
        }
        else if(a==2){
            dequeue();
            if(count==0){
                cout<<"Size:0 Elements: Null"<<endl;
                continue;
            }
            else{
                cout<<"Size:"<<size()<<" Elements: ";
                display();
            }
        }
        
    }
}