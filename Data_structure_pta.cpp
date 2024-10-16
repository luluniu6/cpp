void FindMax(int a[], int n, int *pmax1, int *pmax2)
{
    *pmax1 = a[1];
    *pmax2 = a[2];
    if (*pmax1 < *pmax2)
    {
        int temp = *pmax1;
        *pmax1 = *pmax2;
        *pmax2 = temp;
    }
    for (int i = 3; i <= n; i++)
    {
        if (a[i] > *pmax1)
        {
            *pmax2 = *pmax1;
            *pmax1 = a[i];
        }
        else if (a[i] > *pmax2)
        {
            *pmax2 = a[i];
        }
    }
}

// //7-1 一元多项式运算器——建立与输出
// #include <iostream>
// #include <map>
// using namespace std;
// int main()
// {
//     int n = 0;
//     cin >> n;
//     getchar();
//     map<int, int> node;
//     for (int i = 0; i < n; i++)
//     {
//         int coef, exp;
//         scanf("(%d,%d)", &coef, &exp);
//         node[exp] = coef;
//     }
//     map<int,int>::iterator it = node.begin();
//     if (it->first == 0) cout << it->second;
//     else if (it->first == 1) cout << it->second << "X";
//     else cout << it->second << "X^" << it->first;
//     it++;
//     while (it != node.end())
//     {
//         if (it->second > 0) cout << "+";
//         if (it->first == 0) cout << it->second;
//         else if (it->first == 1) cout << it->second << "X";
//         else cout << it->second << "X^" << it->first;
//         it++;
//     }
//     return 0;
// }

// //7-2 一元多项式运算器——加法
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// typedef struct node {
//     int coef;
//     int expn;
//     struct node *next;
// }Node, *List;

// List Creat(int i) {
//     List head;
//     head = (List)malloc(sizeof(Node));
//     List pre, pnew;
//     pre = head;
//     char a,b;
//     for(int j = 0; j <= i; j++) {
//         pnew = (List)malloc(sizeof(Node));
//         scanf("%c%d,%d%c", &a, &pnew->coef, &pnew->expn, &b);
//         pre -> next = pnew;
//         pre = pnew;
//     }
//     return head;
// }

// void Print(List head) {
//     List q = head->next->next;
//     int flag = 1;
//     if(!q) {
//         putchar('0');
//         printf("\n");
//         return;
//     }
//     while(q) {
//         if(q->coef > 0 && flag != 1) {
//             putchar('+');
//         }
//         if(q->coef != 1 && q->coef != -1) {
//             printf("%d", q->coef);
//             if(q->expn == 1) {
//                 putchar('X');
//             } else if (q->expn) {
//                 printf("X^%d", q->expn);
//             }
//         } else {
//             if(q->coef == 1) {
//                 if(!q->expn) {
//                     putchar('1');
//                 } else if (q->expn == 1) {
//                     putchar('X');
//                 } else {
//                     printf("X^%d", q->expn);
//                 }
//             }
//             if(q->coef == -1) {
//                 if(!q->expn) {
//                     printf("-1");
//                 } else if(q->expn == 1) {
//                     printf("-X");
//                 } else {
//                     printf("-X^%d", q->expn);
//                 }
//             }
//         }
//         q = q->next;
//         flag++;
//     }
// }

// List Plus(List head1, List head2) {
//     List pre = NULL, p = NULL, qre = NULL, q = NULL;
//     pre = head1->next;
//     p = head1->next->next;
//     qre = head2->next;
//     q = head2->next->next;
//     int index = 1;
//     while (p != NULL) {
//         if (q == NULL) {
//             return head1;
//         }
//         if (p->expn == q->expn) {
//             p->coef = p->coef + q->coef;
//             if (p->coef == 0) {
//                 pre->next = p->next;
//                 free(p);
//                 if (pre) {
//                     p = pre->next;
//                 } else {
//                     p = NULL;
//                 }
//                 qre->next = q->next;
//                 free(q);
//                 if (qre) {
//                     q = qre->next;
//                 } else {
//                     q = NULL;
//                 }
//             } else {
//                 pre = p;
//                 p = p->next;
//                 qre->next = q->next;
//                 free(q);
//                 if (qre) {
//                     q = qre->next;
//                 } else {
//                     q = NULL;
//                 }
//             }
// //            printf("4\n");
//         } else if (p->expn > q->expn) {//多项式1的项的指数大于多项式2的项时
//             qre->next = q->next;
//             q->next = p;
//             pre->next = q;
//             pre = q;
//             q = qre->next;
// //            printf("3\n");
//         } else if (q->expn > p->expn && p->next &&q->expn < (p->next)->expn) {//多项式2的项指数大小在多项式1的项与下一项中间时
// //            printf("1\n");
//             qre->next = q->next;
//             pre = p;
//             p = p->next;
//             q->next = p;
//             pre->next = q;
//             pre = q;
//             q = qre->next;
//         } else if (q->expn > p->expn && p->next && q->expn >= (p->next)->expn) {
//             pre = p;
//             p = p->next;
// //            printf("2\n");
//         } else {
//             pre = p;
//             break;
//         }
//         index ++;
//     }
//     if (q) {//多项式2未计算完
//         pre->next = q;
//     }
//     return head1;
// }

// int main() {
//     int i1, i2;
//     List head1, head2;
//     scanf("%d", &i1);
//     head1 = Creat(i1);
//     scanf("%d", &i2);
//     head2 = Creat(i2);
//     List head = Plus(head1, head2);
//     Print(head);
// }

// //7-3 一元多项式运算器——减法

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// typedef struct node {
//     int coef;
//     int expn;
//     struct node *next;
// }Node, *List;

// List Creat(int i) {
//     List head;
//     head = (List)malloc(sizeof(Node));
//     List pre, pnew;
//     pre = head;
//     char a,b;
//     for(int j = 0; j <= i; j++) {
//         pnew = (List)malloc(sizeof(Node));
//         scanf("%c%d,%d%c", &a, &pnew->coef, &pnew->expn, &b);
//         pre -> next = pnew;
//         pre = pnew;
//     }
//     return head;
// }

// void Print(List head) {
//     List q = head->next->next;
//     int flag = 1;
//     if(!q) {
//         putchar('0');
//         printf("\n");
//         return;
//     }
//     while(q) {
//         if(q->coef > 0 && flag != 1) {
//             putchar('+');
//         }
//         if(q->coef != 1 && q->coef != -1) {
//             printf("%d", q->coef);
//             if(q->expn == 1) {
//                 putchar('X');
//             } else if (q->expn) {
//                 printf("X^%d", q->expn);
//             }
//         } else {
//             if(q->coef == 1) {
//                 if(!q->expn) {
//                     putchar('1');
//                 } else if (q->expn == 1) {
//                     putchar('X');
//                 } else {
//                     printf("X^%d", q->expn);
//                 }
//             }
//             if(q->coef == -1) {
//                 if(!q->expn) {
//                     printf("-1");
//                 } else if(q->expn == 1) {
//                     printf("-X");
//                 } else {
//                     printf("-X^%d", q->expn);
//                 }
//             }
//         }
//         q = q->next;
//         flag++;
//     }
// }

// List Plus(List head1, List head2) {
//     List pre = NULL, p = NULL, qre = NULL, q = NULL;
//     pre = head1->next;
//     p = head1->next->next;
//     qre = head2->next;
//     q = head2->next->next;
//     int index = 1;
//     while (p != NULL) {
//         if (q == NULL) {
//             return head1;
//         }
//         if (p->expn == q->expn) {
//             p->coef = p->coef - q->coef;
//             if (p->coef == 0) {
//                 pre->next = p->next;
//                 free(p);
//                 if (pre) {
//                     p = pre->next;
//                 } else {
//                     p = NULL;
//                 }
//                 qre->next = q->next;
//                 free(q);
//                 if (qre) {
//                     q = qre->next;
//                 } else {
//                     q = NULL;
//                 }
//             } else {
//                 pre = p;
//                 p = p->next;
//                 qre->next = q->next;
//                 free(q);
//                 if (qre) {
//                     q = qre->next;
//                 } else {
//                     q = NULL;
//                 }
//             }
// //            printf("4\n");
//         } else if (p->expn > q->expn) {//多项式1的项的指数大于多项式2的项时
//             q->coef = -q->coef;
//             qre->next = q->next;
//             q->next = p;
//             pre->next = q;
//             pre = q;
//             q = qre->next;
// //            printf("3\n");
//         } else if (q->expn > p->expn && p->next &&q->expn < (p->next)->expn) {//多项式2的项指数大小在多项式1的项与下一项中间时
//             q->coef = -q->coef;
// //            printf("1\n");
//             qre->next = q->next;
//             pre = p;
//             p = p->next;
//             q->next = p;
//             pre->next = q;
//             pre = q;
//             q = qre->next;
//         } else if (q->expn > p->expn && p->next && q->expn >= (p->next)->expn) {
//             pre = p;
//             p = p->next;
// //            printf("2\n");
//         } else {
//             pre = p;
//             break;
//         }
//         index ++;
//     }
//     if (q) {//多项式2未计算完
//         pre->next = q;
//         List qq = q;
//         while(qq) {
//             qq->coef = - qq->coef;
//             qq = qq->next;
//         }
//     }
//     return head1;
// }

// int main() {
//     int i1, i2;
//     List head1, head2;
//     scanf("%d", &i1);
//     head1 = Creat(i1);
//     scanf("%d", &i2);
//     head2 = Creat(i2);
//     List head = Plus(head1, head2);
//     Print(head);
// }

// //7-4 一元多项式运算器——乘法
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// typedef struct node {
//     int coef;
//     int expn;
//     struct node *next;
// }Node, *List;

// List Creat(int i) {
//     List head;
//     head = (List)malloc(sizeof(Node));
//     List pre, pnew;
//     pre = head;
//     char a,b;
//     for(int j = 0; j <= i; j++) {
//         pnew = (List)malloc(sizeof(Node));
//         scanf("%c%d,%d%c", &a, &pnew->coef, &pnew->expn, &b);
//         pre -> next = pnew;
//         pre = pnew;
//     }
//     return head;
// }

// void Print(List head) {
//     List q = head->next->next;
//     int flag = 1;
//     if(!q) {
//         putchar('0');
//         printf("\n");
//         return;
//     }
//     while(q) {
//         if(q->coef > 0 && flag != 1) {
//             putchar('+');
//         }
//         if(q->coef != 1 && q->coef != -1) {
//             printf("%d", q->coef);
//             if(q->expn == 1) {
//                 putchar('X');
//             } else if (q->expn) {
//                 printf("X^%d", q->expn);
//             }
//         } else {
//             if(q->coef == 1) {
//                 if(!q->expn) {
//                     putchar('1');
//                 } else if (q->expn == 1) {
//                     putchar('X');
//                 } else {
//                     printf("X^%d", q->expn);
//                 }
//             }
//             if(q->coef == -1) {
//                 if(!q->expn) {
//                     printf("-1");
//                 } else if(q->expn == 1) {
//                     printf("-X");
//                 } else {
//                     printf("-X^%d", q->expn);
//                 }
//             }
//         }
//         q = q->next;
//         flag++;
//     }
// }

// List CopyList (List head) {
//     List newHead = (List)malloc(sizeof(Node));
//     newHead->next = NULL;
//     List p = head->next;
//     List p2 = newHead;
//     while (p) {
//         List new = (List)malloc(sizeof(Node));
//         new->coef = p->coef;
//         new->expn = p->expn;
//         p2->next = new;
//         p2 = new;
//         p = p->next;
//     }
//     p2->next = NULL;
//     return newHead;
// }

// List Plus(List head1, List head2) {
//     List pre = NULL, p = NULL, qre = NULL, q = NULL;
//     pre = head1->next;
//     p = head1->next->next;
//     qre = head2->next;
//     q = head2->next->next;
//     int index = 1;
//     while (p != NULL) {
//         if (q == NULL) {
//             return head1;
//         }
//         if (p->expn == q->expn) {
//             p->coef = p->coef + q->coef;
//             if (p->coef == 0) {
//                 pre->next = p->next;
//                 free(p);
//                 if (pre) {
//                     p = pre->next;
//                 } else {
//                     p = NULL;
//                 }
//                 qre->next = q->next;
//                 free(q);
//                 if (qre) {
//                     q = qre->next;
//                 } else {
//                     q = NULL;
//                 }
//             } else {
//                 pre = p;
//                 p = p->next;
//                 qre->next = q->next;
//                 free(q);
//                 if (qre) {
//                     q = qre->next;
//                 } else {
//                     q = NULL;
//                 }
//             }
// //            printf("4\n");
//         } else if (p->expn > q->expn) {//多项式1的项的指数大于多项式2的项时
//             qre->next = q->next;
//             q->next = p;
//             pre->next = q;
//             pre = q;
//             q = qre->next;
// //            printf("3\n");
//         } else if (q->expn > p->expn && p->next &&q->expn < (p->next)->expn) {//多项式2的项指数大小在多项式1的项与下一项中间时
// //            printf("1\n");
//             qre->next = q->next;
//             pre = p;
//             p = p->next;
//             q->next = p;
//             pre->next = q;
//             pre = q;
//             q = qre->next;
//         } else if (q->expn > p->expn && p->next && q->expn >= (p->next)->expn) {
//             pre = p;
//             p = p->next;
// //            printf("2\n");
//         } else {
//             pre = p;
//             break;
//         }
//         index ++;
//     }
//     if (q) {//多项式2未计算完
//         pre->next = q;
//     }
//     return head1;
// }

// List Multiply (List head1, List head2) {
//     List p2 = head2->next->next;
//     List newHead = (List)malloc(sizeof(Node));
//     List pp = (List)malloc(sizeof(Node));
//     newHead->next = pp;
//     pp->next = NULL;
//     List p1;
//     List head1Pre = CopyList(head1);
//     List res = NULL;
//     while (p2) {
//         p1 = head1->next->next;
//         while (p1) {
//             p1->coef *= p2->coef;
//             p1->expn += p2->expn;
//             p1 = p1->next;
//         }
//         p2 = p2->next;
//         res = Plus(head1, newHead);
//         newHead = CopyList(head1);
//         head1 = CopyList(head1Pre);
//     }
//     return res;
// }

// int main() {
//     int i1, i2;
//     List head1, head2;
//     scanf("%d", &i1);
//     head1 = Creat(i1);
//     scanf("%d", &i2);
//     head2 = Creat(i2);
//     List head = Multiply(head1, head2);
//     Print(head);
// }

// //7-5 一元多项式运算器——求值
// #include<stdio.h>
// #include<stdlib.h>

// typedef struct Polynode
// {
// 	int coef;
// 	int ind;
// 	struct Polynode* next;
// }Polynode;

// Polynode* Init()
// {
// 	Polynode* h = (Polynode*)malloc(sizeof(Polynode));
// 	h->coef = 0;
// 	h->ind = 0;
// 	h->next = NULL;
// 	return h;
// }

// void creat(int n, Polynode* node)
// {
// 	Polynode* r = node;
// 	for (int i = 0; i <= n; i++)
// 	{
// 		Polynode* s = (Polynode*)malloc(sizeof(Polynode));
// 		int ind, coef;
// 		char c1, c2, c3;
// 		scanf("%c%d%c%d%c", &c1, &coef, &c2, &ind, &c3);
// 		s->coef = coef;
// 		s->ind = ind;
// 		r->next = s;
// 		r = s;
// 	}
// 	r->next = NULL;
// }

// int main()
// {
// 	Polynode* l = Init();
// 	int n;
// 	scanf("%d", &n);
// 	//getchar();
// 	//getchar();
// 	creat(n, l);
// 	int x;
// 	scanf("%d", &x);
// 	int sum = 0;
// 	Polynode* p = l->next;
// 	while (p)
// 	{
// 		int t = 1;
// 		for (int i = 0; i < p->ind; i++)
// 		{
// 			t *= x;
// 		}
// 		sum += t * p->coef;
// 		p = p->next;
// 	}
// 	printf("%d", sum);
// 	return 0;
// }

// 7-6 一元多项式运算器——求导

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// typedef struct node {
//     int coef;
//     int exp;
//     struct node* next;
// }Node, * List;

// List Creat(int i) {
//     List head;
//     head = (List)malloc(sizeof(Node));
//     List pre, pnew;
//     pre = head;
//     for (int j = 0; j <= i; j++) {
//         pnew = (List)malloc(sizeof(Node));
//         char a,b;
//         scanf("%c%d,%d%c)",&a, &pnew->coef, &pnew->exp,&b);
//         pre->next = pnew;
//         pre = pnew;
//     }
//     return head;
// }

// void Print(List head) {
//     List q = head->next->next;
//     int flag = 1;
//     if (!q) {
//         putchar('0');
//         printf("\n");
//         return;
//     }
//     while (q) {
//         if (q->coef > 0 && flag != 1) {
//             putchar('+');
//         }
//         if (q->coef != 1 && q->coef != -1) {
//             printf("%d", q->coef);
//             if (q->exp == 1) {
//                 putchar('X');
//             }
//             else if (q->exp) {
//                 printf("X^%d", q->exp);
//             }
//         }
//         else {
//             if (q->coef == 1) {
//                 if (!q->exp) {
//                     putchar('1');
//                 }
//                 else if (q->exp == 1) {
//                     putchar('X');
//                 }
//                 else {
//                     printf("X^%d", q->exp);
//                 }
//             }
//             if (q->coef == -1) {
//                 if (!q->exp) {
//                     printf("-1");
//                 }
//                 else if (q->exp == 1) {
//                     printf("-X");
//                 }
//                 else {
//                     printf("-X^%d", q->exp);
//                 }
//             }
//         }
//         q = q->next;
//         flag++;
//     }
// }

// void Process(List head) {
//     List pre = head->next;
//     while (pre->next) {
//         if (pre->next && pre->next->exp == 0) {
//             pre->next = pre->next->next;
//         }
//         pre = pre->next;
//         pre->coef *= pre->exp;
//         pre->exp--;
//     }
// }

// int main() {
//     int i;
//     scanf("%d", &i);
//     List head;
//     head = Creat(i);
//     Process(head);
//     Print(head);
// }

// 7-7 约瑟夫环（Josephus）问题
//  #include<stdio.h>
//  int main()
//  {
//      int n = 0, m = 0;
//      scanf("%d %d", &n, &m);
//      int arr[n + 1];
//      for (int i = 1; i <= n; i++)
//      {
//          scanf("%d", &arr[i]);
//      }
//      int cnt = 0, i = 0, k = 0;
//      while (cnt != n)
//      {
//          i++;
//          if (i > n) i = 1;
//          if (arr[i] != 0)//没出局
//          {
//              k++;//报数
//              if (k == m)
//              {
//                  printf("%d ", i);
//                  m = arr[i];
//                  arr[i] = 0;
//                  k = 0;
//                  cnt++;
//              }
//          }
//      }
//      return 0;
//  }

// 7-8 约瑟夫（Josephus）排列问题Step1
//  #include <stdio.h>
//  int Josephus(int n, int k, int i) {
//      if (i == 1)
//          return (k - 1) % n;
//      else
//          return (Josephus(n - 1, k, i - 1) + k) % n;
//  }
//  int main() {
//      int n, m;
//      scanf("%d %d", &n, &m);
//      for (int i = 1; i <= n; i++) {
//          printf("%d ", Josephus(n, m, i) + 1);
//      }
//      return 0;
//  }

// 7-9 约瑟夫（Josephus）排列问题Step2
//  #include <stdio.h>
//  int Josephus(int n, int m, int i)
//  {
//      if (i == 1) return (m - 1) % n;
//      else return (Josephus(n - 1, m, i - 1) + m) % n;
//  }
//  int main()
//  {
//      int n, k;
//      scanf("%d %d", &n, &k);
//      int a[n + 1], b[n + 1];
//      int m = 0;
//      int ret = 0;
//      for (int i = n - k + 1; i <= n; i++)
//      {
//          scanf("%d", &a[i]);
//      }
//      int count = 0;
//      for (int m = 1; m <= n; m++)
//      {
//          for (int i = 1; i <= n; i++)
//          {
//              b[i] = Josephus(n, m, i) + 1;
//              if (i >= n - k + 1)
//              {
//                  if (a[i] == b[i]) count++;
//              }
//              if (count == k)
//                  ret = m;
//          }

//     }
//     printf("%d",ret);
//     return 0;
// }
// 链表逆置
// void Reverse( LinkList head )
// {
//     LinkList p = head->next;
//     head->next = NULL;
//     while (p)
//     {
//         LinkList q = p->next;
//         p->next = head->next;
//         head->next = p;
//         p = q;
//     }
// }

// //6-4 删除顺序表中指定值元素

// void DeleteX(SeqList *q, ElemType x)
// {
//     int i = 0, j = 0;
//     for (i = 0; i < q->length; i++)
//     {
//         if (q->elem[i] != x)
//         {
//             q->elem[j] = q->elem[i];
//             j++;
//         }
//     }
//     q->length = j;
// }

// 6-5 删除循环链表中已知结点的前驱
//  void DelPrior(LNode *s)
//  {
//      LNode* pre = s;
//      LNode* ppre = s;
//      while(pre)
//      {
//          if(ppre->next->next==s)
//          {
//              pre = ppre->next;
//              ppre->next = s;
//              break;
//          }
//          ppre =ppre ->next;
//      }
//  }

// 6-6 从单链表LA指定位置删除连续n个元素并插入单链表LB的指定位置
//  void MoveLaToLb(LinkList *pa, int i, int len, LinkList *pb, int j)
//  {
//      LinkList m = *pa, n, p, q = *pb, r;
//      int length1 = 1 ,length2 = 0;
//      while (m)
//      {
//          length1++;
//          m = m->next;
//      }
//      if (i + len > length1) return;
//      while (q)
//      {
//          length2++;
//          q = q->next;
//      }
//      if (j > length2) return;
//      m = *pa;
//      if (i == 1)
//      {
//          n = m;
//          for (int k = 0; k < len - 1; k++) m = m->next;
//          p = m;
//          *pa = m->next;
//      }
//      else
//      {
//          for (int k = 0; k < i - 2; k++) m = m->next;
//          r = m;
//          n = m->next;
//          for (int k = 0; k < len; k++) m = m->next;
//          p = m;
//          r->next = p->next;
//      }
//      q = *pb;
//      if (j == 0)
//      {
//          p->next = q;
//          *pb = n;
//      }
//      else
//      {
//          for (int k = 0; k < j - 1; k++) q = q->next;
//          p->next = q->next;
//          q->next = n;
//          //n是插入的头，p是尾
//      }
//  }

// 6-7 两个单链表元素交叉合并
//  LinkList CombineList(LinkList La,LinkList Lb)
//  {
//      LNode *p = La->next ,*q = Lb->next ,*r;
//      LinkList Lc;
//      int m = 0 ,n = 0;
//      while(p)
//      {
//          ++m;
//          p = p->next;
//      }
//      while(q)
//      {
//          ++n;
//          q = q->next;
//      }
//      p = La->next;
//      q = Lb->next;
//      if(m <= n)
//      {
//      	Lc = La;
//          r = Lc;
//          while(p && q)
//          {
//              r->next = p;
//              r = p;
//              p = p->next;
//              r->next = q;
//              r = q;
//              q = q->next;
//          }
//          while(q)
//          {
//              r->next = q;
//              r = q;
//              q = q->next;
//          }
//          free(Lb);
//          return (Lc);
//      }
//      else return CombineList(Lb,La);
//  }

// 7-3 打印杨辉三角形
//  #include <iostream>
//  #include <queue>
//  using namespace std;
//  void yanghuitriangle(int n)
//  {
//      queue<int> line;
//      line.push(1);
//      int temp;
//      for (int i = 0; i < n ; ++i)
//      {
//          line.push(1);
//          for (int j = 1; j <= i; ++j)
//          {
//              temp = line.front();
//              cout << temp << " ";
//              line.pop();
//              temp = temp + line.front();
//              line.push(temp);
//          }
//          cout << line.front() << " " << endl;
//          line.pop();
//          line.push(1);
//      }
//  }
//  int main()
//  {
//      int N;
//      cin >> N;
//      yanghuitriangle(N);
//      return 0;
//  }

// 7-4 回文判断

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define TRUE 1
// #define FALSE 0

// #define Stack_Size 50
// typedef char ElemType;
// typedef struct
// {      ElemType  data[Stack_Size];
//        int  top;
// }SeqStack;

// //栈的基本操作函数定义
// SeqStack* InitStack();  //栈初始化
// int IsEmpty(SeqStack *S); //栈判空
// int IsFull(SeqStack *S);  //栈判满
// int Push(SeqStack * S, ElemType x);  //  入栈
// int Pop(SeqStack * S, ElemType *x);  //  出栈
// int GetTop(SeqStack *S, ElemType *x); // 取栈顶元素

// int IsPalindrome(char s[]);  //判断字符串s是否回文。

// int main()
// {
//     char s[200];
//     scanf("%s",s);
//     if(IsPalindrome(s))
//         printf("回文");
//     else
//         printf("不是回文");
// }

// SeqStack* InitStack()
// {
//     SeqStack *s;
//     s=(SeqStack *)malloc(sizeof(SeqStack));
//     s->top=-1;
//     return s;
// }
// int IsEmpty(SeqStack *S)
// {
//       return(S->top==-1?TRUE:FALSE);
// }
// int IsFull(SeqStack *S)
// {
//    return(S->top== Stack_Size-1?TRUE:FALSE);
// }
// int Push(SeqStack * S, ElemType x)
// {
//      if(S->top== Stack_Size-1)
//          return(FALSE);
//      S->top++;
//      S->data[S->top]=x;
//      return(TRUE);
// }
// int Pop(SeqStack * S, ElemType *x)
// {     if(S->top==-1)
//              return(FALSE);
//       *x= S->data[S->top];
//       S->top--;
//       return(TRUE);
// }
// int GetTop(SeqStack *S, ElemType *x)
// {
//       if(S->top==-1)
//             return(FALSE);
//       *x = S->data[S->top];
//       return(TRUE);
// }

// int IsPalindrome(char s[])
// {
//     SeqStack *st = InitStack();
//     st->top = 0;
//     int length = strlen(s);
//     while (st->top < length / 2)
//     {
//         st->data[st->top] = s[st->top];
//         st->top++;
//     }
//     st->top--;
//     for (int p = (length - 1) / 2 + 1; p < length; ++p)
//     {
//         if (st->data[st->top] == s[p]) st->top--;
//         else return 0;
//     }
//     if (st->top == -1) return 1;
//     else return 0;
// }

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n+1);
    for (int i = 0; i <= n; ++i)
    {
        char c1, c2;
        scanf("%c%d,%d%c", &c1, &v[i].first, &v[i].second, &c2);
    }
    for (int i = 0; i <= n; i++)
    {
        v[i].first *= v[i].second;
        v[i].second--;
    }
    int start = 0;
    for (int i = 0; i <= n; i++)
    {
        if (v[i].second < 0) continue;
        else
        {
            start = i;
            break;
        }
    }
    for (int i = start; i <= n; i++)
    {
        if (v[i].first > 0 && i != start) cout << "+";
        if (v[i].second == 0) cout << v[i].first;
        else if (v[i].second == 1) cout << v[i].first << "X";
        else cout << v[i].first << "X^" << v[i].second;
    }
    return 0;
}