#include <iostream>
#include<cmath>
#include "account.h"

using namespace std;

double SavingAccount::total=0;

SavingAccount::SavingAccount(const Date &date,const string &id,double rate):
    id(id),balance(0),rate(rate),lastDate(date),accumulation(0){
    date.show();
    cout<<"\t#"<<id<<"  is created"<<endl;
}

void SavingAccount::error(const std::string &msg){
    cout<<"Error (#"<<id<<")"<<msg<<endl;
}

void SavingAccount::record(const Date &date, double amount, const std::string &desc){
    accumulation=accumulate(date);
    lastDate=date;
    amount=floor(amount*100+0.5)/100;       //保留小数点后两位
    balance+=amount;
    total+=amount;
    date.show();
    cout<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<<endl;
}
    
void SavingAccount::deposit(const Date &date, double amount, const std::string &desc){
    record (date,amount,desc);
}

void SavingAccount::withdraw(const Date &date, double amount, const std::string &desc){
    if (amount>getBalance())
        error("not enough money!");
    else
        record(date,-amount,desc);
}

void SavingAccount:: settle(const Date &date){
    double interest=accumulate(date)*rate/365;
    if (interest!=0)
        record(date,interest,"interest");
    accumulation=0;
}

void SavingAccount::show(){
    cout<<"#"<<id<<"\tBalance "<<balance;
}
