#include <bits/stdc++.h>
using namespace std;

// //类型参数+非类型模板参数
// template <class T, int N>
// class Array
// {
// public:
// private:
//     T _a[N];
// };

// int main()
// {
//     Array<int, 100> a1;
//     Array<int, 1000> a2;
//     return 0;
// }

// 模板的特化
// template <class T>
// bool IsEqual(T &left, T &right)
// {
//     return left == right;
// }
// // 特化(针对某些类型的特殊化处理)
// template <>
// bool IsEqual<char *>(char *&left, char *&right)
// {
//     return strcmp(left, right) == 0;
// }
// int main()
// {
//     int a = 0, b = 1;
//     cout << IsEqual(a, b) << endl;
//     char *p1 = "hello";
//     char *p2 = "world";

//     cout << IsEqual(p1, p2) << endl;
//     return 0;
// }
//类的特化类似，在类名后面加<>
//全特化
//偏特化


//解决模板不能分离编译的方法：
//1.显示实例化 不常用，因为不方便
//2.粗暴，不要分离编译
