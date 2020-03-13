#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include "date.h"
#include "accumulator.h"
#include<string>

class Account
{
private:
    std::string id;
    double balance;
    static double total;

protected:
    Account(const Date &date,const std::string &id);

    //记录一笔帐，date 为日期， amount 为金额
    void record(const Date &date, double amount, const std::string &desc);

    //输出错误信息
    void error(const std::string &msg);

public:

    static double getTotal() {return total;}
    const std::string &getId() const {return id;}
    double getBalance() const {return balance;}
    
    //显示账户信息
    void show() const;
};


class SavingAccount : public Account  //存款账户类
{
private:
    double rate;        //利率
    Accumulator acc;    ///累加

public:
    // 构造函数
    SavingAccount(const Date &date,const std::string &id,double rate);

    double getRate() const {return rate;}
    
    //存入现金
    void deposit(const Date &date, double amount, const std::string &desc);

    //取出现金
    void withdraw(const Date &date, double amount, const std::string &desc);

    //结算利率
    void settle(const Date &date);
};

class CreditAccount : public Account{
    Accumulator acc;
    double fee;
    double credit;
    double rate;

    double getDebt() const {
        double balance = getBalance();
        return balance<0?balance:0;
    }
public:
    CreditAccount(const Date &date , const std::string &id , double fee , double credit , double rate);
    double getFee() const {return fee;}
    double getCredit() const {return credit;}
    double getRate() const {return rate;}

    double getAvailableCredit() const {
        if (getBalance()<0){
            return credit+getBalance();
        }
        else {
            return credit;
        }
    }

    void deposit(const Date &date, double amount, const std::string &desc);

    //取出现金
    void withdraw(const Date &date, double amount, const std::string &desc);

    //结算利率
    void settle(const Date &date);

    void show() const;

};

#endif