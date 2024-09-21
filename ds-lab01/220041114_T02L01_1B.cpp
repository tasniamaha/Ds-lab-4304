#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
bool checkoptag(const string line){
    return line[1]!='/';
}
string extracttag(const string tag){
    string s;
    if(checkoptag(tag)){
        s=tag.substr(1,tag.size()-2);
    }
    else{
        s=tag.substr(2,tag.size()-3);
    }
    return s;
}
string chck(vector<string>& html,int n){
    stack <string> stck;
    for(int i=0;i<n;i++){
        string l=html[i];
        int pos=0;
        while((pos=l.find('<',pos))!=string::npos){
            int endpos=l.find('>',pos);
            if(endpos==string::npos){
                return "Error at line "+to_string(i+1);
            }
            string tag=l.substr(pos,endpos-pos+1);
            string tgname=extracttag(tag);
            if(checkoptag(tag)){
                stck.push(tgname);
            }
            else if(!stck.empty() && stck.top()==tgname){
                stck.pop();
            }
            else{
                return "Error at line "+to_string(i+1);
            }
            pos=endpos+1;
        }
    }
    if(!stck.empty()){
        return "Error at line "+to_string(n);
    }
    return "No error";
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<string> html;
    string s;
    while(getline(cin,s)){
        html.push_back(s);
        if(s=="-1"){
            break;
        }
    }
    string ans=chck(html,n);
    cout<<ans<<endl;
}