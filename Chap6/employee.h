#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include<iostream>

using namespace std;

class Employee
{
private:
    char * name;
    char * address;
    char * city;
    char * code;
public:
    Employee(char * n="",char * a="",char * ct="",char * cd=""):name(n),address(a),city(ct),code(cd){}

    void display() const{
        cout<<"name: "<<name<<endl;
        cout<<"address: "<<address<<endl;
        cout<<"city: "<<city<<endl;
        cout<<"code: "<<code<<endl;

    }

    void changeName(char * nm){
        name=nm;
    }
};

#endif