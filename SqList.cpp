#include <cstdio>
#include <cstdlib>
#define ElemType int
#define Maxsize 100

typedef struct
{
    ElemType Data[Maxsize];
    int Length;
} SqList;

void InitSqList(ElemType *num) // * create a SqList and initialize meanwhile
{
    SqList *head = (SqList *)malloc(sizeof(SqList));
    for (int i = 0; i < 10; i++)
    {
        head->Data[i] = *(num + i);
    }
}
int ListLength(SqList *p) // * return the length of the SqList
{
    return p->Length;
}
bool IsEmpty(SqList *p) // * judge whether the SqList is empty
{
    return p->Length == 0;
}
void ClearList(SqList *p) // * clear the element in the SqList
{
    p->Length = 0;
}
void DestroyList(SqList *head) // * destroy the Sqlist
{
    free(head);
}
void AddElem(SqList *p, int inplace) // * add a new element to the SqList at the very position
{
    if (inplace > p->Length || inplace < 1)
    {
        printf("Input Error!");
        return;
    }
    else
    {
        for (int i = p->Length - 1; i >= inplace - 1; i--)
        {
            p->Data[i + 1] = p->Data[i];
        }
        scanf("%d", &p->Data[inplace - 1]);
        p->Length++;
    }
}
void ChangeElem(SqList *p, int inplace, ElemType newdata) // *change the element at the very position
{
    if (inplace > p->Length + 1 || inplace < 1)
    {
        printf("Input Errpr!");
        return;
    }
    else
    {
        p->Data[inplace - 1] = newdata;
    }
}
void DeleteElem(SqList *p, int inplace) //* delete the element at the very position
{
    if (inplace > p->Length || inplace < 1)
    {
        printf("Input Error");
        return;
    }
    else
    {
        for (int i = inplace - 1; i < p->Length; i++)
        {
            p->Data[i] = p->Data[i + 1];
        }
        p->Length--;
    }
}
void Display(SqList *p) // * display the element in the SqList one by one
{
    if (IsEmpty(p))
    {
        printf("The SqList is empty!");
        return;
    }
    else
    {
        for (int i = 0; i <= p->Length - 1; i++)
        {
            printf("%d   ", p->Data[i]);
        }
        printf("\n");
    }
}
int Seek_Order(SqList *p, ElemType tar) //* seek the tar and return its position
{
    if (IsEmpty(p))
    {
        return -1;
    }
    else
    {
        for (int i = 0; i <= p->Length - 1; i++)
        {
            if (p->Data[i] == tar)
            {
                return i + 1;
            }
        }
        return -1;
    }
}
ElemType Seek_Elem(SqList *p, int pos) // * seek the element locating in pos position
{
    if (IsEmpty(p))
    {
        return INT_MAX;
    }
    else if (pos > p->Length || pos < 1)
    {
        return INT_MAX;
    }
    else
    {
        return p->Data[pos - 1];
    }
}
void Sort(SqList *p) // * sort the element in the SqList
{
    for (int i = 0; i < p->Length - 1; i++)
    {
        for (int j = p->Length - 1; j > i; j--)
        {
            if (p->Data[j - 1] > p->Data[j])
            {
                ElemType temp = p->Data[j - 1];
                p->Data[j - 1] = p->Data[j];
                p->Data[j] = temp;
            }
        }
    }
}
void Reverse(SqList *p) //* reverse the SqList
{
    int i, j;
    for (i = 0, j = p->Length - 1; i <= j; i++, j--)
    {
        int temp = p->Data[i];
        p->Data[i] = p->Data[j];
        p->Data[j] = temp;
    }
}
SqList *Merge(SqList *p1, SqList *p2) //* merge two ordered SqList
{
    int i = 0, j = 0, k = 0;
    SqList *temp = (SqList *)malloc(sizeof(SqList));
    temp->Length = 0;
    while (i <= p1->Length - 1 && j <= p2->Length - 1)
    {
        if (p1->Data[i] <= p2->Data[j])
        {
            temp->Data[k] = p1->Data[i];
            k++;
            i++;
            temp->Length++;
        }
        else
        {
            temp->Data[k] = p2->Data[j];
            k++;
            j++;
            temp->Length++;
        }
    }
    if (i > p1->Length - 1)
    {
        for (; j <= p2->Length - 1; j++)
        {
            temp->Data[k] = p2->Data[j];
            k++;
            temp->Length++;
        }
    }
    else
    {
        for (; i <= p1->Length - 1; i++)
        {
            temp->Data[k] = p1->Data[i];
            k++;
            temp->Length++;
        }
    }
    return temp;
}
SqList *RemoveSame1(SqList *p) // * reduce the same element in the SqList(using two layer circulation)
{
    if (IsEmpty(p))
    {
        return nullptr;
    }
    else
    {
        for (int i = 0; i <= p->Length - 1; i++)
        {
            for (int j = i + 1; j <= p->Length - 1; j++)
            {
                if (p->Data[i] == p->Data[j])
                {
                    DeleteElem(p, j + 1);
                }
            }
        }
    }
    return p;
}
SqList *RemoveSame2(SqList *p) // * reduce the same element in the SqList(using the bucket sorting alike)
{
    if (IsEmpty(p))
    {
        return nullptr;
    }
    else
    {
        int flag[1000] = {0};
        for (int i = 0; i <= p->Length - 1; i++)
        {
            flag[p->Data[i]] += 1;
            if (flag[p->Data[i]] == 2)
            {
                flag[p->Data[i]]--;
                DeleteElem(p, i);
            }
        }
    }
    return p;
}
SqList *RemoveSame3(SqList *p) //* reduce the same element in the SqList(using a new numpy)
{
    if (IsEmpty(p))
    {
        return nullptr;
    }
    else
    {
        int Data[p->Length];
        for (int i = 0; i <= p->Length - 1; i++)
        {
            Data[i] = p->Data[i];
        }
        int k = 0;
        for (int j = 0; j <= p->Length - 1; j++)
        {
            if (Data[j] == Data[j + 1])
                p->Data[k++] = Data[++j];
            else
                p->Data[k++] = Data[j];
        }
        p->Length = k;
        return p;
    }
}
int main()
{
    SqList *head1 = (SqList *)malloc(sizeof(SqList));
    head1->Length = 0; //! never forget to add this sentense!!!!!
    for (int i = 0; i < 10; i++)
    {
        head1->Data[i] = i * i + 1;
        head1->Length++;
    }
    SqList *head2 = (SqList *)malloc(sizeof(SqList));
    head2->Length = 0; //! never forget to add this sentense!!!!!
    for (int j = 0; j < 8; j++)
    {
        head2->Data[j] = j * j;
        head2->Length++;
    }
    Display(head1);
    Display(head2);
    SqList *head = Merge(head1, head2);
    SqList *newhead = RemoveSame3(head);
    Display(newhead);
    return 0;
}