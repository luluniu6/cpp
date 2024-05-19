#include <bits/stdc++.h>
using namespace std;

namespace lala
{
    // template <class T>
    // class<vector>
    // {
    // public:

    // private:
    //     T *a;
    //     size_t _size;
    //     size_t _capacity;
    // }
    template <class T>
    class vector
    {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;

        vector()
            : _start(nullptr), _finish(nullptr), _endofstorage(nullptr)
        {
        }
        // vector(const vector<T> &v)//v2(v1)_1
        // {
        //     _start = new T[v.capacity()];
        //     _finish = _start;
        //     _endofstorage = _start + v.capacity();

        //     for (size_t i = 0; i < v.size(); i++)
        //     {
        //         *_finish = v[i];
        //         ++_finish;
        //     }
        // }
        vector(const vector<T> &v) // v2(v1)_2
            : _start(nullptr), _finish(nullptr), _endofstorage(nullptr)
        {
            reserve(v.capacity());
            for (const auto &e : v)
            {
                push_back(e);
            }
        }
        // vector<T> &operator=(const vector<T> &v)//v1=v3_1
        // {
        //     if (this != &v)
        //     {
        //         delete[] _start;
        //         _start = new T[v.capacity()];
        //         memccpy(_start, v._start, sizeof(T) * v.size());
        //     }
        //     return *this;
        // }
        vector<T> &operator=(const vector<T> v)//v1=v3_2利用传值构造调用拷贝构造函数
        {
            // swap(_start,v._start);
            // swap(_finish,v._finish);
            // swap(_endofstorage,v._endofstorage);
            // //swap(*this,v);//(swap(v))建议不要用这种，因为实现是靠三个深拷贝代价大
            // //所以一般会写个内置的swap函数包括上面三个交换(交换指针)
            swap(v);
            return *this;
        }
        void swap(vector<T>& v)
        {
            ::swap(_start,v._start);
            ::swap(_finish,v._finish);
            ::swap(_endofstorage,v._endofstorage);
        }
        ~vector()
        {
            delete[] _start;
            _start = _finish = _endofstorage = nullptr;
        }
        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        const_iterator begin() const
        {
            return _start;
        }
        const_iterator end() const
        {
            return _finish;
        }
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t sz = size();
                T *tmp = new T[n];
                if (_start)
                {
                    //memcpy(tmp, _start, sizeof(T) * sz);//按字节拷贝，浅拷贝
                    for(size_t i=0;i<sz;i++)
                    {
                        tmp[i]=_start[i];//调用的是operator= 深拷贝
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = tmp + sz;
                _endofstorage = tmp + n;
            }
        }
        void resize(size_t n, const T &val = T())
        {
            if (n < size())
            {
                _finish = _start + n;
            }
            else
            {
                if (n > capacity())
                {
                    reserve(n);
                }
                iterator it = _finish;
                while (_finish < _start + n)
                {
                    *_finish = val;
                    ++_finish;
                }
            }
        }
        void push_back(const T &x)
        {
            // if (_finish == _endofstorage)
            // {
            //     size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
            //     reserve(newcapacity);
            // }
            // *_finish = x;
            // ++_finish;
            insert(_finish, x);
        }
        void pop_back()
        {
            // assert(_start < _finish);
            // --_finish;
            erase(_finish - 1);
        }
        void insert(iterator pos, const T &x)
        {
            assert(pos <= _finish); // 取等号时即为尾插，此时不会进入下面的while
            if (_finish == _endofstorage)
            {
                size_t n = pos - _start;
                size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
                reserve(newcapacity);
                pos = _start + n;
            }
            iterator end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                end--;
            }
            *pos = x;
            ++_finish;
        }
        iterator erase(iterator pos)
        {
            assert(pos < _finish);
            iterator it = pos;
            while (it < _finish)
            {
                *it = *(it + 1);
                ++it;
            }
            --_finish;
            return pos;
        }
        T &operator[](size_t i)
        {
            assert(i < size());
            return _start[i];
        }
        const T &operator[](size_t i) const
        {
            assert(i < size());
            return _start[i];
        }
        size_t size() const
        {
            return _finish - _start;
        }
        size_t capacity() const
        {
            return _endofstorage - _start;
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
    };
    void print_vector(const vector<int> &v)
    {
        vector<int>::const_iterator it = v.begin();
        while (it != v.end()) // 迭代器遍历
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
    void test_vector1()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        print_vector(v);

        cout << v.size() << endl;
        cout << v.capacity() << endl;

        vector<int>::iterator it = v.begin();
        while (it != v.end()) // 迭代器遍历
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
        for (auto e : v) // 范围for遍历
        {
            e -= 1; // 只是对e进行改变如果想改变v里面的值得用引用
            cout << e << " ";
        }
        cout << endl;
        for (size_t i = 0; i < v.size(); i++) //[下标]遍历
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    void test_vector2()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(30);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        print_vector(v);

        vector<int>::iterator it = v.begin();
        while (it != v.end())
        {
            if (*it % 2 == 0)
            {
                it = v.erase(it);
            }
            else
            {
                ++it;
            }
        }
        print_vector(v);
    }
    void test_vector3()
    {
        vector<int> v;
        v.reserve(10);
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        v.push_back(7);
        print_vector(v);
        cout << v.size() << endl;
        cout << v.capacity() << endl
             << endl;

        v.resize(4);
        print_vector(v);
        cout << v.size() << endl;
        cout << v.capacity() << endl
             << endl;

        v.resize(8);
        print_vector(v);
        cout << v.size() << endl;
        cout << v.capacity() << endl
             << endl;

        v.resize(12, 250);
        print_vector(v);
        cout << v.size() << endl;
        cout << v.capacity() << endl
             << endl;
    }
    void test_vector4()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        print_vector(v1);
        vector<int> v2(v1);
        print_vector(v1);
    }
    void test_vector5()
    {
        vector<int> v3;
        v3.push_back(1);
        v3.push_back(2);
        v3.push_back(3);
        v3.push_back(4);
        v3.push_back(5);
        print_vector(v3);
        vector<int> v1 = v3;
        print_vector(v1);
    }
    void test_vector6()
    {
        vector<string> v;
        v.push_back("111");
        v.push_back("222");
        v.push_back("333");
        v.push_back("444");
        v.push_back("555");
        for(auto e: v)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    // lala::test_vector1();
    // lala::test_vector2();
    // lala::test_vector3();
    //lala::test_vector4();
    //lala::test_vector5();
    lala::test_vector6();
    return 0;
}