#include <iostream>
using namespace std;

int main() {
	int T;cin>>T;
    while(T-- >0){
        int n;cin>>n;
        int cur=0, tmp;
        for(int i=0;i<n;++i){
            cin>>tmp;
            cur ^= tmp;
        }
        cout << cur << endl;
    }
	return 0;
}