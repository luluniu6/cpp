#include <bits/stdc++.h>
using namespace std;

namespace lala
{
    template <class T, class Container = deque<T>>
    class queue
    {
    public:
        void push(const T &x)
        {
            _con.push_back(x);
        }
        void pop()
        {
            _con.pop_front();
        }
        size_t size()
        {
            return _con.size();
        }
        bool empty()
        {
            return _con.empty();
        }
        T &front()
        {
            return _con.front();
        }
        T &back()
        {
            return _con.back();
        }

    private:
        Container _con;
    };

    void test_queue()
    {
        // queue<int,vector<int>> q;不能用vector,因为vector不支持pop_front(头删)
        // queue<int,list<int>> q;
        //queue<int, deque<int>> q;
        
        queue <int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
}
int main()
{
    lala::test_queue();
    return 0;
}
