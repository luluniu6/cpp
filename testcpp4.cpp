// #include <iostream>
// using namespace std;
// #define TRUE 1
// #define FALSE 0
// #define MaxSize 20
// typedef int Elemtype;
// typedef int Status;

// typedef struct SqDoubleStack
// {
//     Elemtype data[MaxSize];
//     int top1;
//     int top2;
// } SqDoubleStack;

// Status InitStack(SqDoubleStack *s)
// {
//     s->top1 = -1;
//     s->top2 = MaxSize;
//     return TRUE;
// }
// Status GetTop(SqDoubleStack *s,Elemtype *e,int stackNumber)
// {
//     if(stackNumber==1)
//     {
//         if(s->top1==-1) return FALSE; 
//         *e = s->data[s->top1];
//     }
//     if(stackNumber==2)
//     {
//         if(s->top2==MaxSize) return FALSE;
//         *e = s->data[s->top2];
//     }
//     return TRUE;
// }
// Status Push(SqDoubleStack *s,Elemtype e,int stackNumber)
// {
//     if(s->top1+1==s->top2) return FALSE;
//     if(stackNumber==1)
//     {
//         s->top1++;
//         s->data[s->top1] = e;
//     }
//     if(stackNumber==2)
//     {
//         s->top2--;
//         s->data[s->top2] = e;
//     }
//     return TRUE;
// }
// Status Pop(SqDoubleStack *s,Elemtype *e,int stackNumber)
// {
//     if(stackNumber==1)
//     {
//         if(s->top1==-1) return FALSE;
//         *e = s->data[s->top1];
//         s->top1--;
//     }
//     if(stackNumber==2)
//     {
//         if(s->top2==MaxSize) return FALSE;
//         *e = s->data[s->top2];
//         s->top2++;
//     }
//     return FALSE;
// }
// int main()
// {
//     SqDoubleStack S;
//     Elemtype e = 1;
//     int stackNumber = 2;
//     InitStack(&S);
//     Push(&S,e,stackNumber);
//     Pop(&S,&e,stackNumber);
//     cout<<e<<endl;
//     return 0;
// }