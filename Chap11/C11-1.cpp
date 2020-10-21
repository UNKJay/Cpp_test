#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
    int M,N;
    double num;
    cin>>M>>N>>num;

    if (M == 0 && N == 0) cout<<0<<endl;
    else {
        cout.fill('0');
        num = floor(num * pow(10,N))/pow(10,N); //截断数字
        int w = (N==0?M:M+N+1);
        cout<<setiosflags(ios_base::fixed)<<setprecision(N)<<setw(w)<<num<<endl;
    }
    return 0;
}