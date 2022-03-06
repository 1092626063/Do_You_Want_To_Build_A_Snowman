# 简介：
	priority_queue<Type, Container, Functional>
	其中Type 为数据类型， Container 为保存数据的容器，Functional 为元素比较方式。
	Container 必须是用数组实现的容器，比如 vector, deque 但不能用 list.
	STL里面默认用的是 vector. 比较方式默认用 operator< , 所以如果你把后面俩个参数缺省的话，优先队列就是大顶堆，队头元素最大，用top（）调用。
    默认大顶堆！！！

# 网站：
http://www.cnblogs.com/flyoung2008/articles/2136485.html


# 代码：
## 实现
priority_queue调用 STL里面的 make_heap(), pop_heap(), push_heap() 算法实现，也算是堆的另外一种形式。
先写一个用 STL 里面堆算法实现的与真正的STL里面的 priority_queue用法相似的priority_queue， 以加深对 priority_queue 的理解

```c++
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
class priority_queue
{
    private:
        vector<int> data;
         
    public:
        void push( int t ){ 
            data.push_back(t); 
            push_heap( data.begin(), data.end());  //用vector实现堆，把新入队的元素放在末尾，向上调整堆至合适的位置。
        }
         
        void pop(){
            pop_heap( data.begin(), data.end() );
            data.pop_back();                       //将堆顶元素取出，向下调整堆。 
        }
         
        int top() { return data.front(); }
        int size() { return data.size(); }
        bool empty() { return data.empty(); }
};
 
 
int main()
{
    priority_queue test;
    test.push( 3 );
    test.push( 5 );
    test.push( 2 );
    test.push( 4 );
     
    while( !test.empty() ){
        cout << test.top() << endl;
        test.pop(); }
         
    return 0;
 
}
```
 
STL里面的 priority_queue 写法与此相似，只是增加了模板及相关的迭代器什么的。 

## 使用（大顶堆）
priority_queue 对于基本类型的使用方法相对简单。他的模板声明带有三个参数:
priority_queue<Type, Container, Functional>
其中Type 为数据类型， Container 为保存数据的容器，Functional 为元素比较方式。
Container 必须是用数组实现的容器，比如 vector, deque 但不能用 list.
STL里面默认用的是 vector. 比较方式默认用 operator< , 所以如果你把后面俩个参数缺省的话，
优先队列默认大顶堆，队头元素最大。
方法只需使用：push()、pop()、top()、empty()即可。
 
#include <iostream>
#include <queue>
 
using namespace std;
 
int main(){
    priority_queue<int> q;
     
    for( int i= 0; i< 10; ++i ) q.push( rand() );
    while( !q.empty() ){
        cout << q.top() << endl;
        q.pop();
    }
     
    getchar();
    return 0;
}
 
 ## 使用（小顶堆）
如果要用到小顶堆，则一般要把模板的三个参数都带进去。
STL里面定义了一个仿函数 greater<Type>，对于基本类型可以用这个仿函数声明小顶堆
 
#include <iostream>
#include <queue>
 
using namespace std;
 
int main(){
    priority_queue<int, vector<int>, greater<int> > q;
     
    for( int i= 0; i< 10; ++i ) q.push( rand() );
    while( !q.empty() ){
        cout << q.top() << endl;
        q.pop();
    }
     
    getchar();
    return 0;
}
 

## 使用（自定义类型）
对于自定义类型，则必须自己重载 operator< 或者自己写仿函数
 
#include <iostream>
#include <queue>
 
using namespace std;
 
struct Node{
    int x, y;
    Node( int a= 0, int b= 0 ):
        x(a), y(b) {}
};
 
bool operator<( Node a, Node b ){     //重载小于号（需掌握）
    if( a.x== b.x ) return a.y> b.y;
    return a.x> b.x; 
}

//区别于sort比较，上面的重载反正就是反过来的，孟神也不知道为什么。
bool cmp (Node a, Node b) {
    return a.x < b.x;//从小到大
}
 
int main(){
    priority_queue<Node> q;
     
    for( int i= 0; i< 10; ++i )
    q.push( Node( rand(), rand() ) );
     
    while( !q.empty() ){
        cout << q.top().x << ' ' << q.top().y << endl;
        q.pop();
    }
     
    getchar();
    return 0;
}
自定义类型重载 operator< 后，声明对象时就可以只带一个模板参数。
但此时不能像基本类型这样声明
priority_queue<Node, vector<Node>, greater<Node> >;
原因是 greater<Node> 没有定义，如果想用这种方法定义则可以按如下方式:
 
#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

struct Node{
    int x, y;
    Node( int a= 0, int b= 0 ):
        x(a), y(b) {}
};

struct cmp{
    bool operator() ( Node a, Node b ){
        if( a.x== b.x ) return a.y> b.y;

        return a.x> b.x; 
    }
};

int main(){
    priority_queue<Node, vector<Node>, cmp> q;

    for( int i= 0; i< 10; ++i )
    q.push( Node( rand(), rand() ) );

    while( !q.empty() ){
        cout << q.top().x << ' ' << q.top().y << endl;
        q.pop();
    }

    return 0;
}
