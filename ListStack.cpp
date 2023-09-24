#include <iostream>
#include <cstdlib>
#define Maxsize 100

using namespace std;

typedef int ElemType;
typedef struct ListStack
{
    ElemType Data;
    ListStack *next;
} ListStack;
ListStack *CreateListStack(ListStack *S, int num)
{
    S = (ListStack *)malloc(sizeof(ListStack));
    ListStack *p = S;
    for (int i = 0; i < num; i++)
    {
        ListStack *node = (ListStack *)malloc(sizeof(ListStack));
        cin >> node->Data;
        p->next = node;
        p = node;
    }
    p->next = nullptr;
    return S;
}
bool IsEmpty(ListStack *S)
{
    return S->next == nullptr;
}
int StackLength(ListStack *S)
{
    if (IsEmpty(S))
    {
        return 0;
    }
    else
    {
        int len = 0;
        ListStack *p = S->next;
        while (p)
        {
            len++;
            p = p->next;
        }
        return len;
    }
}
void Display(ListStack *S)
{
    ListStack *p = S->next;
    while (p)
    {
        cout << p->Data << "  ";
        p = p->next;
    }
    cout << endl;
}
ElemType Pop(ListStack *S)
{
    if (IsEmpty(S))
    {
        return -1;
    }
    else
    {
        ListStack *pre = S, *cur = pre->next;
        while (cur->next)
        {
            pre = cur;
            cur = cur->next;
        }
        ElemType var = cur->Data;
        pre->next = nullptr;
        free(cur);
        return var;
    }
}
void Push(ListStack *S)
{
    if (IsEmpty(S))
    {
        cout << "The ListStack is already empty" << endl;
        return;
    }
    else
    {
        ListStack *node = (ListStack *)malloc(sizeof(ListStack));
        cin >> node->Data;
        ListStack *p = S->next;
        while (p->next)
        {
            p = p->next;
        }
        node->next = nullptr;
        p->next = node;
    }
}
int main()
{
    ListStack *head = CreateListStack(head, 5);
    Pop(head);
    // Push(head);
    // Display(head);
    cout << StackLength(head);
    return 0;
}