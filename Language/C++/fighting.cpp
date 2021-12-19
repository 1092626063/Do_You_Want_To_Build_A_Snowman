#include <iostream>
#include <map>
#include <string>
 
using namespace std;
 
template<typename T>
void func(T& param) {
    cout << "传入的是左值" << endl;
}
template<typename T>
void func(T&& param) {
    cout << "传入的是右值" << endl;
}
template<typename T>
void warp(T&& param) {
    func(param);
}
int main() {
    int num = 2019;
    warp(num);
    warp(2019);
    return 0;
}