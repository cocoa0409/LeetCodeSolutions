//
//  SFINAE  检查内嵌类型（老写法）.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/18.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <iostream>
#include <vector>

template <typename T>
struct has_typedef_iterator {
    // Types "yes" and "no" are guaranteed to have different sizes,
    // specifically sizeof(yes) == 1 and sizeof(no) == 2.
    typedef char yes[1];
    typedef char no[2];

    template <typename C>
    static yes& test(typename C::iterator*);
    template <typename>
    static no& test(...);

    // If the "sizeof" of the result of calling test<T>(nullptr) is equal to sizeof(yes),
    // the first overload worked and T has a nested type named iterator.
    static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
};

struct foo {
    typedef float iterator;
};

int main() {
    std::cout << std::boolalpha;
    std::cout << has_typedef_iterator<foo>::value << std::endl;//true
    std::cout << has_typedef_iterator<int>::value << std::endl;//false
    std::cout << has_typedef_iterator<std::vector<int> >::value << std::endl;//true
    return 0;
}

