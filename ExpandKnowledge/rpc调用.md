# 简介
RPC（Remote Procedure Call）远程过程调用，即允许程序调用另一个地址空间，区别于本地调用。它隐藏了底层网络技术，使分布式环境下编程变得简单，无需关系底层网络实现细节&协议仅关注业务逻辑实现即可，比如Java的Dubbo、谷歌的grpc等。
# 原理
## 远程调用过程
![Image](/Pictures/rpc.png)

1. Service A的应用层代码中，调用了Calculator的一个实现类的add方法，希望执行一个加法运算；
2. 这个Calculator实现类，内部并不是直接实现计算器的加减乘除逻辑，而是通过远程调用Service B的RPC接口，来获取运算结果，因此称之为Stub；
3. Stub怎么和Service B建立远程通讯呢？这时候就要用到远程通讯工具了，也就是图中的Run-time Library，这个工具将帮你实现远程通讯的功能，比如Java的Socket，就是这样一个库，当然，你也可以用基于Http协议的HttpClient，或者其他通讯工具类，都可以，RPC并没有规定说你要用何种协议进行通讯；
4. Stub通过调用通讯工具提供的方法，和Service B建立起了通讯，然后将请求数据发给Service B。需要注意的是，由于底层的网络通讯是基于二进制格式的，因此这里Stub传给通讯工具类的数据也必须是二进制，比如calculator.add(1,2)，你必须把参数值1和2放到一个Request对象里头（这个Request对象当然不只这些信息，还包括要调用哪个服务的哪个RPC接口等其他信息），然后序列化为二进制，再传给通讯工具类，这一点也将在下面的代码实现中体现；
5. 二进制的数据传到Service B这一边了，Service B当然也有自己的通讯工具，通过这个通讯工具接收二进制的请求；
6. 既然数据是二进制的，那么自然要进行反序列化了，将二进制的数据反序列化为请求对象，然后将这个请求对象交给Service B的Stub处理；
7. 和之前的Service A的Stub一样，这里的Stub也同样是个“假玩意”，它所负责的，只是去解析请求对象，知道调用方要调的是哪个RPC接口，传进来的参数又是什么，然后再把这些参数传给对应的RPC接口，也就是Calculator的实际实现类去执行。很明显，如果是Java，那这里肯定用到了反射。
8. RPC接口执行完毕，返回执行结果，现在轮到Service B要把数据发给Service A了，怎么发？一样的道理，一样的流程，只是现在Service B变成了Client，Service A变成了Server而已：Service B反序列化执行结果->传输给Service A->Service A反序列化执行结果 -> 将结果返回给Application，完毕。

## 通信协议
RPC跨越了传输层与应用层，gRPC是基于http2.0的协议，Dubbo在tcp的基础上研发的应用层传输协议。
http与RPC的区别？

## 编码协议
RPC协议是与语言无关的，客户端实现语言与服务端实现语言可以是不同的的，在RPC调用过程中需要一种标准的接口定义语言即(IDL)，IDL可以是基于文本的json、xml，基于二进制编码的protobuf、thrift

## 序列化

## 服务注册&服务发现

# 参考链接
1. 包含rpc demo以及gRPC与REST的比较： https://www.jianshu.com/p/7d6853140e13