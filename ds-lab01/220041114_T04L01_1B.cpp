#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int main(){
    int t;
    vector<int> a;
    while(1){
        cin>>t;
        if(t==-1){
            break;
        }
        a.push_back(t);
        
    }
    stack<int> stck;
    vector<int> res(a.size(),-1);
    stck.push(a[0]);
    for(int i=0;i<a.size();i++){
        while(!stck.empty() && a[stck.top()]<a[i]){
            res[stck.top()]=a[i];
            stck.pop();
        }
        stck.push(i);
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}