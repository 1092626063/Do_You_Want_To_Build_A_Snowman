# 基础

## 拷贝构造函数

### 拷贝构造函数调用时机
- 通过使用另一个同类型的对象来初始化新创建的对象。
- 复制对象把它作为参数传递给函数。
- 复制对象，并从函数返回这个对象。

### 拷贝构造函数代码实例
```C++
class Myint { 
private: 
    int x; 
public: 
    Myint(){} 
    Myint(int xx) { //构造函数
        cout<<"constructor is called"<<endl; 
        x = xx; 
    } 
    Myint(Myint &s) { //拷贝构造函数
        x = s.x; 
        cout<<"copy constructor is called"<<endl; 
    } 
    Myint& operator=(Myint y) { //operator=，只有在 b = a; 时调用，初始化赋值时调用拷贝构造函数。
        x = y.x; 
        cout<<" = "<<endl; 
        return *this; 
    } 
    Myint& operator++() {//调用前++   ... 如果返回值不是引用，则还需要调用一次拷贝构造函数. 
        x++;                            //而返回引用则可以节省这一次拷贝构造函数所消耗的时间和空间。 
        return *this; 
    } 
    Myint operator++(int) {//调用后++ 
        Myint old = *this;//调用拷贝构造函数 
        ++(*this); 
        return old;//并没有调用拷贝构造函数,为什么呢？编译器优化了！ 
    } 
    void Show() { 
        cout<<x<<endl; 
    } 
};

int main() 
{ 
    Myint a(3); 
    cout<<"++a:"<<endl; 
    ++a; 
    cout<<"a++:"<<endl; 
    a++; 
    a.Show(); 
    Myint b = a; 
    b = a;
    return 0;
}

输出：
constructor is called //调用构造函数
++a: 
a++: 
copy constructor is called  //调用拷贝构造函数
copy constructor is called  //关闭编译器优化后显示的，调用拷贝构造函数
5 
copy constructor is called  //调用拷贝构造函数，因为是初始化赋值
copy constructor is called  //调用operator=，先有一个参数传递需要拷贝构造函数参与，如果参数是引用传递，这句话就不会输出。
 = 

```

### 初始化列表与构造函数赋值效率区别
- 初始化列表效率一般会高一点。

```C++
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
       //:_a(a)   //语句1 
    { 
        _a = a; //语句2 
    } 
private: 
    A _a; 
};
int main(void){ 
    A a; 
    B b(a);//若使用语句2，则会调用默认构造函数和operator = ，而使用语句1，则调用拷贝构造函数 
    return 0; 
}
```

****

## 友元函数

### 友元函数实例
```C++
class Box 
{ 
    double width; 
public: 
    friend void printWidth(Box box); 
    friend class BigBox; 
    void setWidth(double wid); 
}; 
class BigBox 
{ 
public : 
    void Print(int width, Box &box) 
    { 
        // BigBox是Box的友元类，它可以直接访问Box类的任何成员 
        box.setWidth(width); 
        cout << "Width of box : " << box.width << endl; 
    } 
}; 
// 请注意：printWidth() 不是任何类的成员函数 
void printWidth(Box box) 
{ 
    /* 因为 printWidth() 函数是 Box 的友元，它可以直接访问该类的任何成员 */ 
    cout << "Width of box : " << box.width << endl; 
}
```

****

## const

### const数据成员和引用数据成员的初始化
- 类中const数据成员、引用数据成员，必须在初始化列表中初始化，不能使用赋值的方式初始化

```C++
Dog(int weight,int height,int type) : Animal(weight,height),m_type (type),LEGS(4) //必须在初始化列表中初始化 
{ 
　　this->m_type = type;//error 
　　//LEGS = 4; //error 
}
```


****

## this指针
- 友元函数没有 this 指针，因为友元不是类的成员。只有成员函数才有 this 指针。
- 静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。

### 指针和引用的区别
1. 指针存放一个变量的地址，而引用实质上是变量的别名。
2. 引用不能为空，创建时必须初始化，而指针可以为空。
3. 指针可以是多级的，而引用不行。
4. 指针在初始化之后可以改变指向其他的存储单元，而引用初始化后不再改变。
5. 在使用 sizeof 函数时，引用的结果是对象的大小，而指针是其本身的大小。
6. 在进行参数传递时，指针其实也是传值，只不过传递的是地址，而引用传递的其实是实参本身，不是实参的拷贝，是一种间接寻址，所以引用进行参数传递时不仅可以节省时间还能节省空间。//TODO 不懂哦
7. 自增（++）的意义不一样，引用自增被引对象的值，指针自增内存地址。
8. 引用的底层实现：事实上是一个常指针，一旦指向某个单元就不能指向别处，必须在定义的时候初始化。
int a = 1;
func1(&a);
func2(a);

void func1(int *p);
void func2(int &p);

## Inline函数

函数调用需要时间和空间开销，inline 是在编译期把函数展开，省去了调用这一过程，节省时空开销。

****

## 虚函数

### 为什么要使用虚函数
定义他为虚函数是为了允许用基类的指针来调用子类的这个虚函数（注意：不是虚函数将出现compiler error）。
```C++
class A {
    virtual void foo();
};

class B: public A {
    void foo() {...}
};

int main() {
    A* ptr = new B();
    ptr->foo(); //调用B中的foo函数
    prt->foo(10); //compiler error
}
```

### 什么是多态

### 多态的实现原理

### 虚函数的使用场景
- inline 函数可以是虚函数吗？
不可以，inline 函数没有地址，无法放到虚函数表中。
- 静态成员函数可以是虚函数吗？
不可以，静态成员函数没有 this 指针，无法查找虚函数表。
- 构造函数可以是虚函数吗？
不可以，对象中的虚函数指针是在构造函数初始化列表时才初始化的。
- 析构函数可以是虚函数吗？
可以。

### 虚函数表是在什么阶段生成的
在编译阶段

### 虚函数表存在于哪里
一般存在于代码段的文字常量区。

### 虚函数表和虚基表的区别
- 虚函数表实现多态
- 虚基表消除菱形继承的二义性问题。

### 抽象类的作用
抽象类就是实现纯虚函数的类，为了让子类强制重写虚函数，体现接口继承关系。

### 虚析构函数
设置虚析构函数的目的是防止基类指针在释放派生类对象时，造成子类的内存泄漏问题。
```C++
int main () { 
    Base *b = new Derived(); //Derived 是 Base 的派生类。 
    b->dosomething(); 
    delete b; 
    return 0; 
}
```

### 虚继承
https://www.cnblogs.com/longcnblogs/archive/2017/10/09/7642951.html

****

## 重载 cin、cout
```C++
friend ostream &operator<<( ostream &output,  const Distance &D ) 
{  
     output << "F : " << D.feet << " I : " << D.inches; 
     return output;             
} 
friend istream &operator>>( istream  &input, Distance &D ) 
{  
     input >> D.feet >> D.inches; 
     return input;             
}

cin >> D3; 
cout << "First Distance : " << D1 << endl;
```