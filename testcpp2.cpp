#include <iostream>
#include <string>
#include <vector>
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

// // 模板的特化
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
// 类的特化类似，在类名后面加<>
// 全特化
// 偏特化

// 类模板的全特化
// template <class T1, class T2>
// class Data
// {
// public:
//     Data() { cout << "Data<T1, T2>" << endl; }
// private:
//     T1 _d1;
//     T2 _d2;
// };
// template <>
// class Data<int, char>
// {
// public:
//     Data() { cout << "Data<int, char>" << endl; }
// private:
//     int _d1;
//     char _d2;
// };
// void TestVector()
// {
//     Data<int, int> d1;
//     Data<int, char> d2;
// }

// 偏特化
template <class T1, class T2>
class Data
{
public:
    Data() { cout << "Data<T1, T2>" << endl; }

private:
    T1 _d1;
    T2 _d2;
};

// 1.部分特化
// 将模板参数类表中的一部分参数特化
//  将第二个参数特化为int
template <class T1>
class Data<T1, int>
{
public:
    Data() { cout << "Data<T1, int>" << endl; }

private:
    T1 _d1;
    int _d2;
};
// 2.参数进一步的限制
// 偏特化并不仅仅是指特化部分参数，而是针对模板参数更进一步的条件限制所设计出来的一个特化版本。
//  两个参数偏特化为指针类型
template <typename T1, typename T2>
class Data<T1 *, T2 *>
{
public:
    Data() { cout << "Data<T1*, T2*>" << endl; }

private:
    T1 _d1;
    T2 _d2;
};
// 两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data<T1 &, T2 &>
{
public:
    Data(const T1 &d1, const T2 &d2)
        : _d1(d1), _d2(d2)
    {
        cout << "Data<T1&, T2&>" << endl;
    }

private:
    const T1 &_d1;
    const T2 &_d2;
};
void test2()
{
    Data<double, int> d1;        // 调用特化的int版本
    Data<int, double> d2;        // 调用基础的模板
    Data<int *, int *> d3;       // 调用特化的指针版本
    Data<int &, int &> d4(1, 2); // 调用特化的指针版本
}

// 类模板特化应用示例
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}

	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// cout << (d1 == d2) << endl; // 转换成d1.operator==(d2)
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	// d1 > d2
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

	// d1 >= d2
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}

	// ....  <  <=  !=
    bool operator<(const Date& d)
	{
		return !(*this >= d);
	}

	bool operator<=(const Date& d)
	{
		return !(*this > d);
	}

    bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// d1 += 100
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;

			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}

		return *this;
	}

	// d1 + 100
	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		return ret;
	}

private:
	int _year;
	int _month;
	int _day;
};

// 有如下专门用来按照小于比较的类模板Less：
#include <vector>
#include <algorithm>
template <class T>
struct Less
{
    bool operator()(const T &x, const T &y) const
    {
        return x < y;
    }
};
int main()
{
    Date d1(2022, 7, 7);
    Date d2(2022, 7, 6);
    Date d3(2022, 7, 8);
    vector<Date> v1;
    v1.push_back(d1);
    v1.push_back(d2);
    v1.push_back(d3);
    // 可以直接排序，结果是日期升序
    sort(v1.begin(), v1.end(), Less<Date>());
    vector<Date *> v2;
    v2.push_back(&d1);
    v2.push_back(&d2);
    v2.push_back(&d3);
    // 可以直接排序，结果错误日期还不是升序，而v2中放的地址是升序
    // 此处需要在排序过程中，让sort比较v2中存放地址指向的日期对象
    // 但是走Less模板，sort在排序时实际比较的是v2中指针的地址，因此无法达到预期
    sort(v2.begin(), v2.end(), Less<Date *>());
    return 0;
}
// 通过观察上述程序的结果发现，对于日期对象可以直接排序，并且结果是正确的。但是如果待排序元素是指针，结果就不一定正确。因为：sort最终按照Less模板中方式比较，所以只会比较指针，而不是比较指针指向空间中内容，此时可以使用类版本特化来处理上述问题：
//  对Less类模板按照指针方式特化
template <>
struct Less<Date *>
{
    bool operator()(Date *x, Date *y) const
    {
        return *x < *y;
    }
};
// 特化之后，在运行上述代码，就可以得到正确的结果


//  模板分离编译
//  什么是分离编译
//  一个程序（项目）由若干个源文件共同实现，而每个源文件单独编译生成目标文件，最后将所有目标文件链接起来形成单一的可执行文件的过程称为分离编译模式。
//  模板的分离编译
//  假如有以下场景，模板的声明与定义分离开，在头文件中进行声明，源文件中完成定义：

// // a.h
// template<class T>
// T Add(const T& left, const T& right);

// // a.cpp
// template<class T>
// T Add(const T& left, const T& right)
// {
//     return left + right;
// }

// // main.cpp
// //#include "a.h"
// int main()
// {
//     Add(1,2);
//     Add(1.0, 2.0);
//     return 0;
// }

//解决方法
//1. 将声明和定义放到一个文件 "xxx.hpp" 里面或者xxx.h其实也是可以的。推荐使用这种。
//2. 模板定义的位置显式实例化。这种方法不实用，不推荐使用。

//模板总结
//【优点】
//1. 模板复用了代码，节省资源，更快的迭代开发，C++的标准模板库(STL)因此而产生
//2. 增强了代码的灵活性
//【缺陷】
//1. 模板会导致代码膨胀问题，也会导致编译时间变长
//2. 出现模板编译错误时，错误信息非常凌乱，不易定位错误

// 解决模板不能分离编译的方法：
// 1.显示实例化 不常用，因为不方便
// 2.粗暴，不要分离编译

// virtual 关键字
// 可以修饰成原函数，为了完成虚函数的重写，满足多态的条件之一
// 可以在菱形继承中，去完成虚继承，解决数据冗余和二义性
// 两个地方使用了同一个关键字，但是他们互相之间没有一点关联

// //多态的两个条件
// //1.虚函数的重写
// //2.父类对象的指针或者引用去调用虚函数

// //满足多态：跟调用对象的类型无关，跟指向对象有关，指向哪个对象调用就是他的虚函数
// //不满足多态：跟调用对象的类型有关，类型是什么调用的就是谁的虚函数
// class Person
// {
// public:
//     virtual void BuyTicket()
//     {
//         cout<<"Person::买票-全价"<<endl;
//     }
// };
// class Student :public Person
// {
// public:
//     virtual void BuyTicket()
//     {
//         cout<<"Student::买票-半价"<<endl;
//     }
// };
// void Func(Person& p)
// {
//     p.BuyTicket();
// }
// int main()
// {
//     Person p;
//     Student s;
//     Func(p);
//     Func(s);
//     return 0;
// }

// 虚函数重写的两个例外：
// 1. 协变(基类与派生类虚函数返回值类型不同)
// 派生类重写基类虚函数时，与基类虚函数返回值类型不同。即基类虚函数返回基类对象的指针或者引用，派生类虚函数返回派生类对象的指针或者引用时，称为协变。（了解）
// 2. 析构函数的重写(基类与派生类析构函数的名字不同)
// 如果基类的析构函数为虚函数，此时派生类析构函数只要定义，无论是否加virtual关键字，都与基类的析构函数构成重写，虽然基类与派生类析构函数名字不同。虽然函数名不相同，看起来违背了重写的规则，其实不然，这里可以理解为编译器对析构函数的名称做了特殊处理，编译后析构函数的名称统一处理成destructor。

// 析构函数是否需要定义成虚函数--需要
//  class Person
//  {
//  public:
//      virtual ~Person() {cout<<"~Person()"<<endl;}
//  };
//  class Student:public Person
//  {
//  public:
//      virtual ~Student() {cout<<"~Student()"<<endl;}
//  };
//  //这两个析构函数虽然函数名不相同，但会被处理成destructor
//  int main()
//  {
//      Person* p1=new Person;
//      delete p1;
//      Person *p2 =new Student;
//      delete p2;
//      return 0;
//  }

class A
{
public:
    virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
    virtual void test() { func(); } // A* this
};
class B : public A
{
public:
    void func(int val = 0) { std::cout << "B->" << val << std::endl; } // 子类的virtual省略，重写是对函数体内容重写，继承下来virtual void func(int val = 1),所以val继承下来为1,而且子类的func的缺省值val=0压根不起作用
    // 体现接口继承
};
int main()
{
    B *p = new B;
    p->test(); // p->test(p);
    return 0;
}
// A: A->0 B: B->1 C: A->1 D: B->0 E: 编译出错 F: 以上都不正确
// 答案为B

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
