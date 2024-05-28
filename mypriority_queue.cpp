#include <bits/stdc++.h>
using namespace std;
namespace lala
{
    template <class T, class Container = vector<T>, class Compare = less<T>>
    class priority_queue
    {
    public:
        // 默认是大堆
        void AdjustUp(int child) // 向上调整算法
        {
            Compare com;
            int parent = (child - 1) / 2;
            while (child > 0)
            {
                // if (_con[child] > _con[parent])
                if (com(_con[parent], _con[child]))
                {
                    swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }
        void push(const T &x)
        {
            // O(logN)
            _con.push_back(x);
            AdjustUp(_con.size() - 1);
        }
        void AdjustDown(int root)
        {
            int parent = root;
            int child = root * 2 + 1;

            Compare com;
            while (child < _con.size())
            {
                // if (child + 1 < _con.size() && _con[child] < _con[child + 1])
                if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
                {
                    child++;
                }
                // if (_con[child] > _con[parent])
                if (com(_con[parent], _con[child]))
                {
                    swap(_con[child], _con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }
        void pop()
        {
            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
            AdjustDown(0);
        }
        T &top()
        {
            return _con[0];
        }
        size_t size()
        {
            return _con.size();
        }
        bool empty()
        {
            return _con.empty();
        }

    private:
        Container _con;
    };
    // 仿函数 函数对象
    template <class T>
    struct less
    {
        bool operator()(const T &x1, const T &x2)
        {
            return x1 < x2;
        }
    };
    template <class T>
    struct greater
    {
        bool operator()(const T &x1, const T &x2)
        {
            return x1 > x2;
        }
    };
    void test_priority_queue()
    {
        priority_queue<int> pq;
        // priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(3);
        pq.push(1);
        pq.push(8);
        pq.push(4);
        pq.push(2);
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
    void test_sort()
    {
        vector<int> v;
        v.push_back(5);
        v.push_back(1);
        v.push_back(2);
        v.push_back(4);
        v.push_back(3);

        // 升序 less <
        sort(v.begin(), v.end());

        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
        // 降序 greater >
        // greater<int> gt;
        // sort(v.begin(), v.end(), gt);
        sort(v.begin(), v.end(), greater<int>());
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

int main()
{
    // lala::test_priority_queue();
    lala::test_sort();
    return 0;
}
