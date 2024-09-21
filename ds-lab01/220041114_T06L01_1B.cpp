#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
bool checkbrack(const string s){
    stack <char> stck;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stck.push(s[i]);
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(stck.empty()){
                return false;
            }
            char t=stck.top();
            stck.pop();
            if(s[i]==')' && t!='(' || s[i]=='}' && t!='{' || s[i]==']' && t!='[' ){
                return false;
            }
        }
    }
    return stck.empty();
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        if(checkbrack(s)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

}