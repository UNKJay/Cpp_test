#include<iostream>
#include<cmath>
using namespace std;

int factorNum(int n){
    int num=0;
    for (int i = 1; i <= n; i++)
    {
        if (n%i==0)
            num++;
    }
    return num;
}

int light(int n){
    int num=0;
    for (int i=1;i<=n;i++)
        if (factorNum(i)%2==1)
            num++;
    return num;
}

int light1(int n){      //c3-9
    return floor(sqrt(n));
}

int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        cout<<light1(n)<<endl;
    }
    return 0;
}