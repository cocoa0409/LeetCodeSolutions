//
//  智能指针shared_ptr循环引用.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/15.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <iostream>
#include <memory>
using namespace std;
 
class Parent;
typedef std::shared_ptr<Parent> ParentPtr;
 
class Child
{
public:
    ParentPtr father;
    Child() {
        cout << "hello Child" << endl;
    }
    ~Child() {
        cout << "bye Child\n";
    }
};
 
typedef std::shared_ptr<Child> ChildPtr;
 
class Parent {
public:
    ChildPtr son;
    Parent() {
        cout << "hello parent\n";
    }
    ~Parent() {
        cout << "bye Parent\n";
    }
};
 
void testParentAndChild()
{
/*
 均用shared_ptr指向了new出的对象
 shared_ptr<Parent> noramlp,p 与 shared_ptr<children> c 均在栈上
 对应的new内存 均在堆上
*/
    ParentPtr normalp(new Parent());
    ParentPtr p(new Parent());
    ChildPtr c(new Child());
    p->son = c;
    c->father = p;
    cout << normalp.use_count() << endl;
    cout << p.use_count() << endl;
    cout << c.use_count() << endl;
/*
 当程序返回时
 shared_ptr<Parent> noramlp,p 与 shared_ptr<children> c 栈上的变量被释放
 noramlp的释放导致了对应堆上内存的 引用计数 为0，
 所以释放 ParentPtr normalp(new Parent()); new出来的内存，调用了Parent的～Parent析构函数
 
 p与c同样被栈释放，但是对应堆上内存的 引用计数 为1，
 所以未调用析构函数
*/
}
 
int main()
{
    testParentAndChild();
    return 0;
}

