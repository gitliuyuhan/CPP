/*======================================================
    > File Name: 4.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月13日 星期日 16时43分58秒
 =======================================================*/

#include<iostream>

using namespace std;

class Base  
{  
    public:  
        Base()  
        {  
            mBase = 11;  
        }  
        virtual void funcA()  
        {  
            cout << "Base::funcA()" << endl;  
        }  
        virtual void funcX()  
        {  
            cout << "Base::funcX()" << endl;  
        }  
    protected:  
        int mBase;  
};  
class Base1 : public Base  
{  
    public:  
        Base1():  
            Base()  
        {  
            mBase1 = 101;  
        }  
        virtual void funcA()  
        {  
            cout << "Base1::funcA()" << endl;  
        }  
        virtual void funcB()  
        {  
            cout << "Base1::funcB()" << endl;  
        }  
    private:  
        int mBase1;  
};  
class Base2 : public Base  
{  
    public:  
        Base2():  
            Base()  
        {  
            mBase2 = 102;  
        }  
        virtual void funcA()  
        {  
            cout << "Base2::funcA()" << endl;  
        }  
        virtual void funcC()  
        {  
            cout << "Base2::funcC()" << endl;  
        }  
    private:  
        int mBase2;  
};  
class Derived : public Base1, public Base2  
{  
    public:  
        Derived():  
            Base1(),  
            Base2()  
        {  
            mDerived = 1001;  
        }  
        virtual void funcD()  
        {  
            cout << "Derived::funcD()" << endl;  
        }  
        virtual void funcA()  
        {  
            cout << "Derived::funcA()" << endl;  
        }  
    private:  
        int mDerived;  
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
    visitVtbl((int**)*(int**)p, 4);  
    p += sizeof(int**);  
  
    cout << *(int*)p << endl;  
    p += sizeof(int);  
  
    cout << *(int*)p << endl;  
    p += sizeof(int);  
  
    visitVtbl((int**)*(int**)p, 3);  
    p += sizeof(int**);  
  
    cout << *(int*)p << endl;  
    p += sizeof(int);  
  
    cout << *(int*)p << endl;  
    p += sizeof(int);  
  
    cout << *(int*)p << endl;  
    return 0;  
}  

