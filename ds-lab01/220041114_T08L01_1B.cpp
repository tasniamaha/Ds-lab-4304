#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
string chckbrack(vector<string> &code,int n){
    stack<char> stck;
    for(int i=0;i<n;i++){
        string s=code[i];
        for(int j=0;j<s.length();j++){
            if(s[j]=='(' || s[j]=='{' || s[j]=='['){
                stck.push(s[j]);
            }
            else if(s[j]==')' || s[j]=='}' || s[j]==']'){
                if(stck.empty()){
                    return "Missing Parentheses";
                }
                char t=stck.top();
                
                if((s[j]==')' && t!='(')||(s[j]=='}' && t!='{')||(s[j]==']' && t!='[')){
                    return "Improper parenthesis";
                }
                stck.pop();
            }
        }
        
    }
    if(!stck.empty()){
        return "Missing Parentheses";
    }
    else{
        return "No Error";
    }
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<string> code(n);
    string s;
    for(int i=0;i<n;i++){
        getline(cin,s);
        code[i]=s;
    }
    cout<<chckbrack(code,n)<<endl;
}