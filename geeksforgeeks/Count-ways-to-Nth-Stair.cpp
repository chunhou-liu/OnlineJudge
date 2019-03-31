#include <iostream>
#include <vector>
using namespace std;


int climbStairs(int n){
    return n/2+1;
}


int main(){
    int T;cin>>T;
    while(T-->0){
        int n;cin>>n;
        cout << climbStairs(n) << endl;
    }
    return 0;
}