# operator

C++ operator 是C++中的关键字，常用于运算符的重写.

## 运算符重写
```c++
//重写 = 运算符
class A{
    //...
    void operator=(){
        //do something
    }
    //...
}
```

## 用户类型转换
implicit 类型转换.
考虑如下的代码:
```C++
class FontHandle{
    //....
}
class Font{ 
  private:
    FontHandle f;
    
  public:
    explicit Font(FontHadle fh):f(fh) {

    }
    //提供Font中数据的访问接口
    
    FontHandle get() const{
        return f;
    }
    
    ~Font(){
        // ....
    }
}
```
这时在main函数中我们不得不写出这样的代码：
```C++
int main(){
    //font 是Font类的一个对象
    //调用其他函数
    changeFontSize(font.get());
}
```
这时我们通过operator可以写出不显示类型转换
```C++
class Font{
    //...
    operator FonHandle() const{
        return f;
    }
    //...
}
//这时的main函数中可以如下书写:
changeFontSize(f);
```