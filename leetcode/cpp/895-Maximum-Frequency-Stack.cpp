#include <map>
#include <stack>
using namespace std;


class FreqStack {
    map<int, stack<int>> freqs_elems;
    map<int, int> elem_freqs;
public:
    FreqStack() {
        freqs_elems[1] = stack<int>();
    }
    
    void push(int x) {
        if(elem_freqs.find(x)==elem_freqs.end()){
            elem_freqs[x]=1;
            freqs_elems[1].push(x);
        }else{
            ++elem_freqs[x];
            int freq = elem_freqs[x];
            if(freqs_elems.find(freq)==freqs_elems.end()){
                stack<int> tmp;tmp.push(x);
                freqs_elems[freq]=tmp;
            }else{
                freqs_elems[freq].push(x);
            }
        }
    }
    
    int pop() {
        map<int, stack<int>>::reverse_iterator it = freqs_elems.rbegin();
        stack<int> &stk = it->second;
        int elem = stk.top(); stk.pop();
        if(stk.empty())freqs_elems.erase(it->first);
        --elem_freqs[elem];
        if(elem_freqs[elem]==0)elem_freqs.erase(elem);
        return elem;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */