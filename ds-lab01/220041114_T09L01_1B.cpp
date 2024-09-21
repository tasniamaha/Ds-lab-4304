#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char> stck;
    
    for(int i=0;i<s.length();i++){
        if(stck.empty()||stck.top()!=s[i]){
            stck.push(s[i]);
        }
        else{
            stck.pop();
        }
    }
    if(stck.empty()){
        cout<<"Null"<<endl;
        return 0;
    }
    string ans;
    while(!stck.empty()){
        ans+=stck.top();
        stck.pop();
    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}