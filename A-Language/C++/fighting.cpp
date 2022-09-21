#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;
int dopse[50];

int main() {
    int n, m, k, a;
    cin>>m>>n>>k;
    for (int i = 0; i < k; ++i) {
        cin>>a;
        dopse[a] = 1;
    }

    //dp[i][j]表示到i这个位置第j条命时能走的方法数
    vector<vector<int>> dp(n+2, vector<int>(m+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n+1; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int t = 1; t <= 3; ++t) {
                if (i - t >= 0) {
                    if (dopse[i] && j > 0) {//空木板，掉一条命
                        dp[i][j] += dp[i-t][j-1];
                    } else if (!dopse[i]) {//非空，直接走
                        dp[i][j] += dp[i-t][j];
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ans += dp[n+1][i];
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