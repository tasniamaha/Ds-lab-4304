#include<iostream>
#include<string>
using namespace std;
int peak=-1;

bool isEmpty(){
    return peak==-1;
}

bool isFull(int max){
    return peak==max;
}
void push(int x,int max,int ar[]){
    if(isFull(max)){
        cout<<"Overflow";
        return ;
    }
    else{
        peak++;
        ar[peak]=x;
        
    }
}
void pop(int ar[]){
    if(isEmpty()){
        cout<<"Underflow";
        
    }
    else{
        int popped=ar[peak];
        peak--;
        
    }
}
int size(){
    return peak+1;
}
int top(int arr[]){
    return arr[peak];
}
void print(int arr[]){
    
    for(int i=0;i<peak+1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int max;
    cin>>max;
    int arr[max];
    while(true){
        int a,b;
        cin>>a;
        if(a==-1){
            break;
        }
        if(a==3){
            if(isEmpty()){
                cout<<"True"<<endl;
                continue;
            }
            else{
                cout<<"False"<<endl;
                continue;
            }

        }
        if(a==4){
            if(isFull(max)){
                cout<<"True"<<endl;
                continue;
            }
            else{
                cout<<"False"<<endl;
                continue;
            }
        }
        if(a==2){
            pop(arr);
            print(arr);
        }
        
        if(a==1){
            cin>>b;
            push(b,max,arr);
            if(isFull(max)){
                cout<<"Overflow"<<endl;
                continue;
            }
            else{
                
                print(arr);
            }
            
        }
        else if(a==5){
            cout<<size()<<endl;
        }
        else if(a==6){
            cout<<top(arr)<<endl;
        }
    }
}