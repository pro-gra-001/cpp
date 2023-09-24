#include <cstdio>
#include <cstdlib>

#define Maxsize 100
typedef int ElemType;
typedef struct ListNode //! WARNING:don't forget to add "ListNode" after "struct" when using C++ !!!!!
{
    ElemType Data;
    ListNode *next;
} ListNode;

ListNode *CreateTail(ListNode *head, int num) //* create a ListNode in order
{
    head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *tail = head;
    for (int i = 0; i < num; i++)
    {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        scanf("%d", &node->Data);
        tail->next = node;
        tail = node;
    }
    tail->next = nullptr;
    return head;
}
ListNode *CreateHead(ListNode *head, int num) //* create a ListNode reverse order
{
    head = (ListNode *)malloc(sizeof(ListNode));
    head->next = nullptr;
    for (int i = 0; i < num; i++)
    {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        scanf("%d", &node->Data);
        node->next = head->next;
        head->next = node;
    }
    return head;
}
int ListLength(ListNode *head) //* return the length of the ListNode
{
    int len = 0;
    ListNode *p = head->next;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
bool IsEmpty(ListNode *head) //* judge whether the ListNode is empty
{
    return ListLength(head) == 0;
}
void ClearList(ListNode *head) //* clear the ListNode
{
    ListNode *pre = head, *p = head->next;
    while (p)
    {
        p = p->next;
        free(pre);
        pre = p;
    }
    free(pre);
}
void DestoryList(ListNode *head) //* destory the ListNode
{
}
void Display(ListNode *head) //* display the element in the ListNode
{
    ListNode *p = head->next; //! WARNING: when meeting the situation that the ListNode need to be travel,begin at head->next,explain locates in line 74/75
    while (p)
    {

        printf("%d  ", p->Data);
        p = p->next; //! Generally,the upgrade operation will be done at last.For instance, once "p=p->next"is in front of "printf……",there may be "Segmentation fault"
    }
    printf("\n");
}
void AddElem(ListNode *head, int inplace) //* add a new element to the ListNode
{
    if (inplace > ListLength(head) || inplace < 1)
    {
        printf("Input Error!\n");
        return;
    }
    else
    {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        scanf("%d", &node->Data);
        ListNode *p = head; //! for the reason that when adding a new element,we need to find its previous node,so here begins from "head"
        while (--inplace)
        {
            p = p->next;
        }
        node->next = p->next;
        p->next = node;
    }
}
void ChangeElem(ListNode *head, int inplace, ElemType newdata) //* change the very element in the ListNode
{
    if (inplace > ListLength(head) || inplace < 1)
    {
        printf("Input error\n");
        return;
    }
    else
    {
        ListNode *p = head->next; //! different from AddElem,we need to find itself when change one node,so here begins at "head->next"
        while (--inplace)
        {
            p = p->next;
        }
        p->Data = newdata;
    }
}
void DeleteElem(ListNode *head, int inplace) //* delete the very element in the ListNode
{
    if (inplace > ListLength(head) || inplace < 1)
    {
        printf("Input Error\n");
        return;
    }
    else
    {
        ListNode *p = head; //! the same as AddElem
        while (--inplace)
        {
            p = p->next;
        }
        ListNode *nex = p->next;
        p->next = nex->next;
        free(nex);
    }
}
int Seek_Order(ListNode *head, ElemType tar) //* return the position of the very element
{
    if (IsEmpty(head))
    {
        return -1;
    }
    else
    {
        ListNode *p = head->next;
        int n = 0;
        while (p)
        {
            n++;
            if (p->Data == tar)
                return n;
            p = p->next;
        }
        return -1;
    }
}
ElemType Seek_Elem(ListNode *head, int inplace) //* return the element at the very position
{
    if (IsEmpty(head))
    {
        return INT_MAX;
    }
    else if (inplace > ListLength(head) || inplace < 1)
    {
        return INT_MAX;
    }
    else
    {
        ListNode *p = head;
        while (inplace--)
        {
            p = p->next;
        }
        return p->Data;
    }
}
ListNode *Merge(ListNode *head1, ListNode *head2) //* merge two ordered ListNode
{
    if (head1 == nullptr || IsEmpty(head1))
        return head2;
    if (head2 == nullptr || IsEmpty(head2))
        return head1;
    int i = 0, j = 0;
    ListNode *p = head1->next, *q = head2->next, *temp = (ListNode *)malloc(sizeof(ListNode)), *tail = temp;
    while (p && q)
    {
        if (p->Data <= q->Data)
        {
            tail->next = p;
            tail = p;
            p = p->next;
        }
        else
        {
            tail->next = q;
            tail = q;
            q = q->next;
        }
    }
    while (p)
    {
        tail->next = p;
        tail = p;
        p = p->next;
    }
    while (q)
    {
        tail->next = q;
        tail = q;
        q = q->next;
    }
    tail->next = nullptr;
    return temp;
}
void RemoveSame1(ListNode *head) //* remove the same element in the ListNode(need to be sorted but O(n))
{
    ListNode *pre = head->next, *p = pre->next;
    while (p)
    {
        if (pre->Data == p->Data)
        {
            ListNode *cur = p->next;
            free(p);
            p = cur;
            pre->next = p;
        }
        pre = p;
        p = p->next;
    }
}
void RemoveSame2(ListNode *head) //* remove the same element in the ListNode(without sort but O(n*n))
{
    for (ListNode *p = head->next; p != nullptr; p = p->next)
    {
        ListNode *pre = p;
        for (ListNode *q = p->next; q != nullptr; q = q->next)
        {
            if (p->Data == q->Data)
            {
                ListNode *cur = q->next;
                free(q);
                q->next = cur;
                pre->next = cur;
            }
            else
            {
                pre = pre->next; // TODO: I came out this method! hiahiahia
            }
        }
    }
}
ListNode *ReverseList(ListNode *head) //* reverse the whole list
{
    if (IsEmpty(head))
        return nullptr;
    ListNode *pre = nullptr, *cur = head->next; //* "pre = nullptr" enable the tail of the returned ListNode to own a end,avoid to endless circulation;
    while (cur)
    {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    head->next = pre; //* Here couldn't be "cur",for the reason that after reverse the "cur" become nullptr, leading to no outcome
    return head;
}
ListNode *ReverseBetween(ListNode *head, int m, int n) // * reverse the list between m and n
{
    if (IsEmpty(head) || m < 1 || n > ListLength(head))
    {
        return nullptr;
    }
    else
    {
        ListNode *p = head;
        int k = m;
        while (--m)
        {
            p = p->next;
        }
        ListNode *tail = p->next, *cur = tail->next;
        for (int i = k; i < n; i++)
        {
            ListNode *tmp = cur->next;
            cur->next = p->next;
            p->next = cur;
            cur = tmp;
        }
        tail->next = cur;
        return head;
    }
}
void Sort(ListNode *head) // * sort the ListNode
{
    if (IsEmpty(head))
    {
        printf("The ListNode is empty\n");
        return;
    }
    else
    {
        ElemType num[ListLength(head)];
        ListNode *p = head->next;
        int i = 0;
        while (p)
        {
            num[i++] = p->Data;
            p = p->next;
        }
        for (int i = 0; i < ListLength(head) - 1; i++)
        {
            for (int j = ListLength(head) - 1; j > i; j--)
            {
                if (num[j - 1] > num[j])
                {
                    int temp = num[j - 1];
                    num[j - 1] = num[j];
                    num[j] = temp;
                }
            }
        }
        p = head->next;
        for (int k = 0; k < ListLength(head); k++)
        {
            p->Data = num[k];
            p = p->next;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    ListNode *phead1 = CreateTail(phead1, n);
    // ListNode *phead2 = CreateTail(phead2, n);
    Display(phead1);
    // Display(phead2);
    // ListNode *phead = Merge(phead1, phead2);
    // Display(phead);
    // RemoveSame2(phead1);
    ListNode *phead3 = ReverseBetween(phead1, 2, 4);
    Display(phead3);
    return 0;
}