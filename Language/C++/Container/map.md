# 简介
C++ 中的 map 是键值对容器（key-value形式），每个关键字（key）只能在 map 中出现一次。
map 使用红黑树实现，其插入、删除、查找复杂度均为 O(logn)，有自动排序功能，内部所有数据都是有序的。

# 常见函数的使用
自己写一个小demo：

```c++
#include <iostream>
#include <map>
#include <string>
 
using namespace std;
 
int main(){
    map<int, string> mp;

    //insert
    mp[1] = "a";                            //数组方式插入
    mp.insert(pair<int, string>(2, "b"));   //pair方式插入
    mp.insert(make_pair(3, "c"));           //make_pair方式插入
    mp.insert(map<int, string>::value_type(4, "d"));    //TODO value_type
    mp.insert({ {5, "e"}, {6, "f"} });
    // insert 与数组插入的区别在于，当 key 存在时，数组有覆盖功能。

    //通过 pair 的第二个返回值来判断插入是否成功，第一个返回值是插入的位置
    pair< map<int, string>::iterator, bool > Insert_Pair;
    Insert_Pair = mp.insert(make_pair(1, "b"));
    if (Insert_Pair.second == true) {
        cout << "Insert Successfully" << endl;
    } else {
        cout << "Insert Failure" << endl;
    }

    //指定插入位置
    map<int, string>::iterator it = mp.begin();
    mp.insert(it, make_pair(7, "g"));

    //范围插入多值
    map<int, string> anothermp;
    anothermp.insert(mp.begin(), mp.find(3));

    //判断一个 key 是否存在
    it = mp.find(2);    // 可以返回 key 的位置
    if (it != mp.end()) {
        cout<< "Find, value is " << it->second << endl;
    }
    map<int, string>::iterator it2 = prev(it); //返回前一个迭代器指针

    int cnt = mp.count(2); // 不能返回 key 的位置，返回结果只有 0 或 1 .

    //取值，存在一个坑点：如果 key 不存在，此时使用[]访问，则会导致插入，推荐使用 at 函数，如果 key 不存在则会报出异常
    string s = mp.at(1);

    if (mp.empty()) { //数据判空
        cout << "empty" << endl;
    } else {
        cout << "not empty" << endl;
    }

    //遍历
    for (it = mp.begin(); it != mp.end(); ++it) {
        cout<< it->first << " " << it->second << endl;
    }

    //delete
    it = mp.find(1);
    mp.erase(it);   //用迭代器删除
    mp.erase(2);    //用 key 删除
    mp.clear();     //清空


    //结构体排序，需要重载小于号
    typedef struct tagStudent {
        int id;
        string name;
        bool operator < (tagStudent const& a) const {
            if (id == a.id) {
                return name.compare(a.name) < 0;
            }
            return id > a.id;
        }
    }StudentInfo;

    map<StudentInfo, int> st;
    StudentInfo s1, s2, s3;
    s1.id = 1;
    s1.name = "xiaowang";
    s2.id = 2;
    s2.name = "xiaoming";
    s3.id = 3;
    s3.name = "xiaohong";
    st.insert(make_pair(s1, 77));
    st.insert(make_pair(s3, 88));
    st.insert(make_pair(s2, 100));

    for (map<StudentInfo, int>::iterator iter = st.begin(); iter != st.end(); ++iter) {
        cout << iter->first.id << iter->first.name << endl;
    }

    return 0;
}
```