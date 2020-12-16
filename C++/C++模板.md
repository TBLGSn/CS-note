# C++ 模板

## 结构体使用模板
```c++
//使用方式
template <typename T1, typename T2 = std::string //默认参数//>
struct List {
	T1 data1;
	T2 data2;
};
```
C++中的std::pair结构体就使用了这种方式。
```c++
//std::pair 定义
template <class _Ty1, class _Ty2>
struct pair { // store a pair of values
    using first_type  = _Ty1;
    using second_type = _Ty2;
    //............
}
```
## C++ 成员函数使用模板
```c++
class Myclass {
public:
	template <typename T>
	void method(T);
};
template <typename T>
void Myclass::method(T t) {
	// ....
}
```
但需要注意的是，此时该模板函数不能定义为virtual
## C++ 类模板也能使用默认参数

```c++
//声明类型如下
template <typename T1, typename T2 = std::string>
class MyClass{
    //.....
};
// 使用方式如下
MyClass<string> myclss;
```
我们熟悉的 std::string 的实现方式就使用到了这种技术。
```c++
// string 类实际上是借助basic_string类和typedef实现的.
typedef basic_string<char>    string; //stringfwd.h
// 在该文件中有basic_string的声明
template<typename _CharT, typename _Traits = char_traits<_CharT>,
        typename _Alloc = allocator<_CharT> >
    class basic_string;
```
