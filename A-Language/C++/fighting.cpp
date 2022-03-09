#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void printTab(int num) {
    cout<<endl;
    for (int j = 0; j < num; ++j) {
        cout<<"    ";
    }
}

int main()
{
    unordered_map<char, char> mp = {{'{','}'}, {'[', ']'}, {'(', ')'}};
    string s;
    cin>>s;
    int len = s.length();
    int num = 0;
    for (int i = 0; i < len; ++i) {
        cout<<s[i];
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            num++;
            if (mp[s[i]] == s[i+1]) {
                continue;
            }
            printTab(num);
        }else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            num--;
        }

        if (s[i] == ',') {
            if (s[i+1] == '}' || s[i+1] == ']' || s[i+1] == ')')
                printTab(num-1);
            else
                printTab(num);
        }
    }
    //getchar();
    return 0;
}