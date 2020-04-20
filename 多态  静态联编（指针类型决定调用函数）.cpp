
#include <memory>
#include <iostream>
using namespace std;

class Base
{
public:
    void fun(){cout << "Base::fun()" << endl;}
    void foo(){cout <<"Base::foo()"<<endl;}
};
class Derive: public Base
{
public:
    void fun(){cout << "Derive::fun()" << endl;}
    void foo(){cout <<"Derive::foo()"<<endl;}
    void foo(int num){cout <<"Derive::foo("<<num<<")"<<endl;}
};
int main()
{
    cout<<"sizeof(Base)="<<sizeof(Base)<<endl;
    cout<<"sizeof(Derive)="<<sizeof(Derive)<<endl;
    
    Base * bpt_to_derive=new Derive();          //Base指针指向Derive对象
    cout<<"bpt_to_derive->fun()  ";
    bpt_to_derive->fun();                       //调用了Base的fun()方法，而不是Derive的fun()方法
    cout<<"bpt_to_derive->foo()  ";             //调用了Base的foo()方法
    bpt_to_derive->foo();
//    cout<<"bpt_to_derive->foo(int num)  ";
//    bpt_to_derive->foo(5);//compile time error:Too many arguments to function call, expected 0, have 1
//    bpt_to_derive->Derive::foo(5);  //compile time error: 'Derive::foo' is not a member of class 'Base'
    
    Derive * dpt_to_derive=new Derive();        //Derive指针指向Derive对象
    cout<<"dpt_to_derive->fun()  ";
    dpt_to_derive->fun();
    cout<<"dpt_to_derive->foo()  ";
    dpt_to_derive->foo();
    cout<<"dpt_to_derive->Base::foo()  ";
    dpt_to_derive->Base::foo();
    cout<<"dpt_to_derive->foo(int num)  ";      //foo同名重载
    dpt_to_derive->foo(5);
    
//    Derive * dpt_to_base=new Base();//compile time error:Cannot initialize a variable of type 'Derive *' with an rvalue of type 'Base *'
    return 0;
}
