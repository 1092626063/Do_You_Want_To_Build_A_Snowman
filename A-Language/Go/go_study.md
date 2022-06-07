# 字节青训营日记
## Day1
### 记录一些 go 基础语法值得注意的点
1. switch 语句与 C++ 的完全不同，go 只会执行其中一个 case，即不需要写 break
2. map 的遍历输出结果是随机的 // TODO
3. 定义的变量类型是后置的
4. 无引用，但有引用传递的概念，想要在函数中修改变量只能使用指针
5. slice 底层实现是自动扩缩容的数组，注意 append 方法执行完要赋值给原 slice，因为扩容后的地址就不一样了
6. 结构体方法，等于说是一个类的概念
7. 结构体的变量名只要是大写的，就能被 json.Marshal 序列化

## Day2
### go协程
1. 与线程相比较：协程是用户态的，线程是内核态的

### go 依赖管理

go.mod 就是帮你管理项目所需要的依赖，避免冲突

1. go mod init 初始化，创建 go.mod 文件
2. go mod tidy 增加新的依赖，删除不需要的依赖
3. go get xxx 拉取指定的依赖版本

### 测试

1. 单元测试：所有测试文件以 _test.go 结尾，使用 func TestXxx(*testing.T)，初始化逻辑放到 TestMain 中。
2. 单元测试覆盖率，保证测试的完备性。go test xxxxxx --cover
3. Mock
4. 基准测试: func BenchmarkXxxx