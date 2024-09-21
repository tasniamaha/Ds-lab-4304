#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<char>stck;
        for(int i=0;i<s.length();i++){
            stck.push(s[i]);
        }
        while (!stck.empty())
        {
            cout<<stck.top();
            stck.pop();
        }
        
        cout<<endl;
    }
}