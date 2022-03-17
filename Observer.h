//
// Created by zhaobo on 2022/3/16.
//
// 观察者模式

#ifndef DESIGNPATTERN_OBSERVER_H
#define DESIGNPATTERN_OBSERVER_H

#include "Helper.h"

class Observer {
public:
    Observer() {}
    ~Observer() {}
    virtual void update() {}
};

class Subject {
private:
    vector<Observer*> subjects;
    int _state;
public:
    Subject() = default;
    ~Subject() {
        for (auto subject : subjects) {
            if (subject != nullptr) {
                DESTROY_PTR(subject);
            }
        }
    }

    int getState() {
        return _state;
    }

    void setState(int state) {
        _state = state;
        notifyAllObserver();
    }

    void attach(Observer* observer) {
        subjects.push_back(observer);
    }

    void notifyAllObserver() {
        for (auto obj : subjects) {
            if (obj == nullptr) continue;
            obj->update();
        }
    }
};

class BinaryObserver : public Observer {
public:
    BinaryObserver(Subject* subject) {
        if (subject == nullptr) return;
        subject->attach(this);
    }

    void update() {
        cout << "update BinaryObserver" << endl;
    }
};

class OctalObserver : public Observer {
public:
    OctalObserver(Subject* subject) {
        if (subject == nullptr) return;
        subject->attach(this);
    }

    void update() {
        cout << "update OctalObserver" << endl;
    }
};

class HexaObserver : public Observer {
public:
    HexaObserver(Subject* subject) {
        subject->attach(this);
    }

    void update() {
        cout << "update HexaObserver" << endl;
    }
};

#endif //DESIGNPATTERN_OBSERVER_H
