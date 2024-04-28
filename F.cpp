#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, p, q;
    scanf("%d %d %d %d %d", &n, &a, &b, &p, &q);
    long long sum = 0;
    // 辗转相除求最大公约数(gcd)
    int la1 = a, la2 = b, temp = 0;
    while (temp = la1 % la2)
    {
        la1 = la2;
        la2 = temp;
    }
    long long lcm;
    lcm = a * b / la2;
    sum = n / a * p;
    sum+=n/b*q;
    int ln=n/lcm;
    long long ln1=ln*(min(p,q));
    sum-=ln1;
    printf("%lld",sum);
    return 0;
}