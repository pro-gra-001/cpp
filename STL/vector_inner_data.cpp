#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector容器存放内置数据类型
void MyPrint(int var)
{
    cout << var << endl;
}
//vector的迭代器是随机迭代器
void test1()
{
    vector<int> v;
    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //通过迭代器访问数据
    vector<int>::iterator itBegin=v.begin();//起始迭代器 指向容器第一个元素
    vector<int>::iterator itEnd=v.end();//结束迭代器 指向容器最后一个位置的下一个位置
    //第一种遍历方式
    // while(itBegin!=itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }
    //第二种遍历方式
    // for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    // {
    //     cout << *it << endl;
    // }
    //第三种遍历方式-----利用STL提供的遍历算法
    for_each(v.begin(),v.end(),MyPrint);
}
int main()
{
    test1();
    return 0;
}