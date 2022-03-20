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
    int n, m1, m2;
    cin>>n>>m1>>m2;
    vector<int> al(m1, 0);
    vector<int> ar(m1, 0);
    vector<node> A(m1);
    for (int i = 0; i < m1; ++i) {
        cin>>al[i];
    }
    for (int i = 0; i < m1; ++i) {
        cin>>ar[i];
        A[i].l = al[i];
        A[i].r = ar[i];
    }
    sort(A.begin(), A.end());

    vector<int> bl(m2, 0);
    vector<int> br(m2, 0);
    vector<node> B(m2);
    for (int i = 0; i < m2; ++i) {
        cin>>bl[i];
    }
    for (int i = 0; i < m2; ++i) {
        cin>>br[i];
        B[i].l = bl[i];
        B[i].r = br[i];
    }
    sort(B.begin(), B.end());

    vector<node> S(m1+m2);
    int p = -1;

    //merge A, B
    for (int i = 0; i < m1; ++i) {
        if (i == 0) {
            p++;
            S[p].l = A[i].l;
            S[p].r = A[i].r;
            continue;
        }
        if (A[i].l == A[i-1].l) continue;
        if (A[i].l <= S[p].r) {
            S[p].r = max(A[i].r, S[p].r);
        } else {
            p++;
            S[p].l = A[i].l;
            S[p].r = A[i].r;
        }
    }
    for (int i = 0; i < m2; ++i) {
        if (i == 0) {
            p++;
            S[p] = B[i];
            continue;
        }
        if (B[i].l == B[i-1].l) continue;
        if (B[i].l <= S[p].r) {
            S[p].r = max(S[p].r, B[i].r);
        } else {
            p++;
            S[p] = B[i];
        }
    }

    sort(S.begin(), S.begin()+p+1);
    int ans = 0;
    int l = S[0].l;
    int r = S[0].r;
    for (int i = 1; i <= p; ++i) {
        if (S[i].l == l) {
            ans += (S[i].r-S[i].l+1);
            continue;
        }
        if (S[i].l <= r) {
            if (S[i].r <= r) {
                ans += (S[i].r-S[i].l+1);
            } else {
                ans += (r-S[i].l+1);
                l = S[i].l;
                r = S[i].r;
            }
        } else {
            l = S[i].l;
            r = S[i].r;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*

*/