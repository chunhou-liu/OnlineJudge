#include <string>
using namespace std;


class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        size_t a_plus_pos = a.find('+'), b_plus_pos = b.find('+');
        int a_r = stoi(a.substr(0, a_plus_pos)), b_r = stoi(b.substr(0, b_plus_pos));
        int a_v = stoi(a.substr(a_plus_pos+1, a.size()-2-a_plus_pos)), b_v = stoi(b.substr(b_plus_pos+1, b.size()-2-b_plus_pos));
        int real = a_r*b_r - a_v*b_v, vir = a_r * b_v + b_r * a_v;
        return to_string(real) + "+" + to_string(vir) + "i";
    }
};