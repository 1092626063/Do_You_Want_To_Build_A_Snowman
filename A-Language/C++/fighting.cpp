#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct node {
    int l, r;
    node() {}
    node(int ll, int rr) : l(ll), r(rr) {}
};

bool operator < (node a, node b) {
    if (a.l == b.l) {
        return a.r > b.r;
    }
    return a.l < b.l;
}

int main()
{
    
    return 0;
}

/*

*/