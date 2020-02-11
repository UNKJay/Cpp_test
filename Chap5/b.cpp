#include<iostream>
using namespace std;

int fun1(int a,int b);

extern int a;

int main(){
    int b;
    cin>>b;
    cout<<fun1(a,b)<<endl;
}