//
// Created by zhaobo on 2022/3/17.
//
// 组合模式

#ifndef DESIGNPATTERN_COMPOSITE_H
#define DESIGNPATTERN_COMPOSITE_H

#include "Helper.h"

class Employee {
private:
    string _name;        // 名字
    string _dept;        // 职称
    int _salary;         // 薪资
    list<Employee> _subordinates;    // 下属

public:
    Employee(const string& name, const string& dept, int salary) : _name(name), _dept(dept), _salary(salary){}
    void add(const Employee& e) {
        _subordinates.push_back(e);
    }
    void remove(const Employee& e) {
        _subordinates.remove(e);
    }
    list<Employee> getSubordinates() {
        return _subordinates;
    }
    bool operator==(const Employee& e) const {
        return _salary == e._salary && _dept == e._dept && _name == e._name && _subordinates == e._subordinates;
    }

    string toString() {
        return ("Employee :[ Name : " + _name
                + ", dept : " + _dept + ", salary :"
                + to_string(_salary) + " ]");
    }
};

class CompositePatternDemo {
public:
    void exec() {
        Employee *CEO = new Employee("John", "CEO", 30000);

        Employee *headSales = new Employee("Robert", "Head Sales", 20000);

        Employee *headMarketing = new Employee("Michel", "Head Marketing", 20000);

        Employee *clerk1 = new Employee("Laura", "Marketing", 10000);
        Employee *clerk2 = new Employee("Bob", "Marketing", 10000);

        Employee *salesExecutive1 = new Employee("Richard", "Sales", 10000);
        Employee *salesExecutive2 = new Employee("Rob", "Sales", 10000);

        //CEO->add(*headSales);
        //CEO->add(*headMarketing);

        headSales->add(*salesExecutive1);
        headSales->add(*salesExecutive2);

        headMarketing->add(*clerk1);
        headMarketing->add(*clerk2);

        CEO->add(*headSales);
        CEO->add(*headMarketing);

        //打印该组织的所有员工
        cout << CEO->toString() << endl;
        for (Employee headEmployee : CEO->getSubordinates()) {
            cout << headEmployee.toString() << endl;
            for (Employee employee : headEmployee.getSubordinates()) {
                cout << employee.toString() << endl;
            }
        }
    }
};

#endif //DESIGNPATTERN_COMPOSITE_H
