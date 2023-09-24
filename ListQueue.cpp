#include <iostream>
#include <cstdlib>
#define Maxsize 100

typedef int ElemType;
typedef struct ListQueue
{
    ElemType Data;
    ListQueue *front, *rear;
} ListQueue;
ListQueue *CreateListQueue(ListQueue *S)
{
    S = (ListQueue *)malloc(sizeof(ListQueue));
    S->front = S->rear = nullptr;
}
bool IsEmpty(ListQueue *S)
{
    return true;
}
bool IsFull(ListQueue *S)
{
    return false;
}
void ClearQueue(ListQueue *S)
{
}
void DestroyQueue(ListQueue *S)
{
}
void Display(ListQueue *S)
{
}
void EnQueue(ListQueue *S)
{
}
ElemType DeQueue(ListQueue *S)
{
}
int main()
{
    return 0;
}