#ifndef _ACCUMULATOR_H_
#define _ACCUMULATOR_H_

#include "date.h"

class Accumulator
{
    Date lastDate;
    double value;
    double sum;

    
public:
    Accumulator(const Date &d , double value):
        lastDate(d),value(value),sum(0) {}

    double getSum(const Date &date){
        return sum + value * date.distance(lastDate);
    }

    void change(const Date &date , double value){
        sum = getSum(date);
        this->value = value;
        lastDate = date;
    }

    void reset(const Date &date , double value){
        sum = 0;
        this->value = value;
        lastDate = date;
    }
};




#endif