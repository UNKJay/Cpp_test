#include<iostream>

using namespace std;

int main(){
    int n;
    long long f[81];
    while(cin>>n){
        f[0]=1;
        f[1]=1;
        if (n>=2)
            for (int i = 2; i <= n; i++)
                f[i]= f[i-1]+f[i-2];
        cout<<f[n]<<endl;
    }
    return 0;
}