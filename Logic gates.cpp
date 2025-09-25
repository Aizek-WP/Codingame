#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int toVal(char c) {
    if (c == '_')
        return 0;
    if (c == '-')
        return 1;
    throw - 1;
}

char toChar(int i) {
    if (i == 0)
        return '_';
    if (i == 1)
        return '-';
    throw - 1;
}

unordered_map<string, function<int(int, int)>> map = {
    {  "AND" , [](int a, int b) { return  (a & b); } },
    {   "OR" , [](int a, int b) { return  (a | b); } },
    {  "XOR" , [](int a, int b) { return  (a ^ b); } },
    { "NAND" , [](int a, int b) { return !(a & b); } },
    {  "NOR" , [](int a, int b) { return !(a | b); } },
    { "NXOR" , [](int a, int b) { return !(a ^ b); } }
};

string process(const string& s1, const string& s2, const string& op) {
    string ans = "";
    for (int i = 0; i < s1.length(); ++i)
        ans += toChar(map[op](toVal(s1[i]), toVal(s2[i])));
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> data;
    for (int i = 0; i < n; i++) {
        string input_name;
        string input_signal;
        cin >> input_name >> input_signal;
        data[input_name] = input_signal;
    }

    for (int i = 0; i < m; i++) {
        string output_name;
        string type;
        string input_name_1;
        string input_name_2;
        cin >> output_name >> type >> input_name_1 >> input_name_2;
        cout << output_name << " " << process(data[input_name_1], data[input_name_2], type) << endl;
    }
}