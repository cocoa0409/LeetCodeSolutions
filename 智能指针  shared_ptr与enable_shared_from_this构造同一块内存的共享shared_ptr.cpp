
#include <memory>
#include <iostream>
class Bad
{
public:
    std::shared_ptr<Bad> getptr() {
        return std::shared_ptr<Bad>(this);
    }
    ~Bad() { std::cout << "Bad::~Bad() called" << std::endl; }
};

class Good : private std::enable_shared_from_this<Good> // 必须公有继承
{
public:
    std::shared_ptr<Good> getptr() {
        return shared_from_this();
    }
    ~Good() { std::cout << "Good::~Good() called" << std::endl; }
};
int main()
{
    std::cout<<"shared_ptr不可通过原指针增加引用:"<<std::endl;
    Bad * point2Bad=new Bad();
    std::shared_ptr<Bad> bpa(point2Bad);
    std::shared_ptr<Bad> bpb(point2Bad);
    // 打印bpa和bpb的引用计数
    std::cout << "bp1.use_count() = " << bpa.use_count() << std::endl;
    std::cout << "bp2.use_count() = " << bpb.use_count() << std::endl;
        
    std::cout<<"shared_ptr不可通过shared_ptr<Bad>(this)返回:"<<std::endl;
    // 错误的示例，每个shared_ptr都认为自己是对象仅有的所有者
    std::shared_ptr<Bad> bp1(new Bad());
    std::shared_ptr<Bad> bp2 = bp1->getptr();
    // 打印bp1和bp2的引用计数
    std::cout << "bp1.use_count() = " << bp1.use_count() << std::endl;
    std::cout << "bp2.use_count() = " << bp2.use_count() << std::endl;
    
    std::cout<<"std::enable_shared_from_this返回指向对象的shared_ptr指针，并增加计数"<<std::endl;
    std::shared_ptr<Good> gp1(new Good());
    std::shared_ptr<Good> gp2 = gp1->getptr();
    // 打印gp1和gp2的引用计数
    std::cout << "gp1.use_count() = " << gp1.use_count() << std::endl;
    std::cout << "gp2.use_count() = " << gp2.use_count() << std::endl;
    
    return 0;
}  // Bad 对象将会被删除两次
