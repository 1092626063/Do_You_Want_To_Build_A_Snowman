#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;


int main() {
    string s = "-7 + 3 1 - 2";

    int n = s.length();
    vector<int> a;
    vector<int> op;

    int t = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '+') {
                op.push_back(1);
            } else {
                op.push_back(0);
            }
            a.push_back(t);
            t = 0;
        } else if (s[i] == ' ') {
            continue;
        } else {
            t = t*10 + s[i]-'0';
        }
    }
    if (t) {
        a.push_back(t);
    }

    int pos = 0;//op size
    n = a.size();
    int ans = a[0];//32 bit
    if (a.size() == op.size() && op[pos] == 0) {
        ans = -ans;
        pos++;
    }

    for (int i = 1; i < n; ++i) {
        if (op[pos] == 1) {
            ans += a[i];
        } else {
            ans -= a[i];
        }
        pos++;
    }

    cout<<ans<<endl;
    return 0;
}

/*
2 2 1
2

1 3 2
1 3


*/