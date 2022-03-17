//
// Created by zhaobo on 2022/3/16.
//
// 单例模式

#ifndef DESIGNPATTERN_SINGLETON_H
#define DESIGNPATTERN_SINGLETON_H

#include "Helper.h"

class Singleton {
private:
    map<int,int> SharedMap;

    Singleton() {
        cout << "instance construct." << endl;
    }
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    class GC {
    public:
        ~GC() {
            if (instance != nullptr) {
                DESTROY_PTR(instance);
                cout << "instance destroy by gc." << endl;
            }
        }
    };
    static Singleton* instance;
    static Singleton::GC gc;

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton;
            return instance;
        } else {
            return instance;
        }
    }

    static void destroy() {
        if (instance != nullptr) {
            DESTROY_PTR(instance);
            cout << "instance destroy by user." << endl;
        }
    }

    void set(int key, int value) {
        SharedMap[key] = value;
    }

    int get(int key) {
        if (SharedMap.count(key)) {
            return SharedMap[key];
        }
        return -1;
    }

    int count(int key) {
        return SharedMap.count(key);
    }

    void print() {
        cout << "output the values:" << endl;
        for (auto val : SharedMap) {
            cout << "key : " << val.first << " value : " << val.second << endl;
        }
    }
};

Singleton* Singleton::instance = nullptr;
Singleton::GC Singleton::gc;

#endif