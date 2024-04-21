#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define N 100000
int n;
int arr[N];
int temp[N];
void quicksort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int x = arr[l];
    int i = l - 1;
    int j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (arr[i] < x);
        do
            j--;
        while (arr[j] > x);
        if (i < j)
            swap(arr[i], arr[j]);
    }
    quicksort(arr, l, j);
    quicksort(arr, j + 1, r);
}
void mergesort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        arr[i] = temp[j];
}
/*
int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    // quicksort(arr, 0, n - 1);
    // mergesort(arr, 0, n - 1);
    // vector<int> arr={1,3,4,2}
    quick_sort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
*/
/*
class A
{
public:
    A()
    {
        ++_N;
        sum += _N;
    }
    static void Reset()
    {
        _N = 0;
        sum = 0;
    }
    static int _N;
    static int sum;
};
int A::_N = 0;
int A::sum = 0;
class Solution
{
public:
    int Sum_Solution(int n)
    {
        A::Reset();//每次调用构造函数要清除之前的数据
        A *a = new A[n];
        delete[] a;  // 防止内存泄漏
        a = nullptr; // 防止悬空指针
        return A::sum;
    }
};
int main()
{
    Solution l;
    int num = 0;
    while(~scanf("%d",&num))
    {
        cout << l.Sum_Solution(num)<<endl;
    }

}
*/
/*
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};
int main()
{
    Solution l;
    cout<<l.tribonacci(4);
    return 0;
}
*/

/*
int main(int argc, char const *argv[])
{
    static int monthday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;
    while (cin >> year >> month >> day)
    {
        int n = 0;
        for (int i = 1; i < month; i++)
        {
            n += monthday[i];
        }
        n += day;
        if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            n += 1;
        }
        cout << n << endl;
    }
    return 0;
}
*/

int globalVar = 1;              // 全局变量
static int staticGlobalVar = 1; // 静态全局变量
// globalVar和staticGlobalVar，在main函数之前就初始化，在哪都能用，作用域是全局的
// 两个全局变量的区别：链接属性不一样
// globalVar所有文件中可见
// staticGlobalVar只在当前文件可见
void Test()
{
    static int staticVar = 1; // 运行到这里才初始化，它的作用域在Test函数中，只能在该函数使用
    int localVar = 1;
    int num1[10] = {1, 2, 3, 4};
    char char2[] = "abcd"; // char2是栈上的数组
    char *pChar3 = "abcd"; // 常量字符串-->常量区<-->代码段
    int *ptr1 = (int *)malloc(sizeof(int) * 4);
    int *ptr2 = (int *)calloc(4, sizeof(int));
    int *ptr3 = (int *)realloc(ptr2, sizeof(int) * 4);
    free(ptr1);
    free(ptr3);
}
// 选择题
//   A.栈       B.堆     C.数据段（静态区）    D.代码段（常量区）
// globalVar----C
// staticGlobalVar----C
// staticVar----C
// localVar----A
// num1----A
// char2----A
//*char2----A
// pChar3----A
//*pChar3----D
// ptr1----A
//*ptr1----B
// 填空题
// sizeof(num1)=40
// sizeof(char2)=5   strlen(char2)=4
// sizeof(pChar3)=4/8   strlen(pChar3)=4
// sizeof(ptr1)=4/8
/*
#include <bits/stdc++.h>
int main()
{
	int n, i = 0, nums, b, c;
	vector<int> a;
	cin >> n;
	for (i; i < n; i++)
	{
		while (cin >> nums)
		{
			a.push_back(nums);
			if (cin.get() == '\n')
				break;
		}
	}
	for(i=0;i<a.size();i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			if (a[i] == a[j])
			{
				c = j;
				b = a[j];
			}
		}
	}
	cout << c <<" " << b;
	return 0;
}
*/

