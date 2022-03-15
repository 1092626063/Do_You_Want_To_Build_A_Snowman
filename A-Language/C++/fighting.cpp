#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//字符串，文章，string，压缩，还原

unordered_map<string, int> mp1;
unordered_map<int, string> mp2;
vector<int> enco;
vector<string> deco;
vector<string> art;

void encode(vector<string> v) {
    int n = v.size();
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        string word = v[i];
        if (!mp1.count(word)) {
            mp1[word] = cnt;
            mp2[cnt] = word;
            cnt++;
        }

        enco.push_back(mp1[word]);
    }
}

void decode(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        string word = mp2[v[i]];
        deco.push_back(word);
    }
}

void printEncode(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        cout<<v[i]<<" ";
    }
}

int main()
{
    string s;
    while(cin>>s) {
        if (s == "###") {
            break;
        }
        art.push_back(s);
    }
    encode(art);
    printEncode(enco);
    return 0;
}

/*
my name is my name
1   2   3  4
*/