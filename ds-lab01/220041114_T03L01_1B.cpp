#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int main(){
    char c;
    int x;
    vector<int> a;
    while(cin>>x){
        if(x<1){
            break;
        }
        a.push_back(x);
        if(cin.peek()=='\n'){
            break;
        }
    }
    int n;
    cin>>n;
    int i=0;
    vector<string> s;
    for(int num=1;num<=n;num++){
        if(i>=a.size()){
            break;
        }
        else if(a[i]==num){
            s.push_back("Push");
            i++;
        }
        else{
            s.push_back("Push");
            s.push_back("Pop");
        }
    }
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}