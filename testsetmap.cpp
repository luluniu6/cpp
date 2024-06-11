#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

void test_set1()
{
    set<int>s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(7);

    set<int>::iterator it=s.begin();
    while(it!=s.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;

    set<int> copy(s);
    for(auto e:copy)
    {
        cout<<e<<" ";
    }
    cout<<endl;

    set<int>::iterator pos=s.find(3);//O(logN)
    //set<int>::iterator pos=find(s.begin(),s.end();3);//O(N)
    if(pos!=s.end())
    {
        s.erase(pos);
    }
    for(auto e:s)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    s.erase(7);
    s.erase(70);
    for(auto e:s)
    {
        cout<<e<<" ";
    }
    cout<<endl;

}
void test_map1()
{
    map<int,int> m;
    m.insert(pair<int,int>(1,1));
    m.insert(pair<int,int>(2,2));
    m.insert(pair<int,int>(3,3));
    m.insert(pair<int,int>(4,4));//pair构造函数，构造一个匿名对象
    m.insert(make_pair(5,5));//函数模板构造一个pair对象
    m.insert(make_pair(6,6));
    map<int,int>::iterator it=m.begin();
    while(it!=m.end())
    {
        cout<<(*it).first<<":"<<(*it).second<<endl;
        //cout<<it->first<<":"<<it->second<<endl;
        it++;
    }
    for(auto& e:m)
    {
        cout<<e.first<<":"<<e.second<<endl;
    }
}
void test_map2()
{
    std::map<std::string,std::string> dict;
    dict.insert(pair<std::string,std::string>("sort","排序"));
    dict.insert(make_pair("left","左边"));
    dict.insert(make_pair("right","右边"));

    std::map<std::string,std::string>::iterator it=dict.begin();
    while(it!=dict.end())
    {
        cout<<it->first<<":"<<it->second<<endl;
        it++;
    }
}
void test_map3()
{
    string strs[]={"西瓜","樱桃","西瓜","苹果","西瓜","西瓜","苹果","西瓜","西瓜"};
    map<string,int> countMap;
    for(auto& str:strs)
    {
        map<string,int>::iterator ret=countMap.find(str);
        if(ret!=countMap.end())
        {
            ret->second++;
        }
        else
        {
            countMap.insert(make_pair(str,1));
        }
    }
    for(auto& e:countMap)
    {
        cout<<e.first<<":"<<e.second<<endl;
    }
}
int main()
{
   //test_set1(); 
   //test_map1();
   //test_map2();
   test_map3();
    return 0;
}


