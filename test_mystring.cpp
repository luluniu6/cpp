#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
namespace lala
{
	class string // 字符数组还存个\0
	{
	public:
		typedef char *iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char *str = "") // 构造函数
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string &s) // string s2(s1)->深拷贝,防止浅拷贝指向同一块空间然后被析构函数释放就没了
			: _str(nullptr), _size(0), _capacity(0)
		{
			string tmp(s._str);
			swap(tmp); // this->swap(tmp);
		}
		void swap(string &s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		string &operator=(string &s) // 实现s3=s1的赋值
		{
			swap(s); // this->swap(s);
			return *this;
		}
		~string() // 析构函数
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		const char *c_str()
		{
			return _str;
		}
		size_t size() const
		{
			return strlen(_str);
		}
		size_t capacity() const
		{
			return _capacity;
		}
		const char &operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}
		char &operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char *newstr = new char[n + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size == _capacity) // 增容
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
			// insert(_size,ch);//或者直接调用insert
		}
		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}
		void append(const char *str)
		{
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
			// insert(_size,str);//或者直接调insert
		}
		string &operator+=(char ch)
		{
			this->push_back(ch);
			return *this;
		}
		string &operator+=(const char *str)
		{
			this->append(str);
			return *this;
		}
		string &insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}
		string &insert(size_t pos, const char *str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				end--;
			}

			// for (int i = 0; i < len; i++)
			// {
			// 	_str[pos + i] = str[i];
			// }
			strncpy(_str + pos, str, len);

			_size += len;
			return *this;
		}
		string &erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len >= _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos + len;
				while (i <= _size)
				{
					_str[i - len] = _str[i];
					++i;
				}
				_size -= len;
			}
			return *this;
		}
		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
				return npos;
			}
		}
		size_t find(const char *str, size_t pos = 0)
		{
			char *p = strstr(_str, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - _str;
			}
		}
		bool operator<(const string &s)
		{
			int ret = strcmp(_str, s._str);
			return ret < 0;
		}
		bool operator==(const string &s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}
		bool operator<=(const string &s)
		{
			return *this < s || *this == s;
		}
		bool operator>(const string &s)
		{
			return !(*this < s);
		}
		bool operator>=(const string &s)
		{
			return !(*this <= s);
		}
		bool operator!=(const string &s)
		{
			return !(*this == s);
		}

	private:
		char *_str;
		size_t _size;	  // 已经有多少个有效字符
		size_t _capacity; // 能存多少个有效字符,\0不是有效字符

		const static size_t npos = -1; // 64位2^64-1=18446744073709551615输出为-1
	};

	istream &operator>>(istream &in, string &s)
	{
		while (1)
		{
			char ch;
			ch = in.get();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}
		return in;
	}
	ostream &operator<<(ostream &out, const string &s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		return out;
	}
	void test_string1()
	{
		string s1("hello");
		string s2("a");
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
		string s3 = s1;
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
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
	void test_string4()
	{
		string s1;
		string s2("hello");
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		// 三种遍历
		//  for(size_t i=0;i<s2.size();i++)
		//  {
		//  	s2[i]-=1;
		//  	cout<<s2[i]<<" ";
		//  }
		//  cout<<endl;
		string ::iterator it2 = s2.begin();
		while (it2 != s2.end())
		{
			*it2 += 1;
			cout << *it2 << " ";
			++it2;
		}
		cout << endl;
		// 范围for是由迭代器支持的，也就是说这段代码最终会被编译器替换成迭代器
		for (auto e : s2)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_string5()
	{
		string s1("hello");
		s1.push_back(' ');
		s1.push_back('l');
		s1.push_back('u');
		s1.push_back('l');
		s1.push_back('u');
		cout << s1 << endl;
		s1.append(" lala!");
		cout << s1 << endl;
	}
	void test_string6()
	{
		string s1("lala");
		s1 += "hello";
		cout << s1;
	}
	void test_string7()
	{
		string s1("helo");
		s1.insert(2, 'l');
		cout << s1 << endl;
		s1.insert(3, "la");
		cout << s1 << endl;

		string s2("hello");
		s2.reserve(10);
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl;

		s2.resize(8, 'x');
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl;

		s2.resize(18, 'a');
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl;

		s2.resize(2, 'a');
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl;

		s1.erase(3, 1);
		cout << s1 << endl;
	}
	void test_string8()
	{
		string s1("abcdabcdef");
		cout << s1.find("cde") << endl;
		cout << s1.find("cdex") << endl;
	}
	void test_string9()
	{
		string s;
		cin >> s;
		cout << s;
	}
}
int main()
{
	// lala::test_string1();
	lala::test_string2();
	// lala::test_string3();
	// lala::test_string4();
	// lala::test_string5();
	// lala::test_string6();
	// lala::test_string7();
	// lala::test_string8();
	// lala::test_string9();

	return 0;
}

namespace lala_easy
{
	// 面试限时实现一个String类，不可能具备std：string的功能
	// 但至少要求能正确管理资源-->构造+析构+拷贝+operator=
	class String
	{
	public:
		String(const char *str = "") // 构造函数
			: _str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}
		// String(const String &s)// 深拷贝-传统写法
		// :_str(new char[strlen(s._str)+1])
		// {
		// 	strcpy(_str,s._str);
		// }
		String(const String &s) // 深拷贝-现代写法
			: _str(nullptr)
		{
			String tmp(s._str); // 调用构造函数，不能写成括号里面是s不然就相当于调拷贝构造会死循环
			swap(_str, tmp._str);
		}
		// String& operator=(const String& s)// s3=s1 传统写法
		// {
		// 	if(this!=&s)
		// 	{
		// 		char* tmp=new char[strlen(s._str)+1];
		// 		strcpy(tmp,s._str);
		// 		delete[] _str;
		// 		_str=tmp;
		// 	}
		// 	return *this;
		// }
		// String& operator=(const String& s)// s3=s1 现代写法1
		// {
		// 	if(this!=&s)
		// 	{
		// 		String tmp(s);
		// 		swap(_str,tmp._str);
		// 	}
		// 	return *this;
		// }
		String &operator=(String s) // s3=s1 现代写法最终版
		{
			swap(_str, s._str);
			return *this;
		}
		size_t size() const
		{
			return strlen(_str);
		}
		const char &operator[](size_t i) const
		{
			return _str[i];
		}
		char &operator[](size_t i)
		{
			return _str[i];
		}
		~String()
		{
			delete[] _str;
			_str = nullptr;
		}

	private:
		char *_str;
	};
	ostream &operator<<(ostream &out, const String &s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		return out;
	}
	void test_String()
	{
		String s1("hello");
		String s2(s1);
		String s3 = s1;
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
	}
}
// int main()
// {
// 	lala_easy::test_String();
// }