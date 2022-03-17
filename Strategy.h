//
// Created by zhaobo on 2022/3/16.
//
// 策略模式

#ifndef DESIGNPATTERN_STRATEGY_H
#define DESIGNPATTERN_STRATEGY_H

#include "Helper.h"

class Strategy {
public:
    Strategy() = default;
    ~Strategy() = default;
    virtual int doOperation(int val1, int val2) {
        return val1 + val2;
    }
};

class OperationAdd : public Strategy {
public:
    OperationAdd() = default;
    ~OperationAdd() = default;
    virtual int doOperation(int val1, int val2) {
        return val1 + val2;
    }
};

class OperationSub : public Strategy {
public:
    OperationSub() = default;
    ~OperationSub() = default;
    virtual int doOperation(int val1, int val2) {
        return val1 - val2;
    }
};

class OperationMulti : public Strategy {
public:
    OperationMulti() = default;
    ~OperationMulti() = default;
    virtual int doOperation(int val1, int val2) {
        return val1 * val2;
    }
};

class Context {
public:
    Context(Strategy* strategy) : _strategy(strategy) {}

    ~Context() {
        if (_strategy != nullptr) {
            DESTROY_PTR(_strategy);
        }
    }

    int doOperation(int val1, int val2) {
        return _strategy->doOperation(val1, val2);
    }

private:
    Strategy* _strategy = nullptr;
};

#endif //DESIGNPATTERN_STRATEGY_H
