#include <iostream>
using namespace std;
typedef struct
{
    char *ch;
    int length;
} Str;
// * Here are some basic operations
void StrAssign(Str *S2, char *ch) // * assignment operation
{
    if (S2->ch)
        free(S2->ch); //* release the original space
    int len = 0;
    char *c = ch;
    while (*c)
    {
        ++len;
        ++c;
    }
    if (len == 0) //* if ch is empty,return a empty string
    {
        S2->ch = nullptr;
        S2->length = 0;
    }
    else
    {
        S2->ch = (char *)malloc((len + 1) * sizeof(char)); //* Here is "len+1" because of '\0'
        if (S2->ch == nullptr)
        {
            return;
        }
        else
        {
            c = ch;
            for (int i = 0; i <= len; ++c, ++i) //* Here is "<=" because of '\0'
                S2->ch[i] = *c;
            S2->length = len;
        }
    }
}
int main()
{
    return 0;
}