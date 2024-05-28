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

//堆的逻辑结构是一颗完全二叉树
//堆的物理结构是一个数组
//大堆:堆顶数据最大
//小堆:堆顶数据最小
//数组下标性质
//leftchild = parent * 2 + 1;
//rightchild = parent * 2 + 2;
//parent = (child - 1) / 2;

//建大堆，向下调整算法->最多调整高度次O(logN)，前提左右子树都是大堆
void AdjustDown(int* a, int n, int root)//时间复杂度O(N)
{
	int parent = root;
	int child = parent * 2 + 1;//默认为左孩子
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;//变成右孩子
		}
		//使得child一定是左右孩子中大的那个
		if (a[parent] < a[child])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
//整体时间复杂度O(N*logN)
void HeapSort(int* a, int n)
{
	//建堆//升序排序建大堆 
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//从倒数第一个非叶子结点开始调整，即从最后一个结点父亲开始
	{
		//建堆的时间复杂度为O(N)
		AdjustDown(a, n, i);//n个数，i表示每次调整的开头位置,然后向下调整
	}

	int end = n - 1;
	while (end > 0)
	{
		swap(a[0], a[end]);//交换第一个数(最大值)与最后一个数,这样最大的数放在数组最后
		AdjustDown(a, end, 0);//每次排好最大值后,需要排的数减少1,待排序的有end个数,0表示从第一个parent开始向下调整
		--end;
	}
}

//另一种写法
//维护堆的性质
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
//优先队列是堆
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