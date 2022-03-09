# 重温 Python 语言
首先 python 是解释型语言，不需要编译，运行速度可能是 c语言的 100 倍，虽慢，但语言学习成本并不高。
参考博客：https://www.liaoxuefeng.com/wiki/1016959663602400

## Python 解释器
### CPython
官网下载使用的是 CPython 解释器，是用 C语言开发的，是使用最广泛的解释器，具体有什么特殊日后补充。

### IPython
IPython是基于CPython之上的一个交互式解释器，也就是说，IPython只是在交互方式上有所增强，但是执行Python代码的功能和CPython是完全一样的。
该解释器可以输出漂亮的 python 语法树。

## 字符串
```python
转义字符为 \
Python还允许用r''表示''内部的字符串默认不转义,如：
>>> print('\\\t\\')
\       \
>>> print(r'\\\t\\')
\\\t\\

如果字符串内部有很多换行，用'\n'写在一行里不好阅读，为了简化，Python允许用'''...'''的格式表示多行内容,如：
>>> print('''line1
... line2
... line3''')
line1
line2
line3

```