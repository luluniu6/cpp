#include <bits/stdc++.h>
using namespace std;

int main2()
{
    // 引用取别名时，变量访问的权限可以缩小不能放大

    int i = 0;
    double db = i;        // 隐式类型转换会创建double的临时变量，临时变量具有常性
    const double &rd = i; // 要加const
    return 0;
}
void TestFor() // 范围for
{
    int array[] = {1, 2, 3, 4, 5};
    for (auto &e : array)
        e *= 2;
    for (auto e : array)
        cout << e << " ";
    return;
}
// class Date
//{
// public:
//	// 1.无参构造函数
//	Date()
//	{}
//	// 2.带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
// private:
//	int _year;
//	int _month;
//	int _day;
// };
class Time
{
public:
    Time()
    {
        int _hour = 0;
        int _minute = 0;
        int _second = 0;
    }

private:
    int _hour;
    int _minute;
    int _second;
};
// int main()
//{
//	//TestFor();
//	Date d1;
//	d1.Print();
//	Date d2(2003, 1, 1);
//	d2.Print();
//	Time t1;
//
//	return 0;
// }

class Date
{
public:
    // explicit Date(int year = 1900, int month = 1, int day = 1)
    //  构造函数不仅可以构造与初始化对象，对于单个参数或者除第一个参数无默认值其余均有默认值的构造函数，还具有类型转换的作用。
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    Date(const Date &d) // 不用引用是错误写法，编译报错，会引发无穷递归 没有可用的复制构造函数
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    // bool operator==(const Date& d1, const Date& d2)//运算符过多因为有一个隐含的this指针
    //{
    //	return d1._year == d2._day
    //		&& d1._month == d2._month
    //		&& d1._day == d2._day;
    // }

    // d1==d2;
    // d1.operator==(&d1,d2);
    bool operator==(const Date &d2) // bool operator==(Date* this,const Date& d2)
    {
        return /*this->*/ _year == d2._day && _month == d2._month && _day == d2._day;
    }

    /*void operator=(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }*/
    Date &operator=(const Date &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
        return *this; // 如果不用引用返回，将创建Date类型的临时变量
    }

    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

// 运算符有几个操作数，opeator重载的函数就有几个参数
// 写成全局，但只能在类中变量为public中才可以使用
// bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._day
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
// }
// 自定义类型是不能用运算符的，要用就得实现重载函数，
int mainnnnnnn()
{
    Date d1(2020, 4, 15);
    Date d2;

    // 我们不实现时，编译器生成默认构造函数和析构函数。
    //  针对成员变量：内置类型就不处理，自定义类型会调这个成员对象的构造和析构

    d2 = d1;     // operator=
    Date d3(d1); // 拷贝构造

    // 我们不实现时（把Date(const Date& d)和void operator=(const Date& d)屏蔽掉），
    //  编译器生成默认拷贝构造函数和operator=，会完成按字节的值拷贝（浅拷贝）
    // 也就是说有些类，我们是不需要去实现拷贝构造函和operator=的，因为编译器生成的就能用，比如Date类
    // 但是Stack这个类就不可以有浅拷贝问题，因为在调用析构函数时候，同一块空间不能被释放两次

    d1 == d2; // 如果不写，编译器不会自动生成，因为它不是默认成员函数

    d1.Print();
    d2.Print();
    d3.Print();

    Date d11(1);  // 构造
    Date d22 = 2; // 隐式类型的转换(单参数但我懒得改了)，构造出tmp（2）+用tmp拷贝构造d2(tmp)+优化成直接构造
    // const Date& d22 = 2;//引用就是中间产生的临时变量
    Date d33 = d11; // 拷贝构造

    Date d44 = {2, 4, 2}; // 隐式类型的转换(多参数)C++11花括号
    d11.Print();
    d22.Print();
    d44.Print();

    // 隐式类型的转换
    int i = 1;
    // double d = i;
    // 会创建一个double临时变量，临时变量给d，临时变量具有常性
    const double &d = i; // 只加&引用表示可以修改值，但常性不能被修改，所以前面要加const

    return 0;
}

// class Date
//{
// public:
//	int GetMonthDay(int year, int month)
//	{
//		static int monthDayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			return 29;
//		}
//		else
//		{
//			return monthDayArray[month];
//		}
//	}
//
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// cout << (d1 == d2) << endl; // 转换成d1.operator==(d2)
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	// d1 > d2
//	bool operator>(const Date& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//
//		return false;
//	}
//
//	// d1 >= d2
//	bool operator>=(const Date& d)
//	{
//		return *this > d || *this == d;
//	}
//
//	// ....  <  <=  !=
//
//	// d1 += 100
//	Date& operator+=(int day)
//	{
//		_day += day;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			_month++;
//
//			if (_month == 13)
//			{
//				++_year;
//				_month = 1;
//			}
//		}
//
//		return *this;
//	}
//
//	// d1 + 100
//	Date operator+(int day)
//	{
//		Date ret(*this);
//		ret += day;
//		return ret;
//	}
//
// private:
//	int _year;
//	int _month;
//	int _day;
// };

// int main()
//{
//	Date d1(2022, 9, 22);
//	Date d2(2022, 9, 22);
//
//	cout << (d1 > d2) << endl;
//	cout << (d1 == d2) << endl; // 转换成d1.operator==(d2)
//
//	// 也可以显示调用，一般不这样
//	cout << d1.operator==(d2) << endl;
//
//	d1 += 50;
//	d2 += 100;
//
//	/*d1 - d2;*/
//
//	return 0;
// }

// class A
//{
// public:
//	A(int a)
//		:_a(a)
//	{}
// private:
//	int _a;
// };
// class B
//{
// public:
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{
//		_x = 10;
//	}
// private:
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const
//	int _x;
// };
// int main()
//{
//	B b(1, 2);
//	return 0;
// }

// 看一个创建了多少个对象
class A
{
public:
    A()
    {
        ++n;
    }
    A(const A &a)
    {
        ++n;
    }
    static int GetN() // 没有this指针，函数中不可以访问非静态的成员
    {
        return n;
    }

private:
    static int n; // 声明，不是属于某个对象，是属于类的所有对象，属于这个类
    // n不在对象中，n在静态区
};
int A::n = 0; // 定义
// A f1(A a)//传参拷贝构造，传值返回拷贝构造
// A& f1(A a)//传参拷贝构造，传引用返回
A &f1(A &a) // 引用传参，引用返回，不调用拷贝构造
{
    return a;
}
// int main()
//{
//	A a1;
//	A a2;
//	/*f1(a1);
//	f1(a2);*/
//	/*cout << n;*/
//	cout << a1.GetN() << endl;
//	cout << a2.GetN() << endl;//传值返回是返回n的拷贝，只读
//	//可以改成引用返回就可以修改
//	//再加个const也不能修改了
//	cout << A::GetN << endl;
//	return 0;
// }
class L
{
public:
    L()
    {
        ++_N;
        sum += _N;
    }
    static void Reset()
    {
        _N = 0;
        sum = 0;
    }
    static int getsum()
    {
        return sum;
    }

private:
    static int _N;
    static int sum;
};
int L::_N = 0;
int L::sum = 0;
class Solution
{
public:
    int Sum_Solution(int n)
    {
        L::Reset(); // 每次调用构造函数要清除之前的数据
        L *a = new L[n];
        delete[] a;  // 防止内存泄漏
        a = nullptr; // 防止悬空指针
        return L::getsum();
    }
};
// int main()
//{
//	Solution l;
//	int num = 0;
//	while (~scanf("%d", &num))
//	{
//		if (num == -1)
//			break;
//		cout << l.Sum_Solution(num) << endl;
//	}
//
// }

class Datee
{
    friend ostream &operator<<(ostream &_cout, const Datee &d);
    friend istream &operator>>(istream &_cin, Datee &d);

public:
    Datee(int year = 1900, int month = 1, int day = 1)
        : _year(year), _month(month), _day(day)
    {
    }

private:
    int _year;
    int _month;
    int _day;
};
ostream &operator<<(ostream &_cout, const Datee &d)
{
    _cout << d._year << "-" << d._month << "-" << d._day;
    return _cout;
}
istream &operator>>(istream &_cin, Datee &d)
{
    _cin >> d._year;
    _cin >> d._month;
    _cin >> d._day;
    return _cin;
}
int main()
{
    Datee d;
    // 为什么能自动识别类型，因为函数重载
    cin >> d;
    cout << d << endl;
    return 0;
}