#include <bits/stdc++.h>
using namespace std;

//const 首先作用于左边，如果左边没有东西，就作用于右边
//函数重载 ：允许存在多个同名函数，而这些函数的参数表不同，即函数名相同但函数的签名不同，在编译阶段实现
//顶层const表示指针本身是个常量，底层const表示指针所指的对象是一个常量
//1.
void fun(const int i)  //顶层const,传参的时候会被忽略
{  
    cout << "fun(const int) called ";  
}  
void fun(int i)  
{  
    cout << "fun(int ) called " ;  
} 

int main()  
{  
    const int i = 10;  
    fun(i);  
    return 0;  
}   
// 上述两个函数的函数签名是一样的，不是一个重载
//结果：编译错误，提示重定义

//2.
// void fun(char *a)  
// {  
//   cout << "non-const fun() " << a;  
// }  
   
// void fun(const char *a)  //底层const,传参的时候不会被忽略
// {  
//   cout << "const fun() " << a;  
// }  
   
// int main()  
// {  
//   const char *ptr = "hello world";  
//   fun(ptr);  
//   return 0;  
// }
//结果：通过编译，且输出结果为：const fun() hello world
//char *a中a指向的是一个字符串变量，const char* a 是指针常量

//3.
// void fun(char *a)  
// {  
//   cout << "non-const fun() " << a;  
// }  
   
// void fun(char * const a)  
// {  
//   cout << "const fun() " << a;  
// }  
   
// int main()  
// {  
//   char ptr[] = "hello world";  
//   fun(ptr);  
//   return 0;  
// }
//char*a和char* const a这两个都是指向字符串的变量，
//不同的是前者是指针变量，后者是指针常量
//结果：编译不通过，提示重定义

// 总结：对于函数值传递的情况，因为参数传递是通过复制实参创建一个临时变量传递进函数的，函数内只能改变临时变量，但无法改变实参，则这个时候无论加不加const对实参不会产生任何影响。
// 但是在引用或指针传递函数调用中，因为传进去的是一个引用或指针，这样函数内部可以改变引用或指针所指向的变量，这时const 才是实实在在地保护了实参所指向的变量。
// 因为在编译阶段编译器对调用函数的选择是根据实参进行的，所以，只有引用传递和指针传递可以用是否加const来重载。

//const修饰引用时的重载
// void fun(const int &i)  
// {  
//     cout << "fun(const int &) called  "<<endl;  
// }  
// void fun(int &amp;i)  
// {  
//     cout << "fun(int &) called "<<endl ;  
// }  
// int main()  
// {  
//     const int i = 10;  
//     fun(i);  
//     return 0;  
// }
//输出结果：fun(const int &) called

// 1.const重载主要是通过能否对传入的参数进行修改为判断的。

// 2.const参数重载和const函数重载机制都是一样的，因为对于const 函数重载可看做是对隐含的指针this的参数重载。

// 3.重载是在编译阶段已经完成，对于汇编和链接来说透明的。

// 4.const 对象只能调用const 方法，非const 对象既能调用const 方法也能调用非const方法，优先调用非const方法。

// 5.如果重载的函数都是引用或指针，const 变量 只能调用带有const 参数的方法，非const 变量既能调用带const 参数的方法，也能调用不带cosnt 参数的方法，优先调用不带const 参数的方法