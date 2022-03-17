#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct node {
    char rawc;//原始棋子
    char nowc;//现在棋子
    int group;// 0, 1, 2
    node(){}
    node(char cc, int gg) : rawc(cc), nowc(cc), group(gg) {}
}P[3][3];

bool vis[3][3];//表示第i个group的数字是否使用过
int ans = 0;//答案数量

void print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout<<P[i][j].nowc;
        }
        cout<<endl;
    }
}

bool check() {
    // just check row and clo for each 0,1,2
    vector<int> num(4, 0);
    for (int i = 0; i < 3; ++i) {
        fill(num.begin(), num.end(), 0);
        for (int j = 0; j < 3; ++j) {
            int x = P[i][j].rawc-'0';
            if (num[x] == 1) {
                return false;
            }
            num[x] = 1;
        }
    }

    for (int i = 0; i < 3; ++i) {
        fill(num.begin(), num.end(), 0);
        for (int j = 0; j < 3; ++j) {
            int x = P[j][i].rawc-'0';
            if (num[x] == 1) {
                return false;
            }
            num[x] = 1;
        }
    }
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            P[i][j].nowc = P[i][j].rawc;
        }
    }
    return true;
}

bool checkGroup(int g, int i) {
    return vis[g][i];
}

void setGroup(int g, int i, int flag) {
    vis[g][i] = flag;
}

void dfs(int idx) {
    int x = idx / 3;
    int y = idx % 3;
    if (idx == 10) {
        if (check())
            ans++;
        return ;
    }

    if (P[x][y].rawc != '*') {        
        dfs(idx+1);
        return ;
    }

    for (int i = 1; i <= 3; ++i) {
        if (!checkGroup(P[x][y].group, i-1)) {
            setGroup(P[x][y].group, i-1, true);
            P[x][y].rawc = '0'+i;
            dfs(idx+1);
            P[x][y].rawc = '*';
            setGroup(P[x][y].group, i-1, false);
        }
    }
    return ;
}

int main()
{
    cout<<1111<<endl;
    int T;
    cin>>T;
    string s;
    int x, y;
    while (T--) {
        ans = 0;
        for (int i = 0; i < 3; ++i) {
            cin>>s;
            for (int j = 0; j < 3; ++j) {
                P[i][j] = node(s[j], -1);
                vis[i][j] = false;
            }
        }
        for (int i = 1; i <= 3; ++i) {
            for (int k = 0; k < 3; ++k) {
                cin>>x>>y;
                P[x][y].group = i;
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (P[i][j].rawc != '*') {
                    setGroup(P[i][j].group, (P[i][j].rawc - '0')-1, true);
                }
            }
        } 
        dfs(0);
        if (ans == 1) {
            cout<<"Unique"<<endl;
            print();
        } else if (ans > 1) {
            cout<<"Multiple"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

/*
4
*2*
1*2
***
0 0 0 1 1 0
0 2 1 1 1 2
2 0 2 1 2 2
**3
***
***
0 0 1 0 1 1
0 1 0 2 1 2
2 0 2 1 2 2
**3
1**
**2
0 0 1 0 1 1
0 1 0 2 1 2
2 0 2 1 2 2
3*3
1**
**2
0 0 1 0 1 1
0 1 0 2 1 2
2 0 2 1 2 2
*/