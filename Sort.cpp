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

void InsertSort(int* a, int n);//直接插入排序  稳定
void ShellSort(int* a, int n);//希尔排序  不稳定
void AdjustDown(int* a, int n, int root);//堆排序中的向下调整算法
void SelectSort(int* a, int n);//直接选择排序  不稳定
void HeapSort(int* a, int n);//堆排序  不稳定
void BubbleSort(int* a, int n);//冒泡排序 稳定
int GetMidIndex(int* a, int left, int right);//快速排序优化-->三数取中
int PartSort1(int* a, int left, int right);//快速排序单趟排序-->挖坑法
int PartSort2(int* a, int left, int right); //快速排序单趟排序-->左右指针法
int PartSort3(int* a, int left, int right);///快速排序单趟排序-->前后指针法
void QuickSort(int* a, int left, int right);//快速排序递归  不稳定
void QuickSortNonR(int* a, int n); //快速排序非递归
void QuickSortNonR1(int* a, int n); //快速排序非递归
void MergeSort(int* a, int n);//归并排序  稳定
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSortNonR(int* a, int n);
//还有非比较排序
//还有基数排序(桶排序),只能适用于整形,依次取每个数的个位,十位,百位...排序，没啥重要意义
//还有计数排序利用映射思想，开一个数量为最大值的数组，统计每个数出现的次数，但可能会造成空间的浪费但可以利用相对映射位置
void CountSort(int* a, int n);//计数排序 时间复杂度O(N+range)适用于范围集中的整形数据排序
void TestSort();//单个排序小组数字测试排序
void PrintArray(int* a, int n);//升序排序后打印
void TestOP();//多个排序随机数组巨大数据量排序时间(毫秒)
void SelectSort1(int* a, int n);
void Output(int* arr, int n, const char* s = "arr");
template<typename T>
void Output(vector<T>& arr);

//c++ sort方法的使用
struct Data
{
	int x, y;
};
ostream& operator<<(ostream& out, const Data& d) {
	out << "(" << d.x << ", " << d.y << ")";
	return out;
}

bool cmp(const Data& a, const Data& b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y > b.y;
}
template<typename T>
void Output(vector<T>& arr) {
	cout<<"arr["<< arr.size()<<"] = ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	return;
}

void Output(int* arr, int n, const char* s) {
	printf("%s[%d] = ", s, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	return;
}

int *getRandData(int n)
{
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10000;
	}
	return arr;

}
void sort_array()
{
	int* arr = getRandData(10);
	Output(arr, 10);
	sort(arr, arr + 10);//默认从小到大排序
	Output(arr, 10);
	sort(arr, arr + 10, greater<int>());
	Output(arr, 10);
	free(arr);
}
void sort_vector()
{
	vector<int>arr;
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 10000);
	}
	Output(arr);
	sort(arr.begin(), arr.end());
	Output(arr);
	sort(arr.begin(), arr.end(), greater<int>());
	Output(arr);
}
void sort_others()
{
	vector<Data>arr;
	for (int i = 0; i < 10; i++)
	{
		Data d;
		d.x = rand() % 10, d.y = rand() % 10;
		arr.push_back(d);
	}
	Output(arr);
	sort(arr.begin(), arr.end(), cmp);
	Output(arr);
}
void sort_test()
{
	int* arr = getRandData(10);
	int* ind = getRandData(10);
	for (int i = 0; i < 10; i++) ind[i] = i;
	Output(arr, 10);
	sort(ind, ind + 10, [&](int i, int j) -> bool {
		return arr[i] < arr[j];
		});
	Output(arr, 10);
	Output(ind, 10, "ind");
	return;
}
//int main()
//{
//	sort_array();
//	sort_vector();
//	sort_others();
//	sort_test();
//	return 0;
//}



//按照升序排序
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void TestSort()
{
	int a[] = { 6,1,4,8,2,9,0,3,5,7 };
	//int a[] = { 3,1,2 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//直接插入排序
//时间复杂度O(n^2),逆序情况最坏,1+2+3+4+5+...+n-1
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)//i<n-1:防止数组越界
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > temp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = temp;
	}
}
//直接插入排序的基础上的优化
//希尔排序
//gap为间隔多少为一组进行直接插入排序
// //gap>1是预排序，接近有序
//gap==1时为直接插入排序，有序
//时间复杂度O(n*logN)
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		//gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > temp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = temp;
		}
	}
}

//直接选择排序O(N^2)
//最好情况还是(N^2)
void SelectSort(int* a, int n)//选两个
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		swap(a[begin], a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(a[maxi], a[end]);
		begin++;
		end--;
	}

}
void SelectSort1(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int min = a[j];
		for (int i = j; i < n; i++)
		{
			if (a[i] < min)
			{
				swap(a[i], min);
			}
		}
		a[j] = min;
	}
}
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
//冒泡排序O(N^2)
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

//快速排序
//时间复杂度O(N*logN)
//在有序的时候最坏，一次排一个O(N^2)

//改进:三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
		{
			return left;
		}
		else
			return right;
	}
}
int GetMidIndex1(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[right])
	{
		if (a[left] > a[mid])
		{
			return a[mid] > a[right] ? a[mid] : a[right];
		}
		else if (a[left] < a[mid])
		{
			return a[left];
		}
	}
	else if (a[left] <= a[right])
	{
		if (a[left] >= a[mid])
		{
			return a[mid];
		}
		else if (a[left] < a[mid])
		{
			return a[mid] > a[right] ? a[right] : a[mid];
		}
	}

}
//挖坑法
int PartSort1(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	swap(a[left], a[index]);//三数取中,优化有序的时候排序慢的问题

	int begin = left;
	int end = right;
	int pivot = begin;//坑
	int key = a[begin];

	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[pivot] = a[end];
		pivot = end;

		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;
	return pivot;
}
int PartSort11(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	swap(a[left], a[index]);//三数取中,优化有序的时候排序慢的问题
	int begin = left;
	int end = right;
	int k = begin;
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[k] = a[end];
		k = end;
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[k] = a[begin];
		k = begin;

	}
	a[k] = key;
	return k;
}
//左右指针法
int PartSort2(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	swap(a[left], a[index]);//三数取中,优化有序的时候排序慢的问题

	int begin = left;
	int end = right;
	int keyi = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}
		swap(a[begin], a[end]);
	}
	swap(a[begin], a[keyi]);
	return begin;
}
//前后指针法
int PartSort3(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	swap(a[left], a[index]);//三数取中,优化有序的时候排序慢的问题
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi])
		{
			++prev;
			swap(a[prev], a[cur]);
		}
		++cur;

	}
	swap(a[keyi], a[prev]);
	return prev;
}
//快速排序
void QuickSort(int* a, int left,int right)
{
	if (left >= right)
		return;

	//int keyIndex = PartSort1(a, left, right);//单趟排序--挖坑法
	//int keyIndex = PartSort2(a, left, right);//单趟排序--左右指针法
	int keyIndex = PartSort11(a, left, right);//单趟排序--前后指针法

	//[left,keyIndex]
	//[left,keyIndex - 1] keyIndex [keyIndex + 1,right]
	//分治递归
	 
	//小区间优化(效果不太明显)
	if (keyIndex - 1 - left > 10)//这个10也可以为其他值
	{
		QuickSort(a, left, keyIndex - 1);
	}
	else
	{
		InsertSort(a + left, keyIndex - 1 - left + 1);

	}
	if (right - 1 - keyIndex > 10)//这个10也可以为其他值
	{
		QuickSort(a, keyIndex + 1, right);
	}
	else
	{
		InsertSort(a + keyIndex + 1, right - 1 - keyIndex + 1);

	}
}
//递归的缺陷:栈帧的深度太深,栈空间不够用,可能会溢出
//递归改非递归:1.直接改循环 2.借助数据结构的栈模拟递归过程
void QuickSortNonR(int* a, int n)
{
	stack<int> s;
	s.push(n-1);
	s.push(0);//后进先出
	while (!s.empty())
	{
		int left = s.top();//0
		s.pop();
		int right = s.top();//n-1
		s.pop();

		int keyIndex = PartSort1(a, left, right);
		//[left,keyIndex-1]  keyIndex  [keyIndex+1,right]
		if (keyIndex + 1 < right)
		{
			s.push(right);//注意栈先进后出的顺序
			s.push(keyIndex+1);//要使left为每次左边的下标
		}
		if (left < keyIndex - 1)
		{
			s.push(keyIndex-1);
			s.push(left);
		}
		     
	}
}
void QuickSortNonR1(int* a, int n)
{
	stack<int> st;
	st.push(n - 1);
	st.push(0);
	while (!st.empty())
	{
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();
		int keyIndex = PartSort1(a, left, right);
		if (left < keyIndex - 1)
		{
			st.push(keyIndex - 1);
			st.push(left);

		}
		if (keyIndex + 1 < right)
		{
			st.push(right);
			st.push(keyIndex + 1);
		}

	}
}
//归并排序
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) >> 1;
	//假设[left,mid] [mid+1,right]有序,那么就可以开始归并了
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//拷贝回去
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a,int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//归并过程中右半区间可能不存在
			if (begin2 >= n)
				break;
			//归并过程中右半区间算多了，修正一下
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
			//拷贝回去
			for (int j = i; j <= end2; ++j)
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	free(tmp);
}
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;

		}
	}
}

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	BubbleSort(a5, N);
	int end5 = clock();

	int begin6 = clock();
	QuickSort(a6, 0, N-1);
	int end6 = clock();

	int begin7 = clock();
	MergeSort(a7, N);
	int end7 = clock();

	cout << "InsertSort:" << end1 - begin1 << endl;
	cout << "ShellSort:" << end2 - begin2<< endl;
	cout << "SelectSort:" << end3 - begin3 << endl;
	cout << "HeapSort:" << end4 - begin4 << endl;
	cout << "BubbleSort:" << end5 - begin5 << endl;
	cout << "QuickSort:" << end6 - begin6 << endl;
	cout << "MergeSort:" << end7 - begin7 << endl;

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

int main()
{ 
	TestSort();
	//TestOP();
	return 0;
}