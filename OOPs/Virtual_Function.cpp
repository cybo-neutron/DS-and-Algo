#include<bits/stdc++.h>
using namespace std;

class A
{
    public :
        void f1(){
            cout<<"Calling f1 from A"<<endl;
        }
        void f2()
        {
            cout<<"Calling f2 from A"<<endl;
        }
        virtual void f3()
        {
            cout<<"Calling f3 from A"<<endl;
        }
        
    
};

class B:public A
{
    public:
        void f1()   // method overriding
        {
            cout<<"Calling f1 from B"<<endl;
        }
        void f2(int x)  //method hiding 
        {
            cout<<"Calling f2 from B"<<endl;
        }
        void f3()
        {
            cout<<"Calling f3 from B"<<endl;
        }

};

int main()
{
    B ob1;
    ob1.f1();   //early binding
    //ob1.f2();   //error
    ob1.f2(3);
    
    A*p=&ob1;
    p->f3();     //late binding (Runtime polymorphism)
    
        
    cout<<sizeof(A);    
    
    
}