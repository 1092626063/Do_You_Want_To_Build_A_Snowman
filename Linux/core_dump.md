# 参考
http://senlinzhan.github.io/2017/12/31/coredump/
https://zhuanlan.zhihu.com/p/361711167

# segmentation fault
遇到了程序段错误 segmentation fault，为了尽快定位到错误，使用 gdb 调试 core 文件。

## segmentation fault 产生原因
1.内存访问出错
这类问题的典型代表就是数组越界，访问到不属于你的内存区域 。

2.非法内存访问
出现这类问题主要是程序试图访问内核段内存而产生的错误。（比如新建指针时没有初始化，编译不会出错，但运行时可能产生非法内存访问）

3.栈溢出
Linux默认给一个进程分配的栈空间大小为8M。c++申请变量时，new操作申请的变量在堆中，其他变量一般在存储在栈中。因此如果你数组开的过大变会出现这种问题。