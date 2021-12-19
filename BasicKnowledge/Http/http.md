# 前置知识
曾经考研复试整理过CSDN博客，里面是最基础的知识点：https://blog.csdn.net/qq_37368095/category_9739264.html?spm=1001.2014.3001.5482

# HTTP 常见面试题

## 概念
### URI 与 URL 的区别
URI，即 uniform resource identifier，统一资源标识符，用来唯一标识一个资源。
- Web 上可用的每种资源，如 HTML 文档、图像、视频片段、程序等都用 URI 来定位。
- URI 一般由三部分组成：1.访问资源的命名机制 2.存放资源的主机名 3. 资源自身的名称，由路径表示，着重强调于资源。

URL，即 uniform resource locator，统一资源定位器，既可以用来标识一个资源，又定位了这个资源。
- URL 可以用一种统一的格式来描述各种信息资源，包括文件、服务器的地址和目录等。
- URL 一般由三部分组成：1.协议 2.存有该资源的主机IP地址 3.主机资源的具体地址，如目录和文件名等。


## HTTP 请求
### 常用的 HTTP 请求方法
- GET：用于请求访问已经被 URI（统一资源标识符）识别的资源，可以通过 URL 传参给服务器。
- POST：用于传输信息给服务器，主要功能与 GET 方法类似，但一般推荐使用 POST 方式。
- PUT：传输文件，报文主体中包含文件内容，保存到对应的 URI 位置。
- HEAD：获取报文首部，与 GET 方法类似，只是不返回报文主体，一般用于验证 URI 是否有效。
- DELETE：删除文件，与 PUT 方法相反，删除对应 URI 位置文件。
- OPTIONS：查询相应 URI 支持的 HTTP 方法。

### GET 和 POST 的区别
https://www.cnblogs.com/zhou-test/p/9803478.html这个讲得比较好

### GET 和 POST 方法都是安全、幂等的吗
- GET 方法涉及到的参数都在 URL 里面，是可见的，是不安全的，可能会泄漏隐私信息，如密码等。

### HTTP 请求报文格式

![Image](/Pictures/http请求格式.png)

```http
GET /562f25980001b1b106000338.jpg HTTP/1.1              //请求行
Host: img.mukewang.com                                   //以下是首部字段
User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.106 Safari/537.36 
Accept: image/webp,image/*,*/*;q=0.8 
Referer: http://www.imooc.com/ 
Accept-Encoding: gzip, deflate, sdch 
Accept-Language: zh-CN,zh;q=0.8 
Connection：Keep-Alive
空行                                                    //空行
请求数据为空                                             //请求数据
```

- 请求行：包含请求方法、URL、HTTP协议版本
- 请求头部：
    - HOST：请求资源所在的服务器域名。
    - User-Agent：HTTP 客户端程序的信息。
    - Accept：支持响应的数据类型。
    - Accept-Encoding：支持的内容编码。
    - Accept-Language：支持的自然语言。
    - Connection：连接管理，可以是Keep-Alive或close。
    - Content-Type：实体适用的数据类型。
    - Content-Encoding：实体适用的编码方式。
    - Content-Language：实体适用的自然语言。//TODO Accept与Content区别
- 空行
- 请求数据：即报文主体


### HTTP 响应报文格式
```http
HTTP/1.1 200 OK
Date: Fri, 22 May 2009 06:07:21 GMT
Content-Type: text/html; charset=UTF-8

<html>
      <head></head>
      <body>
            <!--body goes here-->
      </body>
</html>
```

- 状态行：HTTP协议版本、状态码、状态消息。
- 消息报头：用来说明「客户端」要使用的一些附加信息。
    - Date：生成相应的日期和时间；
    - Content-Type：指定了MIME类型的HTML（text/html），编码类型是UTF-8
- 空行
- 响应正文：服务器返回给客户端的信息。

### 状态码
- 1xx：指示信息，表示请求已接收，继续处理。
- 2xx：成功，表示请求正常处理完毕。
- 3xx：重定向，要完成请求必须进行进一步操作。
    - 302：临时重定向，服务器返回的头部信息中会包含一个重定向 url
- 4xx：客户端错误，请求有语法错误，服务器无法处理。
- 5xx：服务端错误，服务器处理请求出错

### 一次完整的 HTTP 请求的步骤
1. 建立 TCP 连接
2. 客户端发送 HTTP 请求报文
3. 服务器发送应答报文将客户端请求的数据返回
4. 释放 TCP 连接
5. 客户端解析

### 在浏览器地址栏键入 URL，按下回车之后会经历什么（开放性问题，答得全面一些更好）
1. 浏览器向 DNS 服务器请求解析该 URL 中的域名所对应的 IP 地址
2. 根据 IP 地址和默认端口号80，与服务器建立 TCP 连接
3. 浏览器发送 HTTP 请求，该请求报文作为 TCP 三次握手的第三个报文数据发送给服务器
4. 服务器对浏览器做出响应，把数据发送给客户端
5. 释放 TCP 连接
6. 浏览器解析应答报文，将内容显示给用户

****

## HTTP 与 HTTPS

### 什么是 HTTP 协议


### 什么是 HTTP 无状态协议

### HTTP1.0 和 HTTP1.1 的区别

### HTTP2.0 和 HTTP1.X 相比的特性

### HTTP3.0 和 HTTP2.0 相比的特性


### HTTP 和 HTTPS 的区别


### HTTPS 的优缺点


### 什么是运营商劫持


### HTTPS 工作流程


### 对称加密和非对称加密


### 为什么要有 CA 颁发机构


******

## HTTP 优化
### Cookie 是否会被覆盖
https://blog.csdn.net/weixin_38051694/article/details/77777010 最后面

### localStorage的优缺点
