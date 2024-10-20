#include <iostream>
using namespace std;
// 继承
// 1.继承的语法格式如下：
// class Person
// {
// public:
//     void Print()
//     {
//         cout << "name:" << _name << endl;
//         cout << "age:" << _age << endl;
//     }

// protected:
//     string _name = "peter"; // 姓名
//     int _age = 18;          // 年龄
// };
// // 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
// //    派生类    继承方式  基类
// //    Student   public   Person
// class Student : public Person
// {
// protected:
//     int _stuid; // 学号
// };
// class Teacher : public Person
// {
// protected:
//     int _jobid; // 工号
// };
// int main()
// {
//     Student s;
//     Teacher t;
//     s.Print();
//     t.Print();
//     return 0;
// }

//----------------------------------------------------------------------

// 2.基类和派生类对象赋值转换

// class Person
// {
// protected:
//     string _name; // 姓名
//     string _sex;  // 性别
//     int _age;     // 年龄
// };
// class Student : public Person
// {
// public:
//     int _No; // 学号
// };
// void Test()
// {
//     Student sobj;
//     // 1.子类对象可以赋值给父类对象/指针/引用
//     //这里有个形象的说法叫切片或者切割。寓意把派生类中父类那部分切来赋值过去。
//     Person pobj = sobj;
//     Person *pp = &sobj;
//     Person &rp = sobj;

//     // 2.基类对象不能赋值给派生类对象
//     // sobj = pobj;

//     // 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//     pp = &sobj;
//     Student *ps1 = (Student *)pp; // 这种情况转换时可以的。
//     ps1->_No = 10;
//     pp = &pobj;

//     Student *ps2 = (Student *)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//     ps2->_No = 10;
// }

//----------------------------------------------------------------------

// 3.继承中的作用域
//----------------------------------------------------------------------
//子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的直接访问，这种情况叫隐藏，也叫重定义。（在子类成员函数中，可以使用 基类::基类成员 显示访问）
// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆

// class Person
// {
// protected:
//     string _name = "啦啦"; // 姓名
//     int _num = 111;          // 身份证号
// };
// class Student : public Person
// {
// public:
//     void Print()
//     {
//         cout << " 姓名:" << _name << endl;
//         cout << " 身份证号:" << Person::_num << endl;
//         cout << " 学号:" << _num << endl;
//     }
// protected:
//     int _num = 999; // 学号
// };
// void Test()
// {
//     Student s1;
//     s1.Print();
// };
// int main()
// {
//     Test();
//     return 0;
// }

//----------------------------------------------------------------------

//a.重载  b.重写   c.重定义   d.编译不通过
//选c.重定义也就是隐藏
// // B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// // B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。

class A
{
public:
    void fun()
    {
        cout << "func()" << endl;
    }
};
class B : public A
{
public:
    void fun(int i)
    {
        A::fun();
        cout << "func(int i)->" << i << endl;
    }
};
void Test()
{
    B b;
    b.fun(10);
    // b.fun();//隐藏了A中的fun,调不动
    // b.A::fun(); //显示调用A中的fun
}

//----------------------------------------------------------------------