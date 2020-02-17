#include<iostream>
#include<cmath>

using namespace std;

class SavingAccount     //存款账户类
{
private:
    int id;     //账户
    double balance;     //余额
    double rate;        //利率
    int lastDate;       //上次变更余额日期
    double accumulation;    //余额按日累加之和

    //记录一笔帐，date 为日期， amount 为金额
    void record(int date, double amount);

    //获得到指定日期为止的存款累计值
    double accumulate(int date) const{
        return accumulation+(date-lastDate)*balance;
    }
public:
    // 构造函数
    SavingAccount(int date,int id,double rate);

    int getId() const {return id;}
    double getBalance() const {return balance;}
    double getRate() const {return rate;}
    
    //存入现金
    void deposit(int date, double amount);

    //取出现金
    void withdraw(int date, double amount);

    //结算利率
    void settle(int date);

    //显示账户信息
    void show();
};

SavingAccount::SavingAccount(int date, int id, double rate):id(id),balance(0),rate(rate),lastDate(date),accumulation(0){
    cout<<date<<"\t#"<<id<<"  is created"<<endl;
}

void SavingAccount::record(int date,double amount){
    accumulation=accumulate(date);
    lastDate=date;
    amount=floor(amount*100+0.5)/100;       //保留小数点后两位
    balance+=amount;
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}
    
void SavingAccount::deposit(int date, double amount){
    record (date,amount);
}

void SavingAccount::withdraw(int date, double amount){
    if (amount>getBalance())
        cout<<"Error : not enough money"<<endl;
    else
        record(date,-amount);
}

void SavingAccount::settle(int date){
    double interest=accumulate(date)*rate/365;
    if (interest!=0)
        record(date,interest);
    accumulation=0;
}

void SavingAccount::show(){
    cout<<"#"<<id<<"\tBalance "<<balance<<endl;
}

int main(){
    SavingAccount sa0(1, 21325302, 0.015);
	SavingAccount sa1(1, 58320212, 0.015);

	sa0.deposit(5, 5000);
	sa1.deposit(25, 10000);
	sa0.deposit(45, 5500);
	sa1.withdraw(60, 4000);

	sa0.settle(90);
	sa1.settle(90);

	sa0.show();	
	sa1.show();	
    return 0;
}