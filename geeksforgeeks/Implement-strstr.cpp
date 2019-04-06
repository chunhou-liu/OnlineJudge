#include <string>
#include <vector>
using namespace std;

vector<int> build_next(const string &p){
    vector<int> next(p.size(), 0);
    int k=0;
    for(int i=1;i<p.size();++i){
        while(k>0 && p[i]!=p[k])k=next[k-1];
        if(p[i]==p[k])++k;
        next[i]=k;
    }
    return next;
}

int strstr(string s, string x){
     vector<int> next = build_next(x);
     int i=0, j=0;
     for(;i<s.size() && j<x.size();++i){
         while(j>0 && s[i]!=x[j])j=next[j-1];
         if(s[i]==x[j])++j;
     }
     return j==x.size()?i-j:-1;
}