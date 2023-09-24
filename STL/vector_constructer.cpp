#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> &V)
{
    for(vector<int>::iterator it=V.begin();it!=V.end();it++)
    {
        cout << (*it) << " ";
    }
}
//构造
void test0()
{
    vector<int> v1;//默认构造函数  无参
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    Print(v1);
    vector<int> v2(v1.begin(),v1.end());//第二种构造方式
    Print(v2);
    vector<int> v3(5,100);//第三种  5个100
    Print(v3);
    vector<int> v4(v3);//第四种
    Print(v4);
}
int main()
{
    test0();
    return 0;
}