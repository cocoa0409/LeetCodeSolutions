//
//  O迭代器.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/19.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <iostream>
#include <math.h>
//------------------------
#include <string>
//------------------------
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
//------------------------
#include <stack>
#include <queue>
//------------------------
#include <numeric>   //For accumulate()
#include <algorithm> //For copy()
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

int main(){
    vector<string> v;
    std::copy(std::istream_iterator<string>(std::cin), std::istream_iterator<string>(), std::back_inserter(v));
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<string>(std::cout, " "));
}

