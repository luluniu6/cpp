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
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
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
		void insert(size_t pos, char ch)
		{
			assert(pos<_szie);
			if(_size==_capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			int end=_size();
			while(end>=pos)
			{
				_str[end+1]=_str[end];
				--end;
			}
			_str[pos]=ch;
			++_szie;
		}
		void insert(size_t pos, const char *str);
		void erase(size_t pos, size_t len = npos);
		size_t find(char ch, size_t pos = 0);
		size_t find(const char *str, size_t pos = 0);
		bool operator<(const string &s);
		bool operator==(const string &s);
		bool operator<=(const string &s);
		bool operator>(const string &s);
		bool operator>=(const string &s);
		bool operator!=(const string &s);

	private:
		char *_str;
		size_t _size;	  // 已经有多少个有效字符
		size_t _capacity; // 能存多少个有效字符,\0不是有效字符
		static size_t npos;
	};

	string ::npos = -1;

	ostream &operator<<(ostream &out, const string &s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			cout << s[i];
		}
		return out;
	}
	// void test_string1()
	// {
	// 	string s1("hello");
	// 	string s2;
	// 	for (size_t i = 0; i < s1.size(); i++)
	// 	{
	// 		s1[i] += 'a'
	// 		cout << s1[i] << " ";
	// 	}
	// 	for (size_t i = 0; i < s2.size(); i++)
	// 	{
	// 		s2[i] += 'a';
	// 		cout << s2[i] << " ";
	// 	}
	// }
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
}
int main()
{
	// lala::test_string1();
	// lala::test_string2();
	// lala::test_string3();
	// lala::test_string4();
	// lala::test_string5();
	lala::test_string6();
	return 0;
}
