#include <bits/stdc++.h>
using namespace std;

// 一维前缀和模板题
//  const int N = 10010;
//  int n, m;
//  int a[N], s[N];
//  int main()
//  {
//      scanf("%d%d", &n, &m);
//      for (int i = 1; i <= n; i++)
//          scanf("%d", &a[i]);
//      for (int i = 1; i <= n; i++)
//          s[i] = s[i - 1] + a[i];
//      while (m--)
//      {
//          int l, r;
//          scanf("%d%d", &l, &r);
//          printf("%d\n", s[r] - s[l - 1]);
//      }
//      return 0;
//  }

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
int a[N], s[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    scanf("%d", &m);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}