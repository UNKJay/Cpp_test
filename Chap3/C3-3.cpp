#include<iostream>

using namespace std;

bool isUgly(int n){
    while (n%2==0)
        n/=2;
    while (n%3==0)
        n/=3;
    while (n%5==0)
        n/=5;
    return (n==1)?true:false;
}

int main(){
    int n;
    while (cin>>n)
    {
        if (isUgly(n))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}