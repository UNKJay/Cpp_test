#include<iostream>
#include "client.h"

using namespace std;

//静态数据成员在类外进行单独的初始化
int Client::ClientNum=0;
char Client::ServerName='a';

int main(){
    Client c1;
    c1.ChangeServerName('b');
    cout<<c1.GetClientNum()<<endl;

    Client c2;
    c2.ChangeServerName('c');
    cout<<c2.GetClientNum()<<endl;
}