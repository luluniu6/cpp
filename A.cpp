#include <bits/stdc++.h>
using namespace std;
int a[1000000];
long long Cmn(int m, int n)
{
    long long ans = 1;
    for (int x = m - n + 1, y = 1; y <= n; ++x, ++y)
    {
        ans = ans * x / y;
    }
    return ans;
}

int bin_search(int l, int r, int val)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (a[mid] > val)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(&a[0], &a[n]);
    int l = 0, r = 0;
    long long sum = 0;
    while (l <= n - m)
    {
        int cha=r;
        r = bin_search(0, n - 1, a[l] + k);
        if (a[r] - a[l] <= k)
        {
            sum += Cmn(r - l + 1, m)%(int)(1e9+7);
            if(cha-l+1>=m) sum-=Cmn(cha-l+1,m)%(int)(1e9+7);
        }
        while (1)
        {
            if (a[l] == a[l + 1])
                l++;
            else
                break;
        }
        l++;
    }
    cout << sum;
    return 0;
}
