#include <bits/stdc++.h>
using namespace std;
namespace lala
{
	class string
	{
	public:
		// string()//两种构造但被下面的缺省值的代替
		// 	: _str(new char[1])
		// {
		// 	_str[0]='\0';
		// }
		// string(char *str)
		// 	: _str(new char[strlen(str) + 1])
		// {
		// 	strcpy(_str, str);
		// }
		string(const char *str = "") // 构造函数
			// : _str(new char[strlen(str) + 1])
		{
			_size=strlen(str);
			_capacity=_size;
			_str=new char[];
		}
		string(const string &s) // string s2(s1)->深拷贝,防止浅拷贝指向同一块空间然后被析构函数释放就没了
			: _str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		string &operator=(const string &s) // 实现s1=s2的赋值
		{
			if (this != &s) // 防止s1=s1的赋值
			{
				char *tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}

			return *this;
		}
		~string() // 析构函数
		{
			delete[] _str;
			_str = nullptr;
		}
		const char *c_str()
		{
			return _str;
		}
		size_t size()
		{
			return strlen(_str);
		}
		char &operator[](size_t i)
		{
			return _str[i];
		}

	private:
		char *_str;
		size_t size;
		size_t capacity;
	};
	void test_string1()
	{
		string s1("hello");
		string s2;
		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i] += 1;
			cout << s1[i] << " ";
		}
		for (size_t i = 0; i < s2.size(); i++)
		{
			s2[i] += 1;
			cout << s2[i] << " ";
		}
	}
	void test_string2()
	{
		string s1("hello");
		string s2(s1);
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		for (size_t i = 0; i < s2.size(); i++)
		{
			cout << s2[i] << " ";
		}
	}
	void test_string3()
	{
		string s1("lalala");
		string s2 = s1;
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i];
		}
		cout << endl;
		for (size_t i = 0; i < s2.size(); i++)
		{
			cout << s2[i];
		}
		cout << endl;
	}
}
int main(int argc, char const *argv[])
{
	// lala::test_string1();
	// lala::test_string2();
	lala::test_string3();
	return 0;
}
