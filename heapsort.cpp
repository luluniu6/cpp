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

void heapify(int *a, int n, int i)
{
	int largest = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;
	if (lson < n && a[lson] > a[largest])
	{
		largest = lson;
	}
	if (rson < n && a[rson] > a[largest])
	{
		largest = rson;
	}
	if (largest != i)
	{
		swap(a[largest], a[i]);
		heapify(a, n, largest);
	}
}
void HeapSort(int *a, int n)
{
	int i;
	// 建堆--使用向下调整算法
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	// 排序
	for (i = n - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}
int main(int argc, char const *argv[])
{
	int a[] = {4, 2, 1, 6, 7, 9, 3, 0, 5, 8};
	HeapSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}

// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/ 215. 数组中的第K个最大元素
class Solution
{
public:
	int findKthLargest(vector<int> &nums, int k)
	{
		// 建立k个数的小堆
		// 时间复杂度O(N*logK)
		// 空间复杂度O(K)
		priority_queue<int, vector<int>, greater<int>> minheap;
		size_t i = 0;
		for (; i < k; i++)
		{
			minheap.push(nums[i]);
		}
		for (; i < nums.size(); ++i)
		{
			if (nums[i] > minheap.top())
			{
				minheap.pop();
				minheap.push(nums[i]);
			}
		}
		return minheap.top();
	}
};