//
//  vector的移动构造.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
#include <iostream>
#include <vector>

using std::cout; using std::endl;

class MoreArgv{
public:
    int a;
    double b;
    MoreArgv(int a_){
        a=a_;  b=0;
        cout << "  调用 单变量 构造函数：MoreArgv("<<a<<" "<<b<<")" << endl;}
    MoreArgv(int a_,double b_){
        a=a_;b=b_;
        cout << "  调用构造函数：MoreArgv("<<a<<" "<<b<<")" << endl;}
    MoreArgv(const MoreArgv&& targ) {
        a=targ.a;b=targ.b;
        cout << "  调用 移动 构造函数：MoreArgv("<<a<<" "<<b<<")" << endl;}
    MoreArgv(const MoreArgv& targ) {
        a=targ.a;b=targ.b;
        cout << "  调用 拷贝 构造函数：MoreArgv("<<a<<" "<<b<<")" << endl;}
    ~MoreArgv(){
        cout << "  调用析构函数：~MoreArgv("<<a<<" "<<b<<")" << endl;}
};

int main(int argc, char **argv)
{
    std::vector<MoreArgv> vec;
    vec.reserve(20);
//    cout<< "push_back() 调用单变量的构造函数:"<<endl;
//    vec.push_back(1);
//    vec.push_back(2);
////    cout<< "push_back() 调用多变量的构造函数？(同emplace_back()?):"<<endl;
////    vec.push_back(2,INT_MAX);          //compile-time ERROR
    
    cout<< "push_back() 优先调用 Move constructor:"<<endl;
    vec.push_back(MoreArgv(3,0));
    vec.push_back(MoreArgv(4,0));
    
    cout<< "emplace_back() 优先调用 Move constructor:"<<endl;
    vec.emplace_back(3,0);
    vec.emplace_back(4,0);
    vec.emplace_back(5,0);
    vec.emplace_back(6,0);
    vec.emplace_back(7,0);
    return 0;
}

