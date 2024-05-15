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
                    memcpy(tmp, _start, sizeof(T) * sz);
                    delete[] _start;
                }
                _start = tmp;
                _finish = tmp + sz;
                _endofstorage = tmp + n;
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
            assert(_start < _finish);
            --_finish;
        }
        void insert(iterator pos, const T &x)
        {
            assert(pos <= _finish); // 取等号时即为尾插，此时不会进入下面的while
            if (_finish = _endofstorage)
            {
                size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
                reserve(newcapacity);
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
        }
        T &operator[](size_t i)
        {
            assert(i < size());
            return _start[i];
        }
        size_t size()
        {
            return _finish - _start;
        }
        size_t capacity()
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
}
int main()
{
    lala::test_vector1();
    return 0;
}