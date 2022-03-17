//
// Created by zhaobo on 2022/3/17.
//
// 工厂模式

#ifndef DESIGNPATTERN_FACTORY_H
#define DESIGNPATTERN_FACTORY_H

#include "Helper.h"

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() {
        cout << "draw a circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() {
        cout << "draw a rectangle." << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "draw a square." << endl;
    }
};

class Color {
public:
    virtual void fill() = 0;
};

class Red : public Color {
public:
    void fill() {
        cout << "red fill." << endl;
    }
};

class Green : public Color {
public:
    void fill() {
        cout << "green fill." << endl;
    }
};

class Blue : public Color {
public:
    void fill() {
        cout << "blue fill." << endl;
    }
};

class AbstractFactory {
public:
    virtual Shape* getShape(const string &) = 0;
    virtual Color* getColor(const string &) = 0;
};

class ShapeFactory : public AbstractFactory {
public:
    Shape* getShape(const string& shape) {
        if (shape == "CIRCLE") {
            return new Circle();
        } else if (shape == "RECTANGLE") {
            return new Rectangle();
        } else if (shape == "SQUARE") {
            return new Square();
        }
        return nullptr;
    }

    Color* getColor(const string& color) {
        return nullptr;
    }
};

class ColorFactory : public AbstractFactory {
public:
    Color* getColor(const string& color) {
        if (color == "RED") {
            return new Red();
        } else if (color == "GREEN") {
            return new Green();
        } else if (color == "BLUE") {
            return new Blue();
        }
        return nullptr;
    }

    Shape* getShape(const string& shape) {
        return nullptr;
    }
};

class FactoryProducer {
public:
    AbstractFactory* getFactory(const string& choice) {
        if (choice == "SHAPE") {
            return new ShapeFactory();
        } else if (choice == "COLOR") {
            return new ColorFactory();
        } else {
            return nullptr;
        }
    }
};

class AbstractFactoryPatternDemo {
public:
    void exec() {
        FactoryProducer* factoryProducer = new FactoryProducer();

        //获取形状工厂
        AbstractFactory* shapeFactory = factoryProducer->getFactory("SHAPE");

        //获取形状为 Circle 的对象
        Shape* shape1 = shapeFactory->getShape("CIRCLE");

        //调用 Circle 的 draw 方法
        shape1->draw();

        //获取形状为 Rectangle 的对象
        Shape* shape2 = shapeFactory->getShape("RECTANGLE");

        //调用 Rectangle 的 draw 方法
        shape2->draw();

        //获取形状为 Square 的对象
        Shape* shape3 = shapeFactory->getShape("SQUARE");

        //调用 Square 的 draw 方法
        shape3->draw();

        //获取颜色工厂
        AbstractFactory* colorFactory = factoryProducer->getFactory("COLOR");

        //获取颜色为 Red 的对象
        Color* color1 = colorFactory->getColor("RED");

        //调用 Red 的 fill 方法
        color1->fill();

        //获取颜色为 Green 的对象
        Color* color2 = colorFactory->getColor("GREEN");

        //调用 Green 的 fill 方法
        color2->fill();

        //获取颜色为 Blue 的对象
        Color* color3 = colorFactory->getColor("BLUE");

        //调用 Blue 的 fill 方法
        color3->fill();
    }
};

#endif //DESIGNPATTERN_FACTORY_H
