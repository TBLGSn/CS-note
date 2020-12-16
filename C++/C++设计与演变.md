# release1 带类的C
# release1 带类的C
# release1 带类的C
# release1 带类的C
# release1 带类的C
# release1 带类的C
包括类，派生类(没有虚函数)，共有和私有的控制,
构造函数和析构函数,调用和返回函数,friend类,函数参数的检查和类型的转换，
1981年又引入了在线函数，默认函数，赋值运算符的重载

## 带类的C
- 此时函数new()是构造函数,建构函数被保证一定会被调用，以初始化它所属的类的每一个对象，这一项工作一定在第一次使用对象前完成.
- 带类的C对象被看作是一个C结构体
```c++
class stack{
    char s[10];
    char* min;
    char* top;
    char* max;
    void new();//当时的构造函数
public:
    void push();
    char top();
}
//等价于
struct stack{
    char s[10];
    char* min;
    char* top;
    char* max;
}
```
同样的对于成员函数的调用做直接映射

## 派生类

# new 和malloc 的区别
new是运算符,而malloc是一个函数.
对于C语言而言，只需要调用malloc申请空间就行了，但对于C++不行，C++必须调用构造函数(**开始时调用构造函数，结束时调用析解函数**),因此引入了new这个运算符使得分配和初始化都能够完成.
运算符 new 的职责是确保相互分离的储存分配和初始化能够正确的放在一起使用。
而malloc只是负责从堆上申请空间的一个函数.
 void* operator new(size_t sz);

 # 析解函数不能够被重载