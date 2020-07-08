

#include <bits/stdc++.h>
using namespace std;

 class c
{
        static int a;
    public:
  
    static void call()
    {
        cout<<"Fuck you";
    }
}x;


int c::a=0;


class Complex
{
    
    public:
    int a,b;
    Complex(int a=0,int b=0)
    {
        this->a=a,this->b=b;
    }
    
    
    Complex operator-()
    {
        Complex temp;
        temp.a=-a;
        temp.b=-b;
        return temp;
    }
    Complex operator-(Complex c)
    {
        Complex temp;
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }
    
    Complex operator++()
    {
        Complex temp;
        temp.a=++a;
        temp.b=++b;
        return temp;
    }
    Complex operator++(int)
    {
        Complex temp;
        temp.a=a++;
        temp.b=b++;
        return temp;
    }
    
    void print()
    {
        printf("%d + %di\n",a,b);
    }
};


class FriendDemo{
    int a,b;
    public:
    FriendDemo(int a=0,int b=0):a(a),b(b){}
    
        friend void print(FriendDemo);
};



void print(FriendDemo f)
{
    printf("a: %d | b: %d\n",f.a,f.b);
}


//Inheritance

class A{
    public:
        A(int a)
        {
            cout<<"Calling A"<<endl;
        }
};

class B:public A
{
public:
    B():A(5)
    {
        cout<<"Calling B"<<endl;
    }

};



int main() {
 
    // c::call();
    
    
    //Operator Overloading
    /*
    Complex obj(4,5);
    obj.print();
    obj=-obj;
    obj.print();
    Complex sub=obj-Complex(2,5);
    Complex sub2=obj.operator-(Complex(2,3));
    sub.print();
    sub2.print();
    
    sub2=++sub;
    sub.print();
    sub2.print();
    sub2=sub++;
    sub.print();
    sub2.print();
    */
    
    // FriendDemo f;
    // print(f);
    // FriendDemo f1(5,6);
    // print(f1);
    
    
    B b;


    
    
   
}