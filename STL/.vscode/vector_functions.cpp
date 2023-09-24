#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
void test0()
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout << (*it) << endl;
    }
}
void test1()
{
    if(!v.empty())
    {
        cout << v.capacity() << endl << v.size();
    }
}
void test2()
{
    // v.resize(4);
    v.resize(10,-1);
}
void test3()
{
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
}
void test4()
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        if((*it)==2)
        {
            v.insert(it,250);
        }
    }
}
void test5()
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        if((*it)==250)
        {
            v.erase(it);
        }
    }
}
void test6()
{
    v.clear();
}
void test7()
{
    cout << v.at(2) << endl << v[1] << endl << v.front() << v.back() << endl;
}
int main()
{
    for(int i=0;i<8;i++)
    {
    v.push_back(i);
    }
    test4();
    test0();
    return 0;
}