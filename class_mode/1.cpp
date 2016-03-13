/*======================================================
    > File Name: 1.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月13日 星期日 10时40分09秒
 =======================================================*/

#include<iostream>
#include<stdio.h>

using namespace std;

class Person
{
public:
    Person():mId(10),mAge(20)
    {
        ++sCount;
    }
    virtual void print()
    {
        cout<<"id:"<<this->mId<<"  age:"<<this->mAge<<endl;
    }
    virtual void job()
    {
        cout<<"Person job"<<endl;
    }
    static int personCount()
    {
        return sCount;
    }
    virtual ~Person()
    {
        --sCount;
        cout<<"~Person"<<endl;
    }
private:
    static int sCount;
    int mId;
    int mAge;
};

int Person::sCount = 0;

typedef void (*FuncPtr)();
int main()
{
    Person   person;

    /*
    cout<<"sizeof(person) ="<<sizeof(person)<<endl;
    int *p = (int*)&person;
    for(int i=0;i<sizeof(person) /sizeof(int); ++i,++p)
    {
        cout<<*p<<endl;
    }
    */
    int   **vtb1 = (int**)*(int**)&person;
    for(int i=0;i<3 && *vtb1 !=NULL;++i)
    {
        FuncPtr func = (FuncPtr)*vtb1;
        func();
        ++vtb1;
    }
    
    while(*vtb1)
    {
        cout<<" *vtb1 = "<<*vtb1<<endl;
        ++vtb1;
    }
    
    return 0;
}
