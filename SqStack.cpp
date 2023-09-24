#include <cstdio>
#include <cstdlib>
#define Maxsize 100

typedef int Elemtype;
typedef struct
{
    Elemtype Data[Maxsize];
    int top, base;
} SqStack;

SqStack *CreateSqStack(SqStack *S, int num)
{
    S = (SqStack *)malloc(sizeof(SqStack));
    S->base = S->top = 0;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &S->Data[i]);
        S->top++;
    }
    return S;
}
int SqStackLength(SqStack *S)
{
    return S->top - S->base;
}
bool IsEmpty(SqStack *S)
{
    return S->base == S->top;
}
void ClearSqStack(SqStack *S)
{
    S->base = S->top = 0;
}
void Display(SqStack *S)
{
    if (IsEmpty(S))
    {
        printf("The SqStack is already empty");
        return;
    }
    else
    {
        for (int i = 0; i < S->top; i++)
        {
            printf("%d ", S->Data[i]);
        }
        printf("\n");
    }
}
Elemtype Pop(SqStack *S)
{
    if (IsEmpty(S))
    {
        return -1;
    }
    else
    {
        S->top--;
        return S->Data[S->top];
    }
}
void Push(SqStack *S, Elemtype num)
{
    S->Data[S->top] = num;
    S->top++;
}
int main()
{
    SqStack *S = CreateSqStack(S, 5);
    Push(S, 666);
    Display(S);
    Push(S, 333);
    Display(S);
    return 0;
}