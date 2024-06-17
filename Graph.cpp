#include <iostream>
#include <vector>
#include <map>
using namespace std;

// template<class T>
// class UnionFindSet
// {
// public:
//     UnionFindSet(const T*a,size_t n)
//     {
//         for(size_t i=0;i<n;i++)
//         {
//             _a.push_back(a[i]);
//             _indexMap[a[i]]=i;
//         }
//     }
// private:
//     vector<T> _a;
//     map<T,int> _indexMap; 
// }
class UnionFindSet
{
public:
    UnionFindSet(size_t n)
        :_ufs(n,-1)
    {
    }
    void Union(int x1,int x2)
    {

    }
    int FindRoot(int x)
    {
        int parent=x;
        while(_ufs[parent]>=0)
        {
            parent=_ufs[parent];
        }
        return parent;
    }
    bool InSet(int x1,int x2)
    {

    }
    size_t SetSize()
    {

    }
private:
    int* _ufs;
}


int main()
{
    string a[]={"张三","李四","王五","赵六"};
    UnionFindSet<string> ufs(a,4);
    return 0;
}
