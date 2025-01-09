#include <iostream>
#include<vector>
using namespace std;

vector<string>ByteStuff(vector<string>s,string flag,string ESC){
vector<string>stuffedString;
for(auto& byte: s){
    if(byte==flag || byte == ESC){
        stuffedString.push_back(ESC);
    }
    stuffedString.push_back(byte);
}
return stuffedString;
}
int main()
{
    vector<string>s;
    string v;
    while(cin>>v && v!="end")
    {
        s.push_back(v);
    }
    string flag = "flag";
    string ESC = "ESC";
  vector<string>sd=  ByteStuff(s,flag,ESC);
    for(auto it:sd){
        cout<<it<<" ";
    }
    return 0;
}