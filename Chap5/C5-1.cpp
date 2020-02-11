#include <iostream>
using namespace std;
  
class Yuebao
{
    static double profitRate;
    double money;

    public:
        static void setProfitRate(double rate); 
        Yuebao(double m):money(m){}            //构造函数
        
        void addProfit();               //加利息
        void deposit(double amount);    //存款
        void withdraw(double amount);   //取款
        double getBalance() {return money;}     //总数
    /* Your code here! */
};

double Yuebao::profitRate=0;
void Yuebao::setProfitRate(double rate){
    profitRate=rate;
}

void Yuebao::addProfit(){
    money+=money*profitRate;
}

void Yuebao::deposit(double amount){
    money+=amount;
}

void Yuebao::withdraw(double amount){
    money-=amount;
}

int main()
{
    int n;
    while(cin >> n)
    {
        double profitRate;
        cin >> profitRate;
        Yuebao::setProfitRate(profitRate);//设定鱼额宝的利率
        Yuebao y(0); //新建鱼额宝账户，余额初始化为0
        int operation;//接受输入判断是存还是取
        double amount;//接受输入存取金额
        for (int i = 0; i < n; ++i)
        {
            y.addProfit();//加入前一天余额产生的利息
            cin >> operation >> amount;
            if (operation == 0)
                y.deposit(amount);//存入金额
            else
                y.withdraw(amount);//取出金额
        }
        cout << y.getBalance() << endl;//输出最终账户余额
    }
    return 0;
}