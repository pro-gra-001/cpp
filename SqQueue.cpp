#include <iostream>
#include <cstdlib>
#define Maxsize 100

using namespace std;
typedef int ElemType;
typedef struct
{
    ElemType Data[Maxsize];
    int front, rear;
} SqQueue;
SqQueue *CreateSqQueue(SqQueue *S, int num)
{
    S = (SqQueue *)malloc(sizeof(SqQueue));
    S->front = S->rear = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> S->Data[i];
        S->rear++;
    }
    return S;
}
bool IsEmpty(SqQueue *S)
{
    return S->front == S->rear;
}
bool IsFull(SqQueue *S)
{
    return (S->rear + 1) % Maxsize == S->front;
}
int QueueLength(SqQueue *S)
{
    return (S->rear - S->front + Maxsize) % Maxsize;
}
void ClearQueue(SqQueue *S)
{
    S->front = S->rear;
}
void DestoryQueue(SqQueue *S)
{
    free(S);
}
void Display(SqQueue *S)
{
    for (int i = S->front; i < QueueLength(S); i++) // ! Warning: when output using queue,the loop beins at "S->front" ,not "0"
    {
        cout << S->Data[i] << "  ";
    }
    cout << endl;
}
void EnQueue(SqQueue *S)
{
    if (IsFull(S))
    {
        cout << "The SqQueue is already full" << endl;
        return;
    }
    else
    {
        S->rear = (S->rear + 1) % Maxsize;
        cin >> S->Data[(S->rear - 1)];
    }
}
ElemType DeQueue(SqQueue *S)
{
    if (IsEmpty(S))
    {
        cout << "The SqQueue is already empty" << endl;
        return -1;
    }
    else
    {
        ElemType var = S->Data[S->front];
        S->front = (S->front + 1) % Maxsize;
        return var;
    }
}
int main()
{
    SqQueue *head = CreateSqQueue(head, 5);
    Display(head);
    EnQueue(head);
    Display(head);
    cout << DeQueue(head) << endl;
    Display(head);
    return 0;
}