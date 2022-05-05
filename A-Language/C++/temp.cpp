#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;



int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    while(ss>>s) {
        cout<<s;
    }
    return 0;
}
