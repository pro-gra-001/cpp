#include <iostream>
using namespace std;
int Data[10] = {0};
int main()
{
    int num;
    cin >> num;
    int n = 0;
    while (num / 8)
    {
        Data[n++] = num % 8;
        num /= 8;
    }
    Data[n] = num;
    do
    {
        cout << Data[n];
    } while (n--);
    return 0;
}