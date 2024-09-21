#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    deque<char> d1;
    for(char ch: a){
        d1.push_back(ch);
    }
    if(a==b){
        cout<<"Yes. Rotation not needed."<<endl;
        return 0;
    }
    map<char,int> freq1;
    map<char,int> freq2;
    for(char ch:a){
        freq1[ch]++;
    }
    for(char ch:b){
        freq2[ch]++;
    }
    if(freq1!=freq2){
        cout<<"No"<<endl;
        return 0;
    }
    else{
        int count=0;
        string res;
        while(true){
            char c=d1.back();
            d1.pop_back();
            d1.push_front(c);
            for(char ch:d1){
                res+=ch;
            }
            count++;
            if(res==b){
                break;
            }
        }
        cout<<"Yes. After "<<count<<" clockwise rotations"<<endl;
    }
}