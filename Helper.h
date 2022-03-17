//
// Created by zhaobo on 2022/3/16.
//

#ifndef DESIGNPATTERN_HELPER_H
#define DESIGNPATTERN_HELPER_H

#include <vector>
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

#define DESTROY_PTR(ptr) {      \
    if (ptr != nullptr) {       \
        delete ptr;             \
        ptr = nullptr;          \
    }                           \
}

#endif //DESIGNPATTERN_HELPER_H
