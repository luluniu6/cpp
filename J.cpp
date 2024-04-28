#include <bits/stdc++.h>
using namespace std;

vector<int> res; // 存结果loveyou；love u too~

int main()
{
    long long n;
    cin >> n;
    n--;
    while (1)
    {
        res.push_back(n%5*2);
        n/=5;
        if(n==0) break;
    }
    for(int i=res.size()-1;i>=0;i--)
    {
        cout<<res[i];
    }
    return 0;
}
