//
//  智能指针 enable_shared_from_this分析.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/19.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <memory>
#include <iostream>
using namespace std;

class Good : public std::enable_shared_from_this<Good> // 必须公有继承
{
public:
    std::shared_ptr<Good> getptr() {
        return shared_from_this();
    }
    ~Good() { std::cout << "Good::~Good() called" << std::endl; }
};
int main()
{
    std::cout<<std::is_convertible<Good *,enable_shared_from_this<Good> *>::value<<endl;
    
    Good * _OrigPtr=new Good();
    std::shared_ptr<Good> bp1(_OrigPtr);

    
    std::shared_ptr<Good> bp2 = bp1->getptr();
    // 打印bp1和bp2的引用计数
    std::cout << "bp1.use_count() = " << bp1.use_count() << std::endl;
    std::cout << "bp2.use_count() = " << bp2.use_count() << std::endl;
    
    return 0;
}  // Bad 对象将会被删除两次

