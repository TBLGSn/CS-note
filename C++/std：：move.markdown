C++11 中最重要的特性就是，支持 move semantic.
用以避免**非必要**的拷贝和临时对象.

## 预备知识
### right-Value 和left-Value
```c
// 我们用C语言的知识来直观的理解右值与左值.
int a;
a = 1;  // a被解释为一个地址。→ 左值。 
swap(a);//a 在这里被解释为一个整数。→ 右值。
```

### 右值引用声明语法
```c++
type-id && cast-expression
```

## 为什么我们需要std::move
考虑以下的代码:
```c++
void createAndInsert(std::set<X> & coll){
    X x;
    coll.insert(x);
}
namespace std{
    
    // 集合提供Value semantic,及安插临时对象或者“安插后使用和改变该对象”的能力
    template <typename T, ....> 
    class set{
        
        public:
            ...insert(const T& v); // copy the value
            ....
    }
}

```
然而对于下面的代码，作为程序员我们应该最好的指出“被传入值 x+x和x不再被调用者使用”，**如此一来coll就不用在内部为此建立一份copy，且以某种方式 move 其内容进入新建元素中**。
```c++
X x;
coll.insert(x);
...
coll.insert(x+x);
...
coll.insert(x);
```
在c++11之后，我们可以使用**std::move**完成这样的任务，(某些情况下，编译器也会默认进行这样的任务)。
```c++
X x;
coll.insert(x);
...
coll.insert(x+x);
...
coll.insert(std::move(x));
//有了声明于<utility>的std::move(),x可被moved而不再被copied
```
注意，注意**是move而非copy**,下面的例子会帮助理解这一点。
```c++
int main() {
	
	std::vector<int> t = {1,2,3};
	std::vector<int> t2 = std::move(t);
	// 元素的搬移方式是以某种“pointer”的方式，而非“逐一复制”。
	for (auto p : t) {
		std::cout << p <<"\n";
	}
	return 0;
}
```

# 实现方式
std::move并不做任何的移动操作，而是将其实参转变成一个所谓的**rvalue reference**.我们为集合提供一个insert的重载版本，用来处理这些rvalue reference.
```c++
namespace std{
    
    // 集合提供Value semantic,及安插临时对象或者“安插后使用和改变该对象”的能力
    template <typename T, ....> 
    class set{
        
        public:
            ...insert(const T& v); //copy the left-value
            ...insert(T&& x); // move the right-value
            ....
    }
}
```
