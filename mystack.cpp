#include <bits/stdc++.h>
using namespace std;

namespace lala
{
    template <class T, class Container = deque<T>>
    class stack
    {
    public:
        void push(const T &x)
        {
            _con.push_back(x);
        }
        void pop()
        {
            _con.pop_back();
        }
        size_t size()
        {
            return _con.size();
        }
        bool empty()
        {
            return _con.empty();
        }
        T &top()
        {
            return _con.back();
        }

    private:
        Container _con;
    };

    void test_stack()
    {
        // stack<int,vector<int>> st;//容器适配转换
        // stack<int, list<int>> st;
        // stack<int, deque<int>> st;
        stack<int> st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}
int main()
{
    lala::test_stack();
    return 0;
}
