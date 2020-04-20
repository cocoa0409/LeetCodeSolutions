#include <iostream>
using namespace std;
class Base
{
    int v1=1;
    int v2=2;
    int v3=3;
public:
    virtual void x() { cout << "Base::x()" << endl; } //行为1:虚函数x()
    virtual void y() { cout << "Base::y()" << endl; } //行为2:虚函数y()
    //virtual void z()=0;                             //行为5:纯虚函数()
};

class Derive : public Base
{
    int v4=4;
    int v5=5;
public:
    void x() { cout << "Derive::x()" << endl; }              //行为1:虚函数x()的实现
                                                             //行为2:虚函数y()忽略不做实现
    virtual void newvirtual() { cout << "Derive::newvirtual()" << endl; }  //行为3:增加新虚函数
    void newnoraml() { cout << "Derive::newnormal()" << endl;} //行为4:增加普通函数
//    void z() { cout << "Derive::z()" << endl; }
};


int main()
{
    Base b;
    Derive d;
    cout<<"sizeof(int)="<<sizeof(int)<<endl;
    cout<<"sizeof(Base)="<<sizeof(Base)<<endl;
    cout<<"sizeof(Derive)="<<sizeof(Derive)<<endl;
    
    int* vptrBase = (int*)&b;                     // 虚函数表地址
    int* vptrDerive = (int*)&d;
    return 0;
}

// x/8ag
