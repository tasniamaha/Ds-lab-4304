#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<int> stck;
    int num=1;
    vector<int> res;
    for(int i=0;i<n;i++){
        
        if(a[i]==num ){
            res.push_back(a[i]);
            num++;
        }
        else if(a[i]!=num){
            stck.push(a[i]);
        }
        while(!stck.empty() && stck.top()==num){
            res.push_back(stck.top());
            stck.pop();
            num++;
        }
    }
    while(!stck.empty() && stck.top()==num){
        res.push_back(stck.top());
        stck.pop();
        num++;
    }
    
    if(res.size()==n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}