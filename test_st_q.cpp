// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define TRUE 1
// #define FALSE 0

// #define Stack_Size 50
// typedef char ElemType;
// typedef struct
// {
//     ElemType data[Stack_Size];
//     int top;
// } SeqStack;

// // 栈的基本操作函数定义
// SeqStack *InitStack();                // 栈初始化
// int IsEmpty(SeqStack *S);             // 栈判空
// int IsFull(SeqStack *S);              // 栈判满
// int Push(SeqStack *S, ElemType x);    //  入栈
// int Pop(SeqStack *S, ElemType *x);    //  出栈
// int GetTop(SeqStack *S, ElemType *x); // 取栈顶元素

// int IsPalindrome(char s[]); // 判断字符串s是否回文。

// int main()
// {
//     char s[20];
//     scanf("%s", s);
//     if (IsPalindrome(s))
//         printf("It's Palidrome!\n");
//     else
//         printf("It's not Palidrome!\n");
// }

// SeqStack *InitStack()
// {
//     SeqStack *s;
//     s = (SeqStack *)malloc(sizeof(SeqStack));
//     s->top = -1;
//     return s;
// }
// int IsEmpty(SeqStack *S)
// {
//     return (S->top == -1 ? TRUE : FALSE);
// }
// int IsFull(SeqStack *S)
// {
//     return (S->top == Stack_Size - 1 ? TRUE : FALSE);
// }
// int Push(SeqStack *S, ElemType x)
// {
//     if (S->top == Stack_Size - 1)
//         return (FALSE);
//     S->top++;
//     S->data[S->top] = x;
//     return (TRUE);
// }
// int Pop(SeqStack *S, ElemType *x)
// {
//     if (S->top == -1)
//         return (FALSE);
//     *x = S->data[S->top];
//     S->top--;
//     return (TRUE);
// }
// int GetTop(SeqStack *S, ElemType *x)
// {
//     if (S->top == -1)
//         return (FALSE);
//     *x = S->data[S->top];
//     return (TRUE);
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

// int IsBracketMatch(char *str);//判断str中括号是否匹配。

// int main()
// {
//     char s[20];
//     scanf("%s",s);
//     if( IsBracketMatch(s))
//         printf("Match!\n");
//     else
//         printf("Not Match!\n");
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

// int IsBracketMatch(char *str)
// {
//     Stack *s = InitStack();
//     int length = strlen(str);
//     for(int i =0;i<length;i++)
//     {
//         if(str[i])
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAXSIZE 4 // 队列的最大容量
// typedef int ElemType;
// typedef struct
// {
//     ElemType elem[MAXSIZE];
//     int rear;   // 队尾元素的位置
//     int quelen; // 队中元素的个数
// } SeQueue;

// // 队列的基本操作函数定义
// SeQueue *InitQueue();          // 初始化队列，返回值为指向队列的指针。
// void DestroyQueue(SeQueue *Q); // 依次输出队列中元素值，并释放空间。

// int IsEmptyQueue(SeQueue *Q);          // 队列判空，若为空，则返回1；非空，返回0。
// int IsFullQueue(SeQueue *Q);           // 队列判满，若为满，则返回1；非满，返回0。
// int EnQueue(SeQueue *Q, ElemType x);   //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
// int DelQueue(SeQueue *Q, ElemType *x); //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。

// int main(void)
// {
//     char cmd[20];
//     SeQueue *pQueue = InitQueue();
//     ElemType x;
//     scanf("%s", cmd);
//     while (strcmp(cmd, "END") != 0)
//     {
//         if (strcmp(cmd, "ENQUEUE") == 0)
//         {
//             scanf("%d", &x);
//             if (EnQueue(pQueue, x) == 0)
//                 printf("FULL QUEUE!\n");
//         }
//         else if (strcmp(cmd, "DELQUEUE") == 0)
//         {
//             if (DelQueue(pQueue, &x) == 0)
//                 printf("EMPTY QUEUE!\n");
//             else
//                 printf("%d\n", x);
//         }
//         else if (strcmp(cmd, "ISEMPTY") == 0)
//         {
//             if (IsEmptyQueue(pQueue) == 0)
//                 printf("NOT EMPTY\n");
//             else
//                 printf("EMPTY\n");
//         }
//         else if (strcmp(cmd, "ISFULL") == 0)
//         {
//             if (IsFullQueue(pQueue) == 0)
//                 printf("NOT FULL\n");
//             else
//                 printf("FULL\n");
//         }
//         scanf("%s", cmd);
//     }
//     DestroyQueue(pQueue);
//     return 0;
// }
// SeQueue *InitQueue() // 初始化队列，返回值为指向队列的指针。
// {
//     SeQueue *q;
//     q = (SeQueue *)malloc(sizeof(SeQueue));
//     q->quelen = 0;
//     q->rear = -1;
//     return q;
// }
// void DestroyQueue(SeQueue *Q)
// {
//     ElemType x;
//     while (!IsEmptyQueue(Q))
//     {
//         DelQueue(Q, &x);
//         printf("%d ", x);
//     }
//     printf("\n");
//     free(Q);
// }

// int IsEmptyQueue(SeQueue *Q)
// {
//     if (Q->quelen == 0) return 1;
//     else return 0;
// }
// int IsFullQueue(SeQueue *Q)
// {
//     if (Q->quelen == MAXSIZE) return 1;
//     else return 0;
// }
// int EnQueue(SeQueue *Q, ElemType x)
// {
//     if (IsFullQueue(Q)) return 0;
//     Q->rear = (Q->rear + 1) % MAXSIZE;
//     Q->elem[Q->rear] = x;
//     Q->quelen++;
//     return 1;
// }
// int DelQueue(SeQueue *Q, ElemType *x)
// {
//     if (IsEmptyQueue(Q)) return 0;
//     int front = (1 + Q->rear + MAXSIZE - Q->quelen) % MAXSIZE;
//     *x = Q->elem[front];
//     Q->quelen--;
//     return 1;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4 // 队列的最大容量
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int rear;  // 队尾元素的位置
    int front; // 对头元素的前一个位置
    int tag;   // 标志最近一次队列操作是入队还是出队。入队设为1，出队设为0。
} SeqQueue;

// 队列的基本操作函数定义
SeqQueue *InitQueue();          // 初始化队列，返回值为指向队列的指针。
void DestroyQueue(SeqQueue *Q); // 依次输出队列中元素值，并释放空间。

int IsEmptyQueue(SeqQueue *Q);          // 队列判空，若为空，则返回1；非空，返回0。
int IsFullQueue(SeqQueue *Q);           // 队列判满，若为满，则返回1；非满，返回0。
int EnQueue(SeqQueue *Q, ElemType x);   //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
int DelQueue(SeqQueue *Q, ElemType *x); //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。

int main(void)
{
    char cmd[20];
    SeqQueue *pQueue = InitQueue();
    ElemType x;
    scanf("%s", cmd);
    while (strcmp(cmd, "END") != 0)
    {
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            scanf("%d", &x);
            if (EnQueue(pQueue, x) == 0)
                printf("FULL QUEUE!\n");
        }
        else if (strcmp(cmd, "DELQUEUE") == 0)
        {
            if (DelQueue(pQueue, &x) == 0)
                printf("EMPTY QUEUE!\n");
            else
                printf("%d\n", x);
        }
        else if (strcmp(cmd, "ISEMPTY") == 0)
        {
            if (IsEmptyQueue(pQueue) == 0)
                printf("NOT EMPTY\n");
            else
                printf("EMPTY\n");
        }
        else if (strcmp(cmd, "ISFULL") == 0)
        {
            if (IsFullQueue(pQueue) == 0)
                printf("NOT FULL\n");
            else
                printf("FULL\n");
        }
        scanf("%s", cmd);
    }
    DestroyQueue(pQueue);
    return 0;
}

void DestroyQueue(SeqQueue *Q)
{
    ElemType x;
    while (!IsEmptyQueue(Q))
    {
        DelQueue(Q, &x);
        printf("%d ", x);
    }
    printf("\n");
    free(Q);
}
SeqQueue *InitQueue()
{
    SeqQueue *Q = (SeqQueue*)malloc(sizeof(SeqQueue));
    Q->front = Q->rear = -1;
    return Q;
}
int IsEmptyQueue(SeqQueue *Q)
{
    if (Q->tag == 0 && Q->front == Q->rear) return 1;
    return 0;
}
int IsFullQueue(SeqQueue *Q)
{
    if (Q->tag == 1 && Q->front == Q->rear) return 1;
    return 0;
}
int EnQueue(SeqQueue *Q, ElemType x)
{
    if (IsFullQueue(Q)) return 0;
    Q->tag = 1;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    Q->elem[Q->rear] = x;
    return 1;
}
int DelQueue(SeqQueue *Q, ElemType *x)
{
    if (IsEmptyQueue(Q)) return 0;
    Q->tag = 0;
    Q->front = (Q->front + 1) % MAXSIZE;
    *x = Q->elem[Q->front];
    return 1;
}