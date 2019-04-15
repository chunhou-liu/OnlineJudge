#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


void shiftUpper(string &s){
    int n=s.size();
    for(int i=n-1;i>=0;--i){
        if(s[i]>='a' && s[i]<='z')continue;
        for(int j=i+1;j<n && s[j]>='a' && s[j]<='z';++j)swap(s[j], s[j-1]);
    }
}


int main(){
    string s;
    while(cin>>s){
        shiftUpper(s);
        cout << s << endl;
    }
    return 0;
}