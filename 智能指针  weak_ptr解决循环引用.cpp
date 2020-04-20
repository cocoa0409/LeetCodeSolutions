//
//  智能指针weak_ptr解决循环引用.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/15.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <memory>
using namespace std;
 
class Parent;
typedef std::shared_ptr<Parent> ParentPtr;
typedef std::weak_ptr<Parent> WeakParentPtr;
 
class Child
{
public:
    WeakParentPtr father;                 // 只要一环换成 weak_ptr, 即可打破环
    Child() {
        cout << "hello Child" << endl;
    }
    ~Child() {
        cout << "bye Child\n";
    }
};
 
typedef std::shared_ptr<Child> ChildPtr;
typedef std::weak_ptr<Child> WeakChildPtr;
 
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
    ParentPtr p(new Parent());
    ChildPtr c(new Child());
    p->son = c;
    c->father = p;
    cout << p.use_count() << endl;
    cout << c.use_count() << endl;
/*
 函数返回时释放p与c
 - c的释放导致了c指向堆内存的 引用计数 为1
 - p的释放导致p指向堆内存的 引用计数 为0，故该内存被释放，调用了～Parent
    这又导致了p内 ChildPtr son;被释放; c的 引用计数 为0，该内存被释放，调用了～Children
P.S. 栈上p先定义，c后定义；弹出时c先弹出，p后弹出？
 */

}
 
int main()
{
    testParentAndChild();
    return 0;
}

