#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//*vector存放自定义数据类型
class Person
{
    public:
        Person(string name,int age){
            m_name=name;
            m_age=age;
        }
    string m_name;
    int m_age;
};
void test01()
{
    vector<Person> v;
    Person p1("aaa",20);
    Person p2("bbb",30);
    Person p3("ccc",40);
    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    //遍历
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout << "姓名 " << (*it).m_name << " 年龄 " << it->m_age << endl;
    }
}
void test2()
{
    vector<Person*> v;
    Person p1("aaa",20);
    Person p2("bbb",30);
    Person p3("ccc",40);
    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    //遍历
    for(vector<Person*>::iterator it=v.begin();it!=v.end();it++)
    {
        cout << "姓名 " << (*it)->m_name << " 年龄 " << (*it)->m_age << endl;
    }
}
int main()
{
    test01();
    return 0;
}