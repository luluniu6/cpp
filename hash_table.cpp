#include <bits/stdc++.h>
using namespace std;
//哈希表
//1.开放地址法
#define NullKey -32768
typedef int DataType;
#define NUM 10
struct HashTable {
	DataType* data;
	int count;
};
HashTable* InitHashTable()
{
	HashTable* H = (HashTable*)malloc(sizeof(HashTable));
	H->count = 0;
	H->data = (DataType*)malloc(sizeof(DataType) * NUM);
	for (int i = 0; i < NUM; i++)
	{
		H->data[i] = NullKey;
	}
	return H;
}
int Hash(DataType key)
{
	return key % NUM;
}
void InsertHashKey(HashTable* H, DataType key)
{
	int address = Hash(key);
	printf("\n插入关键字 %d, 哈希地址 = %d\n", key, address);
	int d = 1;
	while (H->data[address] != NullKey)
	{
		printf("插入下标地址[%d], 发生冲突\n", address);
		// 1. 线性探测法
		address = (address + d) % NUM;

		// 2. 二次探测法
		// address = (address + d * d) % NUM; 

		d++;
	}
	// 在最终地址存储数据
	H->data[address] = key;
	H->count++;
	printf("插入下标地址[%d], 插入成功\n\n", address);
}
int SearchHashKey(HashTable* H, DataType key)
{
	int address = Hash(key);
	int p = address;
	// 查找关键字
	while (H->data[p] != key)
	{
		// 线性探测
		p = (p + 1) % NUM;
		// 指针遍历到空数据，或者指针回到原位置，则代表查找失败
		if (H->data[p] == NullKey || p == address)
		{
			return -1;
		}
	}
	return p;
}
void DisplayHashTable(HashTable* H)
{
	int i;
	printf("哈希表：\n");
	for (i = 0; i < NUM; i++)
	{
		printf("%d\t", i);
	}
	printf("\n");
	for (i = 0; i < NUM; i++)
	{
		if (H->data[i] != NullKey)
		{
			printf("%d\t", H->data[i]);
		}
		else
		{
			printf("-\t");
		}
	}
	printf("\n\n");
}
void test1()
{
	int i;
	DataType key;
	HashTable* H = InitHashTable();
	printf("构建哈希表:");
	for (i = 0; i < NUM; i++)
	{
		// 参考用例: 50 81 191 32 65 75 9 97 88 109
		scanf("%d", &key);
		InsertHashKey(H, key);
	}
	DisplayHashTable(H);

	while (1)
	{
		int address;
		printf("查找关键字: ");
		scanf("%d", &key);
		// 查找关键字地址
		address = SearchHashKey(H, key);
		if (address != -1)
		{
			printf("查找成功, 目标地址 = %d\n", address);
		}
		else
		{
			printf("查找失败\n");
		}
	}
}

//2.拉链法
// 链表结点
typedef struct LNode
{
	DataType data;
	struct LNode* next;
}LNode, * LinkList;
// 哈希表
typedef struct hashTable
{
	LNode* list;
	int count;
}hashTable;
// 初始化哈希表
void InitHashTable(hashTable* H)
{
	// 分配多个链表头结点空间
	H->list = (LNode*)malloc(NUM * sizeof(LNode));
	H->count = 0;

	// 初始化链表头结点（头结点存储初始值，链表后序结点存储冲突值）
	int i;
	for (i = 0; i < NUM; i++)
	{
		H->list[i].data = NullKey;
		H->list[i].next = NULL;
	}
	printf("已初始化哈希表!\n");
}
// 定义哈希函数
int Hash(DataType key);
// 插入关键字
void InsertHashKey(hashTable* H, DataType key)
{
	// 根据哈希函数得到下标地址
	int address = Hash(key);
	printf("\n插入关键字 %d, 哈希地址 = %d\n", key, address);

	if (H->list[address].data == NullKey)
	{
		// 若未发生冲突，则直接赋值给头结点
		H->list[address].data = key;
		printf("插入下标地址[%d], 插入成功!\n\n", address);
	}
	else
	{
		// 若发生冲突，则在该头结点的链表下进行头插
		// 创建新结点
		LNode* s;
		s = (LNode*)malloc(sizeof(LNode));
		s->data = key;
		// 头插法插入
		s->next = H->list[address].next;
		H->list[address].next = s;

		printf("插入下标地址[%d], 发生冲突! 已插入该地址的链表下\n\n", address);
	}
	H->count++;
}

// 查找关键字
LNode* SearchHashKey(hashTable* H, DataType key)
{
	int address = Hash(key);
	// 根据哈希地址获取对应链表的头结点
	LNode* p = &H->list[address];
	// 在链表中查找关键字
	while (p != NULL && p->data != key)
	{
		// 线性探测
		p = p->next;
	}
	return p;
}

void DisplayHashTable(hashTable* H)
{
	int i;
	printf("哈希表：\n**********************************\n");
	for (i = 0; i < NUM; i++)
	{
		printf("%d\t", i);
	}
	printf("\n");

	LNode* p;
	int j, k = 0, flag = 1;

	while (flag)
	{
		flag = 0;
		for (i = 0; i < NUM; i++)
		{
			j = 0;
			p = &H->list[i];
			while (j < k && p)
			{
				p = p->next;
				j++;
			}
			if (p && p->data != NullKey)
			{
				printf("%d\t", p->data);
				flag = 1;
			}
			else
			{
				printf(" \t");
			}
		}
		k++;
		printf("\n");
	}
	printf("*********************************\n");
}

void test2()
{
	int i;
	DataType key;
	hashTable H;
	InitHashTable(&H);
	printf("构建哈希表:");
	for (i = 0; i < NUM; i++)
	{
		// 参考用例: 50 81 191 32 65 75 9 97 88 109
		scanf("%d", &key);
		InsertHashKey(&H, key);
	}
	DisplayHashTable(&H);

	while (1)
	{
		LNode* result;
		printf("查找关键字: ");
		scanf("%d", &key);
		// 查找关键字地址
		result = SearchHashKey(&H, key);
		if (result != NULL)
		{
			printf("查找成功, 目标地址 = %x\n", result);
		}
		else
		{
			printf("查找失败\n");
		}
	}
}
int main()
{
	test1();
	//test2();

	return 0;
}
//https://leetcode.cn/problems/valid-anagram/ 242. 有效的字母异位词
//mine
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         vector<int> a(26,0);
//         for(int i=0;i<s.size();i++)
//         {
//             a[s[i]-'a']++;
//         }
//         vector<int> b(26,0);
//         for(int i=0;i<t.size();i++)
//         {
//             b[t[i]-'a']++;
//         }
//         for(int i=0;i<26;i++)
//         {
//             if(a[i]!=b[i]) return false;
//         }
//         return true;

//     }
// };
//leetcode官方题解
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.length() != t.length()) {
//             return false;
//         }
//         vector<int> table(26, 0);
//         for (auto& ch: s) {
//             table[ch - 'a']++;
//         }
//         for (auto& ch: t) {
//             table[ch - 'a']--;
//             if (table[ch - 'a'] < 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
//https://leetcode.cn/problems/intersection-of-two-arrays/description/  349. 两个数组的交集

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a(1000,0);
        vector<int> c;
        for(int i=0;i<nums1.size();i++)
        {
            a[nums1[i]%1000]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            a[nums2[i]%1000]++;
        }
        int j=0;
        for(int i=0;i<1000;i++)
        {
            if(a[i]==2) c[j++]=a[i];
        }
        return c;
    }
};