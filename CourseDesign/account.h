#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include "date.h"
#include<string>

class SavingAccount     //存款账户类
{
private:
    std::string id;     //账户
    double balance;     //余额
    double rate;        //利率
    Date lastDate;       //上次变更余额日期
    double accumulation;    //余额按日累加之和
    static double total;       //所有账户总金额

    //记录一笔帐，date 为日期， amount 为金额
    void record(const Date &date, double amount, const std::string &desc);

    //输出错误信息
    void error(const std::string &msg);

    //获得到指定日期为止的存款累计值
    double accumulate(const Date &date) const{
        return accumulation + balance * date.distance(lastDate);
    }
public:
    // 构造函数
    SavingAccount(const Date &date,const std::string &id,double rate);

    static double getTotal() {return total;}
    const std::string &getId() const {return id;}
    double getBalance() const {return balance;}
    double getRate() const {return rate;}
    
    //存入现金
    void deposit(const Date &date, double amount, const std::string &desc);

    //取出现金
    void withdraw(const Date &date, double amount, const std::string &desc);

    //结算利率
    void settle(const Date &date);

    //显示账户信息
    void show();

    
};

#endif