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
// 子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的直接访问，这种情况叫隐藏，也叫重定义。（在子类成员函数中，可以使用 基类::基类成员 显示访问）
// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆

// class Person
// {
// protected:
//     string _name = "啦啦"; // 姓名
//     int _num = 111;        // 身份证号
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

// a.重载  b.重写   c.重定义   d.编译不通过
// 选c.重定义也就是隐藏
//  // B中的fun和A中的fun不是构成重载，因为不是在同一作用域
//  // B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。

// class A
// {
// public:
//     void fun()
//     {
//         cout << "func()" << endl;
//     }
// };
// class B : public A
// {
// public:
//     void fun(int i)
//     {
//         A::fun();
//         cout << "func(int i)->" << i << endl;
//     }
// };
// void Test()
// {
//     B b;
//     b.fun(10);
//     // b.fun();//隐藏了A中的fun,调不动
//     // b.A::fun(); //显示调用A中的fun
// }

//----------------------------------------------------------------------

// 派生类的默认成员函数
//----------------------------------------------------------------------

// class Person
//{
// public:
// Person(const char *name = "peter")
//: _name(name)
//{
// cout << "Person()" << endl;
//}
// Person(const Person &p)
//: _name(p._name)
//{
// cout << "Person(const Person& p)" << endl;
//}
// Person &operator=(const Person &p)
//{
// cout << "Person operator=(const Person& p)" << endl;
// if (this != &p)
//_name = p._name;
// return *this;
//}
//~Person()
//{
// cout << "~Person()" << endl;
//}

// protected:
// string _name; // 姓名
//};
// class Student : public Person
//{
// public:
// Student(const char *name, int num)
//: Person(name), _num(num)
//{
// cout << "Student()" << endl;
//}
// Student(const Student &s)
//: Person(s), _num(s._num)
////传子类对象就行，会切割然后调用父类的拷贝构造函数
//{
// cout << "Student(const Student& s)" << endl;
//}
// Student &operator=(const Student &s)
//{
// cout << "Student& operator= (const Student& s)" << endl;
// if (this != &s)
//{
// Person::operator=(s);
////调用Person的赋值运算符
////不能写成operator=(s)，因为Person的被Student隐藏，会重复调用自己，需要指定作用域Person::
//_num = s._num;
//}
// return *this;
//}
//~Student()//子类的析构函数和父类的析构函数构成隐藏，因为它们的名字会被编译器统一处理为destructor
//{
////不能写~Person()，因为~Person()已经被~Student()隐藏

////Person::~Person();//也不用写这个
////正确的用法不需要我们自己显式调用析构函数
////结束时会自动调用父类的析构函数，因为这样才能保证先析构子类后析构父类
// cout << "~Student()" << endl;
//}

// protected:
// int _num; // 学号
//};

// void Test()
//{
// Student s1("jack", 18);
// Student s2(s1);
// Student s3("rose",17);
// s1 = s3;
//}
// int main()
//{
// Test();
// return 0;
//}

////----------------------------------------------------------------------

// 如何设计一个不能被继承的类？
////----------------------------------------------------------------------

// class A
//{
// private:
// A(){}
//};//A是一个不能被继承的类
// class B : public A
//{};
////----------------------------------------------------------------------

// 友元不能被继承
// 也就是说基类友元不能访问子类私有和保护成员

// class Student;
// class Person
//{
// public:
// friend void Display(const Person &p, const Student &s);

// protected:
// string _name; // 姓名
//};
// class Student : public Person
//{
// protected:
// int _stuNum; // 学号
//};
// void Display(const Person &p, const Student &s)
//{
// cout << p._name << endl;
// cout << s._stuNum << endl;
//}
// int main()
//{
// Person p;
// Student s;
// Display(p, s);
//}
////----------------------------------------------------------------------

// 继承与静态成员
// 基类定义了static静态成员，则整个继承体系里面只有一个这样的成员。无论派生出多少个子类，都只有一个static成员实例
////----------------------------------------------------------------------
// class Person
//{
// public:
// Person() { ++_count; }

// protected:
// string _name; // 姓名
// public:
// static int _count; // 统计人的个数。
//};
// int Person ::_count = 0;
// class Student : public Person
//{
// protected:
// int _stuNum; // 学号
//};
// class Graduate : public Student
//{
// protected:
// string _seminarCourse; // 研究科目
//};
// void TestPerson()
//{
// Student s1;
// Student s2;
// Student s3;
// Graduate s4;
// cout << " 人数 :" << Person ::_count << endl;
// Student ::_count = 0;
// cout << " 人数 :" << Person ::_count << endl;
//}
// int main()
//{
// TestPerson();
// return 0;
//}
////----------------------------------------------------------------------

// 复杂的菱形继承及菱形虚拟继承
// 单继承：一个子类只有一个直接父类时称这个继承关系为单继承
// 多继承：一个子类有两个或以上直接父类时称这个继承关系为多继承
// 菱形继承：菱形继承是多继承的一种特殊情况

// 菱形继承的问题：从下面的对象成员模型构造，可以看出菱形继承有数据冗余和二义性的问题。
// 在Assistant的对象中Person成员会有两份

// class Person
// {
// public:
//     string _name; // 姓名
// };
// class Student : public Person
// {
// protected:
//     int _num; // 学号
// };
// class Teacher : public Person
// {
// protected:
//     int _id; // 职工编号
// };
// class Assistant : public Student, public Teacher
// {
// protected:
//     string _majorCourse; // 主修课程
// };
// void Test()
// {
//     // 这样会有二义性无法明确知道访问的是哪一个
//     Assistant a;
//     //a._name = "peter";//error
//     // 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//     a.Student::_name = "xxx";
//     a.Teacher::_name = "yyy";
// }
// int main()
// {
//     Test();
//     return 0;
// }

////----------------------------------------------------------------------
// 解决方法：虚拟继承可以解决菱形继承的二义性和数据冗余的问题。如上面的继承关系，在Student和Teacher的继承Person时使用虚拟继承，即可解决问题。需要注意的是，虚拟继承不要在其他地方去使用

// class Person
// {
// public:
//     string _name; // 姓名
// };
// class Student : virtual public Person
// {
// protected:
//     int _num; // 学号
// };
// class Teacher : virtual public Person
// {
// protected:
//     int _id; // 职工编号
// };
// class Assistant : public Student, public Teacher
// {
// protected:
//     string _majorCourse; // 主修课程
// };
// void Test()
// {
//     Assistant a;
//     a._name = "peter";
// }
// int main()
// {
//     Test();
// }

////----------------------------------------------------------------------
// C++的缺陷有哪些？
// 多继承-->菱形继承-->虚继承-->底层结构的对象模型非常复杂，且有一定的效率损失
// 什么是菱形继承？
// 菱形继承的问题是什么？
// 如何解决？-->虚继承-->解决原理是什么？

////----------------------------------------------------------------------

// 虚拟继承解决数据冗余和二义性的原理
// 为了研究虚拟继承原理，我们给出了一个简化的菱形继承继承体系，再借助内存窗口观察对象成员的模型。

class A
{
public:
    int _a;
};
class B : virtual public A
{
public:
    int _b;
};
class C : virtual public A
{
public:
    int _c;
};
class D : public B, public C
{
public:
    int _d;
};
int main()
{
    D d;
    d.B::_a = 1;
    d.C::_a = 2;
    d._b = 3;
    d._c = 4;
    d._d = 5;
    return 0;
}

// 这里可以分析出D对象中将A放到的了对象组成的最下面，这个A同时属于B和C，那么B和C如何去找到公共的A呢？这里是通过了B和C的两个指针，指向的一张表。这两个指针叫虚基表指针，这两个表叫虚基表。虚基表中存的偏移量。通过偏移量可以找到下面的A。