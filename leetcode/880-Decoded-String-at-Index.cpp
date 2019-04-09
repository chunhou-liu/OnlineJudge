#include <string>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string tape;
        for(int i=0;i<S.size() && tape.size()<K;++i){
            if(!isdigit(S[i]))tape.push_back(S[i]);
            else{
                int repeat = S[i] - '0';
                string cur = tape;
                for(int repeat=S[i]-'0';repeat>1 && tape.size()<K;--repeat)tape += cur;
            }
        }
        return string(1, tape[K-1]);
    }
};