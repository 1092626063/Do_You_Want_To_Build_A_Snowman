# mechanism of new
new是C++的关键字，作用是动态申请内存并初始化。
参考博客：https://www.cnblogs.com/luxiaoxun/archive/2012/08/10/2631812.html，里面介绍了 new、operator new、placement new 的区别

## new 的流程
1. 在堆上申请一块空间
2. 调用对象的构造函数进行初始化
3. 返回指向对象的指针

## new 与 operator new
new operator/delete operator就是new和delete操作符。
而operator new/operator delete是函数。

new operator
（1）调用operator new分配足够的空间，并调用相关对象的构造函数
（2）不可以被重载

operator new
（1）只分配所要求的空间，不调用相关对象的构造函数。当内存不足时，执行bad_alloc异常
（2）可以被重载，返回类型必须声明为void*，第一个参数类型必须为表达要求分配空间的大小（字节），类型为size_t

```C++
X *p = new X; // new操作符，会调用 operator new 分配空间，然后调用构造函数。
```

## 为什么要有 placement new
使用new操作符分配内存需要在堆中查找足够大的剩余空间，显然这个操作速度是很慢的，而且有可能出现无法分配内存的异常（空间不够）。

placement new主要适用于：
在对时间要求非常高的应用程序中，因为这些程序分配的时间是确定的；
长时间运行而不被打断的程序；
以及执行一个垃圾收集器 (garbage collector)。

## placement new 的使用步骤
```c++
char* buf = new char[sizeof(X)];
X *px = new(buf) X;
px->SetNum(10);
px->~X();

...

delete []buf;
```

1. 缓存提前分配
- 使用 new 在堆上分配，char *buf = new char[sizeof(X)];
- 在栈上分配，char buf[sizeof(X)];
- 直接有意义的地址使用，void* buf = reinterpret_cast<void*> (0xF00F);

2. 对象分配
X *px = new(buf) X;

3. 使用
px->SetNum(10);

4. 对象析构
一旦你使用完这个对象，你必须调用它的析构函数来毁灭它。
px->~X();

5. 释放
你可以反复利用缓存并给它分配一个新的对象（重复步骤2，3，4）如果你不打算再次使用这个缓存，你可以象这样释放它：delete [] buf;
