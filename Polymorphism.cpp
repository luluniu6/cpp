#include <iostream>
using namespace std;

// 多态
//----------------------------------------------------------
// class Person
// {
// public:
//     virtual void BuyTicket() { cout << "买票-全价" << endl; }
// };
// class Student : public Person
// {
// public:
//     virtual void BuyTicket() { cout << "买票-半价" << endl; }
//     /*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
//     为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
//     这样使用*/
//     /*void BuyTicket() { cout << "买票-半价" << endl; }*/
// };
// void Func(Person &p)
// {
//     p.BuyTicket();
// }
// int main()
// {
//     Person ps;
//     Student st;
//     Func(ps);
//     Func(st);
//     return 0;
// }
//----------------------------------------------------------

// 虚函数重写的两个例外
// 1.协变
//  class A
//  {
//  };
//  class B : public A
//  {
//  };
//  class Person
//  {
//  public:
//      virtual A *f() { return new A; }
//  };
//  class Student : public Person
//  {
//  public:
//      virtual B *f() { return new B; }
//  };

// 以下看起来很正常，运行结果也合理，但是其实错误

// class Person
//{
// public:
//~Person() { cout << "~Person()" << endl; }
//};
// class Student : public Person
//{
// public:
//~Student() { cout << "~Student()" << endl; }
//};
// void test1()
//{
// Person p;
// Student s;
//}
// void test2()
//{
// Person *p1 = new Person;
// delete p1;
// Person *p2 = new Student;
// delete p2;
////p2子类对象，但是只调了父类的析构函数，error，资源没有全部释放
//}
// int main()
//{
////test1();
// test2();//error,说明上面的析构函数没有正确
// return 0;
//}

// class Person
// {
// public:
//     virtual ~Person() { cout << "~Person()" << endl; }
// };
// class Student : public Person
// {
// public:
//     virtual ~Student() { cout << "~Student()" << endl; }
// };
// // 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函
// // 数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
// int main()
// {
//     Person *p1 = new Person;
//     Person *p2 = new Student;
//     delete p1;
//     delete p2;
//     return 0;
// }

// 这下正确了，说明析构函数需要定义成虚函数

// class Base
// {
// public:
//     Base()
//     {
//         Init();
//     }
//     virtual void Init()
//     {
//         printf("Base Init\n");
//     }
//     void func()
//     {
//         printf("Base func\n");
//     }
// };
// class Derived: public Base
// {
// public:
//     virtual void Init()
//     {
//         printf("Derived Init\n");
//     }
//     void func()
//     {
//         printf("Derived func\n");
//     }
// };

// int main()
// {
//     Derived d;
//     ((Base *)&d)->func();

//     return 0;
// }

// class A
// {
// public:
//     virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//     virtual void test() { func(); }
// };
// class B : public A
// {
// public:
//     void func(int val = 0) { std::cout << "B->" << val << std::endl; }
// };
// int main(int argc, char *argv[])
// {
//     B *p = new B;
//     p->test();
//     return 0;
// }
//tips:
// 多态调子类的func，实现重写，但是重写继承了父类的函数名，参数列表，返回值，只是改变了实现（大括号里的），并没有改变函数名，所以继承了int val = 1的缺省参数。
// 体现接口继承

//  1. final：修饰虚函数，表示该虚函数不能再被重写
// class Car
// {
// public:
//     virtual void Drive() final {}
// };
// class Benz : public Car
// {
// public:
//     virtual void Drive() { cout << "Benz-舒适" << endl; }
// };
//  2. override: 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错。
// class Car
// {
// public:
//     virtual void Drive() {}
// };
// class Benz : public Car
// {
// public:
//     virtual void Drive() override { cout << "Benz-舒适" << endl; }
// };
// int main()
// {
//     Car *p1 = new Benz;
//     p1->Drive();
//     return 0;
// }

// 3. 抽象类：抽象类是一种特殊的类，它不能实例化，只能作为基类被继承，不能创建对象，只能作为接口使用。抽象类中可以有纯虚函数，纯虚函数是一种特殊的虚函数，它不提供函数体，只有函数头，不能实例化，只能作为基类被继承，不能创建对象，只能作为接口使用。
// class Car
// {
// public:
//     virtual void Drive() = 0;
// };
// int main()
// {
//     Car car;//error,抽象类不能实例化
//     return 0;
// }

// 多态如何实现的指向谁就调用谁的虚函数？多态是在运行时到指向的对象的虚表中查找要调用的虚函数的地址来进行调用
// 满足多态以后的函数调用，不是在编译时确定的，是运行起来以后到对象的中取找的。不满足多态的函数调用时编译时确认好的。

// 虚函数存在哪？ 代码段(常量区)   虚函数不是存在虚表，虚表中存的是虚函数的指针
// 虚函数表(虚表)存在哪？ 代码段(常量区)

// 问答题
// 1. 什么是多态？
// 2. 什么是重载、重写(覆盖)、重定义(隐藏)？
// 3. 多态的实现原理？
// 4. inline函数可以是虚函数吗？答：可以，不过编译器就忽略inline属性，这个函数就不再是inline，因为虚函数要放到虚表中去。
// 5. 静态成员可以是虚函数吗？答：不能，因为静态成员函数没有this指针，使用类型::成员函数的调用方式无法访问虚函数表，所以静态成员函数无法放进虚函数表。
// 6. 构造函数可以是虚函数吗？答：不能，因为对象中的虚函数表指针是在构造函数初始化列表阶段才初始化的。
// 7. 析构函数可以是虚函数吗？什么场景下析构函数是虚函数？答：可以，并且最好把基类的析构函数定义成虚函数。参考本节课件内容
// 8. 对象访问普通函数快还是虚函数更快？答：首先如果是普通对象，是一样快的。如果是指针对象或者是引用对象，则调用的普通函数快，因为构成多态，运行时调用虚函数需要到虚函数表中去查找。
// 9. 虚函数表是在什么阶段生成的，存在哪的？答：虚函数表是在编译阶段就生成的，一般情况下存在代码段(常量区)的。
// 10. C++菱形继承的问题？虚继承的原理？答：参考继承课件。注意这里不要把虚函数表和虚基表搞混了。
// 11. 什么是抽象类？抽象类的作用？答：参考（3.抽象类）。抽象类强制重写了虚函数，另外抽象类体现出了接口继承关系。
