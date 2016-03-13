/*======================================================
    > File Name: 2.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月13日 星期日 15时18分05秒
 =======================================================*/

#include<iostream>

using namespace std;
class Base  
{  
    public:  
        Base()  
        {  
            mBase1 = 101;  
            mBase2 = 102;  
        }  
        virtual void func1()  
        {  
            cout << "Base::func1()" << endl;  
        }  
        virtual void func2()  
        {  
            cout << "Base::func2()" << endl;  
        }  
    private:  
        int mBase1;  
        int mBase2;  
};  
  
class Derived : public Base  
{  
    public:  
        Derived():  
            Base()  
        {  
            mDerived1 = 1001;  
            mDerived2 = 1002;  
        }  
        virtual void func2()  
        {  
            cout << "Derived::func2()" << endl;  
        }  
        virtual void func3()  
        {  
            cout << "Derived::func3()" << endl;  
        }  
    private:  
        int mDerived1;  
        int mDerived2;  
};


void visitVtbl(int **vtbl, int count)  
{  
    cout << vtbl << endl;  
    cout << "\t[-1]: " << (long)vtbl[-1] << endl;  
  
    typedef void (*FuncPtr)();  
    for (int i = 0; vtbl[i] && i < count; ++i)  
    {  
        cout << "\t[" << i << "]: " << vtbl[i] << " -> ";  
        FuncPtr func = (FuncPtr)vtbl[i];  
        func();  
    }  
}  

int main()  
{  
    Derived d;  
    char *p = (char*)&d;  
    visitVtbl((int**)*(int**)p, 3);  
    p += sizeof(int**);  
  
    cout << *(int*)p << endl;  
    p += sizeof(int);  
  
    cout << *(int*)p << endl;  
    p += sizeof(int);  
  
    cout << *(int*)p << endl;  
    p += sizeof(int);  
  
    cout << *(int*)p << endl;  
  
    return 0;  
}  
