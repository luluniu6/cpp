#include<bits/stdc++.h>
using namespace std;
void print_list(const list<int>& l)
{
    list<int>::const_iterator it=l.begin();
    while(it!=l.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}
void test_list1()
{
    //带头双向循环链表
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_front(0);
    l.push_front(-1);
    l.push_front(-2);
    l.pop_front();
    l.pop_back();
    list<int>::iterator it =l.begin();
    while(it!=l.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    for(auto e:l)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    list<int>::reverse_iterator rit=l.rbegin();
    while(rit!=l.rend())
    {
        cout<<*rit<<" ";
        *rit++;
    }
    cout<<endl;
}
int main()
{
    test_list1();
    return 0;
}
