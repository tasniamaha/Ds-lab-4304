#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int postoutput(const string str){
    stack<int> stck;
    for(int i=0;i<str.length();i++){
        if(isdigit(str[i])){
            stck.push(str[i]-'0');
        }
        else{
            int val1=stck.top();
            stck.pop();
            int val2=stck.top();
            stck.pop();
            int ans=0;
            if(str[i]=='+'){
                ans=(val1+val2);
            }
            if(str[i]=='-'){
                ans=(val1-val2);
            }
            if(str[i]=='*'){
                ans=(val1*val2);
            }
            if(str[i]=='/'){
                ans=(val1/val2);
            }
            stck.push(ans);
        }
    }
    return stck.top();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<postoutput(s)*-1<<endl;
    }
}