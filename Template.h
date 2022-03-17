//
// Created by zhaobo on 2022/3/17.
//
// 模版模式

#include "Helper.h"

#ifndef DESIGNPATTERN_TEMPLATE_H
#define DESIGNPATTERN_TEMPLATE_H

class Game {
public:
    virtual void init() = 0;
    virtual void run() = 0;
    virtual void stop() = 0;

    void play() {
        init();
        run();
        stop();
    }
};

class Basketball : public Game {
public:
    void init() {
        cout << "basketball init." << endl;
    }
    void run() {
        cout << "run basketball." << endl;
    }
    void stop() {
        cout << "basketball stop." << endl;
    }
};

class Cricket : public Game {
public:
    void init() {
        cout << "cricket init." << endl;
    }
    void run() {
        cout << "run cricket." << endl;
    }
    void stop() {
        cout << "cricket stop." << endl;
    }
};

class GameDemo {
public:
    void exec() {
        Game* game = new Basketball();
        game->play();
        game = new Cricket();
        game->play();
    }
};

#endif //DESIGNPATTERN_TEMPLATE_H
