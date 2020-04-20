#include <iostream>
#include <type_traits>
#include <vector>
#include <memory>
#include <exception>
using namespace std;

int main() {
    cout << boolalpha;
    cout << "is_copy_constructible:" << endl;
    cout << "auto_ptr: " << is_copy_constructible< auto_ptr<int> >::value << endl;
    cout << "unique_ptr: " << is_copy_constructible< unique_ptr<int> >::value << endl;
    cout << "shared_ptr: " << is_copy_constructible< shared_ptr<int> >::value << endl;
    cout << "weak_ptr: " << is_copy_constructible< weak_ptr<int> >::value << endl;
    
    cout << "is_copy_assignable:" << endl;
    cout << "auto_ptr: " << is_copy_assignable< auto_ptr<int> >::value << endl;
    cout << "unique_ptr: " << is_copy_assignable< unique_ptr<int> >::value << endl;
    cout << "shared_ptr: " << is_copy_assignable< shared_ptr<int> >::value << endl;
    cout << "weak_ptr: " << is_copy_assignable< weak_ptr<int> >::value << endl;
    
    vector<int> i_v;
    i_v.push_back(1);
    cout << "i_v=" << i_v[0] << endl;
    vector<int> i_v2=i_v;
    cout << "i_v2=" << i_v2[0] << endl;

    vector< unique_ptr<int> > u_v;
    u_v.push_back(unique_ptr<int>(new int(2)));
    cout << "u_v=" << *u_v[0] << endl;
    //vector< unique_ptr<int> > u_v2=u_v;  //will not compile, need is_copy_constructible == true
    vector< unique_ptr<int> > u_v2 =std::move(u_v);  // but can be moved
    cout << "u_v2=" << *u_v2[0] << " length u_v: " <<u_v.size() << endl;

    vector< shared_ptr<int> > s_v;
    shared_ptr<int> s(new int(3));
    s_v.push_back(s);
    cout << "s_v=" << *s_v[0] << endl;
    vector< shared_ptr<int> > s_v2=s_v;
    cout << "s_v2=" << *s_v2[0] << endl;

    
    vector< auto_ptr<int> > a_v;  //USAGE ERROR
    //a_v.push_back(new int(999));    //ERROR
    /*
这里push_back执行报错了，emplace_back正常
     为什么？
正常来说，这里应该是通过new int(999)
     首先调用 构造函数
     然后再调用 复制构造函数
     然后再调用 析构函数        实现push_back?
     
看push_back的源码，没有可以接受“构造函数参数”的重载，这就蛋疼了，为啥单变量初始化的类可以用构造函数参数当作push_back的参数呢？
     */
    a_v.emplace_back(new int(999));
    vector< auto_ptr<int> > a_v2=a_v;
//    cout << "a_v=" << *a_v[0] << endl;
    cout << "a_v2=" << *a_v2[0] << endl;
}
