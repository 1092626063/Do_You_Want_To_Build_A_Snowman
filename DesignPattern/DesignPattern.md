# 面向对象设计原则：
1. 依赖倒置原则
   要依赖于抽象，不要依赖于具体的实现。
2. 开闭原则
   对扩展开放，对修改关闭。
3. 单一职责原则
   一个类只负责一项职责。
4. Liskov替换原则
   在任何父类出现的地方都可以用他的子类来替代，子类必须完全实现父类的方法。
   子类可以有自己的方法和属性。
5. 接口隔离原则
   不应该强迫客户程序依赖他们不需要使用的方法。
6. 合成复用原则
   优先使用对象组合，而不是类继承。
7. 封装变化点
8. 迪米特原则
   针对接口编程，降低各个对象之间的耦合，提高系统的可维护性，模块之间通过接口来实现

设计模式分类：
- sss
- “对象创建”模式
  通过“对象创建”模式绕开new，来避免对象创建（new）过程中所导致的紧耦合（依赖具体类）（让其在编译过程中尽可能依赖抽象类，而不是具体类，以达到运行时多态），从而支持对象创建的稳定。它是接口抽象之后的第一步工作。Factory Method、Abstract Factory、Prototype、Builder。

模板方法TemplateMethod
意图
定义一个操作中的算法的骨架(稳定)，而将一些步骤延迟到子类中。TemplateMethod使得子类可以不改变(复用)一个算法的结构即可重定义该算法的某些特定的步骤。
举例
- 程序的主流程给Library开发人员来实现，也就是在后期不改变程序的主流程。让Application来实现其中的流程步骤。

策略模式Strategy
意图
定义一系列的算法，把它们一个个封装起来，并且使它们可相互替换。Motivation使得算法可独立于使用它的客户程序(稳定)而变化(扩展，子类化)。
举例
- 一个类如果有多种行为，并且这些行为在这个类的操作中以多个条件语句的形式出现时，将这些分支用他们各自的Strategy类代替这些条件语句。

观察者模式Observer
意图
定义对象间的一种一对多(变化)的依赖关系，以便当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并自动更新。
举例
- 一个观察者有多个目标
- 一个目标有多个观察者

装饰模式Decorator
意图
动态(组合)地给一个对象增加一些额外的职责。就增加功能而言，Decorator模式比生成子类(继承)更为灵活(消除重复代码&减少子类个数)。
举例
- 实现在运行时动态扩展对象功能的能力，可以根据需要扩展多个功能，要点在于解决“主体类在多个方向上的扩展功能”，既使用继承，又使用组合。（给手机装饰挂绳，手机壳，屏幕）

桥接模式Bridge
意图
将抽象部分与实现部分分离，使得他们可以独立得变化(子类化)
举例
- 当有两个非常强的变化维度的时候，比如app维度和平台维度，他们可以各自得发展而不相互影响。

工厂方法Factory Method
意图
定义一个用于创建对象的接口，让子类决定实例化哪个类，Factory Method使得一个类的实例化延迟（目的：解耦，手段：虚函数）到子类。
举例
- 实现对不同类型的分割split
  
  
```
//抽象类 
class ISplitter{ 
public: 
    virtual void split()=0; 
    virtual ~ISplitter(){} 
};
//具体类 
class BinarySplitter : public ISplitter{ 
     
}; 
class TxtSplitter: public ISplitter{ 
     
};
```

```
//工厂基类 
class SplitterFactory{ 
public: 
    virtual ISplitter* CreateSplitter()=0; 
    virtual ~SplitterFactory(){} 
};
//具体工厂 
class BinarySplitterFactory: public SplitterFactory{ 
public: 
    virtual ISplitter* CreateSplitter(){ 
        return new BinarySplitter(); 
    } 
}; 
class TxtSplitterFactory: public SplitterFactory{ 
public: 
    virtual ISplitter* CreateSplitter(){ 
        return new TxtSplitter(); 
    } 
};
```

```
class MainForm : public Form 
{ 
    SplitterFactory*  factory;//工厂 
public:      
    MainForm(SplitterFactory*  factory){  //在运行时传递对应的factory
        this->factory=factory; 
    } 
    void Button1_Click(){
        //ISplitter * splitter=new BinarySplitter();//依赖具体类
	ISplitter * splitter=factory->CreateSplitter(); // 编译时不依赖具体类，达到多态new 
        splitter->split(); 
    } 
};
```

抽象工厂Abstract Factory
意图

原型模式Prototype
意图

生成器模式Builder
意图

单例模式Singleton
意图

享元模式Flyweight
意图

外观模式Facade
意图

代理模式Proxy
意图

适配器模式Adapter
意图

中介者模式Mediator
意图

状态模式State
意图

备忘录模式Memento
意图

组合模式Composite
意图

迭代器模式Iterator
意图

职责链模式Chain Of Responsiblity
意图

命令模式Command
意图
将一个请求（行为）封装成一个对象，从而使你用不同的请求对客户进行参数化，对请求排队或记录请求日志，以及支持可撤销的操作。

访问者模式Visitor
意图

解释器模式Interpreter
意图
