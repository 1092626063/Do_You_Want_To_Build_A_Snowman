#include <iostream>
#include <map>
#include <string>
 
using namespace std;
 
class A 
{ 
public: 
    A(){ cout<<"gouzao"<<endl; } 
    A (A &other) { //拷贝构造函数 
        cout<<"copy"<<endl; 
        x = other.x; 
    } 
    A& operator = (A &other) {//重载等于号 
        cout<<"operator="<<endl; 
        x = other.x; 
        return *this; 
    } 
    ~A(){} 
private: 
    int x; 
}; 
class B{ 
public: 
    B (A &a) 
        :_a(a)   //语句1 
    { 
        //_a = a; //语句2 
    } 
private: 
    A _a; 
};
int main(void){ 
    A a; 
    B b(a);//若使用语句2，则会调用默认构造函数和operator = ，而使用语句1，则调用拷贝构造函数 
    return 0; 
}